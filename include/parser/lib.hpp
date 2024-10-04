
#include <iostream>

#include "antlr4-runtime.h"
#include "src/parser/MolLexer.h"
#include "src/parser/MolParser.h"
#include "src/parser/MolListener.h"
#include "src/molecule.hpp"

using namespace std;
using namespace antlr4;

Molecule parse(string iupac_molecule);
