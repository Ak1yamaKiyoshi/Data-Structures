
#include <malloc.h>
#include <stdio.h>
#include <strings.h>

struct node {
  struct node *left;
  struct node *right;
  int value;
};

/*
 * allocate node with given value, left and right pointers will set on NULL
 * @param value int value to create node with
 * @return node allocated strcut node node with given value
 */
struct node *allocateNode(int value) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/*
 * calculate node distance to nearest NULL child of this node
 * @param tree - subtree to begin search in
 * @param counter distance to nearest node, ! set 0 if starting at root
 * @return left:right distance to nearest NULL child of this node
 */
int nodeNearestNULLChild(struct node *tree, int counter) {
  if (tree == NULL)
    return counter;
  int left = nodeNearestNULLChild(tree->left, counter + 1);
  int right = nodeNearestNULLChild(tree->right, counter + 1);
  return (left <= right) ? left : right;
}

/*
 * rightmost insert node into the tree with given value
 * @param tree struct node* tree to insert value in
 * @param value value to insert node in tree with
 * @return tree - ! assign return value only if youre creating tree, otherwise
 * it probably be subtree
 */
struct node *insert(struct node *tree, int value) {
  if (tree == NULL)
    return allocateNode(value);
  /* check if left tree is not null, if so, insert node at left */
  else if (tree->left == NULL) {
    tree->left = allocateNode(value);
    return tree;
  }
  /* check if right tree is not null, if so, insert node at right */
  else if (tree->right == NULL) {
    tree->right = allocateNode(value);
    return tree;
  }
  (nodeNearestNULLChild(tree->left, 0) < nodeNearestNULLChild(tree->right, 0))
      ? insert(tree->left, value)
      : insert(tree->right, value);
  return tree;
}

/*
 * rightmost insert array of values into the tree
 * @param tree struct node* tree to insert value in
 * @param array array to insert in tree
 * @param len lenght of array that will be inserted in tree
 * @return tree - ! assign return value only if youre creating tree, otherwise
 * it probably be subtree
 */
struct node *insertFromArray(struct node *tree, int *array, int len) {
  for (int i = 0; i < len; i++)
    if (tree == NULL)
      tree = insert(tree, array[i]);
    else
      insert(tree, array[i]);
  return tree;
}

/*
 * serach node in tree using post order traverse
 * @param tree tree to search value in
 * @param value value to search in list
 * @return node with given value or NULL
 */
struct node *searchPostOrder(struct node *tree, int value) {

  if (tree != NULL) {
    struct node *buffer = searchPostOrder(tree->left, value);

    if (buffer != NULL && buffer->value == value)
      return buffer;

    buffer = searchPostOrder(tree->right, value);

    if (buffer != NULL && buffer->value == value)
      return buffer;

    if (tree->value == value)
      return tree;

    else
      return NULL;
  }
  return NULL;
}

/*
 * find node with minimal value in tree
 * @param tree to search in
 * @return minNode node with min value
 */
struct node *min(struct node *tree) {
  if (tree != NULL) {

    struct node *minNode = tree;
    struct node *buffer = min(tree->left);
    if (buffer != NULL && minNode->value > buffer->value)
      minNode = buffer;
    buffer = min(tree->right);
    if (buffer != NULL && minNode->value > buffer->value)
      minNode = buffer;
    return minNode;

  } else
    return tree;
}

/*
 * find parent of given node
 * @param tree search parent of givent nodeToFind in that tree
 * @param nodeToFind parent of that node will be found if exists
 * @return tree parent of nodeToFInd
 */
struct node *findParentOfNode(struct node *tree, struct node *nodeToFind) {
  if (tree != NULL) {
    if (tree->left == nodeToFind || tree->right == nodeToFind)
      return tree;
    struct node *buffer = findParentOfNode(tree->left, nodeToFind);
    if (buffer != NULL &&
        (buffer->left == nodeToFind || buffer->right == nodeToFind))
      return buffer;
    buffer = findParentOfNode(tree->right, nodeToFind);
    if (buffer != NULL &&
        (buffer->left == nodeToFind || buffer->right == nodeToFind))
      return buffer;
    return NULL;
  } else
    return tree;
}

/*
 * remove lass node by given value from tree
 * @param tree tree to remove node from
 * @param value value of node to remove
 * @return tree - pointer to tree  
 * TODO: delete from root
*/
struct node *removeLast(struct node *tree, int value) {
  // 1. find node with given value 
  struct node *nodePtr = searchPostOrder(tree, value);

  // 2. find minimum value of it's subtrees 
  struct node *minNode = min(nodePtr->left);
  struct node *bufferNode = min(nodePtr->right);

  // 3. assign minimum value to minNode 
  if ( minNode != NULL && bufferNode != NULL) 
    minNode = (minNode->value < bufferNode->value) ? minNode : bufferNode;
  else if (minNode == NULL && bufferNode != NULL)
    minNode = bufferNode;
  else if ( minNode == NULL && bufferNode == NULL)
    minNode = nodePtr; 
  
  // 4.find parent of minNode
  if (minNode != NULL)
    bufferNode = findParentOfNode(tree, minNode);

  // 5. assign value of minimum node to current node 
  if ( nodePtr != minNode )
    nodePtr->value = minNode->value;

  // 6. free and delete pointer to buffer node ( can be current node or can be minimum node in subtrees of current node )
  if (bufferNode != NULL && bufferNode->left == minNode) {
    free(bufferNode->left);
    bufferNode->left = NULL;
  } 
  else if (bufferNode != NULL) {
    free(bufferNode->right);
    bufferNode->right = NULL;
  }

  return tree;
}

/*
 * print binary tree in array look using pre     order traverse
 * @param tree tree to print
 */
void printPreOrder(struct node *tree) {
  if (tree == NULL)
    return;
  printPreOrder(tree->left);
  printf("%d ", tree->value);
  printPreOrder(tree->right);
}

/*
 * print binary tree in array look using in order traverse
 * @param tree tree to print
 */
void printInOrder(struct node *tree) {
  if (tree == NULL)
    return;
  printf("%d ", tree->value);
  printInOrder(tree->left);
  printInOrder(tree->right);
}

/*
 * print binary tree in array look using post order traverse
 * @param tree tree to print
 */
void printPostOrder(struct node *tree) {
  if (tree == NULL)
    return;
  printf("%d ", tree->value);
  printPostOrder(tree->right);
  printPostOrder(tree->left);
}

/*
 * print binary tree in tree look
 * @param tree tree to print
 * @param space spacing between nodes in print (heigher spacing, taller the tree
 * will be)
 */
void fancyPrint(struct node *tree, int space) {
  if (tree == NULL)
    return;
  space += 5;
  fancyPrint(tree->right, space);
  printf("\n");
  for (int i = 5; i < space; i++) {
    printf(" ");
  }
  printf("[%d]<\n", tree->value);
  fancyPrint(tree->left, space);
}

/*
 * calculate max sum of node values path to leaf node in tree 
 * @param tree tree to calculate path in 
 * @return max sum of node values path to leaf node in tree 
*/
int calculateMaxTreePath(struct node* tree) {
  if (tree == NULL) return 0;
  int left = calculateMaxTreePath(tree->left);
  int right = calculateMaxTreePath(tree->right);
  return tree->value + ((left > right) ? left : right);
}

void testInsert() {
struct node *tree = NULL;
  int array[] = {0,  1,  2,  3,  4,  5,   6,     7,    8,   -100,
                 9,  10, 11, 12, 13, -90, 14,    15,   16,  17,
                 18, 19, 20, 21, 22, 23,  -2000, -900, -400};
  tree = insertFromArray(tree, array, 28);

  printf("Tree print: ");
  fancyPrint(tree, 1);
  printf("\nTree traverses print: ");
  printf("\ntree pre order traversal:  ");
  printPreOrder(tree);
  printf("\ntree in order traversal:   ");
  printInOrder(tree);
  printf("\ntree post order traversal: ");
  printPostOrder(tree);
  printf("\n node with value 3 [post order search]: %d",
  searchPostOrder(tree, 3)->value);
  printf("\nminimum of the tree: %d\n", min(tree)->value);
  printf("\n parent of min value: %d",
  findParentOfNode(tree, min(tree))->value);
}

void testRemove() {
struct node *tree = NULL;
  int array[] = {1, 2, 3, 4, 5, 6};
  tree = insertFromArray(tree, array, 6); 

  // two child case
  removeLast(tree, 3); 
  // one child case
  removeLast(tree, 4);
  // terminal node case 
  removeLast(tree, 5);
  // root case 
  // removeLast(tree, 1);

  printf("Tree print: ");
  fancyPrint(tree, 1);
}

void testMaxPath() {
  struct node *tree = NULL;
  int array[] = {0,  1,  100,  3,  4, 5, 70};
  tree = insertFromArray(tree, array, 7);
  printf("max path: %d \n ", calculateMaxTreePath(tree));
  
  printf("Tree print: ");
  fancyPrint(tree, 1);
}

int main() {

  testRemove();

  return 0;
}