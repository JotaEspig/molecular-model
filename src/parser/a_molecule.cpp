#include "parser/a_molecule.hpp"
#include <unordered_map>

using namespace std;

namespace parser {

Atom::Atom() :
  name{""} {
}
Atom::Atom(string name, int pos) :
  name{name},
  pos{pos} {
}
Cadeia::Cadeia() :
  n{0},
  tipo{CadeiaTipo::Aberta},
  pos{0} {
}
Cadeia::Cadeia(int n, CadeiaTipo tipo, int pos) :
  n{n},
  tipo{tipo},
  pos{pos} {
}

int Cadeia::inicio() {
    return pos;
}
int Cadeia::tamanho() {
    return n;
}

string Cadeia::tipo_de_cadeia() {
    unordered_map<CadeiaTipo, string> tipo_to_string;
    tipo_to_string[CadeiaTipo::Aberta] = "aberta";
    tipo_to_string[CadeiaTipo::Ciclica] = "ciclica";
    tipo_to_string[CadeiaTipo::Aromatica] = "aromatica";

    return tipo_to_string[tipo];
}
vector<int> Cadeia::get_atoms() {
    vector<int> atoms;
    const int Carbon = 6;
    for (int i = 0; i < n; i++) {
        atoms.push_back(Carbon);
    }

    return atoms;
}

vector<Bond1> Cadeia::get_bonds(int start) {
    vector<Bond1> bonds;
    if (pos != 0)
        bonds.push_back({pos - 1, start, 1});

    for (int i = 0; i < n - 1; i++) {

        int pos1 = start + i;
        int pos2 = start + i + 1;
        int bond_type = 1;

        Bond1 bond = {pos1, pos2, bond_type};

        bonds.push_back(bond);
    }

    if (tipo == CadeiaTipo::Ciclica) {
        Bond1 bond = {0, n - 1, 1};
        bonds.push_back(bond);
    }

    return bonds;
}

Insaturacao::Insaturacao() :
  pos{0},
  tipo{0} {
}
Insaturacao::Insaturacao(int pos, int tipo) :
  pos{pos},
  tipo{tipo} {
}

Insaturacao Insaturacao::dupla(int pos) {
    Insaturacao i(pos, 2);
    return i;
}
Insaturacao Insaturacao::tripla(int pos) {
    Insaturacao i(pos, 3);
    return i;
}

string Insaturacao::name() {
    if (tipo == 2)
        return "dupla";
    else if (tipo == 3)
        return "tripla";

    return "indefinida";
}

int Insaturacao::posicao() {
    return pos;
}

Molecule::Molecule(string name) :
  name{name} {
}

int Molecule::prefixo(string n) {
    unordered_map<string, int> prefix;
    prefix["met"] = 1;
    prefix["et"] = 2;
    prefix["prop"] = 3;
    prefix["but"] = 4;
    prefix["pent"] = 5;
    prefix["hex"] = 6;
    prefix["hept"] = 7;
    prefix["oct"] = 8;
    prefix["non"] = 9;
    prefix["dec"] = 10;

    return prefix[n];
}

void Molecule::set_cadeia_principal(string prefix, CadeiaTipo tipo) {
    int n = prefixo(prefix);
    cadeia_principal = Cadeia(n, tipo);
}

void Molecule::add_substituente(int pos, string prefix, bool is_N) {
    int n = prefixo(prefix);

    Cadeia c(n, CadeiaTipo::Aberta, pos);
    if (is_N)
        grupo_funcional_cadeia.push_back(c);
    else
        substituentes.push_back(c);
}

void Molecule::add_insaturacao(int pos, string tipo) {
    Insaturacao i(0, 0);
    if (tipo == "en")
        i = Insaturacao::dupla(pos);
    else if (tipo == "in")
        i = Insaturacao::tripla(pos);

    insaturacoes.push_back(i);
}
void Molecule::add_grupo_funcional(int pos, string grupo) {
    Atom grupo_fun(grupo, pos);

    grupo_funcional.push_back(grupo_fun);
}

vector<pair<string, int>> Molecule::get_grupo_funcional() {
    vector<pair<string, int>> grupos;
    for (auto grupo : grupo_funcional) {
        grupos.push_back(make_pair(grupo.name, grupo.pos));
    }

    return grupos;
}

void Molecule::print() {
    cout << name << "\n";
    cout << "cadeia principal: " << cadeia_principal.tipo_de_cadeia() << " = "
         << cadeia_principal.tamanho() << "\n";

    cout << "substituentes" << "\n";
    for (Cadeia r : substituentes)
        cout << r.inicio() << " = " << r.tamanho() << "\n";

    cout << "insaturacaoes" << "\n";
    for (Insaturacao i : insaturacoes)
        cout << i.posicao() << " = " << i.name() << "\n";
}
}