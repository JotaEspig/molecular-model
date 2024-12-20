#include "parser/MolLexer.h"
#include "parser/MolListener.h"
#include "parser/MolParser.h"

#include "parser/lib.hpp"

using namespace std;

namespace parser {

class MyListener : public MolListener {
public:
    parser::Molecule m;
    bool is_ramificacao = false;
    MyListener(string name) :
      m{name} {
    }
    virtual void enterMolecula(MolParser::MoleculaContext *ctx) override {
    }
    virtual void exitMolecula(MolParser::MoleculaContext *ctx) override {
    }

    virtual void enterCadeia(MolParser::CadeiaContext *ctx) override {

        parser::CadeiaTipo tipo = CadeiaTipo::Aberta;
        if (ctx->CICLO())
            tipo = CadeiaTipo::Ciclica;
        if (!is_ramificacao)
            m.set_cadeia_principal(ctx->PREFIXO()->getText(), tipo);
    }
    virtual void exitCadeia(MolParser::CadeiaContext *ctx) override {
    }

    virtual void enterRamificacao(MolParser::RamificacaoContext *ctx) override {
        is_ramificacao = true;

        bool is_N = false;
        if (ctx->localizador()->pos()->N()) {
            is_N = true;
            string prefix = ctx->cadeia()->PREFIXO()->getText();
            m.add_substituente(1, prefix, is_N);
        }
        is_N = false;

        for (auto pos_token : ctx->localizador()->pos()->INT()) {

            int pos = stoi(pos_token->getText());
            if (ctx->nome_especial()) {

                string special_name = ctx->nome_especial()->getText();
                m.add_substituente_especial(pos, special_name);
            }
            else {

                string prefix = ctx->cadeia()->PREFIXO()->getText();
                m.add_substituente(pos, prefix, is_N);
            }
        }
    }
    virtual void exitRamificacao(MolParser::RamificacaoContext *ctx) override {
        is_ramificacao = false;
    }

    virtual void enterInsaturacao(MolParser::InsaturacaoContext *ctx) override {
        string licacao = ctx->LIGACAO()->getText();
        if (ctx->localizador()) {
            for (auto localizador : ctx->localizador()->pos()->INT()) {
                int pos = stoi(localizador->getText());
                m.add_insaturacao(pos, licacao);
            }
        }
    }
    virtual void exitInsaturacao(MolParser::InsaturacaoContext *ctx) override {
    }

    virtual void enterGrupo_funcional(MolParser::Grupo_funcionalContext *ctx
    ) override {
        string grupo_funcional = ctx->GRUPO_FUNCIONAL()->getText();
        if (ctx->localizador()) {
            for (auto localizador : ctx->localizador()->pos()->INT()) {
                int pos = stoi(localizador->getText());
                m.add_grupo_funcional(pos, grupo_funcional);
            }
        }
        else
            m.add_grupo_funcional(1, grupo_funcional);
    }
    virtual void exitGrupo_funcional(MolParser::Grupo_funcionalContext *ctx
    ) override {
    }
    virtual void
    enterLocalizador(MolParser::LocalizadorContext * /*ctx*/) override {
    }
    virtual void
    exitLocalizador(MolParser::LocalizadorContext * /*ctx*/) override {
    }

    virtual void
    enterNome_especial(MolParser::Nome_especialContext * /*ctx*/) override {
    }
    virtual void
    exitNome_especial(MolParser::Nome_especialContext * /*ctx*/) override {
    }

    virtual void enterNumero(MolParser::NumeroContext *ctx) override {
    }
    virtual void exitNumero(MolParser::NumeroContext *ctx) override {
    }

    virtual void enterPos(MolParser::PosContext *ctx) override {
    }
    virtual void exitPos(MolParser::PosContext *ctx) override {
    }

    virtual void enterEveryRule(antlr4::ParserRuleContext *ctx) override {
    }
    virtual void exitEveryRule(antlr4::ParserRuleContext *ctx) override {
    }
    virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override {
    }
    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override {
    }
};

string replace_usual_names(string iupac_molecule) {
    unordered_map<string, string> usual_names
        = {{"benzeno", "ciclohex-1,3,5-eno"}};

    for (auto [key, value] : usual_names) {
        const int start = iupac_molecule.find(key);
        if (start == string::npos)
            continue;
        iupac_molecule.replace(start, key.size(), value);
    }

    return iupac_molecule;
}

Molecule parse(string iupac_molecule) {

    iupac_molecule = replace_usual_names(iupac_molecule);

    antlr4::ANTLRInputStream input(iupac_molecule);
    MolLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    MolParser parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.molecula();

    MyListener listener(iupac_molecule);
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    return listener.m;
}

Molecule1 Molecule1_from_Molecule(Molecule m) {

    Molecule1 m2;

    vector<Cadeia> cadeias = m.substituentes;
    cadeias.insert(cadeias.begin(), m.cadeia_principal);

    vector<Bond1> cadeia_principal = m.cadeia_principal.get_bonds(0);

    int bond_offset = 0;
    for (auto cadeia : cadeias) {
        vector<int> atoms = cadeia.get_atoms();
        for (auto atom : atoms)
            m2.atoms.push_back(atom);

        vector<Bond1> bonds = cadeia.get_bonds(bond_offset);

        bond_offset += cadeia.n;

        m2.bonds.insert(m2.bonds.end(), bonds.begin(), bonds.end());
    }

    for (auto unsaturation : m.insaturacoes) {
        int pos = unsaturation.pos - 1;
        int type = unsaturation.tipo;

        m2.bonds[pos].k = type;
    }

    vector<pair<string, int>> grupos = m.get_grupo_funcional();
    for (auto grupo : grupos) {
        string name = grupo.first;
        int pos = grupo.second;

        const int hydrogen = 1;
        const int nitrogen = 7;
        const int oxygen = 8;
        const int carbon = 6;
        int atomic_number;
        if (name == "amina")
            atomic_number = nitrogen;
        else if (name == "ona")
            atomic_number = oxygen;
        else if (name == "ol")
            atomic_number = oxygen;
        else if (name == "al")
            atomic_number = carbon;
        else if (name == "o")
            continue;

        if (name == "ol")
            m2.atoms.push_back(hydrogen);
        if (name == "al") {
            m2.atoms.push_back(hydrogen);
            m2.atoms.push_back(oxygen);
        }

        m2.atoms.push_back(atomic_number);

        int bond_type = 1;
        if (name == "ona")
            bond_type = 2;
        Bond1 bond = {pos - 1, m2.atoms.size() - 1, bond_type};
        m2.bonds.push_back(bond);
        if (name == "ol") {
            Bond1 bond2 = {m2.atoms.size() - 1, m2.atoms.size() - 2, bond_type};
            m2.bonds.push_back(bond2);
        }

        if (name == "al") {

            Bond1 bond2 = {m2.atoms.size() - 1, m2.atoms.size() - 2, 2};
            m2.bonds.push_back(bond2);
            Bond1 bond3 = {m2.atoms.size() - 1, m2.atoms.size() - 3, 1};
            m2.bonds.push_back(bond3);
        }
    }

    auto grupo_cadeias = m.grupo_funcional_cadeia;
    int grupo_pos = m2.atoms.size() - 1;
    for (auto cadeia : grupo_cadeias) {

        vector<int> atoms = cadeia.get_atoms();
        for (auto atom : atoms)
            m2.atoms.push_back(atom);

        vector<Bond1> bonds = cadeia.get_bonds(grupo_pos + 1);
        bonds[0].i = grupo_pos;

        m2.bonds.insert(m2.bonds.end(), bonds.begin(), bonds.end());
    }

    // add missing hydrogens to each carbon
    vector<int> temp_carbons(m2.atoms.size(), 4);
    for (int i = 0; i < m2.atoms.size(); ++i) {
        const int atomic_number = m2.atoms[i];
        const int HYDROGEN = 1;
        const int CARBON = 6;
        const int NITROGEN = 7;
        const int OXYGEN = 8;
        switch (atomic_number) {
        case HYDROGEN:
            temp_carbons[i] = 0;
            break;
        case CARBON:
            temp_carbons[i] = 4;
            break;
        case NITROGEN:
            temp_carbons[i] = 3;
            break;
        case OXYGEN:
            temp_carbons[i] = 2;
            break;
        }
    }

    for (int i = 0; i < m2.bonds.size(); i++) {

        auto bond = m2.bonds[i];
        temp_carbons[bond.i] -= bond.k;
        temp_carbons[bond.j] -= bond.k;
    }

    for (int i = 0; i < temp_carbons.size(); ++i) {
        // add c hydrogens to m2.atoms
        // add bonds to each new hydrogen
        for (int j = 0; j < temp_carbons[i]; ++j) {
            m2.atoms.push_back(1);
            m2.bonds.push_back(
                Bond1{i, static_cast<int>(m2.atoms.size() - 1), 1}
            );
        }
    }

    return m2;
}

}
