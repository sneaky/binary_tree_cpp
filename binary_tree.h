#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinaryTree {
private:
    typedef struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : data(0), left(nullptr), right(nullptr) {}
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
        TreeNode(int val, TreeNode* left, TreeNode* right) : data(val), left(left), right(right) {}
    } TreeNode;

    TreeNode* root;

    TreeNode* insertHelper(int data, TreeNode* tree);
    TreeNode* insertAtRootHelper(int data, TreeNode* tree);
    TreeNode* searchHelper(int data, TreeNode* tree) const;
    void inOrderTraversalHelper(TreeNode* tree) const;
    void preOrderTraversalHelper(TreeNode* tree) const;
    void destroyTree(TreeNode* tree);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int data);
    bool search(int data) const;
    void inOrderTraversal() const;
    void preOrderTraversal() const;
};

#endif