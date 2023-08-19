//#include<iostream>
//using namespace std;
//int main(int argc, char* argv[])
//{int i,j,a[100][100],n,k;
// cin>>n;    
// k=n*n;
//for(i=1;i<=n/2;i=i+1)
// {for(j=i;j<=n-i;j=j+1) {a[i][j]=k;k=k-1;}    
//  for(j=i;j<=n-i;j=j+1) {a[j][n+1-i]=k;k=k-1;} 
//  for(j=n-i+1;j>=i+1;j=j-1){a[n+1-i][j]=k;k=k-1;} 
//  for(j=n-i+1;j>=i+1;j=j-1) {a[j][i]=k;k=k-1;}
//  }
//if (n%2==1)
//  {i=(n+1)/2;a[i][i]=1;}
//for(i=1;i<=n;i=i+1)
//  { cout<<endl; 
//   for(j=1;j<=n;j=j+1)
//       cout<<a[i][j]<<"  ";
//  }
//	return 0;
//}
#include<stdio.h>
int main(){
	int n ;
	int i,j,k,o;
	int p;
	int a[100][100];
	int count;
	
	scanf("%d",&n);
	count=n;
	p=n*n;
	i=0;
	while(count>1){
		k=i;
		for(j=0;j<count-1;j++){
			a[i][k]=p--;
			k++;
		}
		for(j=0;j<count-1;j++){
			a[j+i][count-1+i]=p--;
		}
		for(j=count-1;j>0;j--){
			a[count-1+i][j+i]=p--;
		}
		for(j=count-1;j>0;j--){
			a[j+i][i]=p--;
		} 
		i++;
		count=count-2;
	}
	
	if(count==1){
		o=n/2;
		a[o][o]=1;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 

