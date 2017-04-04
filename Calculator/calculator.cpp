#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<stack>
using namespace std;

double calculate(string str)
{
	char presign = '+';
	str = str + '+';
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	stack<double> stk;
	double result = 0, tmpval = 0;
	for (int i = 0; i != str.size(); ++i)
	{
		if (isdigit(str[i])) tmpval = tmpval * 10 + str[i] - '0';
		else
		{
			if (presign == '+') stk.push(tmpval);
			else if (presign == '-') stk.push(-tmpval);
			else
			{
				double num;
				if (presign == '*') num = stk.top()*tmpval;
				else num = stk.top() / static_cast<double>(tmpval);
				stk.pop();
				stk.push(num);
			}
			presign = str[i];
			tmpval = 0;
		}
	}
	while (!stk.empty())
	{
		result += stk.top(); stk.pop();
	}
	return result;
}

int main()
{
	string str;
	cout << "请输入一个表达式：";
	getline(cin, str);
	cout << "结果是：" << calculate(str) << endl;
	return 0;
}