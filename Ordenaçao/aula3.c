// PROGRAMAÇAO - 2024.2
//
// AULA - 3



#include <stdio.h>
#include <stdlib.h>
#define N 10
int V[N] = {10, 14, 17, 21, 22, 1, 4, 11, 20, 45};
int inicio = 0;
int fim = N-1;

void printar(int V[], int n){
	for (int  i = 0; i<n; i++)
		printf("%d ", V[i]);
	printf("\n");
}

void insertion_sort (int V[], int n){

	int i, j, x;

	for (i = 0; i<n-1; i++){
		x = V[i];
		j = i;
		while (j>0 && V[j-1]>x){
			V[j] = V[j-1];
			j-- ;
		}
		V[j] = x;
	}
}

void ajeita(int V[], int inicio, int fim){
	int x,j;
	j = fim;
	x = V[fim];
	while ( j > inicio && x < V[j-1]){
		V [j] = V[j-1];
		j --;
	}
	V[j] = x;
}	

void ordena(int V[], int n, int inicio, int fim){
	for (int i=1; i<n; i++)
		ajeita(V, inicio, fim);
}



void merge(int V[],int n, int inicio, int meio, int fim){
	int A[n];
	int i,j,k;
	i = inicio;
	j = meio;
	k = 0 ;
	while (i < meio && j <= fim){
		if (V[i]<=V[j]){
			A[k] = V[i];
			i++;
		}
		else{
			A[k] = V[j];
			j++;
		}
		k++;

	}
	while( i < meio) {
		A[k] = V[i]; 
		i++; 
		k++;}
	while( j <= fim) {A[k] = V[j]; j++; k++;}

	for (int l = inicio, m = 0 ; l<=fim ; l++, m++)
		V[l] = A[m];

}

void mergesort(int V[],int n, int inicio, int fim, int meio){
	ordena(V, n, inicio, meio-1);
	ordena(V, n, meio, fim);
	merge(V,n, inicio, meio, fim);
}

int main(){
	int meio;
	meio = N/2;
	mergesort(V, N, inicio, fim, meio);
	printar(V, N);

	return 0;
}
























