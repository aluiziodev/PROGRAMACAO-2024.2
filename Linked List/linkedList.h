#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no 
{
	int val;
	struct no* next;
} no;


typedef struct lista
{
	no* head;
} lista;

lista * inicializa_lista(){
	lista * l = malloc(sizeof(lista));
	l->head = NULL;
	return l;
}

no * cria_no(int v){
	no * n = malloc(sizeof(no));
	n->val = v;
	n->next = NULL;
	return n;
}







#endif