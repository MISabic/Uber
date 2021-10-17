#ifndef TOP_EARNERS_CPP
#define TOP_EARNERS_CPP

#include "TopEarners.h"

template<class ItemType>
TopEarners<ItemType>::TopEarners( ) {
    ReadData( );
}

template<class ItemType>
void TopEarners<ItemType>::ReadData( ) {

    ifstream inFile( "MonthlyEarners.txt" );
    string name;
    double totalIncome;

    while( inFile >> name >> totalIncome ) {
        pq.Enqueue( MaxElem( name, totalIncome ) );
    }

    inFile.close( );
}

template<class ItemType>
vector<string> TopEarners<ItemType>::GetTopFive( ) {
    MaxElem me;
    vector<string> res;

    int sz = pq.GetSize() < 5 ? pq.GetSize() : 5;

    for( int i = 0; i < sz; i++ ) {
        pq.Dequeue( me );
        res.push_back( me.GetName( ) );
    }

    return res;
}

#endif // TOP_EARNERS_CPP

