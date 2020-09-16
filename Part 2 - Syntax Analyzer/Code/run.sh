#!/bin/bash
rm ./a
lex SyntaxScanner.l
yacc -dy SyntaxParser.y
gcc y.tab.c -w -o a
echo " "
echo " "
echo "==========================================================================================="
echo "                                  Test Case: "
echo "==========================================================================================="
./a Test7.c