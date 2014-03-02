%{
	#include "XplodeScanner.h"
	#include <math.h>
%}

%option nodefault yyclass="FlexScanner" noyywrap c++

DIGIT    [0-9]
ID       [a-z][a-z0-9]*


%option yylineno

%%

{DIGIT}+  { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::INTEGER; }
({DIGIT}+).({DIGIT}+)  { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::FLOAT; }


program { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_PROGRAM; }
begin { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_BEGIN; }
end { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_END; }
function { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_FUNCTION; }
proc { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_PROC; }
return { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_RETURN; }
break { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_BREAK; }
continue { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_CONTINUE; }
exit { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_EXIT; }
sleep { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_SLEEP; }


int { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_INT; }
char { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_CHAR; }
bool { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_BOOL; }
float { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_FLOAT; }
void { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_VOID; }

true { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_TRUE; }
false { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_FALSE; }

write { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_WRITE; }
read { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_READ; }

for { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_FOR; }
while { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_WHILE; }
if { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_IF; }
else { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_ELSE; }
case { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_CASE; }
type { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_TYPE; }
union { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_UNION; }

"(" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_LPAR; }
")" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_RPAR; }
"[" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_LBRACKET; }
"]" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_RBRACKET; }
"{" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_LBRACE; }
"}" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_RBRACE; }
";" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_SEMICOLON; }
"," { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_COMMA; }
"." { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_DOT; }

"+" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_PLUS; }
"-" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_MINUS; }
"*" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_MULT; }
"/" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_DIV; }
"**" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_POWER; }

"..." { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_EXTEND;}

":=" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_ASSIGN; }
"==" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_EQ; }
"!=" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_NEQ; }
"&&" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_AND; }
"||" { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_OR; }
"!"  { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_NOT; }
\n   { (*yylval).tok = new Token(yylineno,0,yytext); return Xplode::BisonParser::token::x_NL; }
.+   {LexerError(yytext);}


