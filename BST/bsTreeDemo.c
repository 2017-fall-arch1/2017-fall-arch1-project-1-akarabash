#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bsTree.h"

int gets_n(char *s, int limit){
  char *p =s;
  char c;
  if(fgets(s, limit, stdin)){
    while ((c = *p) && c != '\n'){
      p++;
    }
    if(c == '\n'){
      *p = 0;
    }
    return (p - s);
  }
}

int main(void){
  BST *tree;       /* A tree of names (char) */
  char name [30];  /* character */
  FILE *fp;

  
  
  int choice;

  /* Create a new tree */
  tree = BST_Alloc();

  while(1){
    printf("\n1-Insert Name \n2-Search Name \n3-Delete Name \n4-PrintToFile \n5-PrintTree \n6-Exit \nEnter number corresponding to desired selection: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      printf("Enter name: ");
      scanf("%s", name);
      treeAdd(tree, name);
      break;
    case 2:
      printf("Enter name to search for: ");
      scanf("%s", name);
      if(treeIsMember(tree, name)){
	printf("Name found in tree: %s",name);
      }
      else{
	printf("Name NOT found in tree");
      }
      break;
    case 3:
      printf("Enter name to delete from tree: ");
      scanf("%s", name);
      treeRemove(tree, name);
      break;
    case 4:
      printTreeToFile(tree, fp);
      /*fp = fopen("test.txt", "w");
      if( fp == 0){
	printf("Error opening file!\n");
	exit(1);
      }
      fclose(fp);*/
    case 5:
      printTree(tree);
    case 6:
      exit(0);
    default:
      printf("INVALID CHOICE");
    }
  }
}

  
  
  
