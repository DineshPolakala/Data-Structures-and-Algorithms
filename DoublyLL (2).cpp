#include<bits/stdc++.h>
using namespace std;

struct Node {

	int data;
	Node *next, *previous;

	Node(int x)
	{
		data = x;
		next = NULL;
		previous = NULL;
	}
}*head = NULL;

void Create(int *arr, int n)
{

	head = new Node(arr[0]);
	Node *temp, *last;
	last = head;
	for (int i = 1; i < n; i++)
	{
		temp = new Node(arr[i]);
		last->next = temp;
		temp->previous = last;
		last = last->next;
	}
}

void Insert(Node *p, int index, int key)
{
	Node *temp;
	temp = new Node(key);
	if (index == 0)
	{
		temp->next = head;
		head->previous = temp;
		//delete head;
		head = temp;

	}
	else
	{
		int count = 0;

		while (count < index - 1)
		{
			p = p->next;
			count++;
		}
		temp->next = p->next;
		p->next->previous = temp;
		p->next = temp;
		temp->previous = p;

	}
}

void Display(Node *p)
{
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}
void Reversedisplay(Node *p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p )
	{
		cout << p->data << " ";
		p = p->previous;
	}
	cout << "\n";
}


int main()
{
#ifndef ONLiNE_JUDGE
	freopen("DoublyLLinput.txt", "r", stdin);
	freopen("DoublyLLoutput.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	Create(arr, n);
	Display(head);
	Insert(head , 2, 10);
	Display(head);

	return 0;
}