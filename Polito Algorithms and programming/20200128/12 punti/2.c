//File: 2.c
//Name: Youmbissie Fouapon Ismail
//Date: Jan 4, 2020
//Description: possibile soluzione esame di 03MNO Algorithmi e Programazionne del 28/Jan/2020 - parte da 12 punti - esercizio 2


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
    int i, p;
    if(a>=b) return NULL;
    p=(*pos)++;
    for(i=0;i<b;i++){
        if(inorder[i]==preorder[p]){
            break;
        }
    }
    link left = buildTreeR(inorder,preorder,pos, a, i);
    link right = buildTreeR(inorder,preorder,pos, i+1, b);
    return NEW(preorder[p], left, right);
}
/*
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
*/
link buildTree(int *inorder, int *preorder, int N){
    int pos = 0;
    link root = buildTreeR(inorder,preorder, &pos, 0, N);
	return root;
}







/*
codice di prova
*/
void print_treeR(link node, int pos, char* str){
    int i;
    if(node==NULL) return;
    for(i=0;i<pos;i++){
        printf("--");
    }
    printf(">%s: %d\n",str,node->item);
    print_treeR(node->left,pos+1,"left_");
    print_treeR(node->right,pos+1,"right");
    return;
}
void print_tree(link root){
    int i;
    if(root==NULL) return;
    printf("root: %d\n",root->item);
    print_treeR(root->left,1," left_");
    print_treeR(root->right,1,"right");
    return;
}

int main(){

    int inorder1[]={4,2,5,1,3};
    int preorder1[]={1,2,4,5,3};
    int N1=5;

    int inorder[]={2,7,4,1,5,3,6};
    int preorder[]={1,2,4,7,3,5,6};
    int N=7;
    print_tree(buildTree(inorder,preorder,N));
    return 0;
}
