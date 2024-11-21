
// Generated from Mol.g4 by ANTLR 4.13.2


#include "MolLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MolLexerStaticData final {
  MolLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MolLexerStaticData(const MolLexerStaticData&) = delete;
  MolLexerStaticData(MolLexerStaticData&&) = delete;
  MolLexerStaticData& operator=(const MolLexerStaticData&) = delete;
  MolLexerStaticData& operator=(MolLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mollexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MolLexerStaticData> mollexerLexerStaticData = nullptr;

void mollexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mollexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(mollexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MolLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "CICLO", "N", 
      "PREFIXO", "LIGACAO", "GRUPO_FUNCIONAL", "INT", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,14,129,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,
  	1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,96,8,9,1,10,1,10,
  	1,10,1,10,1,10,1,10,3,10,104,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,3,11,119,8,11,1,12,4,12,122,8,12,11,12,
  	12,12,123,1,13,1,13,1,13,1,13,0,0,14,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,9,19,10,21,11,23,12,25,13,27,14,1,0,1,1,0,48,57,144,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,1,29,1,0,0,0,3,32,1,0,0,0,5,34,1,0,0,0,7,40,
  	1,0,0,0,9,43,1,0,0,0,11,47,1,0,0,0,13,53,1,0,0,0,15,55,1,0,0,0,17,61,
  	1,0,0,0,19,95,1,0,0,0,21,103,1,0,0,0,23,118,1,0,0,0,25,121,1,0,0,0,27,
  	125,1,0,0,0,29,30,5,105,0,0,30,31,5,108,0,0,31,2,1,0,0,0,32,33,5,45,0,
  	0,33,4,1,0,0,0,34,35,5,102,0,0,35,36,5,101,0,0,36,37,5,110,0,0,37,38,
  	5,105,0,0,38,39,5,108,0,0,39,6,1,0,0,0,40,41,5,100,0,0,41,42,5,105,0,
  	0,42,8,1,0,0,0,43,44,5,116,0,0,44,45,5,114,0,0,45,46,5,105,0,0,46,10,
  	1,0,0,0,47,48,5,116,0,0,48,49,5,101,0,0,49,50,5,116,0,0,50,51,5,114,0,
  	0,51,52,5,97,0,0,52,12,1,0,0,0,53,54,5,44,0,0,54,14,1,0,0,0,55,56,5,99,
  	0,0,56,57,5,105,0,0,57,58,5,99,0,0,58,59,5,108,0,0,59,60,5,111,0,0,60,
  	16,1,0,0,0,61,62,5,78,0,0,62,18,1,0,0,0,63,64,5,109,0,0,64,65,5,101,0,
  	0,65,96,5,116,0,0,66,67,5,101,0,0,67,96,5,116,0,0,68,69,5,112,0,0,69,
  	70,5,114,0,0,70,71,5,111,0,0,71,96,5,112,0,0,72,73,5,98,0,0,73,74,5,117,
  	0,0,74,96,5,116,0,0,75,76,5,112,0,0,76,77,5,101,0,0,77,78,5,110,0,0,78,
  	96,5,116,0,0,79,80,5,104,0,0,80,81,5,101,0,0,81,96,5,120,0,0,82,83,5,
  	104,0,0,83,84,5,101,0,0,84,85,5,112,0,0,85,96,5,116,0,0,86,87,5,111,0,
  	0,87,88,5,99,0,0,88,96,5,116,0,0,89,90,5,110,0,0,90,91,5,111,0,0,91,96,
  	5,110,0,0,92,93,5,100,0,0,93,94,5,101,0,0,94,96,5,99,0,0,95,63,1,0,0,
  	0,95,66,1,0,0,0,95,68,1,0,0,0,95,72,1,0,0,0,95,75,1,0,0,0,95,79,1,0,0,
  	0,95,82,1,0,0,0,95,86,1,0,0,0,95,89,1,0,0,0,95,92,1,0,0,0,96,20,1,0,0,
  	0,97,98,5,97,0,0,98,104,5,110,0,0,99,100,5,101,0,0,100,104,5,110,0,0,
  	101,102,5,105,0,0,102,104,5,110,0,0,103,97,1,0,0,0,103,99,1,0,0,0,103,
  	101,1,0,0,0,104,22,1,0,0,0,105,119,5,111,0,0,106,107,5,111,0,0,107,108,
  	5,110,0,0,108,119,5,97,0,0,109,110,5,97,0,0,110,111,5,109,0,0,111,112,
  	5,105,0,0,112,113,5,110,0,0,113,119,5,97,0,0,114,115,5,111,0,0,115,119,
  	5,108,0,0,116,117,5,97,0,0,117,119,5,108,0,0,118,105,1,0,0,0,118,106,
  	1,0,0,0,118,109,1,0,0,0,118,114,1,0,0,0,118,116,1,0,0,0,119,24,1,0,0,
  	0,120,122,7,0,0,0,121,120,1,0,0,0,122,123,1,0,0,0,123,121,1,0,0,0,123,
  	124,1,0,0,0,124,26,1,0,0,0,125,126,5,32,0,0,126,127,1,0,0,0,127,128,6,
  	13,0,0,128,28,1,0,0,0,5,0,95,103,118,123,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mollexerLexerStaticData = std::move(staticData);
}

}

MolLexer::MolLexer(CharStream *input) : Lexer(input) {
  MolLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mollexerLexerStaticData->atn, mollexerLexerStaticData->decisionToDFA, mollexerLexerStaticData->sharedContextCache);
}

MolLexer::~MolLexer() {
  delete _interpreter;
}

std::string MolLexer::getGrammarFileName() const {
  return "Mol.g4";
}

const std::vector<std::string>& MolLexer::getRuleNames() const {
  return mollexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MolLexer::getChannelNames() const {
  return mollexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MolLexer::getModeNames() const {
  return mollexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MolLexer::getVocabulary() const {
  return mollexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MolLexer::getSerializedATN() const {
  return mollexerLexerStaticData->serializedATN;
}

const atn::ATN& MolLexer::getATN() const {
  return *mollexerLexerStaticData->atn;
}




void MolLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mollexerLexerInitialize();
#else
  ::antlr4::internal::call_once(mollexerLexerOnceFlag, mollexerLexerInitialize);
#endif
}
