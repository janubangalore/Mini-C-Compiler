# Running Parser code in different environment

_Please the note the difference in the instruction to implement in both cases. Else one might get error messages_

## Linux
```
rm ./a.out
yacc parser.y
lex parser.l
gcc y.tab.c -ll -ly -w
./a.out <input_filename>

```

## Windows
```
rm ./a
lex parser.l
yacc -dy parser.y
gcc y.tab.c -w -o a
./a <input_filename>

```
