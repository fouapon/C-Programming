//File: 2.c
//Name: Youmbissie Fouapon Ismail
//Date: 04/02/2020
//Description: possibile soluzione esame di 03MNO Algorithmi e Programazionne del 28/Jan/2020 - parte da 12 punti - esercizione 2


/*
Soluzione
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
struct node {int item; link left; link right;};
link NEW(int item, link left, link right){
	link x = malloc(sizeof(*x));
	x->item=item; x->left=left;x->right=right;
	return x;
}

link buildTreeR(int *inorder, int *preorder,int *pos, int a , int b ){
    int i;
    if(a>=b) return NULL;
    link root=NEW(preorder[*pos], NULL,NULL);
    (*pos)++;
    for(i=0;i<b;i++)
        if(inorder[i]==root->item){
            break;
        }
    root->left = buildTreeR(inorder,preorder,pos, a, i);
    root->right = buildTreeR(inorder,preorder,pos, i+1, b);
	return root;
}
link buildTree(int *inorder, int *preorder, int N){
    int pos = 0;
    link root = buildTreeR(inorder,preorder, &pos, 0, N);
	return root;
}







/*
codice di prova
*/
void print_tree(link root, int pos){
    int i;
    if(root==NULL) return;
    for(i=0;i<pos;i++){
        printf("-");
    }
    printf("%d\n",root->item);
    print_tree(root->left,pos+1);
    print_tree(root->right,pos+1);
    return;
}
int main(){
    int inorder[]={4,2,5,1,3};
    int preorder[]={1,2,4,5,3};
    int N=5;
    link root = buildTree(inorder,preorder,N);
    print_tree(root,0);
    return 0;
}
