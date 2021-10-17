#ifndef MAX_ELEM_CPP
#define MAX_ELEM_CPP

#include "MaxElem.h"

MaxElem::MaxElem( ) {

}

MaxElem::MaxElem( string name, double key_val ) {
    this->name = name;
    this->key_val = key_val;
}

string  MaxElem::GetName( ) {
    return this->name;
}

double MaxElem::GetKeyValue( ) {
    return this->key_val;
}

#endif // MAX_ELEM_CPP

