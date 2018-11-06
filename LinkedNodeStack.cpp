#include "LinkedNodeStack.h"
#include <iostream>
using namespace std;

LinkedNodeStack::LinkedNodeStack() {
	head = nullptr;
	//top = -1;
	top = 0;
}
LinkedNodeStack::~LinkedNodeStack() {
	
	while (!isempty()) //링크드 노드 스택이 완전히 비기 전까지
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

	if (head == nullptr) { // 1번째 노드
		Node *newStack = new Node;//구조체 동적 할당 가능하다.
		newStack->next = nullptr;
		head = newStack;
		head->items[0]= item;
		//newStack->items[0] = item;
		top++;
	}
	else if (top%8 == 0 && head != NULL) {// 2번째 이상의 노드
		cout << "PUSH: allocating a new node" << endl;
		Node *newStack = new Node;
		newStack->next=head;//head가 가리키는 것을 newStack이 가리키게 한다.
		head = newStack;//head가 newStack을 가리키게 해서 연결한다.
		head->items[0] = item;
		top = 1;
	}else {
		head->items[top] = item;
		top++;
	}
	return true;
}
bool LinkedNodeStack::pop(int & item) { // top이 0인 수는 없다. 1개가 push 될 경우에만 newNode가 만들어지니까.
	if (head==nullptr) {//빈 스택에서 마지막 노드에서 삭제할 경우
		return false;
	}
	else if (top==1) { // 2번째 이상 노드에서 
		if (head->next==nullptr) {//마지막 노드일 경우
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
