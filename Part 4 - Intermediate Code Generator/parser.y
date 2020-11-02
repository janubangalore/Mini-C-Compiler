%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	void yyerror(char* s);
	int yylex();
	void inserting();
	void insValue();
	int flag=0;
	extern char curid[20];
	extern char curtype[20];
	extern char curval[20];
	extern int currnest;
	#define ANSI_COLOR_RED		"\x1b[31m"
	#define ANSI_COLOR_GREEN	"\x1b[32m"
	#define ANSI_COLOR_CYAN		"\x1b[36m"
	#define ANSI_COLOR_RESET	"\x1b[0m"
	void insertSTparamscount(char*, int);
	int getSTparamscount(char*);
	int checkforduplicate(char*);
	int checkfordeclaration(char*, char *);
	int checkparameters(char*);
	void delete_data (int );
	int check_scope(char*);
	int check_id_is_function(char *);
	void insertST(char*, char*);
	void insertSTnest(char*, int);
        void insertSTarraydimension(char*,char*); 
	int duplicates(char *s);
	int check_array(char*);
	char currfunctype[100];
	char currfunc[100];
	void codeassigning();
	void label3();
	void label4();
	void label5();
	void label6();
	void generationunary();
	void codegeneratingcon();
	void functiongeneration();
	void functiongenend();
	void arggeneration();
	void callgeneration();
	char* itoa(int num, char* str, int base);
	void reverse(char str[], int length); 
	void swap(char*,char*);
	char currfunccall[100];
	void insertSTFunction(char*);
	char get_type(char*,int);
	char getfirst(char*);
	void push(char *s);
	void codegeneration();
	void label1();
	void label2();

	int params_count=0;
	int call_params_count=0;
	int top = 0,count=0,ltop=0,lno=0;
	char temp[3] = "t";
        int array_dim;
%}

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT
%token RETURN MAIN
%token VOID
%token WHILE FOR DO 
%token BREAK
%token ENDIF
%expect 1

%token identifier array_identifier func_identifier
%token integer_constant string_constant float_constant character_constant

%nonassoc ELSE

%left OR_operator
%left AND_operator
%left pipe_operator
%left caret_operator
%left amp_operator
%left equality_operator inequality_operator
%left lessthan_assignment_operator lessthan_operator greaterthan_assignment_operator greaterthan_operator
%left leftshift_operator rightshift_operator 
%left add_operator subtract_operator
%left multiplication_operator division_operator modulo_operator

%right leftshift_assignment_operator rightshift_assignment_operator
%right XOR_assignment_operator OR_assignment_operator
%right AND_assignment_operator modulo_assignment_operator
%right multiplication_assignment_operator division_assignment_operator
%right addition_assignment_operator subtraction_assignment_operator
%right assignment_operator

%right SIZEOF
%right tilde_operator exclamation_operator
%left increment_operator decrement_operator 


%start program

%%
program
			: declaration_list;

D
			: declaration_list
			| ;

declaration_list
			: declaration D 

variable_declaration
			: type_specifier variable_declaration_list ';' 

declaration
			: variable_declaration 
			| function_declaration

variable_declaration_identifier 
			: identifier {if(duplicates(curid)){printf("Duplicate\n");exit(0);}insertSTnest(curid,currnest); inserting();} vdi   
			  | array_identifier {if(duplicates(curid)){printf("Duplicate\n");exit(0);}insertSTnest(curid,currnest); inserting();} vdi;

variable_declaration_list
			: variable_declaration_list ',' variable_declaration_identifier | variable_declaration_identifier;			
			

identifier_array_type
			: '[' initilization_params
			| ;

vdi : identifier_array_type | assignment_operator simple_expression  ; 

initilization
			: string_initilization
			| array_initialization
			| ;

initilization_params
			: integer_constant ']' initilization {if($$ < 1) {printf("Wrong array size\n");exit(0);} array_dim = $$;
			                                                 insertSTarraydimension(curid,array_dim);}
			| ']' string_initilization{array_dim = -2; insertSTarraydimension(curid,array_dim);}


unsigned_grammar 
			: INT | LONG long_grammar | SHORT short_grammar | ;

type_specifier 
			: INT | CHAR | FLOAT  | DOUBLE  
			| LONG long_grammar 
			| SHORT short_grammar
			| UNSIGNED unsigned_grammar 
			| SIGNED signed_grammar
			| VOID  ;


function_declaration
			: function_declaration_type function_declaration_param_statement;

function_declaration_type
			: type_specifier identifier '('  { strcpy(currfunctype, curtype); strcpy(currfunc, curid); 
			                                checkforduplicate(curid); insertSTFunction(curid); inserting(); };

function_declaration_param_statement
			: {params_count=0;}params ')' {functiongeneration();} statement {functiongenend();};


signed_grammar 
			: INT | LONG long_grammar | SHORT short_grammar | ;

long_grammar 
			: INT  | ;

short_grammar 
			: INT | ;


statement 
			: expression_statment | compound_statement 
			| conditional_statements | iterative_statements 
			| return_statement | break_statement 
			| variable_declaration;

compound_statement 
			: {currnest++;} '{'  statment_list  '}' {delete_data(currnest);currnest--;}  ;

statment_list 
			: statement statment_list 
			| ;

expression_statment 
			: expression ';' 
			| ';' ;

conditional_statements 
			: IF '(' simple_expression ')' {label1();if($3!=1)
			  {printf("Condition checking is not of type int\n");exit(0);}} statement {label2();}  conditional_statements_breakup;

conditional_statements_breakup
			: ELSE statement {label3();}
			| {label3();};

iterative_statements 
			: WHILE '(' {label4();} simple_expression ')' {label1();if($4!=1)
			                             {printf("Condition checking is not of type int\n");exit(0);}} statement {label5();} 
			| FOR '(' expression ';' {label4();} simple_expression ';' {label1();if($6!=1)
			                             {printf("Condition checking is not of type int\n");exit(0);}} expression ')'statement {label5();} 
			| {label4();}DO statement WHILE '(' simple_expression ')'{label1();label5();if($6!=1)
			                             {printf("Condition checking is not of type int\n");exit(0);}} ';';
return_statement 
			: RETURN ';' {if(strcmp(currfunctype,"void")) {printf("Returning void of a non-void function\n"); exit(0);}}
			| RETURN expression ';' { 	if(!strcmp(currfunctype, "void"))
										{ 
											yyerror("Function is void");
										}

										if((currfunctype[0]=='i' || currfunctype[0]=='c') && $2!=1)
										{
											printf("Expression doesn't match return type of function\n"); exit(0);
										}

									};

break_statement 
			: BREAK ';' ;

params 
			: parameters_list { insertSTparamscount(currfunc, params_count); }| { insertSTparamscount(currfunc, params_count); };

parameters_list 
			: type_specifier { checkparameters(curtype);} parameters_identifier_list ;

parameters_identifier_list 
			: param_identifier parameters_identifier_list_breakup;

parameters_identifier_list_breakup
			: ',' parameters_list 
			| ;

param_identifier 
			: identifier { inserting();insertSTnest(curid,1); params_count++; } param_identifier_breakup;

param_identifier_breakup
			: '[' ']'
			| ;


expression 
			: mutable assignment_operator {push("=");} expression   {   
					                                   if($1==1 && $4==1) 
					                                          {
			                                                          $$=1;
			                                                          } 
			                                                          else 
			                                                          {$$=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassigning();
			                                                        }
			| mutable addition_assignment_operator {push("+=");}expression {  
									    if($1==1 && $4==1) 
			                                                          $$=1; 
			                                                          else 
			                                                          {$$=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassigning();
			                                                       }
			| mutable subtraction_assignment_operator {push("-=");} expression  {	  
										if($1==1 && $4==1) 
			                                                          $$=1; 
			                                                          else 
			                                                          {$$=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassigning();
			                                                       }
			| mutable multiplication_assignment_operator {push("*=");} expression {
										if($1==1 && $4==1) 
			                                                          $$=1; 
			                                                          else 
			                                                          {$$=-1; printf("Type mismatch\n"); exit(0);}
			                                                          codeassigning(); 
			                                                       }
			| mutable division_assignment_operator {push("/=");}expression 		{ 
										if($1==1 && $4==1) 
			                                                          $$=1; 
			                                                          else 
			                                                          {$$=-1; printf("Type mismatch\n"); exit(0);} 
			                                                       }
			| mutable modulo_assignment_operator {push("%=");}expression 		{ 
										if($1==1 && $3==1) 
			                                                          $$=1; 
			                                                          else 
			                                                          {$$=-1; printf("Type mismatch\n"); exit(0);} 
			                                                          codeassigning();
										}
			| mutable increment_operator 				{ push("++");if($1 == 1) $$=1; else $$=-1; generatingunary();}
			| mutable decrement_operator  				{ push("--");if($1 == 1) $$=1; else $$=-1; }
			| simple_expression                                     { if($1 == 1) $$=1; else $$=-1; } ;


simple_expression 
			: simple_expression OR_operator and_expression {push("||");} {if($1 == 1 && $3==1) $$=1; else $$=-1; codegeneration();}
			| and_expression {if($1 == 1) $$=1; else $$=-1;};

and_expression 
			: and_expression AND_operator {push("&&");} unary_relation_expression  {if($1 == 1 && $3==1) $$=1; else $$=-1; codegeneration();}
			  |unary_relation_expression {if($1 == 1) $$=1; else $$=-1;} ;


unary_relation_expression 
			: exclamation_operator {push("!");} unary_relation_expression {if($2==1) $$=1; else $$=-1; codegeneration();} 
			| regular_expression {if($1 == 1) $$=1; else $$=-1;} ;

regular_expression 
			: regular_expression relational_operators sum_expression {if($1 == 1 && $3==1) $$=1; else $$=-1; codegeneration();}
			  | sum_expression {if($1 == 1) $$=1; else $$=-1;} ;
			
string_initilization
			: assignment_operator string_constant {insValue();} ;

array_initialization
			: assignment_operator '{' array_int_declarations '}';

array_int_declarations
			: integer_constant array_int_declarations_breakup;

array_int_declarations_breakup
			: ',' array_int_declarations 
			| ;

relational_operators 
			: greaterthan_assignment_operator {push(">=");} 
			| lessthan_assignment_operator {push("<=");} 
			| greaterthan_operator {push(">");}
			| lessthan_operator {push("<");}
			| equality_operator {push("==");}
			| inequality_operator {push("!=");} ;

term
			: term MULOP factor {if($1 == 1 && $3==1) $$=1; else $$=-1; codegeneration();}
			| factor {if($1 == 1) $$=1; else $$=-1;} ;

sum_expression 
			: sum_expression sum_operators term  {if($1 == 1 && $3==1) $$=1; else $$=-1; codegeneration();}
			| term {if($1 == 1) $$=1; else $$=-1;};

sum_operators 
			: add_operator {push("+");}
			| subtract_operator {push("-");} ;


mutable 
			: identifier {
				      push(curid);
				      if(check_id_is_function(curid))
				      {printf("Function name used as Identifier\n"); exit(8);}
			              if(!check_scope(curid))
			              {printf("%s\n",curid);printf("Undeclared\n");exit(0);} 
			              if(!check_array(curid))
			              {printf("%s\n",curid);printf("Array ID has no subscript\n");exit(0);}
			              if(get_type(curid,0)=='i' || get_type(curid,1)== 'c')
			              $$ = 1;
			              else
			              $$ = -1;
			              }
			| array_identifier {if(!check_scope(curid)){printf("%s\n",curid);printf("Undeclared\n");exit(0);}} '[' expression ']' 
			                   {if(get_type(curid,0)=='i' || get_type(curid,1)== 'c')
			              		$$ = 1;
			              		else
			              		$$ = -1;
			              		};

immutable 
			: '(' expression ')' {if($2==1) $$=1; else $$=-1;}
			| call {if($1==-1) $$=-1; else $$=1;}
			| constant {if($1==1) $$=1; else $$=-1;};


MULOP 
			: multiplication_operator {push("*");}| division_operator {push("/");} | modulo_operator {push("%");} ;

factor 
			: immutable {if($1 == 1) $$=1; else $$=-1;} 
			| mutable {if($1 == 1) $$=1; else $$=-1;} ;


arguments 
			: arguments_list | ;

arguments_list 
			: arguments_list ',' exp { call_params_count++; }  
			| exp { call_params_count++; };

call
			: identifier '('{

			             if(!checkfordeclaration(curid, "Function"))
			             { printf("Function not declared"); exit(0);} 
			             insertSTFunction(curid); 
						 strcpy(currfunccall,curid);
						 if(get_type(curid,0)=='i' || get_type(curid,1)== 'c')
						 {
			             $$ = 1;
			             }
			             else
			             $$ = -1;
                         call_params_count=0;
			             } 
			             arguments ')' 
						 { if(strcmp(currfunccall,"printf"))
							{ 
								if(getSTparamscount(currfunccall)!=call_params_count)
								{	
									yyerror("Number of arguments in function call doesn't match number of parameters");
									exit(8);
								}
							}
							callgeneration();
						 };

exp : identifier          {arggeneration(1);} 
     | integer_constant   {arggeneration(2);} 
     | string_constant    {arggeneration(3);} 
     | float_constant     {arggeneration(4);} 
     | character_constant {arggeneration(5);} ;

constant 
			: integer_constant 	{  insValue(); codegeneratingcon(); $$=1; } 
			| string_constant	{  insValue(); codegeneratingcon();$$=-1;} 
			| float_constant	{  insValue(); codegeneratingcon();} 
			| character_constant    {  insValue(); codegeneratingcon();$$=1; };

%%

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insertSTtype(char *,char *);
void insertSTvalue(char *, char *);
void incertCT(char *, char *);
void printSTable();
void printCTable();

struct stack
{
	char value[100];
	int labelvalue;
}s[100],label[100];


void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        swap((str+start), (str+end)); 
        start++; 
        end--; 
    } 
} 

char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    int isNegative = 0; 
  
   
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    if (num < 0 && base == 10) 
    { 
        isNegative = 1; 
        num = -num; 
    } 
  
   
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; 
  
   
    reverse(str, i); 
  
    return str; 
} 

void codegeneration()
{
	strcpy(temp,"t");
	char buffer[100];
	itoa(count,buffer,10);
	strcat(temp,buffer);
	printf("%s = %s %s %s\n",temp,s[top-2].value,s[top-1].value,s[top].value);
	top = top - 2;
	strcpy(s[top].value,temp);
	count++; 
}

void push(char *x)
{
	strcpy(s[++top].value,x);
}

void codegeneratingcon()
{
	strcpy(temp,"t");
	char buffer[100];
	itoa(count,buffer,10);
	strcat(temp,buffer);
	printf("%s = %s\n",temp,curval);
	push(temp);
	count++;
}

int isunary(char *s)
{
	if(strcmp(s, "--")==0 || strcmp(s, "++")==0)
	{
		return 1;
	}
	return 0;
}

void generatingunary()
{
	char temp1[100], temp2[100], temp3[100];
	strcpy(temp1, s[top].value);
	strcpy(temp2, s[top-1].value);

	if(isunary(temp1))
	{
		strcpy(temp3, temp1);
		strcpy(temp1, temp2);
		strcpy(temp2, temp3);
	}
	strcpy(temp, "t");
	char buffer[100];
	itoa(count, buffer, 10);
	strcat(temp, buffer);
	count++;

	if(strcmp(temp2,"--")==0)
	{
		printf("%s = %s - 1\n", temp, temp1);
		printf("%s = %s\n", temp1, temp);
	}

	if(strcmp(temp2,"++")==0)
	{
		printf("%s = %s + 1\n", temp, temp1);
		printf("%s = %s\n", temp1, temp);
	}

	top = top -2;
}

void codeassigning()
{
	printf("%s = %s\n",s[top-2].value,s[top].value);
	top = top - 2;
}


void functiongeneration()
{
	printf("Func BEGIN %s\n",currfunc);
}

void label1()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("IF not %s GoTo %s\n",s[top].value,temp);
	label[++ltop].labelvalue = lno++;
}

void label2()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("goto %s\n",temp);
	strcpy(temp,"L");
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop--;
	label[++ltop].labelvalue=lno++;
}

void label3()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop--;
}

void label4()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	label[++ltop].labelvalue = lno++;
}


void label5()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(label[ltop-1].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("goto %s:\n",temp);
	strcpy(temp,"L");
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop = ltop - 2;
}

void arggeneration(int i)
{
    if(i==1)
    {
	printf("refparam %s\n", curid);
	}
	else
	{
	printf("refparam %s\n", curval);
	}
}

void functiongenend()
{
	printf("Func END\n\n");
}

void callgeneration()
{
	printf("refparam result\n");
	push("result");
	printf("call %s, %d\n",currfunccall,call_params_count);
}



int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");
	yyparse();

	if(flag == 0)
	{
		printf(ANSI_COLOR_GREEN "STATUS: PARSING COMPLETE - VALID" ANSI_COLOR_RESET "\n");
		int i;
                for(i=0;i<190;i++)
                printf("=");
                printf("\n");
		printf("%85s" ANSI_COLOR_CYAN "SYMBOL TABLE" ANSI_COLOR_RESET "\n", " ");
                for(i=0;i<190;i++)
		printf("=");
                printf("\n\n\n");
		printSTable();
                printf("\n\n================================================================================\n");
		printf("%30s" ANSI_COLOR_CYAN "CONSTANT TABLE" ANSI_COLOR_RESET "\n", " ");
		printf("================================================================================\n\n\n");
		printCTable();
	}
}

void yyerror(char *s)
{
	printf(ANSI_COLOR_RED "%d %s %s\n", yylineno, s, yytext);
	flag=1;
	printf(ANSI_COLOR_RED "STATUS: PARSING FAILED - INVALID\n" ANSI_COLOR_RESET);
	exit(7);
}

void inserting()
{
	insertSTtype(curid,curtype);
}

void insValue()
{
	insertSTvalue(curid,curval);
}

int yywrap()
{
	return 1;
}
