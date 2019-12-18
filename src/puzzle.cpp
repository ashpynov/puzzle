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

    // hash map to keep middle part of date to have O(1) on middle search
    // key is data value,
    // value is data position 
    unordered_multimap<int, int>  middle;
    middle.reserve( sortedData.size() );
    
    for ( int i = 1; i < sortedData.size()-1 ; ++i )
    {
        middle.insert( make_pair( sortedData[ i ], i ) );
    }

    for ( int sum =0, negativeIndex = 0, positiveIndex = sortedData.size() - 1;
            negativeIndex < positiveIndex &&
            sortedData[ negativeIndex ] <= 0 &&
            sortedData[ positiveIndex ] >= 0 ;
            sum > 0 ? --positiveIndex : ++negativeIndex
        )
    {
        sum = sortedData[ negativeIndex ] + sortedData[ positiveIndex ];

        auto range = middle.equal_range( -1 * sum );
        if ( range.first == middle.end() && range.second == middle.end() )  // Not found
                continue;

        if ( ( range.first->second != negativeIndex && range.first->second  != positiveIndex )    // found index not equal to 
             || ( ++range.first != range.second ) )                                               // our found more than onr item
            {
            outA = sortedData[ negativeIndex ];
            outB = -sum;
            outC = sortedData[ positiveIndex ] ;
            return true;
            }
    }
    return false;

}
