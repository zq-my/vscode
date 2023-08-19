#include<bits/stdc++.h>
using namespace std;

int bestx[4];

template<class Type>
class Loading
{
	Type MaxLoading(Type[],Type,int);
	public:
		void Backtrack(int i);
		int n;//集装箱数 
		Type* w,//集装箱重量数组
		c,//第一艘轮船的载重量
		cw,//当前载重量
		bestw,//当前最优载重量 
		r;//剩余集装箱重量 
};

template<class Type>
void Loading<Type>::Backtrack(int i)
{
	//搜索第i层结点 
	if(i>n)//到达叶节点 
	{
		if(cw>bestw)
			bestw=cw;//更新最优解 
		return;
	}
	r-=w[i];//修改剩余集装箱重量 
	if(cw+w[i]<=c)//x[i]=1 左儿子结点 
	{
		cw+=w[i];//装入 
		bestx[i]=1;
		Backtrack(i+1);
		cw-=w[i];//回溯 
	}
	if(cw+r>bestw)//x[i]=0
	{
		Backtrack(i+1);
		bestx[i]=0;
		r+=w[i];//修改剩余集装箱重量 
	}
}

template<class Type>
Type MaxLoading(Type w[],Type c,int n)
{
	//初始化 
	Loading<Type> X;
	X.w = w;
	X.c = c;
	X.n = n;
	X.bestw = 0;
	X.cw = 0;
	//初始化
	X.r = 0;
	for(int i=1;i<=n;i++)
	{
		X.r+=w[i];
	}
	//初始时的r为全体物品重量和 
	X.Backtrack(1);//从第一层开始搜索 
	return X.bestw;
}

int main()
{   
	int n=3,m;
	int c=50,c2=50;
 
	int w[4]={0,10,40,40};
 
    m=MaxLoading(w, c, n);
 
	cout<<"轮船的载重量分别为："<<endl;
	cout<<"c(1)="<<c<<",c(2)="<<c2<<endl;
 
	cout<<"待装集装箱重量分别为："<<endl;
	cout<<"w(i)=";
	for (int i=1;i<=n;i++)
	{
		cout<<w[i]<<" ";
	}
	cout<<endl;
 
	cout<<"回溯选择结果为："<<endl;
	cout<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"x["<<i<<"]:"<<bestx[i]<<endl;
	} 
	
	return 0;
}

