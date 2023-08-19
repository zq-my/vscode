//#include<stdio.h>
//#define N 9
//int main() {
//    int a[N];
//    int i, k, x;
//    printf("Please input %d numbers:\n",N);
//    for (i=0; i<N; i++) {
//        scanf ("%d", &x);
//        for ( k=i; k>0; k-- ) {
//            if ( a[k-1] > x )
//                a[k]=a[k-1];
//            else   break;
//        }
//        a[k] = x;
//    }
//    for (i=0; i<N; i++)
//        printf("%d ", a[i]);
//    return 0;
//}
#include<stdio.h>

void printArray(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
 
 
void InsertSort(int *arr, int len)
{
 
	for (int i = 1; i < len; ++i)
	{
 
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			int j = i - 1;
			/*
			4 5 8 9 1 2
			*/
			for ( ;j >= 0 && temp < arr[j]; j--)        
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
 
int main()
{
	int arr[] = { 4,5,8,9,1,2 };
	int len = sizeof(arr) / sizeof(int);//通过字节计算数组大小
	printArray(arr, len);
	InsertSort(arr, len);
	printArray(arr, len);
	return 0;
}
