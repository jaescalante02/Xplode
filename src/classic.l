%{

#ifndef CL_FLEX_LEXER
#define CL_FLEX_LEXER
#endif

#include "ClassicScanner.h"
#include <math.h>
#include <string>

extern int line,column;
extern std::string tok; 

#define UPDATE_LOC column += yyleng
#define SAVE_TOK (*yylval).tok = new Token(line,column,yytext); tok = yytext

%}

%option nodefault yyclass="Xplode::ClassicScanner" noyywrap c++

DIGIT    [0-9]
ID       [a-zA-Z][a-zA-Z0-9]*


%option yylineno

%option prefix="cl"

%%

{DIGIT}+  { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::INTEGER; }
({DIGIT}+).({DIGIT}+)  { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::FLOAT; }


[ \t\r\x20]+  {UPDATE_LOC; }  // ignore all whitespace
program { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_PROGRAM; }
begin { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_BEGIN; }
end { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_END; }
function { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_FUNCTION; }
proc { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_PROC; }
return { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_RETURN; }
break { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_BREAK; UPDATE_LOC; }
continue { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_CONTINUE; }
exit { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_EXIT; }
sleep { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_SLEEP; }


int { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_INT; }
char { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_CHAR; }
bool { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_BOOL; }
float { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_FLOAT; }
void { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_VOID; }

true { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_TRUE; }
false { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_FALSE; }

write { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_WRITE; }
read { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_READ; }

for { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_FOR; }
while { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_WHILE; }
if { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_IF; }
else { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_ELSE; }
case { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_CASE; }
type { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_TYPE; }
union { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_UNION; }

"(" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_LPAR; }
")" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_RPAR; }
"[" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_LBRACKET; }
"]" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_RBRACKET; }
"{" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_LBRACE; }
"}" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_RBRACE; }
";" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_SEMICOLON; }
"," { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_COMMA; }
"." { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_DOT; }

"+" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_PLUS; }
"-" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_MINUS; }
"*" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_MULT; }
"/" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_DIV; }
"**" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_POWER; }

"..." { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_EXTEND;}

":=" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_ASSIGN; }
"==" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_EQ; }
"!=" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_NEQ; }
"&&" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_AND; }
"||" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_OR; }
"!"  { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_NOT; }
\n   { line++; column = 1;  }

"<"  { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_LESS; }
"<=" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_LESSEQ; }
">" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_GREATER; }
">=" { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_GREATEREQ; }

{ID} { SAVE_TOK; UPDATE_LOC; return Xplode::BisonParser::token::x_ID; }

%%

