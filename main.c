#include <stdio.h>
#include <stdlib.h>
#include "ads-trees/BinaryTrees.h"

int main(void) 
{

 tree* T = NULL;

T = insert_BST(T,5);
T = insert_BST(T,7);
T = insert_BST(T,0);
T = insert_BST(T,2);
T = insert_BST(T,3);
T = insert_BST(T,1);
T = insert_BST(T,6);
T = insert_BST(T,20);
T = insert_BST(T,30);
T = insert_BST(T,25);
T = insert_BST(T,5);

  print_tree(T,0);

  printf("\n\n\n");
  int n = get_num_nodes(T);
  int h = get_height(T);
  int completo = is_complete(T);
  int max_BST = get_max(T);
  int max = get_max(T);
  int* cammino = (int*)calloc(1,sizeof(int));
  printf("NUMERO NODI: %d",n);
  _Bool trovato = find_preorder(T,0);
  printf("\nTROVATO: %d",trovato);
  printf("\nALTEZZA: %d",h);
  printf("\nCOMPLETO: %d",completo);
  printf("\nMASSIMO: %d",max_BST);
  printf("\nMASSIMO SENZA BST: %d",max);
  printf("\nCAMMINO: ");
  cammino = get_path(T,30);
  printf("%d ",cammino[0]);
  printf("%d ",cammino[1]);
  printf("%d ",cammino[2]);
  printf("%d",cammino[3]);
}