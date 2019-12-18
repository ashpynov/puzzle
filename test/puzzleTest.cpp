#include "puzzle.hpp"

#include <gtest/gtest.h>
#include <vector>

using namespace std;

typedef std::vector<int> Data;
int outA, outB, outC;


TEST( Puzzle, Random ) 
{
    const int           SIZE  = 1000;
    const int           RRAND = 1000;    /// not more than RAND_MAX
    
    vector<int>         data;
    // Fill the data by random integers
    data.reserve( SIZE );
    for (int i = 0; i < SIZE; i++ )
    {
        data.push_back( (rand() % (RRAND * 2 )) - RRAND );
        cout << "Data[" << i << "]:\t" << data[i] << endl;
    }

    ASSERT_NO_FATAL_FAILURE( searchTriplet( data, outA, outB, outC ) );
}

TEST( Puzzle, FoundSimple )
{
    Data data = { -100, 5, -10, 110 };

    ASSERT_TRUE( searchTriplet( data, outA, outB, outC ) );
    ASSERT_EQ( outA, -100 );
    ASSERT_EQ( outB, -10 );
    ASSERT_EQ( outC,  110 );
}

TEST( Puzzle, NotFoundSimple )
{
    Data data = { -100, 5, 9, 110 };

    ASSERT_FALSE( searchTriplet( data, outA, outB, outC ) );
}

TEST( Puzzle, FoundWithOneZero )
{
    Data data = { -100, 0, 5, 100 };

    ASSERT_TRUE( searchTriplet( data, outA, outB, outC ) );
    ASSERT_EQ( outA, -100 );
    ASSERT_EQ( outB, 0 );
    ASSERT_EQ( outC, 100 );
}


TEST( Puzzle, FoundWithThreeZero )
{
    Data data = { -100, 0, 0, 0, 110 };

    ASSERT_TRUE( searchTriplet( data, outA, outB, outC ) );
    ASSERT_EQ( outA, 0 );
    ASSERT_EQ( outB, 0 );
    ASSERT_EQ( outC, 0 );
}

TEST( Puzzle, FoundWithThreeItem )
{
    Data data = { -120, 10, 110 };

    ASSERT_TRUE( searchTriplet( data, outA, outB, outC ) );
    ASSERT_EQ( outA, -120 );
    ASSERT_EQ( outB, 10 );
    ASSERT_EQ( outC, 110 );
}

TEST( Puzzle, NotFoundWithPotentialDublicate )
{
    Data data = { -100, 30, 50, 200 };

    ASSERT_FALSE( searchTriplet( data, outA, outB, outC ) );
}

TEST( Puzzle, FoundWithDublicates )
{
    Data data = { -100, -2, -10, 30, 50, 200, 50 };

    ASSERT_TRUE( searchTriplet( data, outA, outB, outC ) );
    ASSERT_EQ( outA, -100 );
    ASSERT_EQ( outB, 50 );
    ASSERT_EQ( outC, 50 );
}