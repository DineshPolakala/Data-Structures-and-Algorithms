#include<bits/stdc++.h>
using namespace std;
//infix to postfix without peranthesis
bool isoperand(char c)
{
	return ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z'));
}

int pre(char c)
{
	if (c == '+' or c == '-')return 1;
	if (c == '*' or c == '/')return 2;
	return 0;
}
char* infixtopostfix(char *arr)
{
	cout << arr << endl;
	int n = strlen(arr);
	stack<char>s;
	char *postfix = new char[n + 1];
	int i = 0, j = 0;
	while (arr[i] != '\0')
	{
		if (isoperand(arr[i]))
		{
			postfix[j++] = arr[i++];
		}
		else
		{
			if (s.empty())
			{
				s.push(arr[i++]);
			}
			else
			{
				if (pre(arr[i]) > pre(s.top()))
				{
					s.push(arr[i++]);
				}
				else
				{
					postfix[j++] = s.top();
					s.pop();
				}
			}
		}
		//i++;
	}
	while (!s.empty())
	{
		postfix[j++] = s.top();
		s.pop();
	}
	postfix[j] = '\0';
	return postfix;
}
int main()
{
	char arr[] = "a+b*c-d/e";
	cout << sizeof(arr) << endl;
	char *ans = infixtopostfix(arr);
	cout << ans << endl;

	return 0;
}