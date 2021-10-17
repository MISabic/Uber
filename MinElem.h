#ifndef MIN_ELEM_H
#define MIN_ELEM_H

#include<bits/stdc++.h>

using namespace std;

class MinElem {

private:
    string name;
    double key_val;

public:
    MinElem( );
    MinElem( string, double );
    double GetKeyValue( );
    string GetName( );
    bool operator <= ( MinElem&  b ) {
        return ( this->key_val >= b.GetKeyValue( ) );
    }
    bool operator < ( MinElem&  b ) {
        return ( this->key_val > b.GetKeyValue( ) );
    }
};

#endif // MIN_ELEM_H

