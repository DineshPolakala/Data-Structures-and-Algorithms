#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};
Node *head = NULL;

void Create(int *arr, int n)
{
	head = new Node(arr[0]);
	Node *temp, *last;
	last = head;
	for (int i = 1; i < n; i++)
	{
		temp = new Node(arr[i]);
		last->next = temp;
		last = temp;

	}
}

bool isPalindrome_NAIVE(Node *p)
{
	stack<int> s;
	while (p)
	{
		s.push(p->data);
		p = p->next;
	}

	p = head;
	while (p)
	{
		if (p->data != s.top())
			return false;
		s.pop();
		p = p->next;
	}
	return true;

}

int main()
{
	int arr[] = {1, 2, 3, 2, 1};
	int n = 5;

	Create(arr, n);

	bool x = isPalindrome_NAIVE(head);
	if (x) cout << " LL is palindrome " << endl;
	else cout << " Not a Palindrome " << endl;

	return 0;
}