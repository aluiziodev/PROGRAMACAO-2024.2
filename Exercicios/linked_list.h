#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
	int val;
	struct Node * prox;
};

typedef struct Node Node;

void mostra_lista(char * nome, Node * p){
	printf("%s = [", nome);
	Node * ptr = p;
	while( ptr != NULL){
		printf("%d ", ptr->val);
		ptr = ptr->prox;
	}
	printf("]\n");
}


int soma_lista(Node * p){
	if(p==NULL)
		return 0;
	else
		return (p->val) + soma_lista(p->prox);
}



Node *inverte_lista(Node *p) {
    // Caso base: lista vazia ou lista unitária
    if (p == NULL || p->prox == NULL)
        return p;

    // Inverte a sublista a partir do segundo elemento
    Node *nova_cabeca = inverte_lista(p->prox);

    // Ajusta o próximo nó do atual para apontar para ele mesmo
    p->prox->prox = p;

    // Remove o vínculo do próximo do nó atual
    p->prox = NULL;

    // Retorna a nova cabeça da lista invertida
    return nova_cabeca;
}
	

Node * criar_lista_aleatoria(int n){
	if(n==0) return NULL;
	else {
		Node * head;		   
		head = (Node *)malloc(sizeof(Node));
		head->val = rand() % 100 + 1;
		head->prox = criar_lista_aleatoria(n-1);
		return head;
	}
}


int conta_pares(Node * head){
	if(head == NULL)
		return 0;
	else{
		if(head->val % 2 == 0){
			return 1 + conta_pares(head->prox);
		}else{
			return conta_pares(head->prox);
		}
	}
}

Node * remove_pares(Node * head){
	if(head == NULL)
		return NULL;
	else{
		if(head->val % 2 == 0){
			Node * temp = remove_pares(head->prox);
			free(head);
			return temp;
		}else{
			head->prox = remove_pares(head->prox);
			return head;
		}
	}
}


Node * remove_duplicados(Node * head){
	//lista vazia
	if(head==NULL) return head;
	//lista de tamanho 1
	if(head->prox ==NULL) return head;
	
	//remove head
	if(head->val == head->prox->val){
		Node * temp = head->prox;
		free(head);
		return remove_duplicados(temp);
	}else{
		head->prox = remove_duplicados(head->prox);
		return head;
	}
	
}


Node * criar_lista_vetor(int v[], int n){
	if(n==0){
		return NULL;
	}else{
		Node * head;
		head = (Node *)malloc(sizeof(Node));
		head->val = v[0];
		head->prox = criar_lista_vetor(++v, n-1);
		return head;
	}
}


Node * criar_lista_vetor2(int v[], int n){
	Node * head = NULL;
	for(int i = n-1; i >= 0; i--){
		Node * p = (Node *)malloc(sizeof(Node));
		p->val = v[i];
		p->prox = head;
		head = p;
	}
	return head;
}

int iguais(Node * head1, Node * head2){
	if(head1 == NULL && head2 == NULL) return 1;
	if(head1 == NULL && head2 != NULL) return 0;
	if(head1 != NULL && head2 == NULL) return 0;
	if(head1->val != head2->val) return 0;
	else return iguais(head1->prox, head2->prox);
}

int ordenado(Node * head){
	//lista vazia
	if(head == NULL) return 1;
	//lista de tamanho 1
	if(head->prox == NULL) return 1;	
	if(head->val > head->prox->val) return 0;
	else return ordenado(head->prox);
}

Node * primeiro_no_fim(Node * primeiro){
	//primeiro já é o ultimo
	if( primeiro == NULL || primeiro->prox == NULL)
		return primeiro;
	//guarda o segundo elemento
	Node * segundo = primeiro->prox;
	//Liga o primeiro com o terceiro
	primeiro->prox = segundo->prox;
	//O próximo do segundo será a cabeça da lista
	//primeiro_no_fim(primeiro)
	segundo->prox = primeiro_no_fim(primeiro);
	//Segundo será o primeiro
	return segundo;
}

Node * maior_para_fim(Node *primeiro){
	//maior já está no fim
	if( primeiro == NULL || primeiro->prox == NULL)
		return primeiro;
	
	//guarda o segundo elemento
	Node * segundo = primeiro->prox;
	
	//primeiro é maior que o segundo	
	if(primeiro->val > segundo->val){
		//primeiro aponta para o terceiro
		primeiro->prox = segundo->prox;
		//O próximo do segundo será 
		//a cabeça da lista maior_para_fim(primeiro)
		segundo->prox = maior_para_fim(primeiro);
		return segundo;
	}else{
		primeiro->prox = maior_para_fim(segundo);
		return primeiro;
	}
}

Node * ordena_lista(Node * primeiro){
	//lista está ordenada
	if( primeiro == NULL || primeiro->prox == NULL)
		return primeiro;
	//guarda o segundo elemento
	Node * segundo = primeiro->prox;
	//ordena lista a partir do segundo
	primeiro->prox = ordena_lista(segundo);
	//apenas um elemento está fora do lugar
	//a função maior para o fim coloca
	//o primeiro na posicao correta
	return maior_para_fim(primeiro);
}

#endif 


