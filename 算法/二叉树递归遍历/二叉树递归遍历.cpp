#include<stdio.h>
#include<iostream>
#include<queue>    
#include<stack>  
#include <cstdlib>  
using namespace std;

typedef struct biTree{
	char data;
	struct biTree *leftChild;
	struct biTree *rightChild;
}bitNode;

void CreatBiTree(bitNode **root){	//创建二叉树 
	char ch;
	cin >> ch;	//输入数据
	if((ch=getchar()) == '#'){
		*root = NULL;
	} else{
		*root = (bitNode *)malloc(sizeof(bitNode));
//		*root = new bitNode*;
		(*root) -> data = ch;
		//cout << "请输入" << ch << "的左子结点" << endl;
		CreatBiTree(&((*root) -> leftChild));
		//cout << "请输入" << ch << "的右子节点" << endl;
		CreatBiTree(&((*root) -> rightChild));
	}
}

void preOrder(bitNode *root){	//前序遍历，先输出，再递归左调用，递归右调用 
	if(root == NULL)	return;
	//中序遍历就是先左递归调用，输出，再右递归调用
	//后续遍历就是先左递归调用，再右递归调用，输出 
	cout << root->data << endl;
	preOrder(root -> leftChild);	//递归遍历，前序调用左子结点
	preOrder(root -> rightChild);	//递归遍历，前序调用右子节点 
}

int main(void){
	bitNode *root;
	cout << "先创建一颗二叉树" << endl;
	CreatBiTree(&root);
	preOrder(root);
	return 0;
} 
