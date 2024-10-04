
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "CICLO", "PREFIXO", 
      "LIGACAO", "GRUPO_FUNCIONAL", "INT", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,12,104,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,1,1,1,1,1,1,2,
  	1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,
  	7,84,8,7,1,8,1,8,1,8,1,8,1,8,1,8,3,8,92,8,8,1,9,1,9,1,10,4,10,97,8,10,
  	11,10,12,10,98,1,11,1,11,1,11,1,11,0,0,12,1,1,3,2,5,3,7,4,9,5,11,6,13,
  	7,15,8,17,9,19,10,21,11,23,12,1,0,1,1,0,48,57,115,0,1,1,0,0,0,0,3,1,0,
  	0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,1,25,1,0,
  	0,0,3,27,1,0,0,0,5,30,1,0,0,0,7,33,1,0,0,0,9,37,1,0,0,0,11,43,1,0,0,0,
  	13,45,1,0,0,0,15,83,1,0,0,0,17,91,1,0,0,0,19,93,1,0,0,0,21,96,1,0,0,0,
  	23,100,1,0,0,0,25,26,5,45,0,0,26,2,1,0,0,0,27,28,5,105,0,0,28,29,5,108,
  	0,0,29,4,1,0,0,0,30,31,5,100,0,0,31,32,5,105,0,0,32,6,1,0,0,0,33,34,5,
  	116,0,0,34,35,5,114,0,0,35,36,5,105,0,0,36,8,1,0,0,0,37,38,5,116,0,0,
  	38,39,5,101,0,0,39,40,5,116,0,0,40,41,5,114,0,0,41,42,5,97,0,0,42,10,
  	1,0,0,0,43,44,5,44,0,0,44,12,1,0,0,0,45,46,5,99,0,0,46,47,5,105,0,0,47,
  	48,5,99,0,0,48,49,5,108,0,0,49,50,5,111,0,0,50,14,1,0,0,0,51,52,5,109,
  	0,0,52,53,5,101,0,0,53,84,5,116,0,0,54,55,5,101,0,0,55,84,5,116,0,0,56,
  	57,5,112,0,0,57,58,5,114,0,0,58,59,5,111,0,0,59,84,5,112,0,0,60,61,5,
  	98,0,0,61,62,5,117,0,0,62,84,5,116,0,0,63,64,5,112,0,0,64,65,5,101,0,
  	0,65,66,5,110,0,0,66,84,5,116,0,0,67,68,5,104,0,0,68,69,5,101,0,0,69,
  	84,5,120,0,0,70,71,5,104,0,0,71,72,5,101,0,0,72,73,5,112,0,0,73,84,5,
  	116,0,0,74,75,5,111,0,0,75,76,5,99,0,0,76,84,5,116,0,0,77,78,5,110,0,
  	0,78,79,5,111,0,0,79,84,5,110,0,0,80,81,5,100,0,0,81,82,5,101,0,0,82,
  	84,5,99,0,0,83,51,1,0,0,0,83,54,1,0,0,0,83,56,1,0,0,0,83,60,1,0,0,0,83,
  	63,1,0,0,0,83,67,1,0,0,0,83,70,1,0,0,0,83,74,1,0,0,0,83,77,1,0,0,0,83,
  	80,1,0,0,0,84,16,1,0,0,0,85,86,5,97,0,0,86,92,5,110,0,0,87,88,5,101,0,
  	0,88,92,5,110,0,0,89,90,5,105,0,0,90,92,5,110,0,0,91,85,1,0,0,0,91,87,
  	1,0,0,0,91,89,1,0,0,0,92,18,1,0,0,0,93,94,5,111,0,0,94,20,1,0,0,0,95,
  	97,7,0,0,0,96,95,1,0,0,0,97,98,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,
  	22,1,0,0,0,100,101,5,32,0,0,101,102,1,0,0,0,102,103,6,11,0,0,103,24,1,
  	0,0,0,4,0,83,91,98,1,6,0,0
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
