#include "tree.h"
#include "stdlib.h"

//cercare sempre il caso base e capire cosa deve succedere al singolo nodo

Tree createNewTree(int value) {
    Tree tree;
    tree.root = createNode(value);
    return tree;

    /* in alternativa
    Tree tree;
    tree.root = malloc(sizeof(Node));
    tree.root->parent = NULL;
    tree.root->left = NULL;
    tree.root->right = NULL;
    tree.root->value = value;
    return tree;
    */
}

void clearTree(Node* root) {
    if (root == NULL)
        return;

    clearTree(root->left);
    clearTree(root->right);

    printf("Cancello il nodo con valore %d", root->value);
    free(root);
    root = NULL;
}


Node* createNode(int value) {
    Node* newNode = calloc(1, sizeof(Node));
    newNode->value = value;
    return newNode;

    /* in alternativa
    Node* newNode = malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->value = value;
    return newNode;
    */
}

void add(Node** root, int value) {
    /* il nodo corrente ha il figlio sinistro/destro
     * nullo, quindi lo aggiungo
     */
    if (*root== NULL) {
        *root = createNode(value);
    }

    /* il valore da inserire è uguale al valore
    * del nodo corrente? esci dalla funzione. */
    if ((*root)->value == value)
        return;

    else {
        if (value < (*root)->value)
            add(&(*root)->left, value);
        else
            add(&(*root)->right, value);
    }
}

unsigned int getNumberOfNodes(Node* root) {
    
    //caso base
    if (root == NULL)
        return 0;

    return getNumberOfNodes(root->left) + 
           getNumberOfNodes(root->right)
           + 1;
}

unsigned int getNumberOfLeaves(Node* root) {
    /* il nodo corrente è una foglia? esci e
     * restituisci uno.
     */
    if (isLeaf(root)) 
        return 1;
    
    return getNumberOfLeaves(root->left) +
           getNumberOfLeaves(root->right);
}

unsigned int getHeight(Node* root) {
    if (root == NULL)
        return -1;

    int l = 1 + getHeight(root->left);
    int r = 1 + getHeight(root->right);

    return (l > r) ? l : r;
}

unsigned int getNodesAtHeight(Node* root, unsigned int height) {
    if (root == NULL)
        return 0;
    if (height == 0)
        return 1;
    return getNodesAtHeight(root->left, height - 1) + 
           getNodesAtHeight(root->right, height - 1);
}

int getMax(Node* root) {
    if (root == NULL)
        return 0;
    
    int tempMax = root->value;
    int leftMax = getMax(root->left);
    int rightMax = getMax(root->right);

    if (leftMax > tempMax)
        tempMax = leftMax;
    if (rightMax > tempMax)
        tempMax = rightMax;

    return tempMax;
}

//funziona solo con alberi binari di ricerca
int* getPath(Node* root, int value) {
    if (root == NULL)
        return NULL;
    
    int* path = calloc(1, sizeof(int));
    int i = 0;
    while (root != NULL) {
        path[i] = root->value;
        //nodo trovato? esci.
        if (root->value == value)
            return path;
        //nodo corrente con valore minore? il nodo da
        //cercare sta a destra.
        if (root->value < value)
            root = root->right;
        //nodo corrente con valore maggiore? il nodo da
        //cercare sta a sinistra.
        else
            root = root->left;
    }
    free(path);
    return NULL;
}

_Bool isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}

_Bool isComplete(Tree* tree) {
    int h = getHeight(tree->root);
    int l = getNumberOfLeaves(tree->root);

    return pow(2,h) == l;
}
