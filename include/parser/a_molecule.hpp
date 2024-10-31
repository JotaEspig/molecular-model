#pragma once

#include "parser/utils2.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

typedef unsigned int uint;

namespace parser {

class Atom {
public:
    std::string name;
    int pos;

    Atom();
    Atom(std::string name, int pos);
};

class Bond {
public:
    std::vector<int> atoms;
    std::vector<int> insaturations;
    Bond() {
    }

    Bond &add(int a, int i);
    std::string show();
};
enum class CadeiaTipo { Aberta, Ciclica, Aromatica, Fenila };
class Cadeia {
public:
    int n;
    int pos;
    CadeiaTipo tipo;

    Cadeia();
    Cadeia(int n_carbonos, CadeiaTipo tipo, int pos = 0);
    int inicio();
    int tamanho();
    std::string tipo_de_cadeia();
    std::vector<int> get_atoms();
    std::vector<Bond1> get_bonds(int start);
};

class Insaturacao {
public:
    int pos;
    int tipo;

    Insaturacao();
    Insaturacao(int pos, int tipo);
    std::string name();
    int posicao();
    static Insaturacao dupla(int pos);
    static Insaturacao tripla(int pos);
};

class Molecule {
public:
    std::string name;

    Cadeia cadeia_principal;
    std::vector<Atom> grupo_funcional;
    std::vector<Cadeia> substituentes;
    std::vector<Cadeia> grupo_funcional_cadeia;
    std::vector<Insaturacao> insaturacoes;

    Molecule(std::string name);
    int prefixo(std::string n);
    void set_cadeia_principal(std::string prefix, CadeiaTipo tipo);
    void add_substituente(int pos, std::string prefix, bool is_N);
    void add_substituente_especial(int pos, std::string nome);
    void add_insaturacao(int pos, std::string tipo);
    void add_grupo_funcional(int pos, std::string grupo);
    std::vector<std::pair<std::string, int>> get_grupo_funcional();

    void print();
};
}