#ifndef MAX_ELEMAG_H
#define MAX_ELEMAG_H

#include<bits/stdc++.h>

using namespace std;

class MaxElemAg {

private:
    string name;
    int key_val;

public:
    MaxElemAg( );
    MaxElemAg( string, int );
    int GetKeyValue( );
    string GetName( );
    bool operator <= ( MaxElemAg&  b ) {
        return ( this->key_val <= b.GetKeyValue( ) );
    }
    bool operator < ( MaxElemAg&  b ) {
        return ( this->key_val < b.GetKeyValue( ) );
    }
};

#endif // MAX_ELEMAG_H


