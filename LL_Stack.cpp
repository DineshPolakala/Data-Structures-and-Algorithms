#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

struct Stack {
	int cap;
	Node *head;
	Stack()
	{
		cap = 0;
		head = NULL;
	}

	void push(int x)
	{
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;
		cap++;
	}

	int pop()
	{
		if (head == NULL) {cout << "Stack Underflow\n"; return -1;}
		int res = head->data;
		Node *temp = head;
		head = head->next;
		delete temp;
		cap--;
		return res;
	}

	int peek()
	{
		if (head == NULL) {cout << "Stack Underflow\n"; return -1;}
		return head->data;
	}

	int size() {
		return cap;
	}

	bool isempty()
	{
		if (head == NULL)return true;
		return false;
	}



};

int main()
{
	Stack s;
	s.push(5);
	s.push(10);
	s.push(20);
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.peek() << endl;
	cout << s.isempty() << endl;

	return 0;
}