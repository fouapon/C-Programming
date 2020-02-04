# 03MNO Algorithmi e Programazionne
## Appello del 28/01/2020 - Prova di programmazione

1. (2 punti)

Sia dato un vettore __V__ di __N__ interi i cui elementi rapresentano, in formato compresso, sequeza di numeri che deve essere inserita in na matrice M di interi di __r__ righe e __c__ colonne secondo la strategia row-major, cioè per righe... Per decodificare la swquenza, gli interi del vettore devono essere considerati a copie (V[0], V[1]), (V[2], V[3]), (V[4], V[5]), etc. Il secondo elemento della copia rapresenta il numero di volte con cui il primo deve essere inserito in __celle adiacenti sulla stessa riga della matrice__ M.

Si scriva una funzione C con il seguente prototipo che riempia la matrice e ne stampi il contenuto:

`void buildAndPrint(int *V, int N, int **M, int r, int c)`

Si assuma corretta il contenuto del vettore V, quidi compatibile con le dimensioni della matrice M.

Esempio. Siano r=3, c=5, N=14 e V=(1, 2, 17, 2, 3, 1, 8, 4, 6, 1, 7, 3, 5, 2): la matrice M avrà il seguente contenuto
```
1  1 17 17  3
8  8  8  8  6
7  7  7  5  7
```

2. (4 punti)

Due vettori interi __preorder__ e __inorder__ di lunghezza __N__ uguale e nota contengono il risultato della visita preorder e inorder di un albero binario. Si scriva una funzione C __buildTrue__ che, ricevuti come parametri i 2 vettori e la lora lunghezza, costruisca l'albero binario che, se visitato respettivamente in preorder e inorder, dà come resiutati i contenuti dei 2 vettori. Dell'albero binario, la funzione restituisce il puntatore di tipo __link__ alla radice. il prototipo della funzione wrapper è uguale sia:

`link buildTree(int* inorder, int* preorder, int N);`

si suppongano disponibili:
```
typedef struct node* link;
struct node {int item; link left; link right;};
link NEW(int item, link left, link right){
	link x = malloc(sizeof(*x));
	x->item=item; x->left=left;x->right=right;
	return x;
}
```

Suggerimento: si realizzi in C l'algoritmo usato nella soluzione dell'esercizio 3 del compito di Teoria. Si tratta di percorrere in parallelo i 2 vettori, ricordando che nel vettore __preorder__ la radice compare per prima, rispetto ai soi sottoalberi e deve essere cercata nel verttore inorder __inoder__, nel quale compare tra i 2 sottoalberi.

3. (6 punti)

Un sistema di monetazione ha __n__ tipi di monete, il cui valore è contenuto in un vettore di interi __val__. Un vettore di __n__ interi __disp__ registra per ogni tipo di moneta quanti pezzi disponibili. Sia dato un resto intero __r__. Si scriva un programma C che, noti r, n, val e disp, calcoli, se posibile, il numero di monete minimo necessario per erogare tale resto. __Non sono ammesse soluzioni greedy__.
Esempio: n=3, val=(1,10,15), disp=(10,3,2), r=30 soluzione ottima 3 monete da 10
