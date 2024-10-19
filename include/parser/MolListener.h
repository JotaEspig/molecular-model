
// Generated from Mol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MolParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MolParser.
 */
class  MolListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMolecula(MolParser::MoleculaContext *ctx) = 0;
  virtual void exitMolecula(MolParser::MoleculaContext *ctx) = 0;

  virtual void enterCadeia(MolParser::CadeiaContext *ctx) = 0;
  virtual void exitCadeia(MolParser::CadeiaContext *ctx) = 0;

  virtual void enterRamificacao(MolParser::RamificacaoContext *ctx) = 0;
  virtual void exitRamificacao(MolParser::RamificacaoContext *ctx) = 0;

  virtual void enterInsaturacao(MolParser::InsaturacaoContext *ctx) = 0;
  virtual void exitInsaturacao(MolParser::InsaturacaoContext *ctx) = 0;

  virtual void enterGrupo_funcional(MolParser::Grupo_funcionalContext *ctx) = 0;
  virtual void exitGrupo_funcional(MolParser::Grupo_funcionalContext *ctx) = 0;

  virtual void enterNumero(MolParser::NumeroContext *ctx) = 0;
  virtual void exitNumero(MolParser::NumeroContext *ctx) = 0;

  virtual void enterPos(MolParser::PosContext *ctx) = 0;
  virtual void exitPos(MolParser::PosContext *ctx) = 0;


};

