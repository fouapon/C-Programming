//File: 1.c
//Name: Youmbissie Fouapon Ismail
//Date: Jan 4, 2020
//Description: possibile soluzione esame di 03MNO Algorithmi e Programazionne del 28/Jan/2020 - parte da 12 punti - esercizio 1


/*
Soluzione1
*/
#include <stdlib.h>
#include <stdio.h>

void buildAndPrint(int *V, int N, int **M, int r, int c){
	int i,j,l,k;

	//buildAndPrint
	M=malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
		M[i]=malloc(c*sizeof(int));

	for(i=0,j=0,l=0;l<N;l+=2){
		for(k=0;k<V[l+1];k++){
			M[i][j]=V[l];
			printf("%3d ",V[l]);
			//printf("%3d ",M[i][j]);
			j++;
			if(j>=c){
				i++;
				j=0;
				printf("\n");
			}
		}
	}
	return;
}

/*
Soluzione2
*/
/*
void buildAndPrint(int *V, int N, int **M, int r, int c){
	int i,j,l,k;

	//build
	M=malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
		M[i]=malloc(c*sizeof(int));

    i=0;
    j=0;
	for(l=0;l<N;l+=2){
		for(k=0;k<V[l+1];k++){
			M[i][j]=V[l];
			j++;
			if(j>=c){
				i++;
				j=0;
			}
		}
	}

	//print
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%3d ",M[i][j]);
		}
		printf("\n");
	}
	return;
}
*/




/*
codice di prova
*/
int main (){
    int r=3,c=5,N=14, **M;
    int V[] = {1,2,17,2,3,1,8,4,6,1,7,3,5,2};
    buildAndPrint(V,N,M,r,c);
}
