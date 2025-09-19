#include "pilha.h"

int balanceado(char s[]){
	Pilha * p;
	inicializa_pilha(p);
	int size = strlen(s);
	for (int i=0; i<size;i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{' ){
			push(p, s[i]);
		}
		else{
			if (p->topo == -1)
				return 0;
			else{
				if (s[i] == ')'){
					if (top(p) == '(')
						pop(p);
					else
						return 0;
				}
				else if (s[i] == ']'){
					if (top(p) == '[')
						pop(p);
					else
						return 0;
				}
				else{
					if (top(p) == '{')
						pop(p);
					else
						return 0;
				}
			}

		}
	}
	return 1;
}

void remove_duplicados_adjacentes(char s[]){
	Pilha * p;
	inicializa_pilha(p);
	int n = strlen(s);
	for (int i  = 0; i<n; i++){
		if((p->topo = -1) || (s[i]!=top(p))){
			push(p, s[i]);
		}
		else
			pop(p);
	}
	int j = 0;
	while(p->topo!= -1){
		s[j] = pop(p);
		j++;
	}
	s[j] = '\0';


}

void stacksort(int v[], int n){
	Pilha p;
	inicializa_pilha(&p);
	Pilha aux;
	inicializa_pilha(&aux);
	for (int i = 0; i<n ; i++){
		if (verifica_vazia(&p) || top(&p)>=v[i]){
			push(&p, v[i]);
		}
		else{
			while(!verifica_vazia(&p) && top(&p)<v[i])
				push(&aux, pop(&p));
			push(&p, v[i]);
			while(!verifica_vazia(&aux))
				push(&p, pop(&aux));
		}
	}
	for (int i = 0; i<n ; i++){
		v[i] = pop(&p);
	}
}

