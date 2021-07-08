#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
}*head = NULL;

void Insert(int key)
{
	Node * temp = new Node(key);
	Node * last = NULL;
	if (head == NULL)
	{
		head = temp;
		last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
}

void Display(struct Node * p)
{
	while (p != NULL)
	{
		cout << p-> data << " ";
		p = p-> next;
	}

	cout << "\n";
}

int main() {
	Insert(10);
	Insert(20);
	Insert(30);
	Insert(40);

	Display(head);
	return 0;
}