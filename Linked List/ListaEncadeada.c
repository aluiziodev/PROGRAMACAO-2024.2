#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedList.h"

lista * cria_lista(int v[], int n){
	lista * l = inicializa_lista();
	no * m;
	for (int i = 0; i < n; ++i){
		m = cria_no(v[i]);
		insere_lista(l, m);
	}
	return l;
}

int soma_lista(lista * l){
	int soma = 0;
	no * aux = l->head;
	while(aux!=NULL){
		soma = soma + aux->val;
		aux = aux->next;
	}
	return soma;
}



int compara_listalinked(lista * l, lista * k){
	no * n = l->head;
	no * m = k->head;
	while(n!= NULL && m!= NULL){
		if(n->val != m->val)
			return 0;
		n = n->next;
		m = m->next;
	}
	if (n==NULL && m==NULL)
		return 1;
	else
		return 0;
}

void move_maior_fim(lista * l){
	no * n = l->head;
	no * k = n;
	no * i = NULL;
	while(n != NULL && n->next!=NULL){
		if(k->val<n->next->val){
			i = n;
			k = n->next;
		}
		n = n->next; 
	}
	if (n != NULL && n->val!=k->val){
		if (i==NULL)
			l->head = k->next; 
		else
			i->next = i->next->next;
		n->next = k;
		k->next = NULL;
	}


}

void remove_repetidos(lista * l){
	no * n = l->head;
	while(l!=NULL && n != NULL && n->next != NULL){
		no * aux = n->next;
		no * ant = n;
		while(aux != NULL){
			if(aux->val == n->val)
				ant->next = ant->next->next;
			else
				ant = aux;
			aux = aux->next;
		}
		n = n->next;

	}
}
void remove_repetidos_aux(no * head, no * ant, no * aux){
	if (aux != NULL){
		if(head->val == aux->val){
			ant->next = aux->next;
			remove_repetidos_aux(head, ant, ant->next);
		}
		else
			remove_repetidos_aux(head, aux, aux->next);
	}
}
void remove_repetidos_rec(lista * l){
	no * n = l->head;
	while(l!=NULL && n != NULL && n->next != NULL){
		no * aux = n->next;
		no * ant = n;
		remove_repetidos_aux(n, ant, aux);
		n = n->next;
	}
}
void remove_todos(lista * l, int x){
	no * n = l->head;
	no * ant = NULL;
	while (n != NULL){
		if(n->val == x){
			if (ant==NULL)
				l->head = n->next;
			else
				ant->next = ant->next->next;
		}
		else
			ant = n;
		n = n->next;
	}
}

int mais_frequente(lista * l){
	no * n = l->head;
	int total = 0;
	int key = 0;
	while(n!= NULL && n->next != NULL){
		no * aux = n;
		int qtd = 0;
		while(aux!= NULL){
			if(aux->val == n->val)
				qtd++;
			aux = aux->next;
		}
		if(total<qtd){
			total = qtd;
			key = n->val;
		}
		n = n->next;
	}
	return key;
}

