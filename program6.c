//Wap to lexically analyze an input file using flex.

%{
#include <stdio.h>
%}

// Regular Expressions for Token Matching
DIGIT   [0-9]+
ID      [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE  [ \t\n]
OPERATOR [+\-*/=<>]
SPECIAL  [(){};,.]

%%
"int"|"float"|"char"|"return"|"if"|"else"|"while"|"for" { printf("Keyword: %s\n", yytext); }
{ID}       { printf("Identifier: %s\n", yytext); }
{DIGIT}    { printf("Number: %s\n", yytext); }
{OPERATOR} { printf("Operator: %s\n", yytext); }
{SPECIAL}  { printf("Special Symbol: %s\n", yytext); }
{WHITESPACE}  { /* Ignore whitespace */ }
.         { printf("Unknown Token: %s\n", yytext); }
%%

int main() {
    yylex();  // Call lexer
    return 0;
}

int yywrap() {
    return 1; // Required for Flex
}
