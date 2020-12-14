%{
	#include <string.h>
	int yylex();
	void yyerror(char* s);

	extern FILE* yyin;
	char* program_name;
%}

%union {
    double d;
}

%union {
	char* s;
}

%token PROGRAM PRINT PANIC SOUND NO_SOUND EXIT
%right INIT_VGA CLEAR HALT SLEEP
	
%%


exp             : INIT_VGA                  { init_vga(__def_fore_color, __def_back_color); }
				| PROGRAM exp               { program_name = $<s>2; }
				| PRINT '"' exp '"'         { puts($<s>2); }
				| PANIC '"' exp '"'         { panic($<s>2);}
				| SOUND exp                 { PlaySound($<d>2); }
				| NO_SOUND                  { NoSound(); }
                | CLEAR exp                 { if (strcmp($<s>2, "screen") == 0) {clear_screen(__def_fore_color, __def_back_color);} 
            								  else if (strcmp($<s>2, "errors") == 0) {clear_errors();}}
                | HALT                      { halt(); }
                | SLEEP exp                 { sleep($<d>2); }
                | EXIT                      { return; }
                ;

%%

void yyerror(char* s) {
	fprintf(stderr, "%s \n", s);
}


// execute .nut NutScripts
void NutScript(char* fpath) {
	yyin = fopen(fpath, "r");
	yyparse();
	fclose(yyin);
	return;
}