#include<bits/stdc++.h>
using namespace std;

struct Kstacks
{
	int *next, *top, *arr;
	int freetop, cap, k;
	Kstacks(int n, int k1)
	{
		k = k1;
		cap = n;
		next = new int[cap];
		arr = new int[cap];
		top = new int[k];
		for (int i = 0; i < k; i++)
		{
			top[i] = -1;
		}
		freetop = 0;
		for (int i = 0; i < cap - 1; i++)
		{
			next [i] = i + 1;
		}
		next[cap - 1] = -1;

	}

	bool isfull()
	{
		return (freetop == -1);
	}

	bool isempty(int sn)
	{
		return (top[sn] == -1);
	}

	void push(int val, int sn)
	{
		if (isfull())
		{
			cout << "Stack Overflow\n";
			return ;
		}
		int i = freetop;
		arr[i] = val;
		freetop = next[i];
		next[i] = top[sn];
		top[sn] = i;
	}

	int pop(int sn)
	{
		if (isempty(sn))
		{
			cout << "Stack Underflow\n";
			return -1;
		}
		int i = top[sn];
		top[sn] = next[i];
		next[i] = freetop;
		freetop = i;
		return arr[i];


	}
};

int main()
{
	Kstacks stack(6, 3);

	stack.push(10, 0);
	stack.push(20, 2);
	stack.push(30, 1);
	stack.push(40, 0);
	stack.push(50, 1);
	stack.push(60, 2);

	for (int i = 0; i < 6; i++)
	{
		cout << stack.arr[i] << ' ';
	}

	stack.pop(2);
	stack.pop(2);
	cout << endl;
	cout << stack.top[2];



	return 0;
}