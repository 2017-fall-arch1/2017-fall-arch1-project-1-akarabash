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
  }
  else{
    recursivePrint(tree->root);
    puts("\n");
  }
}

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
  }
  return root;
}

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

/* determines if word is a member of the tree */
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
  if(root == 0){
    return;
  }
  else{
    fprintf(fp, "%s\n", root->str);
    recurPrintTreeToFile(root->left, fp);
    recurPrintTreeToFile(root->right, fp);
  }
}


  


