//#include <stdio.h>
//#define N 3
//int a[]={1,2,3};
//int num = 0;
//
//void disp()
//{
//	int i;
//	
//	for(i=0;i<N;i++)
//	{
//		printf("%d",a[i]);
//	}
//	printf("\n");
//	num++;
//}
//
//void change(int a[],int i)
//{
//	int t=a[0];
//	a[0]=a[i];
//	a[i]=t;
//}
//
//void permit(int a[], int n)
//{
//	int i;
//		
//	if(n==1)
//	{
//		disp();//��ӡ�� 
//		return;
//	} 
//	for(i=0;i<n;i++)
//	{
//		change(a,i);		//�ѵ�i��λ��Ԫ�ػ����ʼ
//		permit(a+1,n-1);	//�Ѻ����Ԫ�صݹ�ȫ����
//		change(a,i);		//ȫ������ϣ�һ��Ҫ�ٰѵ�i��Ԫ�ػ���ȥ������Ȼ�����ˣ�
//	}
//}
//
//int main ()
//{
//	permit(a,N);
//	printf("\n"); 
//	printf ("һ����%d��ȫ������ϡ�",num);
//	return 0;
// } 




#include<stdio.h>
#include<string.h>
int count=0;
void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void  permit(char *str,int k,int len)
{
	int i;
	if(k==len)
	{
		count++;
		printf("��%d������Ϊ:\t%s\n",count,str);
	}
	else
	{
		for(i=k;i<len;i++)
		{
			swap(str+i,str+k);
			permit(str,k+1,len);
			swap(str+i,str+k);
		}
	}
}

int main()
{
	char str[10];
	printf("���������е��ַ�����"); 
	gets(str);
	permit(str,0,strlen(str));
	return 0;
}


