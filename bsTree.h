#define BSTREE_H_


/* A BST node */
typedef struct node_s{
  struct node_s *left, *right;
  char *str;
} tNode;

/* A Binary Search Tree */
typedef struct{
  tNode *root;
} BST;


/* Create new tree */
BST *BST_Alloc();


/* Free all memory associated with tree */
void BST_Free(BST *tree);

/* Delete nodes in tree */
void makeTreeEmpty(BST *tree);

/* Recursively empties tree */
void recurEmpty(tNode *root);

/* Append a copy of s in proper location within tree */
void treeAdd(BST *tree, char *s);

/* Add name to node so that it can be added to tree */
tNode *addNode(char *s);

/* Print tree membership */
void printTree(BST *tree);

/* Recursivel prints out the tree in order */
void recursivePrint(tNode *root);

/* Delete all elements off tree */
void treeRemove(BST *tree, char *toBeRemoved);

/* Recursively remove name from tree */
tNode *recursiveRemove(tNode *root, char *toBeRemoved);

/* Determines of str is inside of tree */
int treeIsMember(BST *tree, char *s);

/* Prints tree to file */
void printTreeToFile(BST *tree, FILE *fp);

/* Find min element in tree */
tNode *findMin (tNode *root);

/* Recursively checks if word is memeber of tree*/ 
int recurIsMember(tNode *root, char *isMem);

/* Recursively print tree to file */
void recurPrintTreeToFile(tNode *root, FILE *fp);

#endif /* BSTREE_H_ */
