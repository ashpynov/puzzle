#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool searchTriplet( const vector<int> & data, int& outA, int& outB, int& outC )
{
    // here the puzzle starts
    vector<int>sortedData = data;
    std::sort( sortedData.begin(), sortedData.end());

    // hash map to keep positive part of date to have O(1) on positive search
    // key is data value,
    // value is data position 
    unordered_multimap<int, int>  positive;
    positive.reserve( sortedData.size() );
    
    for ( int i = 0; i < sortedData.size() ; ++i )
    {
        if ( sortedData[ i ] >=0 )
         positive.insert( make_pair( sortedData[ i ], i ) );
    }
    for (   int negativeIndex = 0; 
            negativeIndex < sortedData.size() - 2
                && sortedData[negativeIndex] <= 0;
            ++negativeIndex
        )
    {
        for ( int middleIndex = negativeIndex + 1;
                middleIndex < sortedData.size() - 1;
                ++middleIndex
            )
        {
            int sum = sortedData[ negativeIndex ] + sortedData[ middleIndex ];

            auto range = positive.equal_range( -1 * sum );
            if ( range.first == positive.end() && range.second == positive.end() )  // Not found
                    continue;

            if ( ( range.first->second != negativeIndex && range.first->second  != middleIndex )    // found index not equal to 
                || ( ++range.first != range.second ) )                                              // our found more than one item
                {
                outA = sortedData[ negativeIndex ];
                outB = sortedData[ middleIndex ] ;
                outC = -sum;
                return true;
                }
        }
    }
    return false;

}
