%{
	int yylex();
	void yyerror(char* s);
	extern FILE* yyin;
%}

%union {
    double d;
}

%start NutScript
%token EXIT
%right INIT_VGA CHECK_OUT HALT SLEEP
%right NEG
	
%%

NutScript       : root EXIT { }


exp             : INIT_VGA                  { init_vga(__def_fore_color, __def_back_color) }
                | CHECK_OUT                 { CheckOut4Errors() }
                | HALT                      { halt() }
                | SLEEP                     { sleep($<d>2) }
                ;

%%

void yyerror(char* s) {
	fprintf(stderr, "%s \n", s);
}