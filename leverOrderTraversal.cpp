#include<bits/stdc++.h>
using namespace std;

struct Node
{

	int data;
	Node *left_child, *right_child;

	Node(int val)
	{
		data = val;
		left_child = NULL;
		right_child = NULL;
	}
};

void levelorderTraversal(Node *root)
{
	queue<Node *>q;
	q.push(root);
	q.push(NULL);
	while (q.size() > 1)
	{
		Node *cur = q.front();

		q.pop();
		if (cur == NULL)
		{
			cout << "\n";
			q.push(NULL);
			continue;
		}
		cout << cur->data << " ";
		if (cur->left_child)q.push(cur->left_child);
		if (cur->right_child)q.push(cur->right_child);
	}
	//cout << endl;
}

// method 2
void LOrderTraversal(Node *root)
{
	queue<Node *>q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i < n; i++)
		{
			Node *cur = q.front();
			q.pop();
			cout << cur->data << " ";
			if (cur->left_child)q.push(cur->left_child);
			if (cur->right_child)q.push(cur->right_child);
		}
		cout << endl;
	}
}

int size(Node *root)
{
	if (root == NULL)return 0;
	return 1 + size(root->left_child) + size(root->right_child);
}

int getmax(Node *root)
{
	if (root == NULL)return INT_MIN;
	return max(root->data, max(getmax(root->right_child), getmax(root->left_child)));
}

void left_helper(Node *root, int level, int &maxlevel)
{
	if (root == NULL)return;
	if (maxlevel < level)
	{
		cout << root->data << " ";
		maxlevel = level;
	}
	left_helper(root->left_child, level + 1, maxlevel);
	left_helper(root->right_child, level + 1, maxlevel);
}
void leftview(Node *root)
{
	if (root == NULL)return;
	int maxlevel = 0;
	int level = 1;
	left_helper(root, level, maxlevel);

}
void right_helper(Node *root, int level, int &maxlevel)
{
	if (root == NULL)return;
	if (maxlevel < level)
	{
		cout << root->data << " ";
		maxlevel = level;
	}
	right_helper(root->right_child, level + 1, maxlevel);
	right_helper(root->left_child, level + 1, maxlevel);
}

void rightview(Node* root)
{
	int level = 1;
	int maxlevel = 0;
	right_helper(root, level , maxlevel);
}

int getMaxWidth(Node* root)
{

	// Your code here
	queue<Node*>q;
	if (root == NULL)return 0;
	q.push(root);
	int res = 0;
	while (!q.empty())
	{
		int n = q.size();
		res = max(res, n);
		for (int i = 1; i < n; i++)
		{
			Node *cur = q.front();
			q.pop();
			if (cur->left_child)q.push(cur->left_child);
			if (cur->right_child)q.push(cur->right_child);
		}
	}
	return res;
}







/*
Node* Tree_to_DLL(Node* root)
{

	if (root == NULL)return root;
	Node *prev = NULL;
	Node *head = Tree_to_DLL(root->left_child);
	if (prev == NULL)
	{
		head = root;

	}
	else
	{
		root->left_child = prev;
		prev->right_child = root;
	}
	prev = root;

	Tree_to_DLL(root->right_child);
	return head;

}*/


int main()
{
	Node *root = new Node(10);
	root->left_child = new Node(20);
	root->right_child = new Node(30);
	root->left_child->left_child = new Node(40);
	root->right_child->right_child = new Node(50);
	root->left_child->left_child->left_child = new Node(60);

	levelorderTraversal(root);
	LOrderTraversal(root);
	cout << "The size of the tree is : " << size(root) << endl;
	cout << "max is : " << getmax(root) << endl;
	cout << "\tLeft view" << endl;
	leftview(root);
	cout << endl;
	cout << "\tright view" << endl;
	rightview(root);
	cout << endl;
	cout << getMaxWidth(root) << endl;
	//Node * head = Tree_to_DLL(root);
	return 0;
}