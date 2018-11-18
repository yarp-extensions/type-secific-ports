#ifndef TYPESPECIFICPORTS_LIBRARY_H
#define TYPESPECIFICPORTS_LIBRARY_H

#include <string>
using namespace std;

const string thisTypename = "bool";

class BoolInput{
public:
    BoolInput();
    BoolInput(const string &name);
    virtual ~BoolInput();
    virtual void registerPin(string name);
private:
    bool value;
    string name;
};

#endif