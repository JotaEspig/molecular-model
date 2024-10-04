
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned int uint;

class Atom {
public:
	string name;

        Atom();
	Atom(string name);
	static Atom carbon();
	static Atom hidroxila();
};


class Bond {
public:
        vector<int> atoms;
        vector<int> insaturations;
	Bond() {}

        Bond & add(int a, int i);
        string show();
};
enum CadeiaTipo {
        Aberta,
        Ciclica,
        Aromatica
};
class Cadeia {
    int n;
    int pos;
    CadeiaTipo tipo;
    
public:
    Cadeia();
    Cadeia(int n_carbonos, CadeiaTipo tipo, int pos=1);
    int inicio();
    int tamanho();
    string tipo_de_cadeia();

};


class Insaturacao {
    int pos;
    int tipo;

public:
    Insaturacao();
    Insaturacao(int pos, int tipo);
    string name();
    int posicao();
    static Insaturacao dupla(int pos);
    static Insaturacao tripla(int pos);
};

class Molecule {
public:
	string name;

        Cadeia cadeia_principal;
        Atom grupo_funcional;
        vector<Cadeia> substituentes;
        vector<Insaturacao> insaturacoes;

	Molecule(string name);
	int prefixo(string n);
        void set_cadeia_principal(string prefix, CadeiaTipo tipo);
        void add_substituente(int pos, string prefix);
        void add_insaturacao(int pos, string tipo);
        void set_grupo_funcional(string grupo);


	void print();
};

