//#include<stdio.h>
//void left(int a[],int n,int k){
//	for(int i=0;i<k;i++){
//		int temp=a[0];
//		for(int j=1;j<n;j++){
//			a[j-1]=a[j];
//		}
//		a[n-1]=temp;
//	}
//	return ;
//}
//
//void right(int a[],int n,int k){
//	for(int i=k;i<n;i++){
//		int temp=a[n-1];
//		for(int j=n-1;j>0;j--){
//			a[j]=a[j-1];
//		}
//		a[0]=temp;
//	}
//	return ;
//}
//
//void exchange(int a[],int n,int k){
//	if(k>n-k) right(a,n,k);
//	else left(a,n,k);
//	return ;
//}
//
//int main(){
//	int a[10]={1,2,3,4,5,6,7,8,9,10};
//	exchange(a,10,5);
//	for(int i=0;i<10;i++){
//		printf("%d	",a[i]);
//	}
//}


//#include <iostream>
//using namespace std;
//int a[1001][1001];
//int b[1001];
//void copy1 (int n){//����
//	int m = n/2;
//	for(int i=1; i<=m; i++){
//		for(int j=1; j<=m; j++){
//			a[i][j+m] = a[i][j] + m;//���½�
//			a[i+m][j] = a[i][j+m];//���Ͻ�
//			a[i+m][j+m] = a[i][j];//���½�
//		}
//	}
//}
//void copy2(int n){//��������
//	int m = n/2;
//	for(int i=1; i<=m; i++){
//        //���յ�����������
//		b[i] = m+i;
//		b[m+i] = b[i];
//	}
//	//
//	for(int i=1; i<=m; i++){
//		for(int j=1; j<=m+1; j++){
//			if(a[i][j]>m){//��a[i][j]>m��ʱ����Ϊ����ѡ�ֵĶ���������ѡ��
//				a[i][j]=b[i];//����a[i][j]�ֿգ�����ֱ����a[i][j]ѡ����m+i������֤��֮ǰ�Ĺ���һ��
//				a[m+i][j]=(b[i]+m)%n;//ͬʱ�޸�a[m+i]��ѡ�ֵĶ���Ϊ(b[i]+m)%n���Է�ֹ�ظ�
//			}
//			else{
//			    //����a[m+i]�Ķ��ֹ�������Ϊa[i][j]+m
//				a[m+i][j]=a[i][j]+m;
//			}
//		}
//		for(int j=2;j<=m;j++){
//			a[i][m+j]=b[i+j-1];//���Ͻǣ��˴���j-1�൱��m
//			a[b[i+j-1]][m+j]=i;//���½�,�Գ����
//		}
//	}
//}
//void copy3(int n){
//	if(n/2>1 && (n/2)%2!=0)
//	copy2(n);
//	else
//	copy1(n);
//}
//void schedule (int n){
//	if(n == 1){
//		a[1][1] = 1;
//		return;
//	}
//	if(n%2!=0) n++;
//	schedule(n/2);
//	copy3(n);
//}
//void output (int n){
//	int m=n;
//	bool flag=true;
//	if(n%2!=0){
//		flag=false;
//		m++;
//	}
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			if(flag==false && a[i][j]==m)
//			cout<<'x'<<" ";
//			else
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//}
//int main(){
//	int n;
//	cin >> n;
//	schedule(n);
//	output(n);
//	return 0;
//}
//#include<stdio.h>
//int set(int n,int m)
//{
//	if(m==n || m==1)
//		return 1;
//
//	return set(n-1,m-1)+m*set(n-1,m);
//}
//int main()
//{
//	int m,n;
//	int count=0;
//	printf("������Ԫ�ظ���:\n"); 
//	scanf("%d",&n);
//	for(m=1;m<=n;m++)
//	{
//		count+=set(n,m);
//	}
//	printf("�ǿ��Ӽ���Ϊ��%d\n",count);
//}

//#include <iostream> 
//#include <algorithm> 
//#define MAX 101 
//using namespace std; 
//int D[MAX][MAX];
//int n;
//int MaxSum(int i, int j)
//{
//	if(i == n)
//		return D[i][j];
//	int x = MaxSum(i + 1,j); 
//	int y = MaxSum(i + 1,j+1); 
//		return max(x,y) + D[i][j];
//}
//int main()
//{
//	int i,j;
//	cin >> n; 
//	for(i = 1;i <= n;i++)
//		for(j = 1;j <= i;j++)
//			cin >> D[i][j];
//	cout << MaxSum(1,1) << endl;
//} 
//#include<bits/stdc++.h>
//using namespace std;
//int a[100];//����ð������
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%d",&a[i]);
//    }
//    int len,Maxlen=0;
//    int ii;
//    int t;//��ʾ��ǰ�������ĸ��ͺ���ıȽ�
//    for(int i=0;i<n;i++){
//            len=0;
//            t=i;
//        for(int j=i;j<n;j++){
//            if(a[j]>a[t]){
//                t=j;//����t
//                len++;
//
//            }
//        }
//        if(len>Maxlen)
//        {
//            Maxlen=len;
//            ii=i;
//        }
//
//    }
//    t=ii;
//    cout<<Maxlen+1<<endl<<a[ii]<<" ";
//    for(int i=ii;i<n;i++){
//        if(a[i]>a[t])
//        {
//            t=i;
//            cout<<a[i]<<" ";
//        }
//
//    }
//}
//#include<stdio.h>
//void find_max_str(int str[],int length);
//int main() {
//	int i,str[100],n;
//	scanf("%d",&n);
//	for(i=0;i<n;i++){
//		scanf("%d",&str[i]);
//	}
//	find_max_str(str,n);
//	return 0;
//}
//void find_max_str(int str[],int length){
//	int index,count=0,i,j;
//	
//	for( i=0;i<length;i++){
//		for( j=i+1;j<length;j++){
//			if(str[j]<str[j-1])
//				break;
//		}
//		if((j-i)>count){	
//			count=j-i;
//			index=i;
//		}
//	} 
//	printf("������������Ϊ��\t");
//	for(int x=index;x<(count+index);x++){
//		printf("%d ",str[x]);
//	}
//	return ;
//}
//
//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//
//    int arr[100];
//    int time=0;
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>arr[i];
//    }
//    sort(arr,arr+n);
//    for(int i=0;i<n;i++)
//    {
//        //��i���˱������ʱ�������˶��õȣ���Щ�˵ȵ�ʱ����ü���
//        time+=arr[i]*(n-i-1);
//        //�㻹Ҫ����ÿ���˱������ʱ�䣬��Ϊÿ���˱������ʱ��Ҳ���ǵȡ�
//        //---�����������������˰��죬̫��������
//        time+=arr[i];
//    }
//    cout<<time/n<<endl;
//
//    return 0;
//}

// #include<iostream>
//using namespace std;
// #define N 1000
// int cost[N][N];  
//  int isC[N] = {0}; 
//  int n;
// int scost;  
//  
//  void Backstrack(int i, int c) 
// {
//    if(c > scost) return;
//    if(i == n) {  
//        if(c < scost) scost=c;
//         return;
//    }
//    for(int j=0;j<n;j++) {
//        if(isC[j]==0) {
//            isC[j]=1;
//            Backstrack(i+1, c+cost[i][j]);
//             isC[j]=0;
//         }
//     }
// }
// 
// int main()
// {
//     cin>>n;
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//           cin>>cost[i][j];  
//        }
//     }
//    scost = N;  
//    Backstrack(0,0);  
//        
//   cout<<scost;
//     return 0;
// }  

template<class T>

T Traveling<T>::TSP1(int v[]){

bestc = 1;

for(int i=1,MaxCost=0;i<= n;i++){

for(int j=1;j<= n;j++)

if(a[i][j]!= NoEdge && a[i][j]>MaxCost)

MaxCost = a[1i][j];

if(MaxCost == NoEdge)

return NoEdge;

bestC += MaxCost;

}

x= new int[n+1];

for(i=1;i <= n; i++)

x[i]= i;

bestx= v;

CC = 0;

tSP1(2);

delete []x;

return bestc;

}



