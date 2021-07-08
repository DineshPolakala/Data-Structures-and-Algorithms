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

void inorderTraversal(Node *root)
{
	if (root != NULL)
	{
		inorderTraversal(root->left_child);
		cout << root->data << " ";
		inorderTraversal(root->right_child);
	}
}

void preorderTraversal(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorderTraversal(root->left_child);
		preorderTraversal(root->right_child);
	}
}

void postorderTraversal(Node* root)
{
	if (root != NULL)
	{
		postorderTraversal(root->left_child);
		postorderTraversal(root->right_child);
		cout << root->data << " ";
	}
}

void printKDist(Node *root, int k)
{
	if (root == NULL )return ;
	if (k == 0) {cout << root->data << " ";}
	else
	{
		printKDist(root->left_child, k - 1);
		printKDist(root->right_child, k - 1);
	}

}
int height(Node *root)
{
	if (root != NULL)
	{
		return 1 + max(height(root->left_child), height(root->right_child));
	}
	else
		return 0;
}

void levelorderTraversal(Node *root)
{
	cout << "Level order Traversal : \n";
	queue<Node *>q;
	if (root)q.push(root);
	while (! q.empty())
	{
		Node *cur = q.front();
		cout << cur->data << " ";
		q.pop();
		if (cur->left_child)q.push(cur->left_child);
		if (cur->right_child)q.push(cur->right_child);
	}
	cout << endl;
}
void helper(Node *root, int level, int &maxlevel)
{
	if (root == NULL)return;
	if (maxlevel < level)
	{
		cout << root->data << " ";
		maxlevel = level;
	}
	helper(root->left_child, level + 1, maxlevel);
	helper(root->right_child, level + 1, maxlevel);
}
void leftview(Node *root)
{
	if (root == NULL)return;
	int maxlevel = 0;
	int level = 1;
	helper(root, level, maxlevel);

}

int main()
{
	Node *root = new Node(10);
	root->left_child = new Node(20);
	root->right_child = new Node(30);
	root->left_child->left_child = new Node(40);
	root->right_child->right_child = new Node(50);
	root->left_child->left_child->left_child = new Node(60);
	inorderTraversal(root);
	cout << endl;
	preorderTraversal(root);
	cout << endl;
	postorderTraversal(root);

	cout << endl;

	cout << height(root) << endl;

	printKDist(root, 1);
	cout << endl;
	levelorderTraversal(root);

	leftview(root);
	return 0;
}