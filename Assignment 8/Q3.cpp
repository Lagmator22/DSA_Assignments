/*
Q3. BST Insert, Delete, Maximum Depth, Minimum Depth
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int x)
{
    Node* t = new Node;
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insertBST(Node* root, int x)
{
    if(root == NULL) return newNode(x);
    if(x < root->data) root->left = insertBST(root->left, x);
    else if(x > root->data) root->right = insertBST(root->right, x);
    // no duplicates
    return root;
}

Node* minNode(Node* root)
{
    if(root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key)
{
    if(root == NULL) return NULL;

    if(key < root->data)
        root->left = deleteBST(root->left, key);
    else if(key > root->data)
        root->right = deleteBST(root->right, key);
    else
    {
        // node found
        if(root->left == NULL)
        {
            Node* r = root->right;
            delete root;
            return r;
        }
        else if(root->right == NULL)
        {
            Node* l = root->left;
            delete root;
            return l;
        }
        else
        {
            Node* succ = minNode(root->right);
            root->data = succ->data;
            root->right = deleteBST(root->right, succ->data);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// (c) Maximum depth (height)
int maxDepth(Node* root)
{
    if(root == NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + (lh > rh ? lh : rh);
}

// (d) Minimum depth
int minDepth(Node* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left == NULL) return 1 + minDepth(root->right);
    if(root->right == NULL) return 1 + minDepth(root->left);

    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return 1 + (lh < rh ? lh : rh);
}

int main()
{
    Node* root = NULL;
    int choice;

    do
    {
        cin >> choice;
        if(choice == 1)
        {
            int x;
            cin >> x;
            root = insertBST(root, x);
        }
        else if(choice == 2)
        {
            int x;
            cin >> x;
            root = deleteBST(root, x);
        }
        else if(choice == 3)
        {
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
        }
        else if(choice == 4)
        {
            cout << "Max Depth: " << maxDepth(root) << "\n";
        }
        else if(choice == 5)
        {
            cout << "Min Depth: " << minDepth(root) << "\n";
        }
        // 0 to exit
    } while(choice != 0);
}
