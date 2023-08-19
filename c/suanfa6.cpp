//#include <stdio.h>
//#include<stdlib.h>
//int N;
//int NaturalGrouping(int a[], int b[],int N) {  	//��Ȼ���飬��¼ÿ���������ʼλ�õ��±ꡣ
//	int temp = a[0];
//	int j = 0;
//	b[j] = 0;                    //��һ��������±�0��ʼ
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
//	b[j] = N;  //����������һ��Ԫ���±����һ��λ�ô�����	
//	return j;   /*���ط��������*/ 
//}
//void Merge(int a[], int left, int mid, int right,int N) {
//	int i = left;    //��һ���������ʼλ�� 
//	int	j = mid + 1; //�ڶ����������ʼλ�� 
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
//	if (i != mid + 1) {            //˵����ߵ�Ԫ�ػ��У�ֱ�Ӽ�����ʱ����d�С�
//		for (int t = i; t <= mid; t++) {
//			d[k] = a[t];
//			k++;
//		}
//	}
//	if (j != right + 1) {
//		for (int t = j; t <= right; t++) {  //˵���ұߵ�Ԫ�ػ��У�ֱ�Ӽ�����ʱ����d�С�
//			d[k] = a[t];
//			k++;
//		}
//	}
//	for (i = left; i <= right; i++)    //�Ѵ˴ν��кϲ����Ԫ�ؿ�����ԭ����
//		a[i] = d[i];				   
//	
//}
//
//void MergeSort(int a[], int b[],int N) {
//	int length = NaturalGrouping(a, b, N);
//	while (length!=1) {         //���ֻʣһ��������ֹͣѭ�� 
//		for (int i=0; i+2<=length; i+=2){    //i+2<length����Ȼ�����Խ��,���ֻʣһ������������ 
//			Merge(a, b[i], b[i+1]-1, b[i+2]-1, N);
//		}
//		length = NaturalGrouping(a, b, N);    //һ�κϲ���ɣ����½�����Ȼ����.
//	}
//}
//
//void print(int n, int a[]) {  //��ӡ���� 
//	for (int i = 0; i < n; i++) 
//		printf("%d ", a[i]);	
//	printf("\n");
//}
//
//int main() {
//	printf("���������鳤��(N):");
//	scanf("%d",&N);
//	int *a=(int *)malloc(N*sizeof(int));
//	int *b=(int *)malloc(N*sizeof(int));	//��ŷ������ʼ�±� 
//	printf("����������Ԫ��:");
//	for(int i=0;i<N;i++)
//		scanf("%d",&a[i]);
//
//	printf("\n�鲢ǰ������:"); 
//	print(N, a);
//	MergeSort(a, b,N);
//	printf("\n�鲢�������:"); 
//	print(N, a);
//	
//
//	return 0;
//}
#include<stdio.h>
#define M 1000
int a[M],b[M];
void merge(int low,int mid,int high){      //����ú���Ŀ���ǽ��й鲢���� 
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

void mergeSort(int a,int b){       //�ú�����������з��� 
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
 




