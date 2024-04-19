#include "binary_tree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode* tree) {
    if (tree != nullptr) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

BinaryTree::TreeNode* BinaryTree::insertHelper(int data, TreeNode* tree) {
    if (tree == nullptr) {
        return new TreeNode(data);
    }

    if (data < tree->data) {
        tree->left = insertHelper(data, tree->left);
    } else if (data > tree->data) {
        tree->right = insertHelper(data, tree->right);
    }

    return tree;
}

void BinaryTree::insert(int data) {
    root = insertHelper(data, root);
}

BinaryTree::TreeNode* BinaryTree::searchHelper(int data, TreeNode* tree) const {
    if (tree == nullptr || tree->data == data) {
        return tree;
    }

    if (data < tree->data) {
        return searchHelper(data, tree->left);
    } else if (data > tree->data) {
        return searchHelper(data, tree->right);
    }

    return tree;
}

bool BinaryTree::search(int data) const {
    return searchHelper(data, root) != nullptr;
}

void BinaryTree::inOrderTraversalHelper(TreeNode* tree) const {
    if (tree != nullptr) {
        inOrderTraversalHelper(tree->left);
        cout << tree->data << " ";
        inOrderTraversalHelper(tree->right);
    }
}

void BinaryTree::inOrderTraversal() const {
    inOrderTraversalHelper(root);
    cout << endl;
}

void BinaryTree::preOrderTraversalHelper(TreeNode* tree) const {
    if (tree != nullptr) {
        cout << tree->data << " ";
        preOrderTraversalHelper(tree->left);
        preOrderTraversalHelper(tree->right);
    }
}

void BinaryTree::preOrderTraversal() const {
    preOrderTraversalHelper(root);
}

bool BinaryTree::del(int data) {
    TreeNode* curr = getNode(data);
    
    if (curr == nullptr) { return false; }

    if (isLeaf(curr)) {
        delLeaf(curr);
    } else if (isFullParent(curr)) {
        delFullParent(curr);
    } else {
        delSingleParent(curr);
    }

    return true;
}

void BinaryTree::delFullParent(TreeNode* tree) {
    TreeNode* curr = getSuccessor(tree);
    int x = curr->data;

    if (isLeaf(curr)) {
        delLeaf(curr);
    } else {
        if (curr->data > getParent(curr->data, curr)->data) {
            getParent(curr->data, curr)->right = curr->right;
        } else {
            getParent(curr->data, curr)->left = curr->left;
        }
        delete curr;
    }

    tree->data = x;
}

void BinaryTree::delSingleParent(TreeNode* tree)  {
    TreeNode* curr = getParent(tree->data, tree);

    if (curr->right == tree) {
        curr->right = getChild(tree);
    } else {
        curr->left = getChild(tree);
    }

    delete tree;
}

void BinaryTree::delLeaf(TreeNode* tree) {
    if (tree == getParent(tree->data, tree)->right) {
        getParent(tree->data, tree)->right = nullptr;
    } else {
        getParent(tree->data, tree)->left = nullptr;
    }

    delete tree;
}

bool BinaryTree::isFullParent(TreeNode* tree) const {
    return getNode(tree->data)->left != nullptr && getNode(tree->data)->right != nullptr;
}

bool BinaryTree::isSingleParent(TreeNode* tree) const {
    return !isFullParent(tree) && !isLeaf(tree);
}

bool BinaryTree::isLeaf(TreeNode* tree) const {
    return getNode(tree->data)->left == nullptr && getNode(tree->data)->right == nullptr;
}

BinaryTree::TreeNode* BinaryTree::getNode(int x) const {
    TreeNode* curr = root;
    while (curr->data != x) {
        if (curr == nullptr) { return nullptr; }
        if (curr->data > x) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return curr;
}

BinaryTree::TreeNode* BinaryTree::getParent(int data, TreeNode* tree) const {
    if (tree == nullptr) { return nullptr; }

    TreeNode* curr = root;
    return getParentHelper(data, curr);
}

// TODO: fix getParent() so that we don't need this helper function.
// since we only need access to the data we want to find and the root node,
// change getParent() parameters so we only need to pass it the data we're looking for.
BinaryTree::TreeNode* BinaryTree::getParentHelper(int data, TreeNode* tree) const {
    if (isFullParent(tree)) {
        if (tree->left->data == data || tree->right->data == data) { return tree; }
    } else {
        if (getChild(tree)->data == data) { return tree; }
    }

    if (tree->data > data) {
        return getParentHelper(data, tree->left);
    } else {
        return getParentHelper(data, tree->right);
    }
}

BinaryTree::TreeNode* BinaryTree::getChild(TreeNode* tree) const {
    if (isSingleParent(tree)) {
        if (tree->right != nullptr) {
            return tree->right;
        }
        return tree->left;
    }
    return nullptr;
}

BinaryTree::TreeNode* BinaryTree::getLeftChild(TreeNode* tree) const {
    if (tree == nullptr) { return nullptr; }
    return tree->left;
}

BinaryTree::TreeNode* BinaryTree::getRightChild(TreeNode* tree) const {
    if (tree == nullptr) { return nullptr; }
    return tree->right;
}

BinaryTree::TreeNode* BinaryTree::getLeftMost(TreeNode* tree) const {
    if (tree->left == nullptr) { return tree; }
    return getLeftMost(tree->left);
}

BinaryTree::TreeNode* BinaryTree::getRightMost(TreeNode* tree) const {
    if (tree->right == nullptr) { return tree; }
    return getRightMost(tree->right);
}

BinaryTree::TreeNode* BinaryTree::getPredecessor(TreeNode* tree) const {
    if (tree == nullptr) { return nullptr; }
    TreeNode* curr = tree;

    if (curr->left != nullptr) {
        return getMaximum(curr->left);
    } else if (getParent(curr->data, curr) != nullptr && getParent(curr->data, curr)->right == curr) {
        return getParent(curr->data, curr);
    } else {
        TreeNode* predecessor = getParent(curr->data, curr);

        while (predecessor != nullptr && predecessor->left == curr) {
            curr = predecessor;
            predecessor = getParent(predecessor->data, predecessor);
        }
        
        return predecessor;
    }
}

BinaryTree::TreeNode* BinaryTree::getSuccessor(TreeNode* tree) const {
    if (tree == nullptr) { return nullptr; }
    // TODO: test if we can modify tree instead of creating a pointer to it
    TreeNode* curr = tree;
    
    if (curr->right != nullptr) {
        return getMinimum(curr->right);
    }

    TreeNode* successor = getParent(curr->data, curr);

    while (successor != nullptr && curr == successor->right) {
        curr = successor;
        successor = getParent(curr->data, curr);
    }

    return successor;
}

BinaryTree::TreeNode* BinaryTree::getMinimum(TreeNode* tree) const {
    TreeNode* curr = tree;
    
    while (curr->left != nullptr) {
        curr = curr->left;
    }

    return curr;
}

BinaryTree::TreeNode* BinaryTree::getMaximum(TreeNode* tree) const {
    TreeNode* curr = tree;

    while (curr->right != nullptr) {
        curr = curr->right;
    }

    return curr;
}



int main() {
    BinaryTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Searching for 30: " << (bst.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 60: " << (bst.search(60) ? "Found" : "Not Found") << endl;
    cout << "Searching for 61: " << (bst.search(61) ? "Found" : "Not Found") << endl;

    cout << "inOrder: ";
    bst.inOrderTraversal();
    cout << "preOrder: ";
    bst.preOrderTraversal();
    cout << endl;

    bst.del(60);
    cout << "Deleted 60." << endl;
    cout << "inOrder: ";
    bst.inOrderTraversal();
    cout << endl;

    return 0;
}
