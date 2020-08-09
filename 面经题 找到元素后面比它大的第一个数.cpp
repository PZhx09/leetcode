#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//n个整数的无序数组，找到每个元素后面比它大的第一个数   时间复杂度要求N
//O(N2)时间复杂度暴力遍历很好想
vector<int> findMax(vector<int> num)
{
	//思路:维护一个变量location 一个栈stack
	//从前向后遍历vector，遇到数字如果小于栈顶，入栈 location++   遇到的数字如果大于栈顶，不停的出栈，直到栈为空或者栈顶元素大于该数字  出栈的同时，将该元素加入result
	//还要考虑一个问题，就是出栈元素的位置，使用两个栈，第一个栈如上述存放元素，第二个栈存放元素索引

	//题解只用了一个stack，存放索引就行了，可以直接用num[index.top()]来获得对应数据，没有必要用两个栈
	vector<int> result;
	if (num.empty())
	{
		return result;
	}
	result.resize(num.size());
	stack<int> data;
	stack<int> index;

	data.push(num[0]);
	index.push(0);
	for (int i = 1; i < num.size(); i++)
	{
		while (data.top() < num[i])
		{
			result[index.top()] = num[i];
			data.pop();
			index.pop();
		}
		data.push(num[i]);
		index.push(i);
	}
	//此时，栈可能不为空，因为可能找不到后面比自己大的数
	while (!index.empty())
	{
		result[index.top()] = -1;
		index.pop();
	}

	return result;

}