#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}//sort����
int a[10000],b[10000];
int main(){
    int n,fa,fb,la,lb,cnt;
    while(cin>>n&&n!=0){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }//������ɵ���
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }//������������
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        fa=1;
        la=n;
        fb=1;
        lb=n;//��ֵ�����������
        cnt=0;
    for(int i=1;i<=n;i++){
    if(a[fa]>b[fb]){
        cnt++;
        fa++;
        fb++;//(��������ͨ���ƶ��˱�����λ����ʵ�ֵ�ǰ�����������ĸ�ֵ)
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

