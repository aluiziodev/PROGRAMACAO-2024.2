#ifndef LEXER_H
#define LEXER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

enum classe{
	AP = 0,
	FP = 1,
	OP = 2,
	MUL =  3,
	DIV  = 4,
	PLUS = 5,
	SUB = 6,
};


typedef struct token {
	enum classe categoria;
	char valor[5];
} token;



int calcula(enum classe c, int n1, int n2){
	
	if(c == PLUS) 
		return n1+n2;
	if(c == MUL) 
		return n1*n2;
	if(c == SUB)
		return n1-n2;
	if(c == DIV) 
		return n1/n2;
	return -1;
}

typedef struct lista_tokens{
	token tokens[MAX_TOKENS];
	int qtd_tokens;
} lista_tokens;


enum classe get_categoria(lista_tokens * l, int i){
    return l->tokens[i].categoria;
}

char * get_valor(lista_tokens * l, int i){
    return l->tokens[i].valor;
}

void adicionar_token(lista_tokens * l, enum classe categoria, const char *valor) {
    l->tokens[l->qtd_tokens].categoria = categoria;
    strcpy(l->tokens[l->qtd_tokens].valor, valor);
    l->qtd_tokens++;
}

lista_tokens analisador_lexico(const char *expr) {
    lista_tokens l;
    l.qtd_tokens = 0;

    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++; // Ignorar espaços em branco
            continue;
        }

        if (isdigit(expr[i])) {
            // Capturar números inteiros
            char numero[5] = {0};
            int j = 0;
            while (isdigit(expr[i])) {
                numero[j++] = expr[i++];
            }
            numero[j] = '\0';
            adicionar_token(&l, OP, numero);
        } else {
            // Capturar operadores e parênteses
            switch (expr[i]) {
                case '(': adicionar_token(&l, AP, "("); break;
                case ')': adicionar_token(&l, FP, ")"); break;
                case '+': 
                adicionar_token(&l, PLUS, "+"); break;
                case '-':
                if( l.qtd_tokens > 0 && 
                    l.tokens[l.qtd_tokens-1].categoria == FP ||
                    l.tokens[l.qtd_tokens-1].categoria == OP 
                  ){
                    adicionar_token(&l, SUB, "-"); 
                   }
                else {
                    char numero[5] = {0};
                    int j = 0;
                    numero[j++] = expr[i++];
                    while (isdigit(expr[i])) {
                        numero[j++] = expr[i++];
                    }
                    numero[j] = '\0';
                    adicionar_token(&l, OP, numero);
                    i--;

                }
                break;

                case '*': adicionar_token(&l, MUL, "*"); break;
                case '/': adicionar_token(&l, DIV, "/"); break;
                default:
                    printf("Erro: caractere inválido '%c'\n", expr[i]);
                    return l;
            }
            i++;
        }
    }
    return l;
}

void mostra_token(token tok){
    switch(tok.categoria){
			case DIV: printf("DIV /\n"); break;
			case SUB: printf("SUB - \n"); break;
			case PLUS: printf("PLUS + \n"); break;
			case MUL: printf("MUL *\n"); break;
			case AP: printf("AP (\n"); break;
			case FP: printf("FP )\n"); break;
			case OP: printf("OP  %s\n", tok.valor); break;
	}
}

void mostra_lista(lista_tokens * l){
	for(int i = 0; i < l->qtd_tokens; i++){
		mostra_token(l->tokens[i]);
	}
	
}

#endif