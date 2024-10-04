
// Generated from Mol.g4 by ANTLR 4.13.2


#include "MolListener.h"

#include "MolParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MolParserStaticData final {
  MolParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MolParserStaticData(const MolParserStaticData&) = delete;
  MolParserStaticData(MolParserStaticData&&) = delete;
  MolParserStaticData& operator=(const MolParserStaticData&) = delete;
  MolParserStaticData& operator=(MolParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag molParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MolParserStaticData> molParserStaticData = nullptr;

void molParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (molParserStaticData != nullptr) {
    return;
  }
#else
  assert(molParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MolParserStaticData>(
    std::vector<std::string>{
      "molecula", "cadeia", "ramificacao", "insaturacao", "grupo_funcional", 
      "numero", "pos"
    },
    std::vector<std::string>{
      "", "'-'", "'il'", "'di'", "'tri'", "'tetra'", "','", "'ciclo'", "", 
      "", "'o'", "", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "CICLO", "PREFIXO", "LIGACAO", "GRUPO_FUNCIONAL", 
      "INT", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,69,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	5,0,16,8,0,10,0,12,0,19,9,0,1,0,1,0,1,0,1,0,1,0,1,1,3,1,27,8,1,1,1,1,
  	1,1,2,3,2,32,8,2,1,2,1,2,1,2,3,2,37,8,2,3,2,39,8,2,1,2,1,2,1,2,3,2,44,
  	8,2,1,3,1,3,1,3,1,3,3,3,50,8,3,3,3,52,8,3,1,3,1,3,1,4,1,4,1,5,1,5,1,6,
  	1,6,5,6,62,8,6,10,6,12,6,65,9,6,1,6,1,6,1,6,0,0,7,0,2,4,6,8,10,12,0,1,
  	1,0,3,5,70,0,17,1,0,0,0,2,26,1,0,0,0,4,38,1,0,0,0,6,51,1,0,0,0,8,55,1,
  	0,0,0,10,57,1,0,0,0,12,63,1,0,0,0,14,16,3,4,2,0,15,14,1,0,0,0,16,19,1,
  	0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,20,1,0,0,0,19,17,1,0,0,0,20,21,3,
  	2,1,0,21,22,3,6,3,0,22,23,3,8,4,0,23,24,5,0,0,1,24,1,1,0,0,0,25,27,5,
  	7,0,0,26,25,1,0,0,0,26,27,1,0,0,0,27,28,1,0,0,0,28,29,5,8,0,0,29,3,1,
  	0,0,0,30,32,5,1,0,0,31,30,1,0,0,0,31,32,1,0,0,0,32,33,1,0,0,0,33,34,3,
  	12,6,0,34,36,5,1,0,0,35,37,3,10,5,0,36,35,1,0,0,0,36,37,1,0,0,0,37,39,
  	1,0,0,0,38,31,1,0,0,0,38,39,1,0,0,0,39,40,1,0,0,0,40,41,3,2,1,0,41,43,
  	5,2,0,0,42,44,5,1,0,0,43,42,1,0,0,0,43,44,1,0,0,0,44,5,1,0,0,0,45,46,
  	5,1,0,0,46,47,3,12,6,0,47,49,5,1,0,0,48,50,3,10,5,0,49,48,1,0,0,0,49,
  	50,1,0,0,0,50,52,1,0,0,0,51,45,1,0,0,0,51,52,1,0,0,0,52,53,1,0,0,0,53,
  	54,5,9,0,0,54,7,1,0,0,0,55,56,5,10,0,0,56,9,1,0,0,0,57,58,7,0,0,0,58,
  	11,1,0,0,0,59,60,5,11,0,0,60,62,5,6,0,0,61,59,1,0,0,0,62,65,1,0,0,0,63,
  	61,1,0,0,0,63,64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,67,5,11,0,0,67,
  	13,1,0,0,0,9,17,26,31,36,38,43,49,51,63
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  molParserStaticData = std::move(staticData);
}

}

MolParser::MolParser(TokenStream *input) : MolParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MolParser::MolParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MolParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *molParserStaticData->atn, molParserStaticData->decisionToDFA, molParserStaticData->sharedContextCache, options);
}

MolParser::~MolParser() {
  delete _interpreter;
}

const atn::ATN& MolParser::getATN() const {
  return *molParserStaticData->atn;
}

std::string MolParser::getGrammarFileName() const {
  return "Mol.g4";
}

const std::vector<std::string>& MolParser::getRuleNames() const {
  return molParserStaticData->ruleNames;
}

const dfa::Vocabulary& MolParser::getVocabulary() const {
  return molParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MolParser::getSerializedATN() const {
  return molParserStaticData->serializedATN;
}


//----------------- MoleculaContext ------------------------------------------------------------------

MolParser::MoleculaContext::MoleculaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MolParser::CadeiaContext* MolParser::MoleculaContext::cadeia() {
  return getRuleContext<MolParser::CadeiaContext>(0);
}

MolParser::InsaturacaoContext* MolParser::MoleculaContext::insaturacao() {
  return getRuleContext<MolParser::InsaturacaoContext>(0);
}

MolParser::Grupo_funcionalContext* MolParser::MoleculaContext::grupo_funcional() {
  return getRuleContext<MolParser::Grupo_funcionalContext>(0);
}

tree::TerminalNode* MolParser::MoleculaContext::EOF() {
  return getToken(MolParser::EOF, 0);
}

std::vector<MolParser::RamificacaoContext *> MolParser::MoleculaContext::ramificacao() {
  return getRuleContexts<MolParser::RamificacaoContext>();
}

MolParser::RamificacaoContext* MolParser::MoleculaContext::ramificacao(size_t i) {
  return getRuleContext<MolParser::RamificacaoContext>(i);
}


size_t MolParser::MoleculaContext::getRuleIndex() const {
  return MolParser::RuleMolecula;
}

void MolParser::MoleculaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMolecula(this);
}

void MolParser::MoleculaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMolecula(this);
}

MolParser::MoleculaContext* MolParser::molecula() {
  MoleculaContext *_localctx = _tracker.createInstance<MoleculaContext>(_ctx, getState());
  enterRule(_localctx, 0, MolParser::RuleMolecula);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(17);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(14);
        ramificacao(); 
      }
      setState(19);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(20);
    cadeia();
    setState(21);
    insaturacao();
    setState(22);
    grupo_funcional();
    setState(23);
    match(MolParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CadeiaContext ------------------------------------------------------------------

MolParser::CadeiaContext::CadeiaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MolParser::CadeiaContext::PREFIXO() {
  return getToken(MolParser::PREFIXO, 0);
}

tree::TerminalNode* MolParser::CadeiaContext::CICLO() {
  return getToken(MolParser::CICLO, 0);
}


size_t MolParser::CadeiaContext::getRuleIndex() const {
  return MolParser::RuleCadeia;
}

void MolParser::CadeiaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCadeia(this);
}

void MolParser::CadeiaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCadeia(this);
}

MolParser::CadeiaContext* MolParser::cadeia() {
  CadeiaContext *_localctx = _tracker.createInstance<CadeiaContext>(_ctx, getState());
  enterRule(_localctx, 2, MolParser::RuleCadeia);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MolParser::CICLO) {
      setState(25);
      match(MolParser::CICLO);
    }
    setState(28);
    match(MolParser::PREFIXO);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RamificacaoContext ------------------------------------------------------------------

MolParser::RamificacaoContext::RamificacaoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MolParser::CadeiaContext* MolParser::RamificacaoContext::cadeia() {
  return getRuleContext<MolParser::CadeiaContext>(0);
}

MolParser::PosContext* MolParser::RamificacaoContext::pos() {
  return getRuleContext<MolParser::PosContext>(0);
}

MolParser::NumeroContext* MolParser::RamificacaoContext::numero() {
  return getRuleContext<MolParser::NumeroContext>(0);
}


size_t MolParser::RamificacaoContext::getRuleIndex() const {
  return MolParser::RuleRamificacao;
}

void MolParser::RamificacaoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRamificacao(this);
}

void MolParser::RamificacaoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRamificacao(this);
}

MolParser::RamificacaoContext* MolParser::ramificacao() {
  RamificacaoContext *_localctx = _tracker.createInstance<RamificacaoContext>(_ctx, getState());
  enterRule(_localctx, 4, MolParser::RuleRamificacao);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MolParser::T__0

    || _la == MolParser::INT) {
      setState(31);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MolParser::T__0) {
        setState(30);
        match(MolParser::T__0);
      }
      setState(33);
      pos();
      setState(34);
      match(MolParser::T__0);
      setState(36);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 56) != 0)) {
        setState(35);
        numero();
      }
    }
    setState(40);
    cadeia();
    setState(41);
    match(MolParser::T__1);
    setState(43);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(42);
      match(MolParser::T__0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsaturacaoContext ------------------------------------------------------------------

MolParser::InsaturacaoContext::InsaturacaoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MolParser::InsaturacaoContext::LIGACAO() {
  return getToken(MolParser::LIGACAO, 0);
}

MolParser::PosContext* MolParser::InsaturacaoContext::pos() {
  return getRuleContext<MolParser::PosContext>(0);
}

MolParser::NumeroContext* MolParser::InsaturacaoContext::numero() {
  return getRuleContext<MolParser::NumeroContext>(0);
}


size_t MolParser::InsaturacaoContext::getRuleIndex() const {
  return MolParser::RuleInsaturacao;
}

void MolParser::InsaturacaoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsaturacao(this);
}

void MolParser::InsaturacaoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsaturacao(this);
}

MolParser::InsaturacaoContext* MolParser::insaturacao() {
  InsaturacaoContext *_localctx = _tracker.createInstance<InsaturacaoContext>(_ctx, getState());
  enterRule(_localctx, 6, MolParser::RuleInsaturacao);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MolParser::T__0) {
      setState(45);
      match(MolParser::T__0);
      setState(46);
      pos();
      setState(47);
      match(MolParser::T__0);
      setState(49);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 56) != 0)) {
        setState(48);
        numero();
      }
    }

    setState(53);
    match(MolParser::LIGACAO);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Grupo_funcionalContext ------------------------------------------------------------------

MolParser::Grupo_funcionalContext::Grupo_funcionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MolParser::Grupo_funcionalContext::GRUPO_FUNCIONAL() {
  return getToken(MolParser::GRUPO_FUNCIONAL, 0);
}


size_t MolParser::Grupo_funcionalContext::getRuleIndex() const {
  return MolParser::RuleGrupo_funcional;
}

void MolParser::Grupo_funcionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGrupo_funcional(this);
}

void MolParser::Grupo_funcionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGrupo_funcional(this);
}

MolParser::Grupo_funcionalContext* MolParser::grupo_funcional() {
  Grupo_funcionalContext *_localctx = _tracker.createInstance<Grupo_funcionalContext>(_ctx, getState());
  enterRule(_localctx, 8, MolParser::RuleGrupo_funcional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(MolParser::GRUPO_FUNCIONAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumeroContext ------------------------------------------------------------------

MolParser::NumeroContext::NumeroContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MolParser::NumeroContext::getRuleIndex() const {
  return MolParser::RuleNumero;
}

void MolParser::NumeroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumero(this);
}

void MolParser::NumeroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumero(this);
}

MolParser::NumeroContext* MolParser::numero() {
  NumeroContext *_localctx = _tracker.createInstance<NumeroContext>(_ctx, getState());
  enterRule(_localctx, 10, MolParser::RuleNumero);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 56) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PosContext ------------------------------------------------------------------

MolParser::PosContext::PosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MolParser::PosContext::INT() {
  return getTokens(MolParser::INT);
}

tree::TerminalNode* MolParser::PosContext::INT(size_t i) {
  return getToken(MolParser::INT, i);
}


size_t MolParser::PosContext::getRuleIndex() const {
  return MolParser::RulePos;
}

void MolParser::PosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPos(this);
}

void MolParser::PosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPos(this);
}

MolParser::PosContext* MolParser::pos() {
  PosContext *_localctx = _tracker.createInstance<PosContext>(_ctx, getState());
  enterRule(_localctx, 12, MolParser::RulePos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(59);
        match(MolParser::INT);
        setState(60);
        match(MolParser::T__5); 
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(66);
    match(MolParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void MolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  molParserInitialize();
#else
  ::antlr4::internal::call_once(molParserOnceFlag, molParserInitialize);
#endif
}
