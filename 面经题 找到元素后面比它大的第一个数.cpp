#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//n���������������飬�ҵ�ÿ��Ԫ�غ��������ĵ�һ����   ʱ�临�Ӷ�Ҫ��N
//O(N2)ʱ�临�Ӷȱ��������ܺ���
vector<int> findMax(vector<int> num)
{
	//˼·:ά��һ������location һ��ջstack
	//��ǰ������vector�������������С��ջ������ջ location++   �����������������ջ������ͣ�ĳ�ջ��ֱ��ջΪ�ջ���ջ��Ԫ�ش��ڸ�����  ��ջ��ͬʱ������Ԫ�ؼ���result
	//��Ҫ����һ�����⣬���ǳ�ջԪ�ص�λ�ã�ʹ������ջ����һ��ջ���������Ԫ�أ��ڶ���ջ���Ԫ������

	//���ֻ����һ��stack��������������ˣ�����ֱ����num[index.top()]����ö�Ӧ���ݣ�û�б�Ҫ������ջ
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
	//��ʱ��ջ���ܲ�Ϊ�գ���Ϊ�����Ҳ���������Լ������
	while (!index.empty())
	{
		result[index.top()] = -1;
		index.pop();
	}

	return result;

}