%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "y.tab.h"

	#define ANSI_COLOR_RED		"\x1b[31m"
	#define ANSI_COLOR_GREEN	"\x1b[32m"
	#define ANSI_COLOR_YELLOW	"\x1b[33m"
	#define ANSI_COLOR_BLUE		"\x1b[34m"
	#define ANSI_COLOR_MAGENTA	"\x1b[35m"
	#define ANSI_COLOR_CYAN		"\x1b[36m"
	#define ANSI_COLOR_RESET	"\x1b[0m"

	struct symboltable
	{
		char name[100];
		char class[100];
		char type[100];
		char value[100];
		int nestval;
		int lineno;
		int length;
		int params_count;
                int array_dimension;
	}ST[1001];

	struct constanttable
	{
		char name[100];
		char type[100];
		int length;
                int lineno;
	}CT[1001];

	int currnest = 0;
	extern int yylval;

	int hash(char *str)
	{
		int value = 0, i;
		for(i = 0 ; i < strlen(str) ; i++)
		{
			value = 10*value + (str[i] - 'A');
			value = value % 1001;
			while(value < 0)
				value = value + 1001;
		}
		return value;
	}

	int lookingupCT(char *str)
	{
		int value = hash(str),i;
		if(CT[value].length == 0)
                        return 0;
		else if(strcmp(CT[value].name,str)==0)
			return 1;
		else
		{
			for(i = value + 1 ; i!=value ; i = (i+1)%1001)
			{
				if(strcmp(CT[i].name,str)==0)
				{
					return 1;
				}
			}
			return 0;
		}
	}

	int lookingupST(char *str)
	{
		int value = hash(str), i;
		if(ST[value].length == 0)
		{
			return 0;
		}
		else if(strcmp(ST[value].name,str)==0)
		{
			
			return value;
		}
		else
		{
			for(i = value + 1 ; i!=value ; i = (i+1)%1001)
			{
				if(strcmp(ST[i].name,str)==0)
				{
					
					return i;
				}
			}
			return 0;
		}
	}

	void insertSTline(char *str1, int line)
	{
		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(strcmp(ST[i].name,str1)==0)
			{
				ST[i].lineno = line;
			}
		}
	}

    void insertCTline(char *str1 ,int line)
        {
	 int i;
         for(i=0; i<1001 ;i++)
          {
             if(strcmp(CT[i].name,str1)==0)
               {
                CT[i].lineno = line;
               }  
        
           }
        }


	void insertSTable(char *str1, char *str2)
	{
		if(lookingupST(str1))
		{
			if(strcmp(ST[lookingupST(str1)].class,"Identifier")==0 && strcmp(str2,"Array Identifier")==0)
			{
				printf("Error use of array\n");
				exit(0);
			}	
			return;
		}
		else
		{
			int value = hash(str1);
			if(ST[value].length == 0)
			{
				strcpy(ST[value].name,str1);
				strcpy(ST[value].class,str2);
				ST[value].length = strlen(str1);
				ST[value].nestval = 9999;
				ST[value].params_count = -1;
				insertSTline(str1,yylineno);
				return;
			}

			int pos = 0, i;

			for (i = value + 1 ; i!=value ; i = (i+1)%1001)
			{
				if(ST[i].length == 0)
				{
					pos = i;
					break;
				}
			}

			strcpy(ST[pos].name,str1);
			strcpy(ST[pos].class,str2);
			ST[pos].length = strlen(str1);
			ST[pos].nestval = 9999;
			ST[pos].params_count = -1;
                
		}
	}

	void insertSTtype(char *str1, char *str2)
	{
		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(strcmp(ST[i].name,str1)==0)
			{
				strcpy(ST[i].type,str2);
			}
		}
    }

	void insertSTvalue(char *str1, char *str2)
	{
		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(strcmp(ST[i].name,str1)==0 && ST[i].nestval == currnest)
			{
				strcpy(ST[i].value,str2);
			}
		}
	}


	void insertSTnest(char *s, int nest)
	{
		int i;
		if(lookingupST(s) && ST[lookingupST(s)].nestval != 9999)
		{
             int pos = 0;
             int value = hash(s);
			for (i = value + 1 ; i!=value ; i = (i+1)%1001)
			{
				if(ST[i].length == 0)
				{
					pos = i;
					break;
				}
			}

			strcpy(ST[pos].name,s);
			strcpy(ST[pos].class,"Identifier");
			ST[pos].length = strlen(s);
			ST[pos].nestval = nest;
			ST[pos].params_count = -1;
			ST[pos].lineno = yylineno;
		}
		else
		{
			for(i = 0 ; i < 1001 ; i++)
			{
				if(strcmp(ST[i].name,s)==0 )
				{
					ST[i].nestval = nest;
				}
			}
		}
	} 
    

    void insertSTarraydimension(char *s,int array_dim)
        {
            int i;
            for(i=0; i<1001 ; i++)
            {
              if(strcmp(ST[i].name,s)==0)
              {
                ST[i].array_dimension=array_dim;
              }
           }
        }
	void insertSTparamscount(char *s, int count1)
	{

		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(strcmp(ST[i].name,s)==0 )
			{
				ST[i].params_count = count1;
			}
		}
	}

	int getSTparamscount(char *s)
	{
		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(strcmp(ST[i].name,s)==0 )
			{
				return ST[i].params_count;
			}
		}
		return -1;
	}

	void insertSTFunction(char *s)
	{
		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(strcmp(ST[i].name,s)==0 )
			{
				strcpy(ST[i].class,"Function");
				return;
			}
		}

	}

	void delete_data(int nesting)
	{
		int i;
		for(i = 0 ; i < 1001 ; i++)
		{
			if(ST[i].nestval == nesting)
			{
				ST[i].nestval = 99999;
			}
		}
	}

	void insertCTable(char *str1, char *str2)
	{
		if(lookingupCT(str1))
			return;
		else
		{
			int value = hash(str1);
			if(CT[value].length == 0)
			{
				strcpy(CT[value].name,str1);
				strcpy(CT[value].type,str2);
                                insertCTline(str1,yylineno);
				CT[value].length = strlen(str1);
				return;
			}

			int pos = 0,i;

			for (i = value + 1 ; i!=value ; i = (i+1)%1001)
			{
				if(CT[i].length == 0)
				{
					pos = i;
					break;
				}
			}

			strcpy(CT[pos].name,str1);
			strcpy(CT[pos].type,str2);
			CT[pos].length = strlen(str1);
		}
	}

	int check_id_is_function(char *s)
	{
		int i;
		for(i = 0 ; i < 1000 ; i++)
		{
			if(strcmp(ST[i].name,s)==0)
			{
				if(strcmp(ST[i].class,"Function")==0)
					return 1;
			}
		}
		return 0;
	}

	int check_scope(char *s)
	{
		int i,flag = 0;
		for(i = 0 ; i < 1000 ; i++)
		{
			if(strcmp(ST[i].name,s)==0)
			{
				if(ST[i].nestval > currnest)
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if(!flag)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	int check_array(char *s)
	{
		int i;
		for(i = 0 ; i < 1000 ; i++)
		{
			if(strcmp(ST[i].name,s)==0)
			{
				if(strcmp(ST[i].class,"Array Identifier")==0)
				{
					return 0;
				}
			}
		}
		return 1;
	}

	int duplicates(char *s)
	{
		int i;
		for(i = 0 ; i < 1000 ; i++)
		{
			if(strcmp(ST[i].name,s)==0)
			{				
				if(ST[i].nestval == currnest)
				{
			        return 1;
				}
			}
		}
		
		return 0;
	}

	int checkforduplicate(char* str)
	{
		int i;
		for(i=0; i<1001; i++)
		{
			if(strcmp(ST[i].name, str) == 0 && strcmp(ST[i].class, "Function") == 0)
			{
				printf("Function redeclaration not allowed\n");
				exit(0);
			}
		}
	}

	int checkparameters(char* type_specifier)
	{
		if(!strcmp(type_specifier, "void"))
		{
			printf("Parameters cannot be of type void\n");
			exit(0);
		}
		return 0;
	}

	int checkfordeclaration(char* str, char *check_type)
	{
		int i;
		for(i=0; i<1001; i++)
		{
			if(strcmp(ST[i].name, str) == 0 && strcmp(ST[i].class, "Function") == 0 || strcmp(ST[i].name,"printf")==0 )
			{
				return 1;
			}
		}
		return 0;
	}

	char get_type(char *s, int flag)
	{
			int i;
			for(i = 0 ; i < 1001 ; i++ )
			{
				if(strcmp(ST[i].name,s)==0)
				{
					return ST[i].type[0];
				}
			}
		
	}

	void printSTable()
	{      int i;
		for(i=0;i<190;i++)
               {printf("-");}
               printf("\n");
		printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s \n","Line Number","Token name", "Class", "Data Type","Value", "Nesting", "Num of params","Array Dimension");
		for(i=0;i<190;i++) {
			printf("-");
		}
		printf("\n");
		for(i = 0 ; i < 1001 ; i++)
		{
			if(ST[i].length == 0)
			{
				continue;
			}
                        if(ST[i].array_dimension==0)
                        {ST[i].array_dimension=-1;}
                        if(ST[i].array_dimension==-2)
                        {ST[i].array_dimension=0;}
			printf("%5d %20s %22s %20s %16s %22d %20d %22d\n",ST[i].lineno,ST[i].name, ST[i].class, ST[i].type, ST[i].value,ST[i].nestval, ST[i].params_count,ST[i].array_dimension);
		}
                for(i=0;i<190;i++)
                {printf("-");}
    }


	void printCTable()
	{       
		int i;
		for(i=0;i<70;i++)
                {printf("-");}
                printf("\n");
		printf("%20s %20s %18s\n","Line Number","Constant Name","Data Type");
		for(i=0;i<70;i++) {
			printf("-");
		}
		printf("\n");
		for(i = 0 ; i < 1001 ; i++)
		{
			if(CT[i].length == 0)
				continue;

			printf("%12d %22s %29s\n",CT[i].lineno,CT[i].name, CT[i].type);
		}
               for(i=0;i<70;i++)
               {printf("-");}
               printf("\n");
	}
	char curid[20];
	char curtype[20];
	char curval[20];

%}

DE "define"
IN "include"

%%
\n 	{yylineno++;}
([#][" "]*({IN})[ ]*([<]?)([A-Za-z]+)[.]?([A-Za-z]*)([>]?))/["\n"|\/|" "|"\t"]	{ }
([#][" "]*({DE})[" "]*([A-Za-z]+)(" ")*[0-9]+)/["\n"|\/|" "|"\t"]				{ } 
\/\/(.*)																		{ }
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/										{ }
[ \n\t] ;
";"				{ return(';'); }
","				{ return(','); }
("{")			{ return('{'); }
("}")			{ return('}'); }
"("				{ return('('); }
")"				{ return(')'); }
("["|"<:")		{ return('['); }
("]"|":>") 		{ return(']'); }
":"				{ return(':'); }
"."				{ return('.'); }

"char"			{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword");return CHAR;}
"double"		{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword"); return DOUBLE;}
"else"			{ insertSTable(yytext, "Keyword"); return ELSE;}
"float"			{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword"); return FLOAT;}
"while"			{ insertSTable(yytext, "Keyword"); return WHILE;}
"do"			{ insertSTable(yytext, "Keyword"); return DO;}
"for"			{ insertSTable(yytext, "Keyword"); return FOR;}
"if"			{ insertSTable(yytext, "Keyword"); return IF;}
"int"			{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword"); return INT;}
"long"			{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword"); return LONG;}
"return"		{ insertSTable(yytext, "Keyword"); return RETURN;}
"short"			{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword"); return SHORT;}
"signed"		{ strcpy(curtype,yytext); insertSTable(yytext, "Keyword"); return SIGNED;}
"sizeof" 		{ insertSTable(yytext, "Keyword"); return SIZEOF;}
"struct"		{ strcpy(curtype,yytext);   insertSTable(yytext, "Keyword");  return STRUCT;}
"unsigned"		{ insertSTable(yytext, "Keyword");   return UNSIGNED;}
"void"			{ strcpy(curtype,yytext);   insertSTable(yytext, "Keyword");  return VOID;}
"break"			{ insertSTable(yytext, "Keyword");  return BREAK;}



"++"			{ return increment_operator; }
"--"			{ return decrement_operator; }
"<<"			{ return leftshift_operator; }
">>"			{ return rightshift_operator; }
"<="			{ return lessthan_assignment_operator; }
"<"				{ return lessthan_operator; }
">="			{ return greaterthan_assignment_operator; }
">"				{ return greaterthan_operator; }
"=="			{ return equality_operator; }
"!="			{ return inequality_operator; }
"&&"			{ return AND_operator; }
"||"			{ return OR_operator; }
"^"				{ return caret_operator; }
"*="			{ return multiplication_assignment_operator; }
"/="			{ return division_assignment_operator; }
"%="			{ return modulo_assignment_operator; }
"+="			{ return addition_assignment_operator; }
"-="			{ return subtraction_assignment_operator; }
"<<="			{ return leftshift_assignment_operator; }
">>="			{ return rightshift_assignment_operator; }
"&="			{ return AND_assignment_operator; }
"^="			{ return XOR_assignment_operator; }
"|="			{ return OR_assignment_operator; }
"&"				{ return amp_operator; }
"!"				{ return exclamation_operator; }
"~"				{ return tilde_operator; }
"-"				{ return subtract_operator; }
"+"				{ return add_operator; }
"*"				{ return multiplication_operator; }
"/"				{ return division_operator; }
"%"				{ return modulo_operator; }
"|"				{ return pipe_operator; }
\=				{ return assignment_operator;}

\"[^\n]*\"/[;|,|\)] 			{strcpy(curval,yytext); insertCTable(yytext,"String Constant"); return string_constant;}
\'[A-Z|a-z]\'/[;|,|\)|:] 		{strcpy(curval,yytext); insertCTable(yytext,"Character Constant"); return character_constant;}
[a-z|A-Z]([a-z|A-Z]|[0-9])*/\[ 	{strcpy(curid,yytext); insertSTable(yytext, "Array Identifier");  return array_identifier;}
[1-9][0-9]*|0/[;|,|" "|\)|<|>|=|\!|\||&|\+|\-|\*|\/|\%|~|\]|\}|:|\n|\t|\^] 	{strcpy(curval,yytext); insertCTable(yytext, "Number Constant"); yylval = atoi(yytext); return integer_constant;}
([0-9]*)\.([0-9]+)/[;|,|" "|\)|<|>|=|\!|\||&|\+|\-|\*|\/|\%|~|\n|\t|\^] 	{strcpy(curval,yytext); insertCTable(yytext, "Floating Constant"); return float_constant;}
[A-Za-z_][A-Za-z_0-9]* {strcpy(curid,yytext); insertSTable(curid,"Identifier"); return identifier;}

(.?) {
		if(yytext[0]=='#')
		{
			printf("Error in Pre-Processor directive at line no. %d\n",yylineno);
		}
		else if(yytext[0]=='/')
		{
			printf("ERR_UNMATCHED_COMMENT at line no. %d\n",yylineno);
		}
		else if(yytext[0]=='"')
		{
			printf("ERR_INCOMPLETE_STRING at line no. %d\n",yylineno);
		}
		else
		{
			printf("ERROR at line no. %d\n",yylineno);
		}
		printf("%s\n", yytext);
		return 0;
}

%%
