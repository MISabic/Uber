#ifndef HEAP_CPP
#define HEAP_CPP

#include "HeapType.h"

template <class ItemType>
void Swap( ItemType& one, ItemType& two ) {
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp( int root, int bottom ) {
    int parent;
    if ( bottom > root ) {
        parent = (bottom-1) / 2;
        if ( elements[parent] < elements[bottom] ) {
            Swap( elements[parent], elements[bottom] );
            ReheapUp( root, parent );
        }
    }
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown( int root, int bottom ) {

    int maxChild, rightChild = root*2+2, leftChild = root*2+1;

    if ( leftChild <= bottom ) {    //there is at least one child
        if ( leftChild == bottom )  //it is the only child
            maxChild = leftChild;
        else {                      //there are two children
            if ( elements[leftChild] <= elements[rightChild] )
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }

        if ( elements[root] < elements[maxChild] ) {
            Swap( elements[root], elements[maxChild] );
            ReheapDown( maxChild, bottom );
        }
    }
}

#endif // HEAP_CPP

