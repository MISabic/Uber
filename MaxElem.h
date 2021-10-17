#ifndef MAX_ELEM_H
#define MAX_ELEM_H

#include<bits/stdc++.h>

using namespace std;

class MaxElem {

private:
    string name;
    double key_val;

public:
    MaxElem( );
    MaxElem( string, double );
    double GetKeyValue( );
    string GetName( );
    bool operator <= ( MaxElem&  b ) {
        return ( this->key_val <= b.GetKeyValue( ) );
    }
    bool operator < ( MaxElem&  b ) {
        return ( this->key_val < b.GetKeyValue( ) );
    }
};

#endif // MAX_ELEM_H

