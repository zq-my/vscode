#include<stdio.h>
int search(int a[],int *i,int *j,int key){
	int low=0;
	int high=11;
	int mid;
	while(low<high){
	 mid=(low+high)/2;
		if(key==a[mid]){
			*i=*j=mid;
			return 0;
		}
		else if(key>a[mid]){
			low=mid+1;	
		}
		else{
			high=mid-1;
		}

	}
		*i=high;
		*j=low;
		return 0;
}
int main(){
	int a[11]={1,3,5,7,9,11,13,15,17,19,21};
	int x;
	int y;
	int flag;
	printf("输入要查询的数：");
	scanf("%d",&flag);
	search(a,&x,&y,flag);
	printf("小于%d的最大元素位置:%d		大于%d的最小元素位置:%d",flag,x+1,flag,y+1);
}































