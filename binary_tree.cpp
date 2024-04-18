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

void BinaryTree::preOrderTraversal() const {
    preOrderTraversalHelper(root);
}

void BinaryTree::delFullParent(TreeNode* tree) {
    //TODO: implement this
}

void BinaryTree::delSingleParent(TreeNode* tree)  {
    //TODO: implement this
}

void BinaryTree::delLeaf(TreeNode* tree) {
    //TODO: implement this
}

bool BinaryTree::isFullParent(TreeNode* tree) const {
    //TODO: implement this
}

bool BinaryTree::isSingleParent(TreeNode* tree) const {
    //TODO: implement this
}

bool BinaryTree::isLeaf(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getNode(int x) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getParent(int data, TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getChild(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getLeftChild(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getRightChild(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getLeftMost(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getRightMost(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getPredecessor(TreeNode* tree) const {
    //TODO: implement this
}

BinaryTree::TreeNode* BinaryTree::getSuccessor(TreeNode* tree) const {
    //TODO: implement this
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

    return 0;
}
