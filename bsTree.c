
#include <stdio.h>
#include <stdlib.h>
#include <string.h>            /* for strcmp */
#include <ctype.h>             /* for tolower */
#include "bsTree.h"



 BST *BST_Alloc(){
 	BST *tree = (BST *) malloc(sizeof(BST));
 	tree->root = 0;
 	return tree;
 }

 void BST_Free(BST *tree){
 	makeTreeEmpty(tree);
 	free(tree);
 	tree = 0;
 }

 void makeTreeEmpty(BST *tree){
 	tNode *root = tree->root;
 	recurEmpty(root);
 	tree->root = 0;
 }

 void recurEmpty(tNode *root){
 	if(root == 0){
 		return;
 	}
 	recurEmpty(root->left);
 	root->left = 0;
 	recurEmpty(root->right);
 	root->right = 0;
 	free(root->str);
 	free(root);
 }


 void treeAdd(BST *tree, char *s){
 	int stringLen,

 	char wasInserted = 0;
 	char *cpy;
 	tNode *checkOccupied = tree->root;

  	/* append if tree is empty */
  	if(tree->root == 0){
    	tree->root = addNode(char *s);
    	return;
  	}
  	/* Append to where it belongs */
  	while(!wasInserted){
    	if(strcmp(checkOccupied->str, toInsert->str) > 0){
      		if(!checkOccupied->left){
	     		checkOccupied->left = addNode(char *s);
	     		wasInserted = 1;
      		}
      		else{
	     		checkOccupied = checkOccupied->left;
      		}
    	}
    	else if(strcmp(checkOccupied->str, toInsert->str) <0){
      		if(!checkOccupied->right){
				checkOccupied->right = addNode(char *s);
				wasInserted = 1;
      		}
      		else{
				checkOccupied = checkOccupied->right;
      		}
    	}
    	else{
      		puts(" Name already registered. Employee not added.\n");
      		inserted = 1;
    	}
  	}
}

tNode *addNode(char *s){
	int sLen;
	
	tNode *toInsert;

	/* compute length of the string */
	for (sLen = 0; s[sLen]; sLen++);

  	copy = (char *) malloc(sLen+1);

  	/* copy input string into copy variable */
  	for (sLen = 0; s[sLen]; sLen++){
    	copy[sLen] = s[sLen];
  	}
  	copy[sLen] = 0;  /* terminate copy */

  	toInsert = (tNode *) malloc(sLen+1);
  	toInsert->str = copy;
  	toInsert->left = toInsert->right = 0;

  	return toInsert;

}

void printTree(BST *tree){
  if(tree->root == 0){
    puts("Tree is empty.\n");
  }
  else{
    recursivePrint(tree->root);
    puts("\n");
  }
}

void recursivePrint(tNode *root){
	tNode *visited;
	if(root == 0){
		return;
	}
	else{
		recursivePrint(visted = root->left);
		printf("<%s>\n", root->str);
		recursivePrint(visted = root->right);
	}
}

/*Remove a name from the tree */
void bstRemove(BST *tree, char *toBeRemoved){
  tNode *root = tree->root;
  recursiveRemove(root,removee);
}

/* Recursively remove a name form a tree*/
tNode *recursiveRemove(tNode *root, char *toBeRemoved){
  if(root == 0){
    puts("Not found");
    return root;
  }
  int cmp = (strcmp(root->str,toBeRemoved));
  if (cmp > 0){
    root->left = recursiveRemove(root->left,toBeRemoved);
  }
  else if(cmp < 0){
    root->right = recursiveRemove(root->right,toBeRemoved);
  }
  else{
  	/* no children */
  	if((root->left == 0) && (root->right == 0)){
  		free(root);
  		root = 0;	
  	}
  	/* one child left */
  	else if (root->right == 0){
  		tNode *temp = root;
  		root = root-> left;
  		free(temp->str);
  		free(temp);
  	}
  	/* one child right */
  	else if(root->left == 0){
  		tNode *temp = root;
  		root = root->right;
  		free(temp->str);
  		free(temp);
  	}
  	/* two children */
  	else{
  		tNode *temp;
  		temp->str = findMin(root->right)->str;
  		root->str = temp->str;
  		puts("removing");
  		root->right = recursiveRemove(root->right, temp->str);
  	}
  }
  return root;
}

/* Find min element in a tree*/
Node *findMin(Node *root){
	if (root == 0){
		return INT_MAX;
	}
	if(root->left != 0){
		return findMin(root->left);
	}
	return root;
}

int treeIsMember(BST *tree, char *isMember){
	return recIsMember(tree->root, isMember);
}

static int recIsMember(tNode *root, char *isMember){
	if(root == 0){
		return 0;
	}
	if(strcmp(root->str, isMember) == 0){
		return 1; 
	}
	if(recIsMember(root->left, isMember)){
		return 1;
	}

	return recIsMember(root->right, isMember);
}


/*Print to file*/
void printTreeToFile(BST *tree, FILE *fp)
{
  if(tree->root == 0){
    fputs("Empty tree.\n", fp);
  }
  else{
    recPrintToFile(tree->root,fp);
    fputs("\n",fp);
  }
}
/*Recursive printin of the tree to a file*/
void recurPrintTreeToFile(Node *root, FILE *fp)
{
  if(root == 0){
    return;
  }
  else{
    fprintf(fp,"%s\n",root->str);
    recPrintToFile(root->small,fp);
    recPrintToFile(root->big,fp);
  }
}











 