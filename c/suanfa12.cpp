#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}//sort排序
int a[10000],b[10000];
int main(){
    int n,fa,fb,la,lb,cnt;
    while(cin>>n&&n!=0){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }//读入田忌的马
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }//读入齐王的马
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        fa=1;
        la=n;
        fb=1;
        lb=n;//赋值最快最慢的马
        cnt=0;
    for(int i=1;i<=n;i++){
    if(a[fa]>b[fb]){
        cnt++;
        fa++;
        fb++;//(在数组里通过移动此变量的位置来实现当前最快最慢的马的赋值)
    }else if(a[la]>b[lb]){
        cnt++;
        la--;
        lb--;
    }else{
        if(a[la]<b[fb]){
            cnt--;
            la--;
            fb++;
        }
    }
}
cout<<cnt*200<<endl;
}
    return 0;
}

