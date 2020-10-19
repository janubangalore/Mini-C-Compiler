alpha 		[A-Za-z_]
fl			(f|F|l|L)
ul			(u|U|l|L)*
digit 		[0-9]
space 		[ ]
exp			[Ee][+-]?{digit}+

%{
#include <stdio.h>
int lineno = 1, err = 0, nestingLevel = 0;
%}

%%
\n  	{ lineno++; }
"/*"	{ multicomment(); }
"//"	{ singlecomment(); }
"#include<"({alpha})*".h>"	{	printf("\nLine %d : Found header file\n", lineno);	}
"#include"({space})"<"({alpha})*".h>"	{	printf("\nLine %d : Found header file\n", lineno);	}
"#define"({space})""({alpha})""({alpha}|{digit})*""({space})""({digit})+"" 			{ printf("\nLine %d : Found macro definition\n", lineno);  }
"#define"({space})""({alpha}({alpha}|{digit})*)""({space})""(({digit}+)\.({digit}+))"" 		{ printf("\nLine %d : Found macro definition\n", lineno);  }
"#define"({space})""({alpha}({alpha}|{digit})*)""({space})""({alpha}({alpha}|{digit})*)"" 	{ printf("\nLine %d : Found macro definition\n", lineno); }
"#"({alpha})	{	err=1;	yyerror("Invalid headerfile declaration!");	}

\"[^\n]*\" 			{ yylval = yytext; return STRING_CONSTANT; }
\'{alpha}\' 			{ yylval = yytext; return CHAR_CONSTANT; }
{digit}+    			{ yylval = yytext; return INT_CONSTANT; }
({digit}+)\.({digit}+) 		{ yylval = yytext; return FLOAT_CONSTANT; }
({digit}+)\.({digit}+)([eE][-+]?[0-9]+)? 	{ yylval = yytext; return FLOAT_CONSTANT; }

"sizeof"		{  return SIZEOF; }
"++"			{  return INC_OP; }
"--"			{  return DEC_OP; }
"<<"			{  return LEFT_OP; }
">>"			{  return RIGHT_OP; }
"<="			{  return LE_OP; }
">="			{  return GE_OP; }
"=="			{  return EQ_OP; }
"!="			{  return NE_OP; }
"&&"			{  return AND_OP; }
"||"			{  return OR_OP; }
"*="			{  return MUL_ASSIGN; }
"/="			{  return DIV_ASSIGN; }
"%="			{  return MOD_ASSIGN; }
"+="			{  return ADD_ASSIGN; }
"-="			{  return SUB_ASSIGN; }
"<<="			{  return LEFT_ASSIGN; }
">>="			{  return RIGHT_ASSIGN; }
"&="			{  return AND_ASSIGN; }
"^="			{  return XOR_ASSIGN; }
"|="			{  return OR_ASSIGN; }
"char"			{  yylval = yytext; return CHAR; }
"char*"			{  yylval = yytext; return CHAR_; }
"short"			{  yylval = yytext; return SHORT; }
"int"			{  yylval = yytext; return INT; }
"float"			{  yylval = yytext; return FLOAT; }
"double"		{  yylval = yytext; return DOUBLE; }
"int*"			{  yylval = yytext; return INT_; }
"long"			{  yylval = yytext; return LONG; }
"signed"		{  yylval = yytext; return SIGNED; }
"unsigned"		{  yylval = yytext; return UNSIGNED; }
"void"			{  yylval = yytext; return VOID; }
"if"			{  return IF; }
"else"			{  return ELSE; }
"while"			{  return WHILE; }
"for"			{  return FOR; }
"struct"		{  return STRUCT; }
"break"			{  return BREAK; }
"return"		{  return RETURN; }
"switch"		{  return SWITCH; }
"default"		{  return DEFAULT; }
"case"			{  return CASE; }
";"			{  return(';'); }
("{")			{  nestingLevel++;	return('{'); }
("}")			{  nestingLevel--;	return('}'); }
","			{  return(','); }
":"			{  return(':'); }
"="			{  return('='); }
"("			{  return('('); }
")"			{  return(')'); }
("["|"<:")		{  return('['); }
("]"|":>")		{  return(']'); }
"."			{  return('.'); }
"&"			{  return('&'); }
"!"			{  return('!'); }
"~"			{  return('~'); }
"-"			{  return('-'); }
"+"			{  return('+'); }
"*"			{  return('*'); }
"/"			{  return('/'); }
"%"			{  return('%'); }
"<"			{  return('<'); }
">"			{  return('>'); }
"^"			{  return('^'); }
"|"			{  return('|'); }
"?"			{  return('?'); }
{digit}({alpha}|{digit})*    		{  err=1;	yyerror("Invalid identifier! Identifier doesn't start with digit");	  }
{alpha}({alpha}|{digit})*    		{  yylval = yytext; return IDENTIFIER;  }
[ \t\v\n\f]		{  }
.			{ }
%%

yywrap()
{
	return(1);
}

multicomment()
{
	int count = 1;
	char star = 'a', comment_end=EOF;
	while(star!=EOF && count>0){
		if(star == '\n'){
			lineno++;
			star = input();
		}
		else if(star == '/'){
			comment_end = input();
			if(comment_end == EOF){
				err++;
				printf("Reached EOF, but multiline comment isn't ended!");
				break;
			}
			else if(comment_end == '*'){
				count++;
				star = input();
			}
			else{
				star = comment_end;
			}				
	
		}
		else if(star == '*'){
			comment_end = input();
			if(comment_end == EOF){
				err++;
				printf("Reached EOF, but multiline comment isn't ended!");
				break;
			}
			else if(comment_end == '/'){
				printf("\nLine %d : Detected multiline line comment with nesting level = %d\n", lineno, count);
				count--;
				if(count>0)	star = input();
			}
			else{
				star = comment_end;
			}
		}
		else{
			star = input();	
		}
	}
	if(star == EOF){
		err++;
		printf("Reached EOF, but multiline comment isn't ended!");
	}
}

singlecomment()
{
	char comment_end = '/';
	while(comment_end != EOF && comment_end != '\n'){
		comment_end = input();
	}
	printf("\nLine %d : Detected single line comment\n", lineno);
	if(comment_end == '\n'){
		lineno++;
	}
}
