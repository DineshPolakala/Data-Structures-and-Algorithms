#include<bits/stdc++.h>
using namespace std;

struct Deque
{
	int size, cap;
	int *arr;
	Deque(int x)
	{
		size = 0;
		cap = x;
		arr = new int[cap];
	}
	bool isfull()
	{
		if (size == cap)return true;
		return false;
	}
	bool isempty()
	{
		if (size == 0)return true;
		return false;
	}
	void insertRear(int val)
	{
		if (isfull())
		{
			cout << "queue overflow";
			return;

		}

		arr[size] = val;
		size++;

	}

	void deletRear()
	{
		if (isempty())
		{
			cout << "queue underflow" << endl;
			return;
		}
		size--;
	}
	int getRear()
	{
		return arr[size];
	}

	void insertFront(int val)
	{
		if (isfull())return;
		for (int i = 0; i < size; i++)
		{
			arr[i + 1] = arr[i];

		}
		arr[0] = val;
		size++;
	}

	void deleteFront()
	{
		if (isempty())return;
		for (int i = 1; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

	int getFront()
	{
		if (isempty())return -1;
		return arr[0];
	}

};
int main()
{
	Deque q(10);
	q.insertFront(10);
	cout << q.getFront();

	return 0;
}