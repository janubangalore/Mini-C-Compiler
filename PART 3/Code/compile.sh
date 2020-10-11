#!/bin/sh
lex lexicalAnalyzer.l
yacc -dy syntaxChecker.y
gcc lex.yy.c y.tab.c -w -g
./a input.c
