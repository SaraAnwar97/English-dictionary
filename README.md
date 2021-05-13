# English-dictionary
## Program
A binary search tree based spell checking system is implemented. Initially a dictionary of words is given to build the binary search tree ,the
comparison between strings will be based on strcmp function available in c function. During
the BST ,It is ensured that the tree is balanced. After finishing the
BST , the height of the generated tree is printed.
A sentence to spell check is provided from user as input, then each word in the sentence is checked if it is in the tree or
not
1. If it is in the tree then the word is correct is printed
2. If it isn’t then you will three suggestions for the correct word asre printed,The word in the leaf
node you reached ,the word in the predecessor node and the node in the successor node.
## AVL tree
an AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. It was the first such data structure to be invented.In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. they were the first dynamically balanced trees to be proposed.
## Code Implementation:
## Node structure:<br>
A node in an AVL tree has  data of type string (the word),a right and a left pointers to node, and height of type integer. 
### Height function:
Function height takes the root node as a parameter and returns the height of it. If the node is empty it (root is empty so tree is empty) it returns 0, else it returns the height. 
### Max function:
Function max takes two integers as parameters and comparesthem, if the first integer a is greater than the second integer b it returns a , else it returns b.
### NewNode function:
 Function newNode allocates dynamically a new node n using malloc functions to reserve a pointer , with a given data, it copies the given data into it using strcpy function(copying a string into another string) ,makes address of right and left pointers equal to NULL and height of new node equals 1(initially add it to the leaf) and returns the new node n.
 ### rightRotate function:
 Function rightRotate , right rotates a subtree rooted with y, the unbalanced node y becomes the right child of its left child  node x by performing a right rotation,then updates the height of each node and returns the new root x. 
 ### Function leftRotate:
 Function leftRotate, left rotates a subtree rooted with x,the unbalance x becomes the left subtree of y,then updates the height of each node and returns the new root y.
### getBalance Function:
getBalance gets the balancing factor of node, if node is empty(tree is empty;no children) it returns NULL else, it returns height of its left child-height of its right child.  The balancing factor of any node in an AVL tree should be -1,0,1 only.
### Insert function:
Function Insert is a recursive function that compares two strings using strcmp function. It takes two parameters, the root node and data to be inserted in subtree, if root is equal to NULL(tree is empty), it creates a new node, if data given is less than data stored in node, it inserts the given data in the left of node, else if data given is greater than data stored in node, it inserts the given data in the right of node . Then it updates the height of new node by comparing the height of its left and right and adding 1 to it. When we insert new nodes to a tree it become unbalanced. To keep it balanced,  Starting from inserted node, travel up and find the first unbalanced node by getting the balanced factor. Re-balance the tree by performing appropriate rotations on the subtree rooted with the unbalanced node. We have 4 possible cases for rotation handled as x, y and z can be arranged in 4 ways:
<br> 1) y is left child of z and x is left child of y (Left Left Case)
(if a node is inserted in the left subtree of the left subtree. The tree then needs a single right rotation.)
<br>Solution: right rotate
<br> 2) y is left child of z and x is right child of y (Left Right Case)
(A node has been inserted into the right subtree of the left subtree.)
<br>Solution :  left rotate then right rotate
<br> 3) y is right child of z and x is right child of y (Right Right Case)
(when a node is inserted into the right subtree of the right subtree, then we perform a single left rotation)
<br>Solution : left rotate
<br> 4) y is right child of z and x is left child of y (Right Left Case)
(A node has been inserted into the left subtree of the right subtree.)
<br>Solution: right rotate then left rotate
### FindMax function:
FindMax function starts from root of a tree and gets the maximum data in this tree which is the most right leaf.
### Getpredecessor function:
Getpredecessor function gets predecessor(node with maximum data smaller than a give node) of a subtree.
We have 3 cases for getting the predecessor:
<br>1)node has a left subtree
<br>Predecessor is the greatest data in subtree(most right leaf in its left subtree)
<br>2)node does not have a left subtree and it is the left child of its parent
<br>Predecessor is left subtree of parent
<br>3)node does not have a left subtree and it is the right child of its parent
<br>Predecessor is the parent
### FindMin function:
FindMin function starts from root of a tree and gets the minimum data in this tree which is the most left leaf.
### GetSuccessor function:
Getsuccessor function gets predecessor(node with minimum data greater than a give node) of a subtree.
We have 3 cases for getting the successor:
<br>1)node has a right subtree
<br>Successor is the minimum data in tree(most left leaf in its right subtree)
<br>2)node does not have a right subtree and it is the right child of its parent
<br>Successor is right subtree of parent
<br>3)node does not have a right and it is the left of its parent
<br>Successor is the parent
### searchNode function:
searchNode is a recursive function which searches for a node from root of the tree by the node’s data. If if data given is less than data stored in node, it searches for the given data in the left of node, else if data given is greater than data stored in node, it searches for the given data in the right of node . AVL does not support duplicate data so strcmp==0 is not applicable. If data found it prints that the word is correct, else it prints that the word is not correct.
### notCorrect function:
notCorrect function prints three suggestions,the data in leaf I reached, the predecessor and successor if word is not correct. It sets the predecessor and successor to NULL and calls function search to search for a given data starting from root. If node n(the one I am searching for) right’s and left’s  is equal to NULL and strcmp!=0(cause AVL does not support duplicate data in its tree) , ir prints the three suggestions and returns node n.
### Inorder function:
Inorder function prints data in Inorder sequence LVR (Depth first traversal). It visits left subtree,prints data then visits right subtree.
### Readfile function:
Readfile function reads data from a text file(English Dictionary) and insert them in the AVL tree.then closes the file and prints the height of tree after insertion. Scans a sentence from user and uses strtok to break string into series of tokens. A for loop was made on the length of the sentence to handle upper and lower cases.
## Test cases
<img width="566" alt="Screen Shot 2021-05-13 at 5 38 05 AM" src="https://user-images.githubusercontent.com/38399357/118074000-66c78d00-b3ad-11eb-8bf9-67ec3792117f.png">
<img width="566" alt="Screen Shot 2021-05-13 at 5 39 13 AM" src="https://user-images.githubusercontent.com/38399357/118074092-8eb6f080-b3ad-11eb-9ed2-22c5657d9f82.png">
<img width="566" alt="Screen Shot 2021-05-13 at 5 39 34 AM" src="https://user-images.githubusercontent.com/38399357/118074121-9b3b4900-b3ad-11eb-8109-5b70748d6b1c.png">
<img width="581" alt="Screen Shot 2021-05-13 at 5 40 07 AM" src="https://user-images.githubusercontent.com/38399357/118074163-aee6af80-b3ad-11eb-867c-78b0c52af67b.png">
<img width="537" alt="Screen Shot 2021-05-13 at 5 40 49 AM" src="https://user-images.githubusercontent.com/38399357/118074217-c7ef6080-b3ad-11eb-9cf2-e6ddc1be3d74.png">
