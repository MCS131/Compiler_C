/*****  koubun.c  ******************************************/

#include "global_0.h"

void stmt();
void assign(); /**/
void expr();		/* E := T{(+|-)T} */
void term();		/* T := F{(*|/|DIV|MOD)F} */
void factor();		/* F := i|n|(E) */
int match(int t);	/* check token with syantax element and get next token */
void skiptoken(int);

int lookahead;		/* next token */

/*** parse and translates expression list into postfix notation ***/
void parse()	/*** P := E;{E;} ***/
{
	lookahead = lexan();		/* get token from lexical analyzer */
	while (lookahead != DONE){
		stmt(); 
		match(';');
	}
	gencode(DONE, NONE);
	return;
}

void stmt()
{
	assign();
	return;
}

void assign()
{
	int tval = tokenval;
	if(match(ID) == 1){
		error("syntax error: identifier is expected");
		skiptoken('A');
		return;
	}
	gencode(LVALUE, tval);
	if(match('=') == 1){
		error("syntax error: '=' is expected");
		skiptoken('A');
		return;
	}
	expr();
	gencode(STORE, NONE);
	return;
}

void expr()	/*** E := T{(+|-)T} ***/
{
	int t;
	/* parsing term */
	if(lookahead == '-'){
		match('-');
		term();
		gencode(MINUS, NONE);
	}

	else{
		term();
	}		

	while(1)
		switch(lookahead){
			case '+': case '-':
				t = lookahead;
				match(lookahead); term(); gencode(t, NONE);
				continue;
			case ';': case')':
				return;
			default:
			error("system error: ')' or ';' is expected");
		  skiptoken('E');
				return;
	}
}


void term()	/*** T := F{(*|/|DIV|MOD)F} ***/
{
	int t;
	/* parsing factor */
	factor();
	while(1)
		switch(lookahead){
			case '*': case '/': case DIV: case MOD:
				t = lookahead;
				match(lookahead); factor(); gencode(t, NONE);
				continue;
				case '+': case'-': case';': case')':
				return;
			default:
			error("syntax error: '+', '-', '*' '/', 'DIV', 'MOD', ')', ';' or operator is expected");
			skiptoken('T');
				return;
		}
}

void factor()	/*** F := i|n|(E) ***/
{
	switch(lookahead){
		case ID:
			gencode(RVALUE, tokenval); match(ID); break;
		case NUM:
			gencode(NUM, tokenval); match(NUM); break;
		case '(':
			match('('); expr(); 
			if(match(')')==1){
				error("syntax error: ')' is expected)");
				skiptoken('F');
				return;
			}
			break;
		default:
			error("syntax error: identifier, number or '(' is expected");
				skiptoken('F');
				return;
	}
}

int match(int t)	/*** check token with syantax element and get next token ***/
{
	if(lookahead == t) {
		lookahead = lexan();
		return 0;
	}
	else {
		return 1;
	}
}

 // (for KADAI 22)
 void skiptoken(int n)	/*** skip tokens until follow(N) ***/
 {
 	int l;
 	l = lookahead;
 	switch(n) {
 		case 'S': case 'A':
 			while(l!=';' && l!=DONE) l = lexan();
 			break;		
 		case 'E': 
			while(l!=';' && l!=')' && l!=DONE) l = lexan();
 			break;		
 		case 'T': 
 			while(l!=';' && l!=')' && l!='+' && l!='-' && l!=DONE) l = lexan();
 			break;		
 		case 'F': 
 			while(l!=';' && l!=')' && l!='+' && l!='-' && l!='/' && l!= '*' && l!=DIV && l!=MOD && l!=DONE) l = lexan();
 			break;		
 		default:
 			error("illegal nonterminal symbol in skiptoken()"); exit(1);
 	}
 	lookahead = l;
 	return;
}