#ifndef TOP_RATED_H
#define TOP_RATED_H

#include "PQType.h"
#include "MinElem.h"

using namespace std;

template <class ItemType>
class TopRated {

private :
    PQType<ItemType> pq;
public:
    TopRated( );
    void ReadData(  );
    vector<string> GetTopFive( );
};

#endif // TOP_RATED_H

#include "TopRated.cpp"

