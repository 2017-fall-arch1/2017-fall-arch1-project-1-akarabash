
/* a node of the binary search tree */
typedef struct node_s{
	struct node_s *left, *right;
	char *str;
} tNode;

/* a binary search tree comprised of nodes */
typedef struct {
	tNode *root;
} BST;

BST *BST_Alloc();

void makeTreeEmpty(BST *tree)

void treeAdd(BST *tree, char *s);

void printTree(BST *tree, char*msg);

int treeIsMember(BST *tree, char *s);

void printTreeToFile(BST *tree, FILE *fp);