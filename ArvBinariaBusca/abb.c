#include "Abb.h"

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
