#ifndef PQTYPE_H_INCLUDED
#define PQTYPE_H_INCLUDED

#include "HeapType.h"

using namespace std;

class FullPQ{};
class EmptyPQ{};

template<class ItemType>
class PQType {

public:
    PQType( );
    PQType( int );
    ~PQType( );
    void MakeEmpty( );
    bool IsEmpty( );
    bool IsFull( );
    int GetSize( );
    void Enqueue( ItemType newItem );
    void Dequeue( ItemType& item );
private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};

#endif // PQTYPE_H_INCLUDED

#include "PQType.cpp"
