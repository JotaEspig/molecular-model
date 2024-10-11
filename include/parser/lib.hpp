#pragma once

#include "parser/a_molecule.hpp"
#include "parser/utils2.hpp"
#include <antlr4-runtime.h>

namespace parser {

Molecule parse(std::string iupac_molecule);
Molecule1 Molecule1_from_Molecule(Molecule m);

}
