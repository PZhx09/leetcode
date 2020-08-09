#include<iostream>

using namespace std;

class point
{
public:

	float x;
	float y;
	//float为什么要加f
	//小数默认是double，用f来表示这个是float类型的
};

float absZero = 0.0001;
float getTriangleArea(point a, point b, point c)
{
	//利用海伦公式来求解
	float AB = sqrt(pow(a.x - b.x, 2) + pow(a.y-b.y,2));
	float AC = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
	float BC = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));

	float p = (AB + AC + BC) / 2.0f;
	
	//海伦公式
	return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

bool isInTriangle(point a, point b, point c,point p)
{
	float ABPArea = getTriangleArea(a, b, p);
	float ACPArea = getTriangleArea(a, c, p);
	float BCPArea = getTriangleArea(b, c, p);

	float ABCArea = getTriangleArea(a, b, c);
	if (-absZero < (ABPArea + ACPArea + BCPArea - ABCArea) && (ABPArea + ACPArea + BCPArea - ABCArea) < absZero)
	{
		return true;
	}
	else
	{
		return false;

	}

}

/*int main()
{
	point pt0, pt1, pt2;
	point P;
	pt0.x = 0.0f;
	pt0.y = 0.0f;
	pt1.x = 3.0f;
	pt1.y = 0.0f;
	pt2.x = 0.0f;
	pt2.y = 4.0f;
	P.x = 1.5f;
	P.y = 2.0f;
	//	cout<<GetTriangleSquar(pt0,pt1,pt2)<<endl;
	cout << isInTriangle(pt0, pt1, pt2, P) << endl;

	return 0;

}*/