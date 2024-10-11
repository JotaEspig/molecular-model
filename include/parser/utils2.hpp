#pragma once

#include <vector>

namespace parser {
struct Bond1 {
    int i, j, k;
};

struct Molecule1 {
    std::vector<int> atoms;
    std::vector<Bond1> bonds;
};

}
