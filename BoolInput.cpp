#include "BoolInput.h"

#include <iostream>
#include <typeinfo>

BoolInput::BoolInput() {}
BoolInput::BoolInput(const string &name) { registerPin(name); }
BoolInput::~BoolInput() {}
void BoolInput::registerPin(string name) {
    this->name = "/"+thisTypename+"/"+name;
}
