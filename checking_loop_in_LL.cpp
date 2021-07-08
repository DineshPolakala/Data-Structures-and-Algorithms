#include<bits/stdc++.h>
using namespace std;

struct Node
{

	int data;
	Node *next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
}*head = NULL;

void Create(int * arr, int n)
{
	Node *temp, *last = NULL;
	head = new Node(arr[0]);
	last = head;
	for (int i = 1; i < n; i++)
	{
		temp = new Node(arr[i]);
		last->next = temp;
		last = last->next;
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

bool isLoop(Node *p)
{
	Node *slow, *fast;
	slow = fast = p;
	do
	{
		slow = slow->next;
		fast = fast->next;
		fast = (fast) ? fast->next : fast ;
	} while (slow and fast and slow != fast);

	if (slow == fast )return true;
	else return false;
}

int starting_element_in_loop(Node *p)
{
	Node *slow, *fast;
	slow = fast = p;
	do
	{
		slow = slow->next;
		fast = fast->next;
		fast = (fast) ? fast->next : fast ;
	} while (slow and fast and slow != fast);

	fast = p;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return fast->data;

	// if (slow == fast )return true;
	// else return false;
}


int main()
{

	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	Create(arr, 7);

	Node *t1, *t2;
	t1 = head->next->next;
	t2 = t1->next->next->next;
	t2->next = t1;



	//Display(head);

	cout << starting_element_in_loop(head) << endl;

	return 0;
}