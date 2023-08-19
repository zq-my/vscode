#include<stdio.h>
void quicksort(int left,int right,int a[]){
    int i,j,temp,k;
    if(left>right){
        return;
    }
    temp = a[left];
    i = left;
    j = right;
    while(i<j){//交换 
        while(a[j]>=temp && i<j)j--; 
        while(a[i]<=temp && i<j)i++;
		k = a[i];
        a[i] = a[j];
        a[j] = k;
        }
   	 	a[left] = a[i];
    	a[i] = temp;
	quicksort(left,i-1,a);
    quicksort(i+1,right,a);
 
}

int main(){
	int a[100000];
	int i=0,n;
	printf("请输入数的个数："); 
	scanf("%d",&n);
	getchar();
	char temp;
	while(i<n)
	{
		scanf("%d",&a[i]);	
		getchar();
		i++;
	}
    quicksort(0,i-1,a);
    int j;
    for(j=0;j<i;j++){
        printf("%d ",a[j]);
    }
    return 0;
}

