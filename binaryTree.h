#pragma once

void preorder(binaryTreeNode* p);
void inorder(binaryTreeNode* p);
void postorder(binaryTreeNode* p);
int height(binaryTreeNode* p);
int max(int, int); 
void destroy(binaryTreeNode*& p); 
struct binaryTreeNode {
	int info; 
	binaryTreeNode* llink; 
	binaryTreeNode* rlink; 
};


class binaryTree {
protected:
	binaryTreeNode* root; 
public : 
	const binaryTree& operator=
		(const binaryTree&);
	bool isEmpty(); 
	void inorderTraversal(); 
	void preorderTraversal();
	void postorderTraversal();
	int treeHeight(); 
	int treeNodeCount(); 
	int treeLeavesCount(); 
	void destroyTree(); 
	~binaryTree(); 
	binaryTree(); 
	binaryTree(const binaryTree& otherBinaryTree); 
	friend void inorder(binaryTreeNode*p); 
	friend void preorder(binaryTreeNode* p);
	friend void postorder(binaryTreeNode* p); 
	friend int height(binaryTreeNode* p);
	friend int max(int y, int x); 
	friend void destroy(binaryTreeNode*& p); 

private: 
	void copyTree(binaryTreeNode* & copiedBinaryTreeRoot, binaryTreeNode* otherBinarTreeRoot); 
	int nodeCount(binaryTreeNode*& p); 
	int leaveCount(binaryTreeNode*& p); 
};