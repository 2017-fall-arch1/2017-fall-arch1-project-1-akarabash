<<<<<<< HEAD
/*
 *
 * Created on Oct 17, 2017
 * Author: Amin Karabash
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bsTree.h"


/* Create binary search tree */
BST *BST_Alloc(){
  BST *tree = (BST *) malloc(sizeof(BST));
  tree->root =0;
  return tree;
}

/* Free all memory associated with tree */
void BST_Free(BST *tree){
  makeTreeEmpty(tree);
  free(tree);
  tree = 0;
}

/* Delete nodes in tree */
void makeTreeEmpty(BST *tree){
  tNode *root = tree->root;
  recurEmpty(root);
  tree->root = 0;
}

/* Empties tree recursively in a postorder */
void recurEmpty(tNode *root){
  if(root == 0){
    return;
  }
  recurEmpty (root->left);
  root->left = 0;
  recurEmpty (root->right);
  root->right =0;
  free(root->str);
  free(root);
}

/* Adds a new name to tree. A modification of the demo file implementation of llput */
void treeAdd(BST *tree, char *s){
  char wasInserted = 0;
  tNode *checkOccupied = tree->root;
  tNode *toInsert;
  toInsert = addNode(s);

  /* add if tree is empty */
  if(tree->root == 0){
    tree->root = toInsert;
    return;
  }
  /* append node to where it belongs */
  while(!wasInserted){
    if(strcmp(checkOccupied->str, toInsert->str) > 0){
      if(!(checkOccupied->left)){
	checkOccupied->left = toInsert;
	wasInserted = 1;
      }
      else{
	checkOccupied = checkOccupied->left;
      }
    }
    else if(strcmp(checkOccupied->str, toInsert->str) < 0){
      if(!(checkOccupied->right)){
	checkOccupied->right =toInsert;
	wasInserted = 1;
      }
      else{
	checkOccupied = checkOccupied->right;
      }	
    }
    else{
      puts("Name already in tree. Employee name not added.\n");
      wasInserted =1;
    }
  }
}

/* add name to node so that it can be added to tree */
tNode *addNode(char *s){
  int sLen;
  tNode *toInsert;
  char *copy;
  int i=0;

  /* make all input text lower case */
  while(s[i]){
    s[i] = tolower(s[i]);
    i++;
  }
  /* get length of string (name) */
  for (sLen =0; s[sLen]; sLen++);
  copy = (char *) malloc(sLen+1);

  /* make a copy of input string */
  for(sLen = 0; s[sLen]; sLen++){
    copy[sLen] = s[sLen];
  }
  copy[sLen] = 0; /* terminate copy */

  /* allocate memory for node structure */
  toInsert = (tNode *) malloc(sLen+1);
  toInsert->str = copy;
  toInsert->left = toInsert->right = 0;

  return toInsert;
}

/* Prints tree, and if no members in tree
 * it prints default message */
void printTree(BST *tree){
  if(tree->root == 0){
    puts("Empty tree. \n");
=======

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
>>>>>>> a42de625be37bc25a84142c574fd5c79e2b45392
  }
  else{
    recursivePrint(tree->root);
    puts("\n");
  }
}

<<<<<<< HEAD
/* Recursively prints out the tree in order */
void recursivePrint(tNode *root){
  tNode *visitedL = root->left;
  tNode *visitedR = root->right;
  if(root == 0){
    return;
  }
  else{
    recursivePrint(visitedL);
    printf("<%s>\n", root->str);
    recursivePrint(visitedR);
  }
}

/* Removes name from tree */
void treeRemove(BST *tree, char *toBeRemoved){
  tNode *root = tree->root;
  recursiveRemove(root, toBeRemoved);
}

/* Recursively removes name from tree */
tNode *recursiveRemove(tNode *root, char *toBeRemoved){
  if(root == 0){
    puts("Name not found");
    return root;
  }
  int cmp = (strcmp(root->str, toBeRemoved));
  if(cmp > 0){
    root->left = recursiveRemove(root->left, toBeRemoved);
  }
  else if (cmp < 0){
    root->right = recursiveRemove(root->right, toBeRemoved);
  }
  else{
    /* no children */
    if((root->left == 0) && (root->right == 0)){
      free(root);
      root = 0;
    }
    /* one child, left */
    else if(root->right == 0){
      tNode *temp = root;
      root = root->left;
      free(temp->str);
      free(temp);
    }
    /* one child, right */
    else if(root->left == 0){
      tNode *temp = root;
      root = root->right;
      free(temp->str);
      free(temp);
    }
    /* two children */
    else{
      tNode *temp = findMin(root->right);
      root->str = temp->str;
      root->right = recursiveRemove(root->right, temp->str);
    }
=======
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
>>>>>>> a42de625be37bc25a84142c574fd5c79e2b45392
  }
  return root;
}

<<<<<<< HEAD
/* Find min element in tree */
tNode *findMin(tNode *root){
  if(root == 0){
    return NULL;
  }
  if(root->left != 0){
    return findMin(root->left);
  }
  return root;
}

/* determines if word is a member of the tree
 * code heavily influenced from cs.bu.edu/teaching/c/tree/binary/
 */
int treeIsMember(BST *tree, char *isMem){
  return recurIsMember(tree->root, isMem);
}

/* Recursively checks if word is member of tree */
int recurIsMember(tNode *root, char *isMem){
  if(root == 0){
    return 0;
  }
  if(strcmp(root->str, isMem) == 0){
    return 1;
  }
  if(recurIsMember(root->left, isMem)){
    return 1;
  }
  
  return(recurIsMember(root->right, isMem));
  
}

/* Prints tree to file */
void printTreeToFile(BST *tree, FILE *fp){
  if(tree->root == 0){
    fputs("Tree is empty.\n", fp);
  }
  else{
    recurPrintTreeToFile(tree->root, fp);
    fputs("\n",fp);
  }
}

/* Recursive print tree to file */
void recurPrintTreeToFile(tNode *root, FILE *fp){
=======
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
>>>>>>> a42de625be37bc25a84142c574fd5c79e2b45392
  if(root == 0){
    return;
  }
  else{
<<<<<<< HEAD
    fprintf(fp, "%s\n", root->str);
    recurPrintTreeToFile(root->left, fp);
    recurPrintTreeToFile(root->right, fp);
=======
    fprintf(fp,"%s\n",root->str);
    recPrintToFile(root->small,fp);
    recPrintToFile(root->big,fp);
>>>>>>> a42de625be37bc25a84142c574fd5c79e2b45392
  }
}


<<<<<<< HEAD
  


=======









 
>>>>>>> a42de625be37bc25a84142c574fd5c79e2b45392
