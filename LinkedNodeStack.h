#pragma once

struct Node {
	Node *next;//¼ø¼­¹Ù²Þ
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
