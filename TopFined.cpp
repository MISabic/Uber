#ifndef TOP_FINED_CPP
#define TOP_FINED_CPP

#include "TopFined.h"

template<class ItemType>
TopFined<ItemType>::TopFined( ) {
    ReadData( );
}

template<class ItemType>
void TopFined<ItemType>::ReadData( ) {

    ifstream inFile( "FinedDrivers.txt" );
    string name;
    int fines;

    while( inFile >> name >> fines ) {
        pq.Enqueue( MaxElemAg( name, fines ) );
    }

    inFile.close( );
}

template<class ItemType>
vector<string> TopFined<ItemType>::GetTopFive( ) {
    MaxElemAg me;
    vector<string> res;

    int sz = pq.GetSize() < 5 ? pq.GetSize() : 5;

    for( int i = 0; i < sz; i++ ) {
        pq.Dequeue( me );
        res.push_back( me.GetName( ) );
    }

    return res;
}

#endif // TOP_FINED_CPP

