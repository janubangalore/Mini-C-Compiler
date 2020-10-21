%{

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "y.tab.h"
entry_t** constant_table;

int cmnt_strt = 0;

%}

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]
space [ ]

%%
\n                              {yylineno++;}
"/*"	{ multicomment(); }
"//"	{ singlecomment(); }
"int"                             {return INT;}
"char"                            {return CHAR;}
"float"                           {return FLOAT;}
"void"                            {return VOID;}
"long"                            {return LONG;}
"long long"                       {return LONG_LONG;}
"short"                           {return SHORT;}
"signed"                          {return SIGNED;}
"unsigned"                        {return UNSIGNED;}
"for"                             {return FOR;}
"while"                           {return WHILE;}
"break"                           {return BREAK;}
"continue"                        {return CONTINUE;}
"if"                              {return IF;}
"else"                            {return ELSE;}
"return"                          {return RETURN;}

{identifier}                      {return  IDENTIFIER;}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?       { yylval.entry = insert(constant_table,yytext,(int)strtol(yytext, NULL, 16),INT); return  HEX_CONSTANT;}
'({letter}|{digit})'              { yylval.entry = insert(constant_table,yytext,yytext[1],CHAR); return CHAR_CONSTANT;}
[+\-]?{digit}+[lLuU]?             { yylval.entry = insert(constant_table,yytext,atoi(yytext),INT); return  DEC_CONSTANT;}
[+\-]?{digit}*\.{digit}+          { yylval.entry = insert(constant_table,yytext,atof(yytext),FLOAT); return FLOAT_CONSTANT;}

\"[^\"\n]*\"                      {
                                    if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
                                    {
                                      yyless(yyleng-1);       /* push the quote back if it was escaped */
                                      yymore();
                                    }
                                    else
                                    {
                                      insert(constant_table,yytext,INT_MAX,STRING);
                                      return STRING;
                                    }
                                  }

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	          {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}

"#include<"({letter})*".h>"	{	printf("\nLine %d : Found header file\n", yylineno);	}
"#include"({space})"<"({letter})*".h>"	{	printf("\nLine %d : Found header file\n", yylineno);	}
"#define"({space})""({letter})""({letter}|{digit})*""({space})""({digit})+"" 			{ printf("\nLine %d : Found macro definition\n", yylineno);  }
"#define"({space})""({letter}({letter}|{digit})*)""({space})""(({digit}+)\.({digit}+))"" 		{ printf("\nLine %d : Found macro definition\n", yylineno);  }
"#define"({space})""({letter}({letter}|{digit})*)""({space})""({letter}({letter}|{digit})*)"" 	{ printf("\nLine %d : Found macro definition\n", yylineno); }
"#"({letter})	{	yyerror("Invalid headerfile declaration!");	}

"--"			                {return DECREMENT;}
"++"			                {return INCREMENT;}
"+="                      {return ADD_ASSIGN;}
"-="                      {return SUB_ASSIGN;}
"*="                      {return MUL_ASSIGN;}
"/="                      {return DIV_ASSIGN;}
"%="                      {return MOD_ASSIGN;}


"&&"			                {return LOGICAL_AND;}
"||"			                {return LOGICAL_OR;}
"<="			                {return LS_EQ;}
">="			                {return GR_EQ;}
"=="			                {return EQ;}
"!="		                  {return NOT_EQ;}

.                         {return yytext[0];}

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
			yylineno++;
			star = input();
		}
		else if(star == '/'){
			comment_end = input();
			if(comment_end == EOF){
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
				printf("Reached EOF, but multiline comment isn't ended!");
				break;
			}
			else if(comment_end == '/'){
				printf("\nLine %d : Detected multiline line comment with nesting level = %d\n", yylineno, count);
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
		printf("Reached EOF, but multiline comment isn't ended!");
	}
}

singlecomment()
{
	char comment_end = '/';
	while(comment_end != EOF && comment_end != '\n'){
		comment_end = input();
	}
	printf("\nLine %d : Detected single line comment\n", yylineno);
	if(comment_end == '\n'){
		yylineno++;
	}
}
