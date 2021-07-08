#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data ;
	Node *next ;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
}*head = NULL;

void Create(int * arr, int n)
{
	head = new Node(arr[0]);
	Node *temp, *last = NULL;
	last = head;
	for (int i = 1; i < n ; i++)
	{
		temp = new Node(arr[i]);
		last->next = temp;
		last = last->next;
	}
	last->next = head;
}

void Insert(Node *p, int pos, int key)
{
	Node *temp = new Node(key);


	if (pos == 0)
	{
		if (head == NULL)
		{
			head = temp;
			head->next = head;
		}
		else {
			temp->next = head;
			while (p->next != head)
			{
				p = p->next;
			}
			if (p == head)
			{
				delete head;
				head = NULL;
			}
			else
			{
				p->next = temp;
				head = temp;
			}
		}
	}

	else
	{
		int count = 0;
		while (count < pos - 1)
		{
			p = p->next;
			count ++;
		}
		temp->next = p->next;
		p->next = temp;

	}
}

void Delete(int index)
{
	Node *p = head;
	if (index == 0)
	{
		while (p->next != head)
		{
			p = p->next;
		}
		p->next = head->next;
		delete head;
		head = p->next;
	}
	else
	{
		int count = 0;
		Node *q = NULL;
		while (count < index - 1)
		{
			q = p;
			p = p->next;
			count++;
		}
		q->next = p->next;
		delete p;
	}
}
void Display(Node *p)
{


	do
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != head);
	cout << endl;
}
//int flag = 0;
void Rdisplay(Node *p)
{
	static int flag = 0;
	if (p != head or flag == 0)
	{
		flag = 1;
		cout << p->data << " ";
		Rdisplay(p->next);
	}
	flag = 0;
}

int main()
{

	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	Create(arr, n);
	Rdisplay(head);

	Insert(head , 1, 10);
	cout << "\nafter inserting\n";
	Rdisplay(head);
	Delete(5);

	cout << "\nafter Deleting\n";
	Rdisplay(head);


	return 0;

}