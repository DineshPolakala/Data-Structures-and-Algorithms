#include<bits/stdc++.h>
using namespace std;
struct Deque
{
	int size, cap, front;
	int *arr;
	Deque(int x)
	{
		size = 0;
		front = 0;
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

	int getFront()
	{
		if (isempty())return -1;
		return arr[front];
	}

	int getRear()
	{
		if (isempty())return -1;
		return arr[(front + size - 1) % cap];
	}

	void deleteFront()
	{
		if (isempty())return ;
		front = (front + 1) % cap;
		size--;
	}

	void deleteRear()
	{
		if (isempty())return;
		size--;
	}

	void insertFront(int val)
	{
		if (isfull())return ;

		front = (front + cap - 1) % cap;
		arr[front] = val;
		size++;
	}

	void insertRear(int val) {

		if (isfull())return;
		arr[(front + size) % cap] = val;
		size++;

	}
};



int main()
{

	return 0;
}