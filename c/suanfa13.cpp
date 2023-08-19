#include<stdio.h>

int n,tianji[101],qiwang[101]; 

void sort(int m[]);
int race();

int main()
{
    while(1)
    {
        int i;

        scanf("%d",&n);
        if(n==0) return 0;

        for(i=1;i<=n;i++)
        {
            scanf("%d",&tianji[i]);
        } 
        for(i=1;i<=n;i++)
        {
            scanf("%d",&qiwang[i]);
        }
        sort(tianji);
        sort(qiwang);
        //将两个人的马都由小到大排序，方便比较
        printf("%d\n",race());
    }
}

void sort(int m[])
{
    int i,j,t;  
    for(i=1;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(m[j]>m[j+1])
            {
                t=m[j];
                m[j]=m[j+1];
                m[j+1]=t;
            }
        } 
    }
}

int race()
{
    int x0=1,y0=1,x1=n,y1=n,g=0,count=0;
    //x0为田忌所剩的最差的马的编号，y0为齐王所剩的最差的马的编号；
    //x1为田忌所剩的最好的马的编号，y1为齐王所剩的最好的马的编号；
    //count为田忌当前赢的钱数
    //g为两人已经进行过几场比赛
    while(++g<=n)//有n匹马，要进行n场比赛
    {
        if(tianji[x0]>qiwang[y0])
        //田忌最差的马比齐王最差的马快，赢一场。
        //用掉了自己最差的马，同时胜利，这是最优情况。
        {
            count+=1;
            x0++;
            y0++;
        }
        else if(tianji[x0]<qiwang[y0])
    //如果田忌最差的马比齐王最差的马还慢，无论策略如何都会输一局。
    //这时用田忌最差的马和齐王最快的马比，虽然输了一局，但是消耗了齐王最好的马。
        {
            count-=1;
            y1--;
            x0++;
        }
        else if(tianji[x0]==qiwang[y0])
        //当田忌最差的马和齐王最差的马一样快时
        //比较田忌最好的马和齐王最好的马，分情况讨论
        {
            if(tianji[x1]>qiwang[y1])
            //如果田忌最好的马比齐王最好的马快，赢一局
            {
                count+=1;
                x1--;
                y1--;
            }
            //如果田忌最好的马比齐王最好的马慢，用田忌最差的马和齐王最好的马比赛
            //需要考虑到田忌最差的马和齐王最好的马一样快的特殊情况
            else
            {
                if(tianji[x0]==qiwang[y1])
                //田忌最差的马和齐王最好的马一样快，平局
                {
                    count+=0;
                    x0++;
                    y1--;
                }
                else
                //田忌最差的马比齐王最好的马慢，输一局
                {
                    count-=1;
                    x0++;
                    y1--;
                }
            }
        }
    }
    return count;
}
