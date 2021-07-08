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
}*head = NULL;

void Create(int arr[], int n)
{
	head = new Node(arr[0]);
	Node *temp;
	Node *p = head;
	for (int i = 1; i < n; i++)
	{
		temp = new Node(arr[i]);
		p->next = temp;
		p = temp;

	}
}
Node *ReverseK(Node *head, int k)
{
	if (head == NULL or k == 1)return head;
	bool is_first = true;
	Node *cur = head,  *prev_first = NULL;

	while (cur )
	{
		Node *first = cur,  *prev = NULL;
		int count = 0;
		while (cur and count < k)
		{
			Node *next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			count++;
		}

		if (is_first ) {
			is_first = false;
			head = prev;
		}
		else
		{
			prev_first->next = prev;
		}
		prev_first = first;
	}
	return head;

}

Node* Rreversek(Node *head, int k)
{
	if (head == NULL or head->next == NULL)return head;
	Node *cur = head, *prev = NULL, *next = NULL;
	int count = 0;
	while (cur and count < k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}
	if (next)
	{
		Node *rest_head = Rreversek(next , k);
		head->next = rest_head;
	}
	return prev;
}

void Display(Node *p)
{
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	Create(arr, 5);

	Display(head);
	head = Rreversek(head, 3);
	Display(head);


	return 0;
}