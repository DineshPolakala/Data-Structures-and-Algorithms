//#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Node
{
	int data;
	struct Node *next;
}*first = NULL;
// struct Node *first;
// first = (struct Node *) malloc(sizeof(struct Node));

void Create(int *arr, int n) {
	int i;
	struct Node  *temp, *last;
	first = (struct Node *) malloc(sizeof(struct Node));

	first-> data = arr[0];
	first-> next = NULL;
	last = first;
	//cout << first-> data << endl;
	for (i = 1; i < n; i++)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = arr[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}

}

void Display(struct Node* p) {
	while ( p != NULL)
	{
		cout << p->data << " ";
		p = p-> next;
	}

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);// to read input
	freopen("output.txt", "w", stdout);// to display output
#endif
	int arr[] = {6, 5, 4, 9, 8, 7};
	int n = sizeof(arr) / sizeof(int);
	//cout << arr[2] << endl;
	Create(arr, n);
	Display(first);






}