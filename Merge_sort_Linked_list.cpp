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

void Display(Node *p)
{
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
Node* merge_lists(Node* a, Node* b)
{
	Node *merged_list = NULL;
	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;

	}
	if (a->data <= b->data)
	{
		merged_list = a;
		merged_list->next = merge_lists(a->next, b);
	}
	else
	{
		merged_list = b;
		merged_list->next = merge_lists(a, b->next);

	}
	return merged_list;
}


void partition(Node *head, Node **front , Node** back)
{
	Node *fast, *slow;

	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;

		}
	}

	*front = head;
	*back = slow->next;
	slow->next = NULL;
	//Display(front);
	//Display(back);

}

void mergeSort(Node** p)
{
	//id(head== NULL or head->next == NULL)return head;
	Node *head = *p;
	Node *a = NULL, *b = NULL;
	if (!head or !head->next )return ;
	partition(head , &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*p = merge_lists(a, b);


}




int main()
{
	head = new Node(10);
	head->next = new Node(30);
	head->next->next = new Node(50);
	head->next->next->next = new Node(40);
	head->next->next->next->next = new Node(20);

	Display(head);

	mergeSort(&head);
	Display(head);
	return 0;
}
