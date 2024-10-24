grammar Mol;

molecula    : ramificacao* cadeia insaturacao grupo_funcional EOF;

cadeia: CICLO? PREFIXO;
ramificacao           : (N? '-'? pos '-' numero?)? cadeia 'il' '-'?;
insaturacao           : ('-' pos '-' numero?)? (LIGACAO);
grupo_funcional       : ('-' pos '-' numero?)? GRUPO_FUNCIONAL;

numero      : 'di' | 'tri' | 'tetra';
pos         : (INT ',')* INT;

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

GRUPO_FUNCIONAL : 'o' | 'ona' | 'amina';

INT        : [0-9]+ ;
WHITESPACE : ' ' -> skip;
