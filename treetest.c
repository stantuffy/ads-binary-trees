#include "tree.h"
#include "stdlib.h"
#include "stdio.h"

void setupTree(Tree* tree) {
    add(&tree->root, 2);
    add(&tree->root, 5);
}

//questi test restituiscono 1 se hanno successo, 0 altrimenti

// test 1
_Bool testClearTree() {
    Tree tree = createNewTree(4);
    setupTree(&tree);
    clearTree(&tree.root);

    return tree.root == NULL;
}

//test 2
_Bool testGetNumberOfNodes() {
    Tree tree = createNewTree(4);
    setupTree(&tree);

    return getNumberOfNodes(tree.root) == 3;
}

//test 3
_Bool testGetNumberOfLeaves() {
    Tree tree = createNewTree(4);
    setupTree(&tree);

    return getNumberOfLeaves(tree.root) == 2;
}

//test 4
_Bool testGetHeight() {
    Tree tree = createNewTree(4);
    setupTree(&tree);

    return getHeight(tree.root) == 1;
}

//test 5
_Bool testGetNodesAtHeight() {
    Tree tree = createNewTree(4);
    setupTree(&tree);

    return getNodesAtHeight(tree.root, 1) == 2;
}

//test 6
_Bool testGetMax() {
    Tree tree = createNewTree(4);
    setupTree(&tree);

    return getMax(tree.root) == 5;
}

//test 7
_Bool testGetPath() {
    Tree tree = createNewTree(4);
    setupTree(&tree);

    int* array = getPath(tree.root, 5);
    _Bool output = array[0] == 5;
    free(array);
    return output;
}

int main() {
    printf("Esito test 1: %d\n", testClearTree());
    printf("Esito test 2: %d\n", testGetNumberOfNodes());
    printf("Esito test 3: %d\n", testGetNumberOfLeaves());
    printf("Esito test 4: %d\n", testGetHeight());
    printf("Esito test 5: %d\n", testGetNodesAtHeight());
    printf("Esito test 6: %d\n", testGetMax());
    printf("Esito test 7: %d\n", testGetPath());
}

