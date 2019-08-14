typedef struct Node {
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int value;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* createNode(int value);

Tree createNewTree(int value);

void clearTree(Node** root);

void add(Node** root, int value);

unsigned int getNumberOfNodes(Node* root);

unsigned int getNumberOfLeaves(Node* root);

unsigned int getHeight(Node* root);

unsigned int getNodesAtHeight(Node* root, unsigned int height);

int getMax(Node* root);

int* getPath(Node* root, int value);

_Bool isLeaf(Node* node);

_Bool isComplete(Tree* tree);
