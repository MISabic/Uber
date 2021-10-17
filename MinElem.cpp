#ifndef MIN_ELEM_CPP
#define MIN_ELEM_CPP

#include "MinElem.h"

MinElem::MinElem( ) {

}

MinElem::MinElem( string name, double key_val ) {
    this->name = name;
    this->key_val = key_val;

}

string  MinElem::GetName( ) {
    return this->name;
}

double MinElem::GetKeyValue( ) {
    return this->key_val;
}

#endif // MIN_ELEM_CPP

