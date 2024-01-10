#include"binaryTree.h"
#include"binarySearchTree.h"
#include<iostream>
using namespace std;



void binarySearchTree::insert(int ele) {
	if (!search(ele)) {

		binaryTreeNode* newNode; 
		newNode = new binaryTreeNode;
		newNode->info = ele; 
		newNode->llink = 0; 
		newNode->rlink = 0; 

		if (root == 0)
		{
			root = newNode; 
		}
		else
		{
			binaryTreeNode* current, * trailCurrent; 
			current = root; 
			while (current != 0)
			{
				trailCurrent = current; 
				if (current->info > ele) {
					current = current->llink; 
				}
				else if (current->info < ele) {
					current = current->rlink;
				}
			}
			if (trailCurrent->info > ele)
				trailCurrent->llink = newNode;
			else
				trailCurrent->rlink = newNode; 
		}
	}
}


void binarySearchTree::deleteEle(int ele) {
	if (search(ele)) {
		if (root->info == ele) {
			auto temp = root;
			root = root->llink;
			delete temp; 
		}
		else {
			auto  current = root; 
			while (current != 0) {
				auto trailCurrent = current; 
				if (current->info > ele) {
					current = current->llink; 
				}
			}
		}
	}
}
binaryTree::binaryTree(const binaryTree& otherTree) {
	if (otherTree.root == 0) {
		root = 0;
	}
	else {
		copyTree(this->root, otherTree.root); 
	}
}

bool binarySearchTree::search(const int& ele) {
	if (root == 0)
		return false; 
	bool found = false; 
	binaryTreeNode* current = root; 
	while (!found && current != 0) {
		if (current->info == ele)
			found = true; 
		else if (current->info > ele) {
			current = current->rlink; 
		}
		else if (current->info < ele) {
			current = current->llink;
		}
	}
	return found; 
}

const binaryTree& binaryTree::operator=(const binaryTree&other) {
	if (this != &other) {
		if (root != 0) {
			destroy(root);
		}
		if (other.root == 0) {
			root = 0;
		}
		else
		{
			copyTree(root, other.root);
		}
	}return *this; 
}

binaryTree::~binaryTree() {
	destroy(root); 
}
binaryTree::binaryTree() {
	root = 0; 
}

void binaryTree::destroyTree() {
	destroy(root); 
}

void destroy(binaryTreeNode*& p) {
	if (p != 0) {
		destroy(p->llink);
		destroy(p->rlink);
		delete p; 
		p = 0; 
	}
}
void binaryTree::copyTree(binaryTreeNode*& copiedTreeRoot, binaryTreeNode* otherTreeRoot) {
	if (otherTreeRoot == 0) {
		copiedTreeRoot = 0; 
	}
	else {
		copiedTreeRoot = new binaryTreeNode;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink); 
	}
}
bool binaryTree::isEmpty() {
	return (this->root == 0); 
}

void inorder(binaryTreeNode* p) {
	if (p != 0) {
		inorder(p->llink); 
		cout << p->info << " "; 
		inorder(p->rlink); 
	}
}


void preorder(binaryTreeNode* p) {
	if (p != 0) {
		cout << p->info << " "; 
		preorder(p->llink);
		preorder(p->rlink); 
	}
}


void postorder(binaryTreeNode* p) {
	if (p  != 0) {
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " "; 
	}
}


void binaryTree::inorderTraversal() {
	inorder(root); 
}

void binaryTree::preorderTraversal() {
	preorder(root); 
}

void binaryTree::postorderTraversal() {
	postorder(root); 
}


int binaryTree::treeHeight() {
	height(root); 
}


int height(binaryTreeNode* p) {
	if (p == 0) {
		return 0; 
	}
	else {
		return 1 + max(height(p->llink), height(p->rlink)); 
	}
}

int max(int x, int y) {
	return x > y ? x : y; 
}