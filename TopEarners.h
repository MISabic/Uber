#ifndef TOP_EARNERS_H
#define TOP_EARNERS_H

#include "PQType.h"
#include "MaxElem.h"

using namespace std;

template <class ItemType>
class TopEarners {

private :
    PQType<ItemType> pq;
public:
    TopEarners( );
    void ReadData(  );
    vector<string> GetTopFive( );
};

#endif // TOP_EARNERS_H

#include "TopEarners.cpp"
