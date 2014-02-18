%{
	#include "XplodeScanner.h"
	#include <math.h>
%}

%option nodefault yyclass="FlexScanner" noyywrap c++

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%

{DIGIT}+  { *yylval = atoi(yytext); printf("found integer.\n");return Xplode::BisonParser::token::INTEGER; }
({DIGIT}+).({DIGIT}+)  { *yylval = atof(yytext); printf("found float number.\n");return Xplode::BisonParser::token::FLOAT; }


program { return Xplode::BisonParser::token::x_PROGRAM; }
begin { return Xplode::BisonParser::token::x_BEGIN; }
end { return Xplode::BisonParser::token::x_END; }
function { return Xplode::BisonParser::token::x_FUNCTION; }
return { return Xplode::BisonParser::token::x_RETURN; }
break { return Xplode::BisonParser::token::x_BREAK; }
continue { return Xplode::BisonParser::token::x_CONTINUE; }
exit { return Xplode::BisonParser::token::x_EXIT; }

int { return Xplode::BisonParser::token::x_INT; }
char { return Xplode::BisonParser::token::x_CHAR; }
bool { return Xplode::BisonParser::token::x_BOOL; }
float { return Xplode::BisonParser::token::x_FLOAT; }
void { return Xplode::BisonParser::token::x_VOID; }

true { return Xplode::BisonParser::token::x_TRUE; }
false { return Xplode::BisonParser::token::x_FALSE; }

write { return Xplode::BisonParser::token::x_WRITE; }
read { return Xplode::BisonParser::token::x_READ; }

for { return Xplode::BisonParser::token::x_FOR; }
while { return Xplode::BisonParser::token::x_WHILE; }
if { return Xplode::BisonParser::token::x_IF; }
else { return Xplode::BisonParser::token::x_ELSE; }
case { return Xplode::BisonParser::token::x_CASE; }
type { return Xplode::BisonParser::token::x_TYPE; }
union { return Xplode::BisonParser::token::x_UNION; }

"(" { return Xplode::BisonParser::token::x_LPAR; }
")" { return Xplode::BisonParser::token::x_RPAR; }
"[" { return Xplode::BisonParser::token::x_LBRACKET; }
"]" { return Xplode::BisonParser::token::x_RBRACKET; }
"{" { return Xplode::BisonParser::token::x_LBRACE; }
"}" { return Xplode::BisonParser::token::x_RBRACE; }
";" { return Xplode::BisonParser::token::x_SEMICOLON; }
"," { return Xplode::BisonParser::token::x_COMMA; }
"." { return Xplode::BisonParser::token::x_DOT; }

"+" { return Xplode::BisonParser::token::x_PLUS; }
"-" { return Xplode::BisonParser::token::x_MINUS; }
"*" { return Xplode::BisonParser::token::x_MULT; }
"/" { return Xplode::BisonParser::token::x_DIV; }
"**" { return Xplode::BisonParser::token::x_POWER; }

":=" { return Xplode::BisonParser::token::x_ASSIGN; }
"==" { return Xplode::BisonParser::token::x_EQ; }
"!=" { return Xplode::BisonParser::token::x_NEQ; }
"&&" { return Xplode::BisonParser::token::x_AND; }
"||" { return Xplode::BisonParser::token::x_OR; }
"!" { return Xplode::BisonParser::token::x_NOT; }



.+|\n        { /* Ignore everything else */ }

