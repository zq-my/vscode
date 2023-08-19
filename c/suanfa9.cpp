#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,A[110][110],dp[110][110];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&A[i][j]);
		dp[1][1]=A[1][1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dp[i][j]==-1)
					dp[i][j]=max(dp[i-1][j],dp[i][j-1])+A[i][j];
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
} 


