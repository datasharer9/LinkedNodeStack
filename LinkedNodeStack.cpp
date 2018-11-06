#include "LinkedNodeStack.h"
#include <iostream>
using namespace std;

LinkedNodeStack::LinkedNodeStack() {
	head = nullptr;
	//top = -1;
	top = 0;
}
LinkedNodeStack::~LinkedNodeStack() {
	
	while (!isempty()) //��ũ�� ��� ������ ������ ��� ������
	{
		Node* p = head;
		head = p->next;

		delete p;
	}
}
bool LinkedNodeStack::isempty() const {
	return head == nullptr;
}
bool LinkedNodeStack::isfull() const {
	return top%8==0;
}
bool LinkedNodeStack::push(const int & item) { 

	if (head == nullptr) { // 1��° ���
		Node *newStack = new Node;//����ü ���� �Ҵ� �����ϴ�.
		newStack->next = nullptr;
		head = newStack;
		head->items[0]= item;
		//newStack->items[0] = item;
		top++;
	}
	else if (top%8 == 0 && head != NULL) {// 2��° �̻��� ���
		cout << "PUSH: allocating a new node" << endl;
		Node *newStack = new Node;
		newStack->next=head;//head�� ����Ű�� ���� newStack�� ����Ű�� �Ѵ�.
		head = newStack;//head�� newStack�� ����Ű�� �ؼ� �����Ѵ�.
		head->items[0] = item;
		top = 1;
	}else {
		head->items[top] = item;
		top++;
	}
	return true;
}
bool LinkedNodeStack::pop(int & item) { // top�� 0�� ���� ����. 1���� push �� ��쿡�� newNode�� ��������ϱ�.
	if (head==nullptr) {//�� ���ÿ��� ������ ��忡�� ������ ���
		return false;
	}
	else if (top==1) { // 2��° �̻� ��忡�� 
		if (head->next==nullptr) {//������ ����� ���
			head = nullptr;
			return true;
		}
		item = head->items[0];
		head = head->next;
		cout << "POP: deleting a node" << endl;
		top = 8;
	}
	else {
		top -= 1;
		item = head->items[top];

	}

		return true;
	}
