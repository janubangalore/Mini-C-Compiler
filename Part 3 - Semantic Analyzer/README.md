# Syntax Analyzer

## Execution

### Windows
```
cd Code
rm a
lex SemanticScanner.l
yacc -dy SemanticParser.y
gcc y.tab.c -w -o a
a <input c-filename>
```

### Gitbash
```
cd Code
rm ./a
lex SemanticScanner.l
yacc -dy SemanticParser.y
gcc y.tab.c -w -o a
./a <input c-filename>
```

### Linux/Ubuntu
```
cd Code
rm ./a.out
lex SemanticScanner.l
yacc -dy SemanticParser.y
gcc y.tab.c -ll -ly -w
./a.out <input c-filename>
```

## Test Cases Execution

### Windows
```
cd Code
bash 'run-Windows.sh'
```

### GitBash
```
cd Code
bash 'run-GB.sh'

```

### Linux/Ubuntu
```
cd Code
bash 'run-Linux.sh'

```
