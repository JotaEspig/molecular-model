
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
      "localizador", "nome_especial", "numero", "pos"
    },
    std::vector<std::string>{
      "", "'il'", "'-'", "'fenil'", "'di'", "'tri'", "'tetra'", "','", "'ciclo'", 
      "'N'", "", "", "", "", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "CICLO", "N", "PREFIXO", "LIGACAO", 
      "GRUPO_FUNCIONAL", "INT", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,80,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,1,0,5,0,20,8,0,10,0,12,0,23,9,0,1,0,1,0,1,0,1,0,1,0,1,1,3,
  	1,31,8,1,1,1,1,1,1,2,3,2,36,8,2,1,2,1,2,1,2,1,2,3,2,42,8,2,1,2,3,2,45,
  	8,2,1,3,3,3,48,8,3,1,3,1,3,1,4,3,4,53,8,4,1,4,1,4,1,5,3,5,58,8,5,1,5,
  	1,5,1,5,3,5,63,8,5,1,6,1,6,1,7,1,7,1,8,1,8,5,8,71,8,8,10,8,12,8,74,9,
  	8,1,8,1,8,3,8,78,8,8,1,8,0,0,9,0,2,4,6,8,10,12,14,16,0,1,1,0,4,6,81,0,
  	21,1,0,0,0,2,30,1,0,0,0,4,35,1,0,0,0,6,47,1,0,0,0,8,52,1,0,0,0,10,57,
  	1,0,0,0,12,64,1,0,0,0,14,66,1,0,0,0,16,77,1,0,0,0,18,20,3,4,2,0,19,18,
  	1,0,0,0,20,23,1,0,0,0,21,19,1,0,0,0,21,22,1,0,0,0,22,24,1,0,0,0,23,21,
  	1,0,0,0,24,25,3,2,1,0,25,26,3,6,3,0,26,27,3,8,4,0,27,28,5,0,0,1,28,1,
  	1,0,0,0,29,31,5,8,0,0,30,29,1,0,0,0,30,31,1,0,0,0,31,32,1,0,0,0,32,33,
  	5,10,0,0,33,3,1,0,0,0,34,36,3,10,5,0,35,34,1,0,0,0,35,36,1,0,0,0,36,41,
  	1,0,0,0,37,38,3,2,1,0,38,39,5,1,0,0,39,42,1,0,0,0,40,42,3,12,6,0,41,37,
  	1,0,0,0,41,40,1,0,0,0,42,44,1,0,0,0,43,45,5,2,0,0,44,43,1,0,0,0,44,45,
  	1,0,0,0,45,5,1,0,0,0,46,48,3,10,5,0,47,46,1,0,0,0,47,48,1,0,0,0,48,49,
  	1,0,0,0,49,50,5,11,0,0,50,7,1,0,0,0,51,53,3,10,5,0,52,51,1,0,0,0,52,53,
  	1,0,0,0,53,54,1,0,0,0,54,55,5,12,0,0,55,9,1,0,0,0,56,58,5,2,0,0,57,56,
  	1,0,0,0,57,58,1,0,0,0,58,59,1,0,0,0,59,60,3,16,8,0,60,62,5,2,0,0,61,63,
  	3,14,7,0,62,61,1,0,0,0,62,63,1,0,0,0,63,11,1,0,0,0,64,65,5,3,0,0,65,13,
  	1,0,0,0,66,67,7,0,0,0,67,15,1,0,0,0,68,69,5,13,0,0,69,71,5,7,0,0,70,68,
  	1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,72,73,1,0,0,0,73,75,1,0,0,0,74,72,
  	1,0,0,0,75,78,5,13,0,0,76,78,5,9,0,0,77,72,1,0,0,0,77,76,1,0,0,0,78,17,
  	1,0,0,0,11,21,30,35,41,44,47,52,57,62,72,77
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
    setState(21);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(18);
        ramificacao(); 
      }
      setState(23);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(24);
    cadeia();
    setState(25);
    insaturacao();
    setState(26);
    grupo_funcional();
    setState(27);
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
    setState(30);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MolParser::CICLO) {
      setState(29);
      match(MolParser::CICLO);
    }
    setState(32);
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

MolParser::Nome_especialContext* MolParser::RamificacaoContext::nome_especial() {
  return getRuleContext<MolParser::Nome_especialContext>(0);
}

MolParser::LocalizadorContext* MolParser::RamificacaoContext::localizador() {
  return getRuleContext<MolParser::LocalizadorContext>(0);
}

MolParser::CadeiaContext* MolParser::RamificacaoContext::cadeia() {
  return getRuleContext<MolParser::CadeiaContext>(0);
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
    setState(35);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8708) != 0)) {
      setState(34);
      localizador();
    }
    setState(41);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MolParser::CICLO:
      case MolParser::PREFIXO: {
        setState(37);
        cadeia();
        setState(38);
        match(MolParser::T__0);
        break;
      }

      case MolParser::T__2: {
        setState(40);
        nome_especial();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(44);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(43);
      match(MolParser::T__1);
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

MolParser::LocalizadorContext* MolParser::InsaturacaoContext::localizador() {
  return getRuleContext<MolParser::LocalizadorContext>(0);
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
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8708) != 0)) {
      setState(46);
      localizador();
    }

    setState(49);
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

MolParser::LocalizadorContext* MolParser::Grupo_funcionalContext::localizador() {
  return getRuleContext<MolParser::LocalizadorContext>(0);
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
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8708) != 0)) {
      setState(51);
      localizador();
    }
    setState(54);
    match(MolParser::GRUPO_FUNCIONAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalizadorContext ------------------------------------------------------------------

MolParser::LocalizadorContext::LocalizadorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MolParser::PosContext* MolParser::LocalizadorContext::pos() {
  return getRuleContext<MolParser::PosContext>(0);
}

MolParser::NumeroContext* MolParser::LocalizadorContext::numero() {
  return getRuleContext<MolParser::NumeroContext>(0);
}


size_t MolParser::LocalizadorContext::getRuleIndex() const {
  return MolParser::RuleLocalizador;
}

void MolParser::LocalizadorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalizador(this);
}

void MolParser::LocalizadorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalizador(this);
}

MolParser::LocalizadorContext* MolParser::localizador() {
  LocalizadorContext *_localctx = _tracker.createInstance<LocalizadorContext>(_ctx, getState());
  enterRule(_localctx, 10, MolParser::RuleLocalizador);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MolParser::T__1) {
      setState(56);
      match(MolParser::T__1);
    }
    setState(59);
    pos();
    setState(60);
    match(MolParser::T__1);
    setState(62);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 112) != 0)) {
      setState(61);
      numero();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Nome_especialContext ------------------------------------------------------------------

MolParser::Nome_especialContext::Nome_especialContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MolParser::Nome_especialContext::getRuleIndex() const {
  return MolParser::RuleNome_especial;
}

void MolParser::Nome_especialContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNome_especial(this);
}

void MolParser::Nome_especialContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNome_especial(this);
}

MolParser::Nome_especialContext* MolParser::nome_especial() {
  Nome_especialContext *_localctx = _tracker.createInstance<Nome_especialContext>(_ctx, getState());
  enterRule(_localctx, 12, MolParser::RuleNome_especial);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(MolParser::T__2);
   
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
  enterRule(_localctx, 14, MolParser::RuleNumero);
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
    setState(66);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 112) != 0))) {
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

tree::TerminalNode* MolParser::PosContext::N() {
  return getToken(MolParser::N, 0);
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
  enterRule(_localctx, 16, MolParser::RulePos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MolParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(72);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(68);
            match(MolParser::INT);
            setState(69);
            match(MolParser::T__6); 
          }
          setState(74);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        }
        setState(75);
        match(MolParser::INT);
        break;
      }

      case MolParser::N: {
        enterOuterAlt(_localctx, 2);
        setState(76);
        match(MolParser::N);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
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
