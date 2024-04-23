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
    void delFullParent(TreeNode* tree);
    void delSingleParent(TreeNode* tree);
    void delLeaf(TreeNode* tree);
    bool isFullParent(TreeNode* tree) const;
    bool isSingleParent(TreeNode* tree) const;
    bool isLeaf(TreeNode* tree) const;
    TreeNode* getNode(int data) const;
    TreeNode* getParent(int data) const;
    TreeNode* getParentHelper(int data, TreeNode* tree) const;
    TreeNode* getChild(TreeNode* tree) const;
    TreeNode* getLeftChild(TreeNode* tree) const;
    TreeNode* getRightChild(TreeNode* tree) const;
    TreeNode* getLeftMost(TreeNode* tree) const;
    TreeNode* getRightMost(TreeNode* tree) const;
    TreeNode* getPredecessor(TreeNode* tree) const;
    TreeNode* getSuccessor(TreeNode* tree) const;
    TreeNode* getMinimum(TreeNode* tree) const;
    TreeNode* getMaximum(TreeNode* tree) const;
    
public:
    BinaryTree();
    ~BinaryTree();
    int testGetPredecessor(int data) const;
    void insert(int data);
    bool search(int data) const;
    void inOrderTraversal() const;
    void preOrderTraversal() const;
    bool del(int data);
};

#endif
