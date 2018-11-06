#pragma once

struct Node {
	Node *next;//�����ٲ�
	int items[8];
	
};

class LinkedNodeStack {
private:
	Node *head;
	int top;
public:
	LinkedNodeStack();
	~LinkedNodeStack();
	bool isempty() const;
	bool isfull() const;
	bool push(const int & item);
	bool pop(int & item);
};
