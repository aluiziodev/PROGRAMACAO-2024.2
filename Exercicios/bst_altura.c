#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>


typedef struct node_tree{
	int chave;
	int valor;
	int size;
	int altura;
	struct node_tree * esq;
	struct node_tree * dir;
} node_tree;

typedef struct tree{
	node_tree * root;
	int size;
} tree;

tree * cria_arvore(){
	tree * t = malloc( sizeof(tree) );
	t->root = NULL;
	t->size = 0;
	return t;
}


node_tree * cria_no(int chave){
	node_tree * no = malloc( sizeof(node_tree) );
	no->chave = chave;
	no->valor = 1;
	no->size =  1;
	no->altura = -1;
	no->esq = NULL;
	no->dir = NULL;
	return no;
}

int size_node(node_tree * root){
	if(root == NULL) return 0;
	else return root->size;
}

node_tree * insere_node(node_tree * root, int chave){
	if( root == NULL){
		return cria_no(chave);
	}else if( chave == root->chave){
		root->valor++;
	}else if( chave < root->chave){
		root->esq = insere_node(root->esq, chave);
		root->size = size_node(root->esq) + size_node(root->dir) + 1;
	}else{
		root->dir = insere_node(root->dir, chave);
		root->size = size_node(root->esq) + size_node(root->dir) + 1;
	}
	return root;
}


void insere_tree(tree * t, int chave){
	t->root = insere_node(t->root, chave);
	t->size = t->root->size;
}

int size_tree(tree * t){
	return t->root->size;
}

void show_node(node_tree * root, int level){
	if(root){
		show_node(root->esq, level+1);
		for(int i = 0; i < level; i++)
			printf(".");
		printf("%d(%d)[%d]\n", root->chave, root->valor, root->altura);
		show_node(root->dir, level+1);
	}
}

void show_tree(tree * t){
	show_node(t->root, 0);
}


int max(int a, int b){
	return a>b?a:b;
}

int pega_altura_node(node_tree * root){
	if (root==NULL)
		return 0;
	else if (root->dir == NULL && root->esq == NULL)
		return 1;
	else{
		return max(pega_altura_node(root->esq),pega_altura_node(root->dir)) + 1;
	}
}

void preenche_altura_node(node_tree * root){
	if (root==NULL){
		return ;
	}
	else{
		preenche_altura_node(root->esq);
		preenche_altura_node(root->dir);
		root->altura = pega_altura_node(root);
	}
}

void preenche_altura(tree * t){
	preenche_altura_node(t->root);
}

int altura(node_tree * root){
	if(root == NULL) return 0;
	else return max( altura(root->esq), altura(root->dir)) + 1;
}

int checa_altura_node(node_tree * root){
	if(root == NULL) return 1;
	else{
		if( root->altura != altura(root) ) return 0;
		return checa_altura_node(root->esq) && checa_altura_node(root->dir); 
	}
}

int checa_altura_arvore(tree * t){
	return checa_altura_node(t->root);
}


tree * gera_arvore(int n){
	tree * t = cria_arvore();
	srand(time(NULL));   
 
	for(int i = 0; i < n; i++){
		insere_tree(t, rand() % 100 );
	}
	
	return t;
}

void problema1(){
	printf("Problema: Preenche altura\n");
	for(int i = 1; i <= 5; i++){
		printf("Teste %d: ", i);
		tree * t = gera_arvore(15);
		preenche_altura(t);
		if( checa_altura_arvore(t) == 1) printf("OK\n");
		else printf("FAIL\n");
	}
}

int main(){
	problema1();
}





	
