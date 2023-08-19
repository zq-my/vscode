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
//		disp();//打印数 
//		return;
//	} 
//	for(i=0;i<n;i++)
//	{
//		change(a,i);		//把第i个位置元素换到最开始
//		permit(a+1,n-1);	//把后面的元素递归全排列
//		change(a,i);		//全排列完毕，一定要再把第i个元素换回去！！不然就乱了！
//	}
//}
//
//int main ()
//{
//	permit(a,N);
//	printf("\n"); 
//	printf ("一共有%d种全排列组合。",num);
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
		printf("第%d种排列为:\t%s\n",count,str);
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
	printf("请输入排列的字符串："); 
	gets(str);
	permit(str,0,strlen(str));
	return 0;
}


