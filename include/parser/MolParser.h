
// Generated from Mol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  MolParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, CICLO = 7, 
    PREFIXO = 8, LIGACAO = 9, GRUPO_FUNCIONAL = 10, INT = 11, WHITESPACE = 12
  };

  enum {
    RuleMolecula = 0, RuleCadeia = 1, RuleRamificacao = 2, RuleInsaturacao = 3, 
    RuleGrupo_funcional = 4, RuleNumero = 5, RulePos = 6
  };

  explicit MolParser(antlr4::TokenStream *input);

  MolParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MolParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MoleculaContext;
  class CadeiaContext;
  class RamificacaoContext;
  class InsaturacaoContext;
  class Grupo_funcionalContext;
  class NumeroContext;
  class PosContext; 

  class  MoleculaContext : public antlr4::ParserRuleContext {
  public:
    MoleculaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CadeiaContext *cadeia();
    InsaturacaoContext *insaturacao();
    Grupo_funcionalContext *grupo_funcional();
    antlr4::tree::TerminalNode *EOF();
    std::vector<RamificacaoContext *> ramificacao();
    RamificacaoContext* ramificacao(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MoleculaContext* molecula();

  class  CadeiaContext : public antlr4::ParserRuleContext {
  public:
    CadeiaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PREFIXO();
    antlr4::tree::TerminalNode *CICLO();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CadeiaContext* cadeia();

  class  RamificacaoContext : public antlr4::ParserRuleContext {
  public:
    RamificacaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CadeiaContext *cadeia();
    PosContext *pos();
    NumeroContext *numero();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RamificacaoContext* ramificacao();

  class  InsaturacaoContext : public antlr4::ParserRuleContext {
  public:
    InsaturacaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIGACAO();
    PosContext *pos();
    NumeroContext *numero();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InsaturacaoContext* insaturacao();

  class  Grupo_funcionalContext : public antlr4::ParserRuleContext {
  public:
    Grupo_funcionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GRUPO_FUNCIONAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Grupo_funcionalContext* grupo_funcional();

  class  NumeroContext : public antlr4::ParserRuleContext {
  public:
    NumeroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumeroContext* numero();

  class  PosContext : public antlr4::ParserRuleContext {
  public:
    PosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PosContext* pos();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

