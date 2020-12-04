%{
	#include <string.h>
	int yylex();
	void yyerror(char* s);
	extern FILE* yyin;
%}

%union {
    double d;
}

%union {
	char* s;
}

%token ECHO EXIT
%right INIT_VGA CHECK_OUT CLEAR HALT SLEEP
%right NEG
	
%%


exp             : INIT_VGA                  { init_vga(__def_fore_color, __def_back_color); }
                | CHECK_OUT                 { CheckOut4Errors(); }
                | CLEAR exp                 { if (strcmp($<s>2, "screen") == 0) {clear_screen(__def_fore_color, __def_back_color);} 
            								  else if (strcmp($<s>2, "errors") == 0) {clear_errors();}}
                | HALT                      { halt(); }
                | SLEEP exp                 { sleep($<d>2); }
                | ECHO '/' exp '/'          { puts($<s>2); }
                | EXIT                      { return; }
                ;

%%

void yyerror(char* s) {
	fprintf(stderr, "%s \n", s);
}



void NutScript(char* fpath) {
	yyin = fopen(fpath, "r");
	yyparse();
	fclose(yyin);
	return;
}