#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100
// ESTRUTURAS:


typedef struct vetor {
	int * elem;
	int size;
} vetor;

typedef struct node_tree {
	int chave;
	int valor;
	int num_nodes;
	int altura;
	int num_folhas;
	int nivel;
	int balanceado;
	struct node_tree * pai;
	struct node_tree * mais_esq;
	struct node_tree * esq;
	struct node_tree * dir;
} node_tree;

typedef struct tree{
	node_tree * root;
} tree;

typedef struct
{
	int elem[SIZE];
	int topo;

} Pilha;

typedef struct no 
{
	int val;
	struct no* next;
} no;

typedef struct nomin 
{
	int val;
	int min;
	int mult;
	struct nomin* next;

} nomin;

typedef struct lista
{
	no* head;
} lista;


typedef struct lista2
{
	no* head;
	int sum;
} lista2;

typedef struct lista3
{
	no * head;
 	no * end;
} lista3;

typedef struct pilhalink
{	
	no * head;
	int size;

}pilhalink;

typedef struct pilhamin
{	
	nomin * head;

}pilhamin;
// FUNÇOES COMPLEMENTARES:

int max(int a, int b){
	return a>b?a:b;
}

node_tree * cria_no_tree(int x){
	node_tree * t = malloc(sizeof(node_tree));
	t->chave = x;
	t->valor = 1;
	t->num_nodes = -1;
	t->altura = -1;
	t->num_folhas = -1;
	t->nivel = -1;
	t->balanceado = -1;
	t->pai = NULL;
	t->mais_esq = NULL;
	t->esq = NULL;
	t->dir = NULL;
	return t;
}

node_tree * insere_node_tree(node_tree * root, int x){
	if (root == NULL){
		root = cria_no_tree(x);
		return root;
	}
	else if (root->chave == x){
		root->valor++;
		return root;
	}
	else{
		if(root->chave>x)
			root->esq = insere_node_tree(root->esq, x);
		else
			root->dir = insere_node_tree(root->dir, x);
		return root;
	}
}

void insereBST(tree * t, int x){
	t->root = insere_node_tree(t->root, x);
}



lista * inicializa_lista(){
	lista * l = malloc(sizeof(lista));
	l->head = NULL;
	return l;
}

lista2 * inicializa_lista2(){
	lista2 * l = malloc(sizeof(lista2));
	l->head = NULL;
	l->sum = 0;
	return l;
}

lista3 * inicializa_lista3(){
	lista3 * l = malloc(sizeof(lista3));
	l->head = NULL;
	l->end = l->head;
	return l;
}

no * cria_no(int v){
	no * n = malloc(sizeof(no));
	n->val = v;
	n->next = NULL;
	return n;
}


nomin * cria_nomin(int v){
	nomin * n = malloc(sizeof(nomin));
	n->val = v;
	n->min = v;
	n->mult = v;
	n->next = NULL;
	return n;
}


void insere_lista(lista * l, no * n){
	if (l->head == NULL)
		l->head = n;
	else{
		no * aux = l->head;
		while(aux->next!=NULL)
			aux = aux->next;
		aux->next = n;
	} 
}

lista * cria_lista(int v[], int n){
	lista * l = inicializa_lista();
	no * m;
	for (int i = 0; i < n; ++i){
		m = cria_no(v[i]);
		insere_lista(l, m);
	}
	return l;
}

void insere_lista2(lista2 * l, no * n){
	if (l->head == NULL){
		l->head = n;
		l->sum = n->val;
	}

	else{
		no * aux = l->head;
		while(aux->next!=NULL)
			aux = aux->next;
		aux->next = n;
		l->sum = l->sum + n->val;
	} 
}

void insere_lista3(lista3 * l, no * n){
	if (l->head == NULL){
		l->head = n;
		l->end = l->head;
	}
	else{
		l->end->next = n;
		l->end = n;
	} 
}

no * preenche_lista( int v[], int n){
	if(n==0){
		return NULL;
	}
	else{
		no * m= cria_no(v[n-1]);
		m->next = preenche_lista(v, n-1);
		return m;
	}
}


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

int compara_lista(int A[], int B[], int n){
	for(int i = 0; i<n; i++){
		if(A[i]!=B[i]){
			return 0;
		}
	}
	return 1;
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


int modulo(int n){
	if (n<0)
		return n*(-1);
	else
		return n;
}


int verifica_igual(int V[], int L[], int n){
	int valor = 0;
	for (int i=0; i<n; i++)
		if (V[i]!=L[i])
			valor = 1;
	return valor;
}

pilhalink * inicializa_pilhalink(){
	pilhalink * p = malloc(sizeof(pilhalink));
	p->head = NULL;
	p->size = 0;
	return p;
}

int toplink(pilhalink * p){
	return p->head->val;
}

void pushlink(pilhalink * p, int x){
	no * n = cria_no(x);
	n->next = p->head;
	p->head = n;
	p->size = p->size + 1;
}

void poplink(pilhalink * p){
	p->head = p->head->next;
	p->size = p->size - 1;
}

int emptylink(pilhalink * p){
	if (p->head == NULL)
		return 1;
	return 0;
}

pilhamin * inicializa_pilhamin(){
	pilhamin * p = malloc(sizeof(pilhamin));
	p->head = NULL;
	return p;
}

int topmin(pilhamin * p){
	return p->head->val;
}

void pushmin(pilhamin * p, int x){
	nomin * n = cria_nomin(x);
	n->next = p->head;
	p->head = n;
	if (n->next!=NULL){
		if(p->head->val>=n->next->min)
			p->head->min = n->next->min;
		p->head->mult = p->head->mult * n->next->mult;
	}
}

void popmin(pilhamin * p){
	p->head = p->head->next;
}

int emptymin(pilhamin * p){
	if (p->head == NULL)
		return 1;
	return 0;
}

void imprime_lista(int v[], int n){
	printf("[");
	printf("%d", v[0]);
	for(int i = 1; i < n; i++)
		printf(" , %d", v[i]);
	printf("]\n");
}
// EXERCICIOS:


int jogo_sapo(int L[], int n){
	int pulo_max = 0;
	for (int i=0; i<n-1; i++){
		if(modulo(L[i+1]-L[i])>pulo_max){
			pulo_max = modulo(L[i+1]-L[i]);
		}
	} 
	return pulo_max;
}


int figurinhas(int L[], int n){
	int rep = 0;
	int k;
	for (int i = 0; i<n; i++){
		k = 0;
		for (int j = 0 ; j<n; j++){
			if (L[i]==L[j]){
				k++;
			}
		}
		if (k>=rep){
			rep = k; 
		}
	}
	return rep;
}


int __coca_cola(int n, int promo, int k){
	if (n+k<promo){
		return n;
	}
	else{
		return n + __coca_cola((n+k)/promo, promo, (n+k)%promo);
	}
}
int coca_cola(int n, int promo){
	return __coca_cola(n, promo, 0);
}

int cometa(int n){
	int ano, qtd;
	if (n<=1986){
		qtd = (1986-n)%76;
		if (qtd==0)
			ano = n+76;
		else
			ano = n+qtd;
	}
	else{
		qtd = ((n-1986)%76);
		ano = n+(76-qtd);
	}
	return ano;
}

int martelo_força(int n,int a[], int b[], int m, int c[]){
	int total = 0;
	for (int i = 0; i<m ; i++){
		if (c[i]<a[0])
			total = total + b[0];
		else if (c[i]>=a[n-2])
			total = total + b[n-1];
		else{
			int j = 1;
			while(c[i]>=a[j])
				j++;
			total = total + b[j];
		}

	}	
	return total;


}


int dobrando_par(int V[], int n){
	int par = V[0];
	int total = 0;
	for (int i = 1; i<n; i++){
		if (V[i]%2==0){
			if(par*2==V[i]){
				total++;
			}
		par = V[i];
		}
	}
	return total;
}


void remove_duplicados(int V[], int n){
	int pos = 0;
	int i=1;
	while (i<n && V[i]!=0){
		if (V[i]!=V[pos]){
			V[pos+1]=V[i];
			pos++;
		}
		i++;
	}
	pos++;
	while (pos<n && V[pos]!=0){
		V[pos] = 0;
		pos++;
	}
}


int maior_trecho(int V[], int  n){
	int qtd = 0;
	int aux = 0;
	for (int i = 0; i<n; i++){
		if (i != n-1){
			if(V[i]>V[i+1]){
				if(qtd<(i+1)-aux){
					qtd=(i+1)-aux; 
					aux = i+1;
				}
			}
		}
		else{
			if(V[i-1]<=V[i]){
				if(qtd<(i+1)-aux){
					qtd = (i+1)-aux;
				}
			}
		}



	}
	return qtd;

}


void soma_binarios(int A[], int B[], int C[], int n){
	int carry = 0;
	for (int i = n; n>=0 ; i--){
		if(A[i]+B[i]+carry>1){
			if(A[i]+B[i]+carry==2)
				C[i+1]=0;
			else
				C[i+1]=1;
			carry = 1;
		}
		else{
			C[i+1]=A[i]+B[i]+carry;
			carry=0;
		}

	}
	C[0] = carry;
}


void ordena_partes(int A[], int n){
	int i=0;
	int x,POSn;
	while(i<n-1){
		x=A[i];
		for(int j=i+1;j<n;j++){
			if(x>A[j]){
				x=A[j];
				POSn = j;
			}
		}
		if (x!=A[i]){
			A[POSn]=A[i];
			A[i]=x;
		}
		i++;
	}
}


void ordenar_vetores(int A[],int n){
	int i = 0;
	int indice;
	while (i < n-1){
		int menor = A[i];
		for (int j = i; j < n; j++){
			if (A[j] < menor){
				menor = A[j];
				indice = j;
			}
		}
		if(menor!=A[i]){
			A[indice] = A[i];
			A[i] = menor;
		}
		i = i+1;
	}
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

int soma_lista2(lista2 * l){
	return l->sum;
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

int tamanho(pilhalink * p){
	return p->size;
}

int minimo(pilhamin * p){
	if (p->head==NULL)
		return -1;
	else
		return p->head->min;
}

int produto(pilhamin * p){
	if (p->head==NULL)
		return 0;
	else
		return p->head->mult;
}

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

int preenche_num_nodes_rec(node_tree * root){
	if (root == NULL)
		return 0;
	else if (root->esq == NULL && root->dir == NULL){
		root->num_nodes = 1;
		return 1;
	}
	else{
		root->num_nodes = preenche_num_nodes_rec(root->esq) + preenche_num_nodes_rec(root->dir) + 1;
		return root->num_nodes;
	}
		
}

void preenche_num_nodes(tree * t){
	t->root->num_nodes = preenche_num_nodes_rec(t->root);
}

int preenche_altura_rec(node_tree * root){
	if (root == NULL)
		return 0;
	else if (root->esq == NULL && root->dir == NULL){
		root->altura = 1;
		return 1;
	}
	else{
		root->altura = max(preenche_altura_rec(root->esq),preenche_altura_rec(root->dir));
		return root->altura;
	}
}

void preenche_altura(tree * t){
	t->root->altura = preenche_altura_rec(t->root);
}

int preenche_folha_rec(node_tree * root){
	if (root == NULL)
		return 0;
	else if (root->esq == NULL && root->dir == NULL){
		root->num_folhas = 1;
		return 1;
	}
	else{
		root->num_folhas = preenche_folha_rec(root->esq) + preenche_folha_rec(root->dir);
		return root->num_folhas;
	}
}

void preenche_folha(tree * t){
	t->root->num_folhas = preenche_folha_rec(t->root);
}

int preenche_nivel_rec (node_tree * root, int k){
	if (root==NULL)
		return 0;
	else if (root->esq == NULL && root->dir == NULL){
		root->nivel = k;
		return k;
	}
	else{
		root->nivel = max(preenche_nivel_rec(root->esq, k+1), preenche_nivel_rec(root->dir, k+1)) - 1 ;
		return  root->nivel;
	}
}

void balanceia_node(node_tree * root){
	if(root==NULL){
		return;
	}
	else{
		balanceia_node(root->esq);
		int fb = (1.5 * floor(log2(root->num_nodes)))+1;
		root->esq->balanceado = (root->altura<=fb);
		balanceia_node(root->dir);
	}
}
void preenche_arvore(tree * t){
	preenche_altura(t);
	preenche_num_nodes(t);
	balanceia_node(t->root);

}
void vetor_ordenado_aux (node_tree * root, vetor * v){
	if(root != NULL){
		vetor_ordenado_aux(root->esq, v);
		v->elem[v->size++] = root->chave;
		vetor_ordenado_aux(root->dir, v);
	}
}

vetor * vetor_ordenado (tree * t){
	vetor * v = malloc(t->root->num_nodes * sizeof(int));
	v->size = 0;
	vetor_ordenado_aux(t->root, v);
	return v;


}

void tree_ordenado_aux (tree * t, vetor * v, int inicio, int fim){
	if (inicio >= fim){
		int meio = (inicio + fim)/2;
		insereBST(t, v->elem[meio]);
	}
	else{
		int meio = (inicio + fim)/2;
		insereBST(t, v->elem[meio]);
		tree_ordenado_aux(t, v, inicio, meio - 1);
		tree_ordenado_aux(t, v, meio +1 , fim);
	}
}

tree *  tree_ordenado(vetor * v){
	tree * t = malloc(sizeof(tree));
	int size_v = v->size;
	tree_ordenado_aux(t, v, 0, size_v - 1);
	return t;

}

node_tree * preenche_esq_aux(node_tree * root){
	if (root != NULL){
		if(root->esq==NULL && root->dir == NULL){
			root->mais_esq = root;
			return root;
		}
		else{
			if (root->esq == NULL){
				root->mais_esq = root;
				root->dir->mais_esq = preenche_esq_aux(root->dir);
				return root;
			}
			else{
				root->mais_esq = preenche_esq_aux(root->esq);
				if (root->dir != NULL)
					root->dir->mais_esq = preenche_esq_aux(root->dir);
				return root->mais_esq;
			}

		}
	}
	return NULL;
}
void preenche_mais_esq(tree * t){
	if (t!=NULL)
		t->root = preenche_esq_aux(t->root);
}

void preenche_pai_aux(node_tree * root, node_tree * pai){
	if (pai != NULL && root!= NULL){
		root->pai = pai;
		if (root->esq != NULL)
			preenche_pai_aux(root->esq, root);
		if(root->dir != NULL)
			preenche_pai_aux(root->dir, root);
	}
}

void preenche_pai(tree * t){
	if (t != NULL && t->root != NULL){
		preenche_pai_aux(t->root->esq, t->root);
		preenche_pai_aux(t->root->dir, t->root);

	}
}


void remover_folhas_aux(node_tree * root , node_tree * pai){
	if (root != NULL){
		if (root->dir== NULL && root->esq == NULL){
			if (pai != NULL){
				if (pai->chave>root->chave){
					pai->esq = NULL;
				}
				else
					pai->dir = NULL;

			}

			free(root);
		}
		else{
			remover_folhas_aux(root->esq, root);
			remover_folhas_aux(root->dir, root);
		}

	}

}

void remover_folhas(tree * t){
	remover_folhas_aux(t->root, NULL);
}

void  inserçao(tree * t, int x){
	node_tree * root = t->root;
	if (root != NULL){
		node_tree * aux;
		node_tree * aux2 = t->root;
		while(root!= NULL){
			aux = root;
			if(root->chave<x){
				root = root->dir;
				aux2 = root;
			}
			else
				root = root->esq;
		}
		if (aux->chave == x)
			aux->valor++;
		else if (aux->chave>x){
			aux->esq = cria_no_tree(x);
			preenche_esq_aux(aux2);
		}
		else
			aux->dir = cria_no_tree(x);
	}


}

// CORREÇOES:


void problema1(){
	printf("PROBLEMA 1:\n");
	int teste1[] = {1,3,6,7,8,3,8,9,7,10};
	int n = sizeof(teste1)/sizeof(int);
	if (jogo_sapo(teste1, n)==5)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste2[] = {2,4,5,6,7,9,14,3};
	n = sizeof(teste2)/sizeof(int);
	if (jogo_sapo(teste2, n)==11)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste3[] = {1,2,3,4,5,7,8,9};
	n = sizeof(teste3)/sizeof(int);
	if (jogo_sapo(teste3, n)==2)
		printf("OK\n");
	else
		printf("FAIL\n");


}

void problema2(){
	printf("PROBLEMA 2:\n");
	int teste1[] = {1,2,4,2,4,5,3,2};
	int n = sizeof(teste1)/sizeof(int);
	if (figurinhas(teste1, n)==3)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste2[] = {20,32, 78, 32, 90, 65, 10,12,21, 90, 101};
	n = sizeof(teste2)/sizeof(int);
	if (figurinhas(teste2, n)==2)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste3[] = {1,1,1,1,2,2,2,3,3,4};
	n = sizeof(teste3)/sizeof(int);
	if (figurinhas(teste3, n)==4)
		printf("OK\n");
	else
		printf("FAIL\n");


}


void problema3(){
	printf("PROBLEMA 3:\n");
	if (coca_cola(10,3)==14)
		printf("OK\n");
	else
		printf("FAIL\n");
	if (coca_cola(20,3)==29)
		printf("OK\n");
	else
		printf("FAIL\n");
	if (coca_cola(50,3)==74)
		printf("OK\n");
	else
		printf("FAIL\n");


}


void problema5(){
	printf("PROBLEMA 5:\n");
	int teste1[] = {7,6,13,12,24,3,9,48,11,50};
	int n = sizeof(teste1)/sizeof(int);
	if (dobrando_par(teste1, n)==3)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste2[] = {2,3,4,5,6,12,13,14,28,56,70};
	n = sizeof(teste2)/sizeof(int);
	if (dobrando_par(teste2, n)==4)
		printf("OK\n");
	else
		printf("FAIL\n");



}


void problema6(){
	printf("PROBLEMA 6:\n");
	int teste1[] = {1,1,2,3,4,4,4,5,0,0};
	int respt1[] = {1,2,3,4,5,0,0,0,0,0};
	int n = sizeof(teste1)/sizeof(int);
	remove_duplicados(teste1, n);
	if (verifica_igual(teste1, respt1, n)==0)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste2[] = {1,2,2,3,4,4,5,5,6,6,7,0,0};
	int respt2[] = {1,2,3,4,5,6,7,0,0,0,0,0,0};
	n = sizeof(teste2)/sizeof(int);
	remove_duplicados(teste2, n);
	if (verifica_igual(teste2, respt2, n)==0)
		printf("OK\n");
	else
		printf("FAIL\n");


}


void problema7(){
	printf("PROBLEMA 7:\n");
	if (cometa(2300)==2366)
		printf("OK\n");
	else
		printf("FAIL\n");
	if (cometa(1500)==1530)
		printf("OK\n");
	else
		printf("FAIL\n");

}


void problema8(){
	printf("PROBLEMA 8:\n");
	int teste1[] = {2, 3, 4, 1, 2, 3, 4, 6};
	int n = sizeof(teste1)/sizeof(int);
	if (maior_trecho(teste1, n)==5)
		printf("OK\n");
	else
		printf("FAIL\n");
	int teste2[] = {2,2,3,3,3,1,1,2};
	n = sizeof(teste2)/sizeof(int);
	if (maior_trecho(teste2, n)==5)
		printf("OK\n");
	else
		printf("FAIL\n");



}
void problema13(){
	printf("PROBLEMA 13:\n");
	int lim1[]={3,5};
	int pont1[]={1,4,7};
	int jog1[]={2,4,3};
	int n = sizeof(pont1)/sizeof(int);
	int m = sizeof(jog1)/sizeof(int);
	if (martelo_força(n, lim1, pont1, m, jog1)==9)
		printf("OK\n");
	else
		printf("FAIL\n");
	int lim2[]={3,5,8};
	int pont2[]={1,4,6,8};
	int jog2[]={7,10};
	n = sizeof(pont2)/sizeof(int);
	m = sizeof(jog2)/sizeof(int);
	if (martelo_força(n, lim2, pont2, m, jog2)==14)
		printf("OK\n");
	else
		printf("FAIL\n");


	


}


void problemaED(){
	printf("PROBLEMA ED:\n");
	int BIN1[]={1,1,0,0,0,1,0,1};
	int BIN2[]={0,1,0,1,1,0,1,1};
	int n = sizeof(BIN1)/sizeof(int);
	int SOMA[n+1];
	soma_binarios(BIN1,BIN2,SOMA, n);
	int RESP[] = {1,0,0,1,0,0,0,0,0};
	if (compara_lista(RESP, SOMA, n+1)==1)
		printf("OK\n");
	else
		printf("FAIL\n");
}


void problemaED2(){
	printf("PROBLEMA ED:\n");
	int A[] = {8,4,2,5,3};
	int n = sizeof(A)/sizeof(int);
	int B[] = {2,3,4,5,8};
	ordenar_vetores(A, n);
	if (compara_lista(A, B, n)==1)
		printf("OK\n");
	else
		printf("FAIL\n");

}

void problema14(){
	printf("PROBLEMA 14:\n");
	lista * l = inicializa_lista();
	int v[] = {5, 8, 13, 2, 10};
	l->head = preenche_lista( v, 5);
	if (soma_lista(l)==38)
		printf("OK\n");
	else
		printf("FAIL\n");
	lista * k = inicializa_lista();
	int g[] = {2,7,23,8,9,12,23,45,67,100};
	k->head = preenche_lista( g, 10);
	if (soma_lista(k)==296)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema15(){
	printf("PROBLEMA 15:\n");
	lista2 * l = inicializa_lista2();
	no * n;
	int v[] = {5, 8, 13, 2, 10};
	for (int i = 0; i < 5; ++i){
		n = cria_no(v[i]);
		insere_lista2(l, n);
	}
	if (soma_lista2(l)==38)
		printf("OK\n");
	else
		printf("FAIL\n");

	
}

void problema16(){
	printf("PROBLEMA 16:\n");
	lista3 * l = inicializa_lista3();
	no * n;
	int v[] = {5, 8, 13, 2, 10};
	for (int i = 0; i < 5; ++i){
		n = cria_no(v[i]);
		insere_lista3(l, n);
	}
	n = cria_no(16);
	insere_lista3(l, n);
	if (l->end->val==16)
		printf("OK\n");
	else
		printf("FAIL\n");

}

void problema17(){
	printf("PROBLEMA 17:\n");
	int v[] = {5, 8, 13, 2, 10};
	lista * l = cria_lista(v, 5);
	move_maior_fim(l);
	int j[] = {5, 8,  2, 10, 13};
	lista * k = cria_lista(j, 5);
	if (compara_listalinked(l, k)==1)
		printf("OK\n");
	else
		printf("FAIL\n");

}

void problema18(){
	printf("PROBLEMA 18:\n");
	int v[] = {5, 8, 2, 7, 5};
	lista * l = cria_lista(v, 5);
	remove_todos(l, 5);
	int j[] = {8, 2, 7};
	lista * k = cria_lista(j, 3);
	if (compara_listalinked(l, k)==1)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema19(){
	printf("PROBLEMA 19:\n");
	int v[] = {5, 2, 7, 5, 6, 2};
	lista * l = cria_lista(v, 6);
	remove_repetidos_rec(l);
	int j[] = {5, 2, 7, 6};
	lista * k = cria_lista(j, 4);
	if (compara_listalinked(l, k)==1)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema20(){
	printf("PROBLEMA 20:\n");
	int v[] = {5, 2, 7, 5, 6, 5};
	lista * l = cria_lista(v, 6);
	if (mais_frequente(l)==5)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema21(){
	printf("PROBLEMA 21:\n");
	pilhalink * p = inicializa_pilhalink();
	pushlink(p, 5);
	pushlink(p, 6);
	pushlink(p, 5);
	pushlink(p, 7);
	pushlink(p, 2);
	pushlink(p, 5);
	poplink(p);
	int v[] = {2, 7, 5, 6, 5};
	int aux = 0;
	for (int i = 0; i<5; i++){
		if(toplink(p)!=v[i]){
			aux = 1;
			break;
		}
		else{
			poplink(p);
		}
	}
	if (aux==0)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema22(){
	printf("PROBLEMA 22:\n");
	pilhalink * p = inicializa_pilhalink();
	pushlink(p, 5);
	pushlink(p, 6);
	pushlink(p, 5);
	pushlink(p, 7);
	pushlink(p, 2);
	pushlink(p, 5);
	if (tamanho(p)==6)
		printf("OK\n");
	else
		printf("FAIL\n");
	pilhalink * k = inicializa_pilhalink();
	pushlink(k, 1);
	pushlink(k, 6);
	pushlink(k, 5);
	poplink(k);
	pushlink(k, 7);
	pushlink(k, 2);
	pushlink(k, 5);
	poplink(k);
	poplink(k);
	pushlink(k, 12);
	poplink(k);
	pushlink(k, 4);
	pushlink(k, 3);
	poplink(k);
	if (tamanho(k)==4)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema23(){
	printf("PROBLEMA 23:\n");
	pilhamin * p = inicializa_pilhamin();
	pushmin(p, 5);
	pushmin(p, 6);
	pushmin(p, 5);
	pushmin(p, 7);
	pushmin(p, 2);
	pushmin(p, 5);
	if (minimo(p)==2)
		printf("OK\n");
	else
		printf("FAIL\n");
	popmin(p);
	popmin(p);
	if (minimo(p)==5)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema24(){
	printf("PROBLEMA 24:\n");
	pilhamin * p = inicializa_pilhamin();
	pushmin(p, 5);
	pushmin(p, 6);
	pushmin(p, 5);
	pushmin(p, 1);
	pushmin(p, 2);
	pushmin(p, 0);
	if (produto(p)==0)
		printf("OK\n");
	else
		printf("FAIL\n");
	popmin(p);
	popmin(p);
	if (produto(p)==150)
		printf("OK\n");
	else
		printf("FAIL\n");
}

void problema25(){
	printf("PROBLEMA 25:\n");
	int v[] = {5, 3, 6, 8, 2};
	stacksort(v, 5);
	int j[] = {2,3,5,6,8};
	if (compara_lista(v, j, 5)==1)
		printf("OK\n");
	else
		printf("FAIL\n");
	int k[] = {11,3,6,8,2,1,4};
	stacksort(k, 7);
	int l[] = {1,2,3,4,6,8,11};
	if (compara_lista(k, l, 7)==1)
		printf("OK\n");
	else
		printf("FAIL\n");
}
// MAIN:


int main(){
	problema1();
	problema2();
	problema3();
	problema5();
	problema6();
	problema7();
	problema8();
	problema13();
	problemaED2();
	problema14();
	problema15();
	problema16();
	problema17();
	problema18();
	problema19();
	problema20();
	problema21();
	problema22();
	problema23();
	problema24();
	problema25();

	return 0;
}