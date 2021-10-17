#ifndef HEAP_H
#define HEAP_H

#include<bits/stdc++.h>

using namespace std;

template<class ItemType>
struct HeapType {
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements;
    int numElements;
};

#endif // HEAP_H

#include "HeapType.cpp"

