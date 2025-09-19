#ifndef PILHA_H
#define PILHA_H

#define SIZE 100

typedef struct
{
	int elem[SIZE];
	int topo;

} Pilha;

void inicializa_pilha(Pilha * p){
	p->topo = -1;
}

void push(Pilha* p, int n){
	if (p->topo>= SIZE-1){
		printf( "PIlha Cheia!\n");
		exit(EXIT_FAILURE);
	}
	else
		p->elem[++(p->topo)] = n;
}

int pop(Pilha* p){
	if (p->topo==-1){
		printf( "PIlha Vazia!\n");
		exit(EXIT_FAILURE);
	}
	else{
		return p->elem[(p->topo)--];
	}
}


int top(Pilha* p){
	if (p->topo==-1){
		printf( "PIlha Vazia!\n");
		exit(EXIT_FAILURE);
	}
	else{
		return p->elem[(p->topo)];
	}
}

int verifica_vazia(Pilha* p){
	return (p->topo == -1);
}

void mostra_pilha(Pilha* p){
	for (int i =0; i<= p->topo; i++)
		printf("%d", p->elem[i]);
	printf("\n");
}


void mostra_pilha_char(Pilha *p){
    for(int i = 0; i <= p->topo; i++)
        printf("%c ", p->elem[i]);
    printf("$\n");
}







#endif
