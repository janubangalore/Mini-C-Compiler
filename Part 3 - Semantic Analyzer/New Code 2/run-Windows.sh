#!/bin/bash
flex lexer.l
yacc -dy parser.y
gcc y.tab.c -w -o a
a test.c
