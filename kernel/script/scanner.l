%option noyywrap
%{
	#include "y.tab.h"
	void yyerror(char* s);
%}

%x COMMENT

%%
"#="					BEGIN(COMMENT);
<COMMENT>.
<COMMENT>"\n"   
<COMMENT>"=#"   		BEGIN(INITIAL);
" "
"\n"

program                 return PROGRAM;
InitVGA                 return INIT_VGA;
Print                   return PRINT;
Panic                   return PANIC;
Sound                   return SOUND;
NoSound                 return NO_SOUND;
Clear                   return CLEAR;
Halt                    return HALT;
Sleep                   return SLEEP;
EndScript               return EXIT;
.                       { /* not matched */ }
%%