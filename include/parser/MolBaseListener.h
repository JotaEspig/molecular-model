
// Generated from Mol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MolListener.h"


/**
 * This class provides an empty implementation of MolListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MolBaseListener : public MolListener {
public:

  virtual void enterMolecula(MolParser::MoleculaContext * /*ctx*/) override { }
  virtual void exitMolecula(MolParser::MoleculaContext * /*ctx*/) override { }

  virtual void enterCadeia(MolParser::CadeiaContext * /*ctx*/) override { }
  virtual void exitCadeia(MolParser::CadeiaContext * /*ctx*/) override { }

  virtual void enterRamificacao(MolParser::RamificacaoContext * /*ctx*/) override { }
  virtual void exitRamificacao(MolParser::RamificacaoContext * /*ctx*/) override { }

  virtual void enterInsaturacao(MolParser::InsaturacaoContext * /*ctx*/) override { }
  virtual void exitInsaturacao(MolParser::InsaturacaoContext * /*ctx*/) override { }

  virtual void enterGrupo_funcional(MolParser::Grupo_funcionalContext * /*ctx*/) override { }
  virtual void exitGrupo_funcional(MolParser::Grupo_funcionalContext * /*ctx*/) override { }

  virtual void enterNumero(MolParser::NumeroContext * /*ctx*/) override { }
  virtual void exitNumero(MolParser::NumeroContext * /*ctx*/) override { }

  virtual void enterPos(MolParser::PosContext * /*ctx*/) override { }
  virtual void exitPos(MolParser::PosContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

