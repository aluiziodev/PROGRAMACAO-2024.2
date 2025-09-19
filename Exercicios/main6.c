#include "lexer.h"
#include "pilha.h"

lista_tokens polonesa_reversa(lista_tokens l1){

	//pilha com os indices da lista de tokens l1
	Pilha p;
	inicializar_pilha(&p);

	//lista de tokens de saida
	lista_tokens l2;
	l2.qtd_tokens = 0; 
	
	for(int i = 0; i < l1.qtd_tokens; i++){
		//se token for OP vá para saída
		if( get_categoria(&l1, i) == OP){
			adicionar_token(&l2, get_categoria(&l1, i), get_valor(&l1, i) );
			//mostra_token(l1.tokens[i]);
		//se token for AP empilha
		}else if( get_categoria(&l1, i) == AP){
			push(&p, i);
		//se token for FP desempilhe até encontrar AP
		}else if( get_categoria(&l1, i) == FP){
			while( !is_empty(&p) ){ 
			    int index = top(&p);
				if( get_categoria(&l1, index) != AP){
					adicionar_token(&l2, get_categoria(&l1, index), get_valor(&l1, index) );
					//mostra_token(l1.tokens[index]);
					pop(&p);
				}else{
					pop(&p);
					break;
				}
			}
		}else{
			//se token for {PLUS, MINUS, MUL, DIV}
			//desempilhe todos os operadores com precedencia 
			//maior que ele em seguida empilhe o token	
			while( !is_empty(&p) ){ 
			    int index = top(&p);
				
				if( get_categoria(&l1, index) == AP){
					break;
				} else if( get_categoria(&l1, index) <= get_categoria(&l1, i) ){
					adicionar_token(&l2, get_categoria(&l1, index), get_valor(&l1, index) );
					//mostra_token(l1.tokens[index]);
					pop(&p);
				}else{
					break;
				}
			}

			push(&p, i);
		}
			
	}

	//Esvazie a pilha
	while( !is_empty(&p) ){ 
		int index = top(&p);
		adicionar_token(&l2, get_categoria(&l1, index), get_valor(&l1, index) );
		//mostra_token(l1.tokens[index]);
		pop(&p);
	}

	return l2;

}

int avalia_polenesa_reversa(lista_tokens * l2){

	Pilha p;
	inicializar_pilha(&p);
	int v, res;
 	for (int i = 0 ; i < l2->qtd_tokens; i++){
 		if(get_categoria(l2, i)==2){
 			v = atoi(get_valor(l2, i));
 			push(&p, v);
 		}
 		else{
 			int op2 = pop(&p);
 			int op1 = pop(&p);
 			res = calcula(get_categoria(l2, i), op1, op2);
 			push(&p,res);
 		}
 	}
 	return res;

			
		
}

void teste1(){
	printf("analise lexica\n");
	lista_tokens l1 = analisador_lexico("-2+(-3*6)");
	mostra_lista(&l1);

	printf("polonesa reversa\n");
	lista_tokens l2 = polonesa_reversa(l1);
	mostra_lista(&l2);

	int res = avalia_polenesa_reversa(&l2);

	printf("Teste 1: ");
	if(res == -20) printf("OK\n");
	else printf("FAIL\n");
}

void teste2(){
	//printf("analise lexica\n");
	lista_tokens l1 = analisador_lexico("3 + 2 * (5 + 8 * (2 + 3)) + 5");
	//mostra_lista(&l1);

	//printf("polonesa reversa\n");
	lista_tokens l2 = polonesa_reversa(l1);
	//mostra_lista(&l2);
	int res = avalia_polenesa_reversa(&l2);

	printf("Teste 2: ");
	if(res == 98) printf("OK\n");
	else printf("FAIL\n");
}



void teste3(){
	printf("analise lexica\n");
	lista_tokens l1 = analisador_lexico("          3      +     2    ");
	mostra_lista(&l1);

	printf("polonesa reversa\n");
	lista_tokens l2 = polonesa_reversa(l1);
	mostra_lista(&l2);

	int res = avalia_polenesa_reversa(&l2);
	
	printf("Teste 3: ");
	if(res == 5) printf("OK\n");
	else printf("FAIL\n");
}


void problema1(){
	teste1();	
	teste2();
	teste3();
}

int main(){
	problema1();

}


