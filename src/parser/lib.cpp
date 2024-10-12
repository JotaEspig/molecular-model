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
        string prefix = ctx->cadeia()->PREFIXO()->getText();

        for (auto pos_token : ctx->pos()->INT()) {
            int pos = stoi(pos_token->getText());
            m.add_substituente(pos, prefix);
        }
    }
    virtual void exitRamificacao(MolParser::RamificacaoContext *ctx) override {
        is_ramificacao = false;
    }

    virtual void enterInsaturacao(MolParser::InsaturacaoContext *ctx) override {
        string licacao = ctx->LIGACAO()->getText();
        if (ctx->pos()) {
            for (auto localizador : ctx->pos()->INT()) {
                int pos = stoi(localizador->getText());
                m.add_insaturacao(pos, licacao);
            }
        }
    }
    virtual void exitInsaturacao(MolParser::InsaturacaoContext *ctx) override {
    }

    virtual void enterGrupo_funcional(MolParser::Grupo_funcionalContext *ctx
    ) override {
    }
    virtual void exitGrupo_funcional(MolParser::Grupo_funcionalContext *ctx
    ) override {
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

Molecule parse(string iupac_molecule) {
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

    // add missing hydrogens to each carbon
    vector<int> temp_carbons(m2.atoms.size(), 4);
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
