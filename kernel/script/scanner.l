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

InitVGA                 return INIT_VGA;
CheckOut                return CHECK_OUT;
echo                    return ECHO;
clear                   return CLEAR;
halt                    return HALT;
sleep                   return SLEEP;
EndScript               return EXIT;
.                       { /* not matched */ }
%%