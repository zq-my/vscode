#include <iostream>
using namespace std;
//���յ�λ�����ļ�ֵ����С��������
void Sort(int n,float *w,float *v)
{
    int i,j;
    float temp1,temp2;
    for(i=1;i<=n;i++)
    for(j=1;j<=n-i;j++)//ð������
    {
        temp1=v[j]/w[j];
        temp2=v[j+1]/w[j+1];
        if(temp1<temp2)
        {
            swap(w[j],w[j+1]);
            swap(v[j],v[j+1]);
        }
    }
}
int main()
{
    float w[101];//������ʾÿ����Ʒ������
    float v[101];//������ʾÿ����Ʒ�ļ�ֵ��
    float x[101];//��ʾ�����뱳���ı���
    int n;//��Ʒ��
    float M;//���������������
    cin>>n>>M;
    //��������ÿ����Ʒ�������ͼ�ֵ��
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    //���յ�λ�����ļ�ֵ����С��������
    Sort(n,w,v);
    int i;
    for(i=1;i<=n;i++)
        x[i]=0;//��ʼֵ��δװ�뱳����x[i]=0
    float c=M;//���±���������
    for(i=1;i<=n;i++)
    {
        if(c<w[i])  break;//������ȫװ��
        x[i]=1;
        c=c-w[i];
    }
    if(i<=n)
        x[i]=c/w[i];
    //���
    for(int i=1;i<=n;i++)
        cout<<"����Ϊ"<<w[i]<<"��ֵ��Ϊ"<<v[i]<<"����Ʒ"<<"����ı���Ϊ"<<x[i]<<endl;
    return 0;
}


