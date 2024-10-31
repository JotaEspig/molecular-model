grammar Mol;

molecula    : ramificacao* cadeia insaturacao grupo_funcional EOF;

cadeia: CICLO? PREFIXO;
ramificacao           : localizador? ((cadeia 'il') | nome_especial) '-'?;
insaturacao           : localizador? (LIGACAO);
grupo_funcional       : localizador? GRUPO_FUNCIONAL;

localizador : ( '-'? pos '-' numero?);
nome_especial : 'fenil';

numero      : 'di' | 'tri' | 'tetra';
pos         : ((INT ',')* INT) | N;

CICLO : 'ciclo';

N : 'N';

PREFIXO : 
   'met'
 | 'et'
 | 'prop'
 | 'but'
 | 'pent'
 | 'hex'
 | 'hept'
 | 'oct'
 | 'non'
 | 'dec';

LIGACAO :
   'an'
 | 'en'
 | 'in';

GRUPO_FUNCIONAL : 'o' | 'ona' | 'amina' | 'ol';

INT        : [0-9]+ ;
WHITESPACE : ' ' -> skip;
