// PROGRAMAÇÃO - 2024.2

// AULA - 2


#include <stdio.h>
#define N 10

int V[N] = {7,8,1,2,3,10,11,2,4,6};
int a;
void alg_ordenaçao1(int L[], int n)
{
	int M, posM, i;
	M = L[0];
	posM = 0;
	for (i=1; i<n; i++)
		if (M<L[i]){
			M = L[i];
			posM = i;
		}
	L[posM] = L[n-1];
	L[n-1] = M; 

}

int main()
{
	for (a=N; a>1; a--)
		alg_ordenaçao1(V, a);
	for (a=0; a<N; a++)
		printf("%d ", V[a]);
	printf("\n");

	return 0;
}	

