#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TYPE char*
// A structure which represents an AVL node
typedef struct node
{
    char data[50];
    struct node *left,*right;
    int height;
} node;
// A function that returns height of the AVL tree
int height(node*n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
// A functions that returns the maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
// A function to allocate a new node in the tree
node* newNode(TYPE data)
{
    node* n=(node*)malloc(sizeof(node));
    strcpy(n->data,data);
    n->left=n->right=NULL;
    n->height=1;
    return n;
}
// A function to right rotate subtree and y is its root
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    //perform rotation
    x->right = y;
    y->left = T2;
    //update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    //return new root
    return x;
}
// A function to left rotate subtree and x is its root
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    //perform rotation
    y->left = x;
    x->right = T2;
    //update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    //return new root
    return y;
}
// Get Balance factor of node n (A balanced AVL should have a balanced factor <1 and >-1)
int getBalance(node*n)
{
    if (n== NULL)
        return 0;
    return height(n->left) - height(n->right);
}
 //Recursive function to insert data in subtree and node is its root.It returns new root of subtree.
node* Insert(node* n, TYPE data)
{ //Normal BST insertion
    if(n == NULL)
        n=newNode(data);
    if(strcmp(data,n->data)<0)
        n->left = Insert(n->left,data);
    else if(strcmp(data,n->data)>0)
        n->right = Insert(n->right,data);
        // Update height of this ancestor node
    n->height = 1 + max(height(n->left),height(n->right));
    //Get the balance factor of this ancestor node to check whether this node became unbalanced
                        int balance = getBalance(n);
// If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && strcmp(data,n->left->data)==-1)
        return rightRotate(n);
        // Right Right Case
    if (balance < -1 &&  strcmp(data,n->right->data)==1)
        return leftRotate(n);
         // Left Right Case
    if (balance > 1 && strcmp(data, n->left->data)==1)
    {
        n->left =  leftRotate(n->left);
        return rightRotate(n);
    }
    // Right Left Case
    if (balance < -1 && strcmp(data, n->right->data)==-1)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    //return the (unchanged) node pointer
    return n;
}
// A function that returns the node with maximum data in a tree
node* FindMax(node*root)
{
    if(root==NULL)
        return NULL;
    while(root->right)// root->right != NULL
        root=root->right;
    return root;
}
// A function that gets predecessor(node with maximum data smaller than a give node) of a subtree.
node* GetPredecessor(node*root,node*current)
{
    if(current == NULL) return NULL;
    if(current->left != NULL)    //Case 1: Node has left subtree
    {
        return FindMax(current->right);
    }
    else     //Case 2: Node does not have a left subtree
    {
        node* predecessor = NULL;
        node* ancestor = root;
        while(ancestor != current)
        {
            if(strcmp(current->data,ancestor->data)>0)
            {
                predecessor = ancestor; // so far this is the deepest node for which current node is in right
                ancestor = ancestor->right;
            }
            else if(strcmp(current->data,ancestor->data)<0)
                ancestor = ancestor->left;
        }
        if(predecessor!=NULL)
            printf(",%s",predecessor);
        return predecessor;
    }
}

// A function that returns the node with minimum data in a subtree
node* FindMin(node*root)
{
    if(root == NULL) return NULL;
    while(root->left) //root->left != NULL
        root = root->left;
    return root;
}
// A function that gets successor (node with minimum data greater  than a give node) of a subtree.
node* Getsuccessor(node*root,node*current)
{
    if(current == NULL) return NULL;
    if(current->right != NULL)    //Case 1: Node has right subtree.
    {
        return FindMin(current->right);
    }
    else  {   //Case 2: Node does not have a right subtree.
        node* successor = NULL;
        node* ancestor = root;
        while(ancestor != current)
        {
            if(strcmp(current->data,ancestor->data)<0)
            {
                successor = ancestor; // so far this is the deepest node for which current node is in left.
                ancestor = ancestor->left;
            }
            else if(strcmp(current->data,ancestor->data)>0)
                ancestor = ancestor->right;
        }
        if(successor!=NULL)
            printf(",%s.",successor->data);
        return successor;
    }
}
// A function that searches in subtree for a specific node
node* searchNode(node*root,TYPE data)
{
    node* n = root;//a dummy node in order not to mess with the root
    if(n->left==NULL&&n->right==NULL&&strcmp(data,n->data)!=0)
    {
        printf ("Word is not correct!\n");
        node* temp=n;
        return temp;
    }
    if (strcmp(data,n->data)<0)
    {
        searchNode(n->left, data);

    }

    else if(strcmp(data,n->data)>0)
    {
        searchNode(n->right, data);
    }


    else // the current node n is the node with the right data
    {
        printf("Word is correct.\n ");

        return n;
    }
}
// A function that prints three suggestions,the data in leaf I reached, the predecessor and successor.
node* notCorrect(node*root, char *data)
{
    node* successor= NULL;
    node* predecessor=NULL;
    node*n=searchNode(root,data);
    if(n->left==NULL&&n->right==NULL&&strcmp(data,n->data)!=0)
    {
        printf("Here are some suggestions: %s",&n->data);
        GetPredecessor(root,n);
        Getsuccessor(root,n);
    }
    return n;
}

// A functions that prints data in Inorder sequence LVR (Depth first traversal)
void Inorder(node*n)
{
    if(n == NULL) return;

    else Inorder(n->left);       //Visit left subtree
    printf("%s ",n->data);  //Print data
    Inorder(n->right);      // Visit right subtree
}
// A function that reads data from a text file and insert them in the AVL tree.
void ReadFile()
{
    char word[50];
    node*root=NULL;
    int i;
    FILE *f;
    f=fopen("English Dictionary.txt","r");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f, "%s",word);
            fscanf(f,"\n");
            root=Insert(root,word);
        }
    }
    fclose(f);
    int heightt=height(root);
    printf("Height of tree=%d\n",heightt);
    printf("Please enter a sentence:\n");
    char sen[100];
    gets(sen);

    char*input=strtok(sen," ");
    while(input!=NULL)
    {
        for(i=0; i<=strlen(input); i++)
        {
            if(input[i]>='A' && input[i]<='Z')
                input[i]=input[i]+32;
        }
        printf("\n%s\n",input);
        node*b=notCorrect(root,input);
        input=strtok(NULL," ");
    }
}


int main()
{
    ReadFile();

    return 0;
}
