#include "src/lib.hpp"

class  MyListener : public MolListener {
public:

    Molecule m;
    bool is_ramificacao = false;
    MyListener(string name): m{name} {}
    virtual void enterMolecula(MolParser::MoleculaContext * ctx) override {}
    virtual void exitMolecula(MolParser::MoleculaContext * ctx) override {}

    virtual void enterCadeia(MolParser::CadeiaContext * ctx) override { 

        CadeiaTipo tipo = Aberta;
        if (ctx->CICLO())
            tipo = Ciclica;
        if (!is_ramificacao)
            m.set_cadeia_principal(ctx->PREFIXO()->getText(), tipo);
    }
    virtual void exitCadeia(MolParser::CadeiaContext * ctx) override { }

    virtual void enterRamificacao(MolParser::RamificacaoContext * ctx) override {
        is_ramificacao = true;
        string prefix = ctx->cadeia()->PREFIXO()->getText();

        for ( auto pos_token : ctx->pos()->INT()) {
            int pos = stoi(pos_token->getText());
            cout << pos << "\n";
            m.add_substituente(pos, prefix);
        }
    }
    virtual void exitRamificacao(MolParser::RamificacaoContext * ctx) override { 
        is_ramificacao = false;
    }

    virtual void enterInsaturacao(MolParser::InsaturacaoContext * ctx) override { 
        string licacao = ctx->LIGACAO()->getText();
        if (ctx->pos()) {
            for (auto localizador : ctx->pos()->INT()) {
                int pos = stoi(localizador->getText());
                m.add_insaturacao(pos, licacao);
            }
        }
    }
    virtual void exitInsaturacao(MolParser::InsaturacaoContext * ctx) override { }

    virtual void enterGrupo_funcional(MolParser::Grupo_funcionalContext * ctx) override { }
    virtual void exitGrupo_funcional(MolParser::Grupo_funcionalContext * ctx) override { }

    virtual void enterNumero(MolParser::NumeroContext * ctx) override { }
    virtual void exitNumero(MolParser::NumeroContext * ctx) override { }

    virtual void enterPos(MolParser::PosContext * ctx) override { }
    virtual void exitPos(MolParser::PosContext * ctx) override { }


    virtual void enterEveryRule(antlr4::ParserRuleContext * ctx) override { }
    virtual void exitEveryRule(antlr4::ParserRuleContext * ctx) override { }
    virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

Molecule parse(string iupac_molecule) {
    ANTLRInputStream input(iupac_molecule);
    MolLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MolParser parser(&tokens);

    tree::ParseTree *tree = parser.molecula();

    MyListener listener(iupac_molecule);
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    return listener.m;
}
