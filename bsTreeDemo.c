#include <stdio.h>
#include "tree.h"

int main(void)
{
  treeADT t1;         /* A tree of character/int pairs. */
  treeElementT elem;  /* Key/value pair for tree. */

  /* Create a new tree. */

  t1 = TreeCreate();

  /* Add a few elements. */

  elem.key = 'j';
  elem.value = 5;
  TreeAdd(t1, elem);

  elem.key = 'f';
  elem.value = 30;
  TreeAdd(t1, elem);

  elem.key = 'k';
  elem.value = 13;
  TreeAdd(t1, elem);

  elem.key = 'a';
  elem.value = 100;
  TreeAdd(t1, elem);

  elem.key = 'h';
  elem.value = 50;
  TreeAdd(t1, elem);

  elem.key = 'z';
  elem.value = 1;
  TreeAdd(t1, elem);

  /* Try to add it again. */
  TreeAdd(t1, elem);

  /*
   * Print the elements in tree in
   * alphabetical order.
  */

  printf("Elements in alphabetical order:\n");
  TreePrint(t1);

  /* Test some memberships. */

  printf("c is a member = %d\n", TreeIsMember(t1, 'c'));
  printf("a is a member = %d\n", TreeIsMember(t1, 'a'));

  /* We're done with the tree, so destroy it. */
  TreeDestroy(t1);

  return 0;