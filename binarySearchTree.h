#pragma once
#include"binaryTree.h"
class binarySearchTree : public binaryTree {
public:
	bool search(const int&);
	void insert(int ele); 
	void deleteEle(int ele); 
};