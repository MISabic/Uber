#ifndef MAX_ELEMAG_CPP
#define MAX_ELEMAG_CPP

#include "MaxElemAg.h"

MaxElemAg::MaxElemAg( ) {

}

MaxElemAg::MaxElemAg( string name, int key_val ) {
    this->name = name;
    this->key_val = key_val;
}

string  MaxElemAg::GetName( ) {
    return this->name;
}

int MaxElemAg::GetKeyValue( ) {
    return this->key_val;
}

#endif // MAX_ELEMAG_CPP

