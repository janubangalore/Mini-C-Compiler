%nonassoc NO_ELSE
%nonassoc ELSE
%left '<' '>' '=' GE_OP LE_OP EQ_OP NE_OP 
%left  '+'  '-'
%left  '*'  '/' '%'
%left  '|'
%left  '&'
%token IDENTIFIER STRING_CONSTANT CHAR_CONSTANT INT_CONSTANT FLOAT_CONSTANT SIZEOF
%token INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME DEF
%token CHAR CHAR_ SHORT INT INT_ LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token IF ELSE WHILE CONTINUE BREAK RETURN FOR STRUCT
%start start_state
%nonassoc UNARY
%glr-parser

%{
#include<string.h>
char type[100];
char temp[100];
char param_list[300];
char array_dim[100];
extern int yylineno;
extern int err;
extern int nestingLevel;
%}

%%

start_state
	: global_declaration
	| start_state global_declaration
	;

global_declaration
	: function_definition
	| struct_definition
	| declaration
	;

struct_definition		
	: STRUCT struct_name '{' struct_members_declaration '}' ';'	{    StructureInsert("", 0);	}
	;

struct_name
	: IDENTIFIER	{	StructureInsert($1, 1);	}
	;

struct_members_declaration
	: struct_members_declaration struct_members ';'
	| struct_members ';'
	;

struct_members
	: type_specifier IDENTIFIER	{	StructureMemberInsert($2, $1);	}
	;

function_definition		
	: declaration_specifiers declarator compound_statement		{		ScopeAndParamInsert(yylineno);	 }
	| declarator compound_statement		{		ScopeAndParamInsert(yylineno);	 }
	;

fundamental_exp
	: IDENTIFIER		{	if(!(strcmp($1,"printf") == 0 || strcmp($1,"printf") == 0)){
						int flag;
						flag = CheckIdentifierReuse($1);	
						if(flag == 0){
							err++;
							yyerror("Variable has to be declared first before use");
						}
					}
				}
	| STRING_CONSTANT		{ ConstantInsert($1, "string"); }
	| CHAR_CONSTANT     { ConstantInsert($1, "char"); }
	| FLOAT_CONSTANT	  { ConstantInsert($1, "float"); }
	| INT_CONSTANT			{ ConstantInsert($1, "int"); }
	| '(' expression ')'
	;


secondary_exp
	: fundamental_exp
	| secondary_exp '[' expression ']'
	| secondary_exp '(' ')'
	| secondary_exp '(' arg_list ')'	
	| secondary_exp '.' IDENTIFIER
	| secondary_exp INC_OP
	| secondary_exp DEC_OP
	;

arg_list
	: assignment_expression
	| arg_list ',' assignment_expression
	;

unary_expression
	: secondary_exp
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator typecast_exp
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

typecast_exp
	: unary_expression
	| '(' type_name ')' typecast_exp
	;

multdivmod_exp
	: typecast_exp
	| multdivmod_exp '*' typecast_exp
	| multdivmod_exp '/' typecast_exp
	| multdivmod_exp '%' typecast_exp
	;

addsub_exp
	: multdivmod_exp
	| addsub_exp '+' multdivmod_exp
	| addsub_exp '-' multdivmod_exp
	;

shift_exp
	: addsub_exp
	| shift_exp LEFT_OP addsub_exp
	| shift_exp RIGHT_OP addsub_exp
	;

relational_expression
	: shift_exp
	| relational_expression '<' shift_exp
	| relational_expression '>' shift_exp
	| relational_expression LE_OP shift_exp
	| relational_expression GE_OP shift_exp
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exor_expression
	: and_expression
	| exor_expression '^' and_expression
	;

unary_or_expression
	: exor_expression
	| unary_or_expression '|' exor_expression
	;

logical_and_expression
	: unary_or_expression
	| logical_and_expression AND_OP unary_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	| error
	;

declaration_specifiers
	: type_specifier	{ strcpy(type, $1); }
	| type_specifier declaration_specifiers	{ strcpy(temp, $1); strcat(temp, " "); strcat(temp, type); strcpy(type, temp); }
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator 
	| declarator '=' init
	;

type_specifier
	: VOID			{ $$ = "void"; }
	| CHAR			{ $$ = "char"; }
	| CHAR_			{ $$ = "char*"; }
	| SHORT			{ $$ = "short"; }
	| INT			{ $$ = "int"; }
	| INT_			{ $$ = "int*"; }
	| LONG			{ $$ = "long"; }
	| FLOAT			{ $$ = "float"; }
	| SIGNED		{ $$ = "signed"; }
	| UNSIGNED		{ $$ = "unsigned"; }
	;

type_specifier_list
	: type_specifier type_specifier_list
	| type_specifier
	;

declarator
	: direct_declarator
	;

direct_declarator
	: IDENTIFIER								{  SymbolInsert($1, type); }
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'		{	strcpy(array_dim,$3);	
									array_dim[strlen(array_dim)-1]='\0';	}
	| direct_declarator '[' ']'	{	strcpy(array_dim,"0");	}
	| direct_declarator '(' parameter_type_list ')'		
	| direct_declarator '(' identifier_list ')'			
	| direct_declarator '(' ')'
	;


parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration	
	| parameter_list ',' parameter_declaration	
	;

parameter_declaration
	: declaration_specifiers declarator	{ 
		strcat(param_list,$1);
		strcat(param_list," ");
		strcpy(temp,$2);
		temp[strlen(temp)-1]='\0';
		strcat(param_list,temp);
		strcat(param_list,", ");
		}	
	| declaration_specifiers abstract_declarator
	| declaration_specifiers 
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: type_specifier_list
	| type_specifier_list abstract_declarator
	;

abstract_declarator
	: direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

init
	: assignment_expression		{	strcpy($$,$1);		} 
	| '{' init_list '}'
	| '{' init_list ',' '}'
	;

init_list
	: init
	| init_list ',' init
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	| '{' declaration_list statement_list declaration_list statement_list '}'
	| '{' declaration_list statement_list declaration_list '}'
	| '{' statement_list declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement %prec NO_ELSE
	| IF '(' expression ')' statement ELSE statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	: FOR '(' expression ';' expression ';' expression ')'
	;

jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

%%
#include"lex.yy.c"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RESET	"\x1b[0m"

struct Symbol
{
	char token[100];	//Name of the identifier
	char tokenType[100];	//Type of identifier
	int boundary_begin;	//Beginning of scope
	int boundary_end;	//End of scope
	int nesting_level;		//Degree of Nesting
	char paramList[200];	//Parameter list
	int attributeNo;	//Attribute number in list
	char array_dimension[100];

}SymbolTable[100000]; 

struct Constant
{
	char token[100];	//Name of constant;
	char dataType[100];	//Datatype of constant
	int lineNo;		//Line number in which it is detected
	int attributeNo;	//Attribute number in list

}ConstantTable[100000];

struct StructureMembers{
	char MemberName[100];	// Member name
	char MemberType[100];	// Member type
	int lineNo;		//Line number in which it is detected
	struct StructureMembers *next;
};

struct Structure
{
	char name[100];		//Name of struct
	int boundary_begin;	//Beginning of scope
	int boundary_end;	//End of scope
	struct StructureMembers *stm;

}StructureTable[100000] = {"", 0, 0, NULL};

int s=0;	// Number of symbols in the symbol table
int c=0;	// Number of constant in the constant table
int st=0;       // Number of structures declared

// Function to insert value in Constant Table
void ConstantInsert(char* tokenName, char* datatype)
{
	strcpy(ConstantTable[c].token, tokenName);
	strcpy(ConstantTable[c].dataType, datatype);
	ConstantTable[c].lineNo = yylineno;
	ConstantTable[c].attributeNo = c+1;
	c++;
}

// Function to print values in Constant Table
void showConstantTable()
{
	printf("\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* CONSTANT TABLE *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
	printf("Attribute Number\tLine number\t DataType\tConstant value\n\n");
	int itr;
	for(itr=0;itr<c;itr++){
		printf("\t%-17d %-17d %-18s %-50s\n",ConstantTable[itr].attributeNo,ConstantTable[itr].lineNo,ConstantTable[itr].dataType,ConstantTable[itr].token);
	}
}

// Function to insert value in Symbol Table
void SymbolInsert(char* tokenName, char* tokenType)
{
	int itr;
	for(itr=0;itr<s;itr++){
		if(strcmp(SymbolTable[itr].token,tokenName) == 0){
			if(SymbolTable[itr].boundary_end == -1 && SymbolTable[itr].nesting_level >= nestingLevel){
				err++;
				yyerror("Redeclaration of variable");
				return;
			}
		}
	}
	strcpy(SymbolTable[s].token, tokenName);
	if(tokenType[strlen(tokenType)-1]=='*'){
		strcpy(tokenType,"pointer");
	}
	strcpy(SymbolTable[s].tokenType, tokenType);
	SymbolTable[s].boundary_begin = yylineno;
	SymbolTable[s].boundary_end = -1;
	SymbolTable[s].nesting_level = nestingLevel;
	SymbolTable[s].attributeNo = s+1;
	strcpy(SymbolTable[s].paramList, "N/A");
	strcpy(SymbolTable[s-1].array_dimension,"N/A");
	if(strcmp(array_dim, "")!=0){
		strcpy(SymbolTable[s-1].array_dimension, array_dim);
		if(strcmp(SymbolTable[s-1].tokenType,"char")==0)		strcpy(SymbolTable[s-1].tokenType,"string");
		if(strcmp(SymbolTable[s-1].tokenType,"pointer")==0)		strcpy(SymbolTable[s-1].tokenType,"array of pointers");
		else				strcpy(SymbolTable[s-1].tokenType,"array");
	}
	strcpy(array_dim,"");
	s++;
}


//Function to add Parameter List
int ScopeAndParamInsert(int lineNo)
{

	int itr, insert = 1;
	for(itr=0;itr<s;itr++){
		if(SymbolTable[itr].boundary_end == -1){
			if(insert==1){
				if(strlen(param_list) > 2 && param_list[strlen(param_list)-2] == ',')	param_list[strlen(param_list)-2] = '\0';
				if(strlen(param_list)==0)	strcpy(param_list,"Empty");
				strcpy(SymbolTable[itr].paramList,param_list);
				insert = 0;
				strcpy(param_list,"");
				strcpy(SymbolTable[itr].tokenType,"function");
			}
			SymbolTable[itr].boundary_end = lineNo;
		}
	}
}

// Function to print values in Symbol Table
void showSymbolTable()
{
	strcpy(SymbolTable[s-1].array_dimension,"N/A");
	if(strcmp(array_dim, "")!=0){
		strcpy(SymbolTable[s-1].array_dimension, array_dim);
		if(strcmp(SymbolTable[s-1].tokenType,"char")==0)		strcpy(SymbolTable[s-1].tokenType,"string");
		if(strcmp(SymbolTable[s-1].tokenType,"pointer")==0)		strcpy(SymbolTable[s-1].tokenType,"array of pointers");
		else				strcpy(SymbolTable[s-1].tokenType,"array");
	}
	printf("\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* SYMBOL TABLE *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
	printf("Attribute Number\tBoundary(line no)  Nesting level  Identifier Name\tDataType         \tArray dimension\t\tParameter List\n\n");
	int itr;
	for(itr=0;itr<s;itr++){
		if(err == 1 && SymbolTable[itr].boundary_end == -1){
			SymbolTable[itr].boundary_end = yylineno;
		}
		printf("\t%-20d %-3d -  %-13d %-10d  %-15s   %-24s   %-23s %-40s\n",SymbolTable[itr].attributeNo,SymbolTable[itr].boundary_begin,SymbolTable[itr].boundary_end,SymbolTable[itr].nesting_level,SymbolTable[itr].token,SymbolTable[itr].tokenType,SymbolTable[itr].array_dimension,SymbolTable[itr].paramList);
	}
}

// Function to insert struct in Structure Table
void StructureInsert(char* structName, int flag){
	if(flag == 0){
		StructureTable[st].boundary_end = yylineno;
		st++;
		return ;
	}
	int itr;
	for(itr = 0; itr < st; itr++){
		if(strcmp(StructureTable[itr].name, structName)==0){
			err++;
			yyerror("Redeclaration of structure\n");
			return;
		}
	}
	strcpy(StructureTable[st].name, structName);
	StructureTable[st].boundary_begin = yylineno;
}

// Function to insert structure members in Structure Table
void StructureMemberInsert(char* name, char* type){
	struct StructureMembers *m = malloc(sizeof(struct StructureMembers));
	strcpy(m->MemberName, name);
	strcpy(m->MemberType, type);
	m->lineNo = yylineno;
	m->next = NULL;
	struct StructureMembers *ptr = StructureTable[st].stm;
	if(ptr == NULL){
		StructureTable[st].stm = m;
		return ;
	}
	if(strcmp(ptr->MemberName, name)==0){
		err++;
		yyerror("Redeclaration of member of structure member\n");
		return;
	}
	while(ptr->next != NULL){
		if(strcmp((ptr->next)->MemberName, name)==0){
			err++;
			yyerror("Redeclaration of member of structure member\n");
			return;
		}
		ptr = ptr->next;
	}
	ptr->next = m;
}

// Function to print values in Structure Table
void showStructureTable()
{
	printf("\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* STRUCTURE TABLE *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
	printf("Structure name\t   Boundary(line no)\t  Member name\t  Member type\t\tLine number\n\n");
	int itr;
	struct StructureMembers *ptr;
	for(itr = 0; itr < st; itr++){
		ptr = StructureTable[itr].stm;
		while(ptr != NULL){
			printf("\t%-15s %-3d -  %-13d %-18s %-18s %-3d\n",StructureTable[itr].name,StructureTable[itr].boundary_begin,StructureTable[itr].boundary_end,ptr->MemberName,ptr->MemberType,ptr->lineNo);
			ptr = ptr->next;
		}

	}
}

//Function to check if an identifer is in scope or not
int CheckIdentifierReuse(char* tokenName)
{

	int itr;
	for(itr=0;itr<st;itr++){
		if(strcmp(StructureTable[itr].name,tokenName) == 0){
			err++;
			yyerror("A structure with same name is already declared");
			return 0;
		}
	}	
	for(itr=0;itr<s;itr++){
		if(strcmp(SymbolTable[itr].token,tokenName) == 0){
			if(SymbolTable[itr].boundary_end == -1 && SymbolTable[itr].nesting_level <= nestingLevel){
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	yyparse();
	if(err==0)
		printf(ANSI_COLOR_GREEN "Status: PARSING COMPLETE" ANSI_COLOR_RESET "\n");
	else
		printf(ANSI_COLOR_RED "Status: PARSING FAILED" ANSI_COLOR_RESET "\n");
	fclose(yyin);

	showSymbolTable();
	showConstantTable();
	showStructureTable();
	return 0;
}
extern char *yytext;
yyerror(char *s)
{
	err=1;
	printf(ANSI_COLOR_YELLOW "\nLine %d : %s\n\n" ANSI_COLOR_RESET, (yylineno), s);
	printf(ANSI_COLOR_RED "Status: PARSING FAILED" ANSI_COLOR_RESET "\n");
	showSymbolTable();
	showConstantTable();
	showStructureTable();
	exit(0);
}