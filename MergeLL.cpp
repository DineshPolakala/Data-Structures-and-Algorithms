#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
}*first = NULL, *second = NULL, *third = NULL;

void create1(int *arr, int n)
{
	Node *last, *temp;
	first = new Node(arr[0]);
	last = first;
	for (int i = 1; i < n; i++)
	{
		temp = new Node(arr[i]);
		last ->next = temp;
		last = last->next;
	}

}

void create2(int *arr, int n)
{
	Node *last, *temp;
	second = new Node(arr[0]);
	last = second;
	for (int i = 1; i < n; i++)
	{
		temp = new Node(arr[i]);
		last ->next = temp;
		last = last->next;
	}

}

void Merge(Node *first, Node* second)
{

	Node *last = NULL;
	if (first->data < second->data)
	{
		third = last = first;
		first = first->next;
		last->next = NULL;
	}
	else
	{
		third = last = second;
		second = second->next;
		last->next = NULL;
	}

	while (first and second)
	{
		if (first->data < second -> data)
		{
			last->next = first;
			last = first;
			first = first->next;
			last ->next = NULL;

		}
		else
		{
			last ->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	if (first)
		last->next = first;
	else
		last->next = second;
}


void Display(Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("MERGELLinput.txt", "r", stdin);
	freopen("MERGELLoutput.txt", "w", stdout);
#endif

	int n1, n2;
	cin >> n1;
	cin >> n2;

	int arr1[n1], arr2[n2];

	for (int i = 0; i < n1; i++)
		cin >> arr1[i];
	for (int i = 0; i < n2; i++)
	{
		cin >> arr2[i];
	}

	// code begins

	create1(arr1, n1);
	create2(arr2, n2 );

	//create(arr2, n2, second);
	Display(first);
	Display(second);

	Merge(first, second);
	cout << "After Merging :\n";

	Display(third);


	return 0;
}