#!/bin/bash
rm ./a
lex SemanticScanner.l
yacc -dy SemanticParser.y
gcc y.tab.c -w -o a
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 1: "
echo "==============================================================================================================="
a ..\Testcases\Test1.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 2: "
echo "==============================================================================================================="
a ..\Testcases\Test2.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 3: "
echo "==============================================================================================================="
a ..\Testcases\Test3.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 4: "
echo "==============================================================================================================="
a ..\Testcases\Test4.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 5: "
echo "==============================================================================================================="
a ..\Testcases\Test5.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 6: "
echo "==============================================================================================================="
a ..\Testcases\Test6.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 7: "
echo "==============================================================================================================="
a ..\Testcases\Test7.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 8: "
echo "==============================================================================================================="
a ..\Testcases\Test8.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 9: "
echo "==============================================================================================================="
a ..\Testcases\Test9.c
echo " "
echo " "
echo "==============================================================================================================="
echo "                                                  Test Case 10: "
echo "==============================================================================================================="
a ..\Testcases\Test10.c



