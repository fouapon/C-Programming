#include <stdio.h>
#include <stdlib.h>

int areaTot(FILE *fp){
    int MAX_X = 10, MAX_Y = 10;
	int i, j, x1, y1, x2, y2;
	int area=0;
	int **mat=malloc(MAX_X*sizeof(int*));
	for(i=0;i<MAX_X;i++)
		mat[i]=calloc(MAX_Y,sizeof(int));


	while(fscanf(fp,"%d%d%d%d",&x1,&y1,&x2,&y2)==4){
        //printf("%d %d %d %d\n",x1,y1,x2,y2);
		for(i=x1;i<x2;i++)
			for(j=y1;j<y2;j++)
				if(mat[i][j]==0){
					area++;
					mat[i][j]=1;
				}
	}
	return area;
}


int main (){
    printf("%d\n",areaTot(fopen("in.txt","r")));
}
