#ifndef ABB_h
#define ABB_h

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




#endif