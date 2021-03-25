#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    root = insert(root, x);
   // printTree();
   // cout << endl;
}

/*
*   This is the exact same as the inlab BST insert function,
*   except I have added a height adjustment (copied one 
*   provided by remove function) and implemented balance(n).
*/
AVLNode* AVLTree::insert(AVLNode*& n, const string& x) {
    if (n == NULL) {
        AVLNode* node = new AVLNode();
        node->value = x;
        return node;
        //printTree();
    }
    else if(n->value > x) {
        n->left = insert(n->left, x);
        //printTree();
    }
    else if(n->value < x) {
        n->right = insert(n->right, x);
        //printTree();
    }
    //cout << "height before: " << n->height << " BF: " << height(n->right) - height(n->left) << endl;
    n->height = 1 + max(height(n->left), height(n->right));
    //cout << "height after: " << n->height << " BF: " << height(n->right) - height(n->left) <<  endl;
    balance(n);
    //printTree();
    return n;
}


// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    if(!find(x)) return "";
    else return pathTo(root, x);
}
// Exact same pathTo from BST implementation
string AVLTree::pathTo(AVLNode* const& n, const string& x) const {
    
    // Recursive Base Case
    if(n->value == x) return x;
    // Print next right side
    else if(n->value < x) {
        return (n->value + " " + pathTo(n->right, x));  
    }
    // print next left side
    else {
        return (n->value + " " + pathTo(n->left, x));
    }
}


// Exact same implementation from BST inlab.
bool AVLTree::find(const string& x) const {
    return find(root, x);
}
bool AVLTree::find(AVLNode* const& n, const string& x) const{
    if(n==NULL) return false;

    else if(n->value == x) return true;

    else if(n->value < x)return find(n->right, x);

    else return find(n->left, x);
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes(root);
}

// Exact same implementation from BST inlab.
int AVLTree::numNodes(AVLNode* const& n) const {
    if(n==NULL) return 0; // we are leaf's right/left pointer
    if(n->left == NULL && n->right == NULL) return 1; // we are a leaf, stop.
    else{
        return 1 + numNodes(n->left) + numNodes(n->right);
    }
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // calculate balance factor to determine if balancing is needed.
    int bf = height(n->right) - height(n->left); 
    if (bf < -1) {
        // calculate left subtree's balance factor.
        int leftBF = height(n->left->right) - height(n->left->left);
        if (leftBF <= 0) {
            
            n = rotateRight(n);
        } 
            
        else {
            n->left = rotateLeft(n->left);
            n = rotateRight(n);
        }
    }

    else if (bf > 1) {
        // calculate right subtree's balance factor.
        int rightBF = height(n->right->right) - height(n->right->left);
        if (rightBF >= 0) {
            n = rotateLeft(n);
        } 
        
        else {
            n->right = rotateRight(n->right);
            n = rotateLeft(n);
        }
    }
    //else - DO NOTHING, Tree is balanced.
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    //cout << "RotateLeft" << endl;
    //printTree();
    AVLNode* parent = n->right;
    n->right = parent->left;
    parent->left = n;
    n->height = 1 + max(height(n->left), height(n->right));
    parent->height = 1 + max(height(parent->left), height(parent->right));
    //cout << "RotateRight Finished" << endl;
    //printTree();
    return parent;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    //cout << "RotateRight" << endl;
    //printTree();
    AVLNode* parent = n->left;
    n->left = parent->right;
    parent->right = n;
    n->height = 1 + max(height(n->left), height(n->right));
    parent->height = 1 + max(height(parent->left), height(parent->right));
    //cout << "RotateRight Finished" << endl;
    //printTree();

    return parent;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right)); 
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
