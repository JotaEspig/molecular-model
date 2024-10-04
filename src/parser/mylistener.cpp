
#include "src/mylistener.hpp"
#include <iostream>
using namespace std;

void MyListener::enterMolecula(MolParser::MoleculaContext * ctx) {
    cout << ctx->PREFIXO->getText << "\n";
    
}
