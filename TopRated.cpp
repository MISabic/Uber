#ifndef TOP_RATED_CPP
#define TOP_RATED_CPP

#include "TopRated.h"

template<class ItemType>
TopRated<ItemType>::TopRated( ) {
    ReadData( );
}

template<class ItemType>
void TopRated<ItemType>::ReadData( ) {

    ifstream inFile( "RatedDrivers.txt" );
    string name;
    double rating;

    while( inFile >> name >> rating ) {
        pq.Enqueue( MinElem( name, rating ) );
    }

    inFile.close( );
}

template<class ItemType>
vector<string> TopRated<ItemType>::GetTopFive( ) {
    MinElem me;
    vector<string> res;

    int sz = pq.GetSize() < 5 ? pq.GetSize() : 5;

    for( int i = 0; i < sz; i++ ) {
        pq.Dequeue( me );
        res.push_back( me.GetName( ) );
    }

    return res;
}

#endif // TOP_RATED_CPP

