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

void CreatBiTree(bitNode **root){	//���������� 
	char ch;
	cin >> ch;	//��������
	if((ch=getchar()) == '#'){
		*root = NULL;
	} else{
		*root = (bitNode *)malloc(sizeof(bitNode));
//		*root = new bitNode*;
		(*root) -> data = ch;
		//cout << "������" << ch << "�����ӽ��" << endl;
		CreatBiTree(&((*root) -> leftChild));
		//cout << "������" << ch << "�����ӽڵ�" << endl;
		CreatBiTree(&((*root) -> rightChild));
	}
}

void preOrder(bitNode *root){	//ǰ���������������ٵݹ�����ã��ݹ��ҵ��� 
	if(root == NULL)	return;
	//���������������ݹ���ã���������ҵݹ����
	//����������������ݹ���ã����ҵݹ���ã���� 
	cout << root->data << endl;
	preOrder(root -> leftChild);	//�ݹ������ǰ��������ӽ��
	preOrder(root -> rightChild);	//�ݹ������ǰ��������ӽڵ� 
}

int main(void){
	bitNode *root;
	cout << "�ȴ���һ�Ŷ�����" << endl;
	CreatBiTree(&root);
	preOrder(root);
	return 0;
} 
