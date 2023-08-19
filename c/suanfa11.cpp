#include<iostream>
using namespace std;
int MaxSum(int n,int *a,int &besti,int &bestj)
{
	//b表示的是以元素a[i]为结尾的最大子段和 
	int sum = -1, b = 0,flag;
	for(int i = 0;i < n;i++)
	{
		if(b > 0)	b += a[i];
		else 
		{
			b = a[i];
			flag=i;	
		}
		if(b > sum)
		{
			sum = b;
			besti=flag;
			bestj=i;
		}
		
	}
	return sum; 
}
int main()
{
	int n = 6;
	int a[] = {-2,11,-4,13,-5,-2};
	int besti=0,bestj=n-1; 
	int sum=MaxSum(n,a,besti,bestj);
	if(sum==-1)	sum=0;
	cout<<"最大子段和为："<<sum<<endl;
	cout<<"初始位置："<<besti<<"末尾位置："<<bestj<<endl; 
	return 0;
} 
 

