#include<bits/stdc++.h>
using namespace std;

int bestx[4];

template<class Type>
class Loading
{
	Type MaxLoading(Type[],Type,int);
	public:
		void Backtrack(int i);
		int n;//��װ���� 
		Type* w,//��װ����������
		c,//��һ���ִ���������
		cw,//��ǰ������
		bestw,//��ǰ���������� 
		r;//ʣ�༯װ������ 
};

template<class Type>
void Loading<Type>::Backtrack(int i)
{
	//������i���� 
	if(i>n)//����Ҷ�ڵ� 
	{
		if(cw>bestw)
			bestw=cw;//�������Ž� 
		return;
	}
	r-=w[i];//�޸�ʣ�༯װ������ 
	if(cw+w[i]<=c)//x[i]=1 ����ӽ�� 
	{
		cw+=w[i];//װ�� 
		bestx[i]=1;
		Backtrack(i+1);
		cw-=w[i];//���� 
	}
	if(cw+r>bestw)//x[i]=0
	{
		Backtrack(i+1);
		bestx[i]=0;
		r+=w[i];//�޸�ʣ�༯װ������ 
	}
}

template<class Type>
Type MaxLoading(Type w[],Type c,int n)
{
	//��ʼ�� 
	Loading<Type> X;
	X.w = w;
	X.c = c;
	X.n = n;
	X.bestw = 0;
	X.cw = 0;
	//��ʼ��
	X.r = 0;
	for(int i=1;i<=n;i++)
	{
		X.r+=w[i];
	}
	//��ʼʱ��rΪȫ����Ʒ������ 
	X.Backtrack(1);//�ӵ�һ�㿪ʼ���� 
	return X.bestw;
}

int main()
{   
	int n=3,m;
	int c=50,c2=50;
 
	int w[4]={0,10,40,40};
 
    m=MaxLoading(w, c, n);
 
	cout<<"�ִ����������ֱ�Ϊ��"<<endl;
	cout<<"c(1)="<<c<<",c(2)="<<c2<<endl;
 
	cout<<"��װ��װ�������ֱ�Ϊ��"<<endl;
	cout<<"w(i)=";
	for (int i=1;i<=n;i++)
	{
		cout<<w[i]<<" ";
	}
	cout<<endl;
 
	cout<<"����ѡ����Ϊ��"<<endl;
	cout<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"x["<<i<<"]:"<<bestx[i]<<endl;
	} 
	
	return 0;
}

