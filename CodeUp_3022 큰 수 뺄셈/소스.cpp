#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void add_zero(stack<int> &a, int max)
{
	if (a.size() == max)
		return;
	stack<int> t;
	for (int i = a.size(); i < max; i++)
		t.push(0);
	vector<int> v(a.size());
	for (int i = 0; a.size(); i++)
	{
		v[i] = a.top();
		a.pop();
	}
	for (int i = v.size() - 1; i >= 0; i--)
		t.push(v[i]);

	swap(t, a);
}
void find_num(stack<int> &a)
{
	if (a.top())
	{
		int t = a.top() - 1;
		a.pop();
		a.push(t);
	}
	else
	{
		a.pop();
		find_num(a);
		a.push(9);
	}
}
int main()
{
	int max_size, minus = 0;
	string n;
	stack<int> num1;
	stack<int> num2;
	stack<int> result;

	cin >> n;
	vector<int> t1(n.length());
	for (int i = 0; n[i]; i++)
	{
		t1[i] = n[i];
		num1.push(n[i] - '0');
	}


	cin >> n;
	vector<int> t2(n.length());
	for (int i = 0; n[i]; i++)
	{
		t2[i] = n[i];
		num2.push(n[i] - '0');
	}
	

	if (t1.size() < t2.size())
	{
		swap(num1, num2);
		minus = 1;
		max_size = t2.size();
	}
	else if (t1.size() > t2.size())
	{
		max_size = t1.size();
	}
	else
	{
		max_size = t1.size();
		for (int i = 0; i < t1.size(); i++)
		{
			if (t1[i] < t2[i])
			{
				minus = 1;
				break;
			}
			else if (t1[i] > t2[i])
			{
				minus = 0;
				break;
			}
		}
		if (minus)
			swap(num1, num2);
	}

	add_zero(num1, max_size);
	add_zero(num2, max_size);
	
	while (num1.size())
	{
		int a = num1.top();
		int b = num2.top();
		num1.pop();
		num2.pop();
		if (a < b && num1.size())
		{
			a += 10;
			find_num(num1);
		}
		result.push(a - b);
	}

	while (result.size() - 1 && result.top() == 0)
		result.pop();

	if (minus)
		cout << '-';
	while (result.size())
	{
		cout << result.top();
		result.pop();
	}

	return 0;
}