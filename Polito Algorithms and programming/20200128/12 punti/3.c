//File: 3.c
//Name: Youmbissie Fouapon Ismail
//Date: Jan 4, 2020
//Description: possibile soluzione esame di 03MNO Algorithmi e Programazionne del 28/Jan/2020 - parte da 12 punti - esercizione 3


/*
Soluzione
*/
#include <stdio.h>
#include <stdlib.h>

void fr(int *val, int *disp, int n, int r, int *sol, int *nm, int pos){
    int i, nmc, rc;
    if(pos>=n){
        nmc=0;
        rc=0;
        for(i=0;i<n;i++){
            nmc+=sol[i];
            rc+=sol[i]*val[i];
        }
        if(rc==r && (*nm<0 || nmc < *nm))
            *nm=nmc;
        return;
    }
    for(i=0;i<=disp[pos];i++){
        sol[pos]=i;
        fr(val,disp,n,r,sol,nm,pos+1);
    }
}
int f(int *val, int *disp, int n, int r){
    int *sol, nm=-2;
    sol=malloc(n*sizeof(int));
    fr(val,disp,n,r,sol,&nm,0);
    free(sol);
    return nm;
}






/*
codice di prova
*/
int main (){
    int val[]={1,10,25};
    int disp[]={10,3,2};
    int n=3, r=30;
    printf("%d\n",f(val,disp,n,r));
    return 0;
}
