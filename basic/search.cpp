#if 0
/*
*			二分查找  区间为【left，right】，均为闭区间，传入的初始值为【0，n-1】 
*/ 
int BinarySearch(int A[], int left, int right, int x)
{
	int mid;
	while(left<=right)             //此处为<= 
	{
		mid=(left+right)/2;
		if(A[mid]==x)
		{
			return mid;
		}
		else if(A[mid]>x)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	return -1;              //查找失败 
}


// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用
int bsearch_1(int l, int r)
{
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))	r=mid;
		else l=mid+1;
	}
	return l;
}


// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用
int bsearch_1(int l, int r)
{
	while(l<r)
	{
		int mid=l+r+1>>1;   //注意此处要加1
		if(check(mid))	l=mid;
		else r=mid-1;
	}
	return l;
}


//浮点数二分
double bsearch_1(double l, double r)
{
	const double eps=1e-8;
	while(r-l>eps)
	{
		double mid=l+r>>1;
		if(check(mid))	r=mid;
		else	l=mid;	
	}	
	return l;
} 
#endif

#include <iostream>
using namespace std;
int main()
{
	int a = 3;
	int s = a++ * 3;
	cout << s;
}
