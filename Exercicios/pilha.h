#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100


typedef struct {
    int elem[STACKSIZE];
    int topo;
} Pilha;

void inicializar_pilha(Pilha* p) {
    p->topo = -1;
}

void push(Pilha* p, int elemento){
    if (p->topo < STACKSIZE - 1) {
        p->elem[++(p->topo)] = elemento;
    }else{
        fprintf(stderr, "Pilha Cheia\n");
        exit(EXIT_FAILURE); // Encerrar com código de erro
    }
    
}

int pop(Pilha* p) {
    if (p->topo >= 0) {
        return p->elem[(p->topo)--];
    }else{
        fprintf(stderr, "Pilha Vazia\n");
        exit(EXIT_FAILURE); // Encerrar com código de erro
    }    
}

int top(Pilha* p) {
    if (p->topo >= 0) {
        return p->elem[(p->topo)];
    }else{
        fprintf(stderr, "Pilha Vazia\n");
        exit(EXIT_FAILURE); // Encerrar com código de erro
    }    
}


int is_empty(Pilha* p) {
    return p->topo == -1;
}


void mostra_pilha(Pilha *p){
    for(int i = 0; i <= p->topo; i++)
        printf("%d ", p->elem[i]);
    printf("$\n");
}


void mostra_pilha_char(Pilha *p){
    for(int i = 0; i <= p->topo; i++)
        printf("%c ", p->elem[i]);
    printf("$\n");
}
#endif 
