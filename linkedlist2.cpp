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

void Display(Node *p)
{
	while (p != NULL )
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}

int countNodes(struct Node *p)
{
	int count = 0;
	while (p != NULL)
	{
		count += 1;
		p = p-> next;
	}
	return count;
}
int maxelement(Node *p)
{
	int x = INT_MIN;
	while (p != NULL)
	{
		x = max(x, p-> data);
		p = p-> next;
	}

	return x;
}
bool SearchElement(Node *p, int key) {

	while (p != NULL)
	{
		if (p-> data == key)
			return true;
		p = p->next;
	}
	return false;
}
void InsertatIndex(Node *p, int node, int value) {

	int count = 0;
	Node * temp, *q;
	temp = new Node(value);
	if (node == 0)
	{
		temp->next = head;
		head = temp;
	}
	else if (node > 0)
		while (p != NULL )
		{
			if (count == node)
			{
				q->next = temp;
				temp->next = p;

			}
			q = p;
			p = p->next;
			count++;
		}
}
void linearSearch_movetoHead(Node *p, int key)
{
	Node *q = NULL;
	while (p != NULL)
	{
		if (p->data == key)
		{
			q->next = p-> next;
			p->next = head;
			head = p;
		}
		q = p;
		p = p->next;
	}
}

void append(Node *p, int value)
{
	Node *temp = new Node(value);
	if (p == NULL)
	{
		p = temp;
		//head = p;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p-> next;
		}
		p -> next = temp;
	}
}

//void Insert_in_a_sorted_list(Node * p, int key);
void RemoveDuplicates(Node *p) {

	Node *q = p->next;
	while (q and p)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}


void reverseLinkedlist(Node *p)
{
	Node *q = NULL, *r = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;

		p = p->next;
		q->next = r;


	}
	head = q;
}

void RecursiveReverse(Node *q, Node*p)
{
	if (p != NULL) {
		RecursiveReverse(p, p->next);
		p->next = q;
	}
	else
	{
		head = q;
	}


}



int middleElement(Node *p)
{
	Node *slow, *fast;
	slow = fast = head;
	while (fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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
	Node**x = &head;
	cout << head << " \n";
	cout << *x << endl;

	cout << countNodes(head) << endl;

	cout << "Max Element is : " << maxelement(head) << endl;
	int key = 10;

	if (SearchElement(head, key))
		cout << "element is present the list" << endl;
	else
		cout << " Element is not present in the list" << endl;

	int value = 10, node = 1;

	InsertatIndex(head, node, value);
	InsertatIndex(head, node, value);
	InsertatIndex(head, node, value);
	cout << " after inserting the value at node the node will be displayed as \n";
	Display(head);

	linearSearch_movetoHead(head, 11);
	cout << " The modified list after searching will be : \n";

	Display(head);
	//int nodevalue = 100;

	append(head, 120);
	append(head, 120);
	append(head, 120);

	cout << " After appending : \n";

	Display(head);

	RemoveDuplicates(head);

	cout << " After removing duplicates :\n";

	Display(head);

	reverseLinkedlist(head);

	cout << "After reversing the Linked List \n";

	Display(head);

	RecursiveReverse(NULL, head);
	cout << "after reversing the linked list revursively \n";

	Display(head);


	cout << "Middle element is : " << middleElement(head) << endl;

	return 0;
}