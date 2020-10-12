#!/bin/bash
yacc SemanticParser.y
lex SemanticScanner.l
gcc y.tab.c -ll -ly -w -o a
./a BasicInput.c