#ifndef TOP_FINED_H
#define TOP_FINED_H

#include "PQType.h"
#include "MaxElemAg.h"

using namespace std;

template <class ItemType>
class TopFined {

private :
    PQType<ItemType> pq;
public:
    TopFined( );
    void ReadData(  );
    vector<string> GetTopFive( );
};

#endif // TOP_FINED_H

#include "TopFined.cpp"

