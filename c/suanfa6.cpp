//#include <stdio.h>
//#include<stdlib.h>
//int N;
//int NaturalGrouping(int a[], int b[],int N) {  	//自然分组，记录每个分组的起始位置的下标。
//	int temp = a[0];
//	int j = 0;
//	b[j] = 0;                    //第一个分组从下标0开始
//	j++; 
//	for (int i = 1; i < N; i++) {
//		if (temp <= a[i]) {
//			temp = a[i];
//		}
//		else {
//			b[j] = i;
//			j++;
//			temp = a[i];
//		}
//	}
//	b[j] = N;  //把数组的最后一个元素下标的下一个位置存下来	
//	return j;   /*返回分组的数量*/ 
//}
//void Merge(int a[], int left, int mid, int right,int N) {
//	int i = left;    //第一个数组的起始位置 
//	int	j = mid + 1; //第二个数组的起始位置 
//	int k = left;
//	int d[N];
//	while (i <= mid && j <= right) {
//		if (a[i] < a[j]) {
//			d[k] = a[i];
//			i++;
//		}
//		else {
//			d[k] = a[j];
//			j++;
//		}
//		k++;
//	}	
//	if (i != mid + 1) {            //说明左边的元素还有，直接加在临时数组d中。
//		for (int t = i; t <= mid; t++) {
//			d[k] = a[t];
//			k++;
//		}
//	}
//	if (j != right + 1) {
//		for (int t = j; t <= right; t++) {  //说明右边的元素还有，直接加在临时数组d中。
//			d[k] = a[t];
//			k++;
//		}
//	}
//	for (i = left; i <= right; i++)    //把此次进行合并后的元素拷贝到原数组
//		a[i] = d[i];				   
//	
//}
//
//void MergeSort(int a[], int b[],int N) {
//	int length = NaturalGrouping(a, b, N);
//	while (length!=1) {         //如果只剩一个分组则停止循环 
//		for (int i=0; i+2<=length; i+=2){    //i+2<length，不然数组会越界,如果只剩一个数组则跳过 
//			Merge(a, b[i], b[i+1]-1, b[i+2]-1, N);
//		}
//		length = NaturalGrouping(a, b, N);    //一次合并完成，重新进行自然分组.
//	}
//}
//
//void print(int n, int a[]) {  //打印数组 
//	for (int i = 0; i < n; i++) 
//		printf("%d ", a[i]);	
//	printf("\n");
//}
//
//int main() {
//	printf("请输入数组长度(N):");
//	scanf("%d",&N);
//	int *a=(int *)malloc(N*sizeof(int));
//	int *b=(int *)malloc(N*sizeof(int));	//存放分组的起始下标 
//	printf("请输入数组元素:");
//	for(int i=0;i<N;i++)
//		scanf("%d",&a[i]);
//
//	printf("\n归并前的数组:"); 
//	print(N, a);
//	MergeSort(a, b,N);
//	printf("\n归并后的数组:"); 
//	print(N, a);
//	
//
//	return 0;
//}
#include<stdio.h>
#define M 1000
int a[M],b[M];
void merge(int low,int mid,int high){      //定义该函数目的是进行归并排序 
	int i=low,j=mid+1,k=low;
	while(i<=mid&&j<=high){
		if(a[i]<a[j]){
			b[k++]=a[i++];
		}
		else{
			b[k++]=a[j++];
		}
	} 
	while(i<=mid){
		b[k++]=a[i++];
	} 
	while(j<=high){
		b[k++]=a[j++];
	}
	for(i=low;i<=high;i++){
		a[i]=b[i];
	}
}

void mergeSort(int a,int b){       //该函数将数组进行分治 
	if(a<b){
		int mid=(a+b)/2;
		mergeSort(a,mid);
		mergeSort(mid+1,b);
		merge(a,mid,b);
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergeSort(0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	} 
	return 0;
}
 




