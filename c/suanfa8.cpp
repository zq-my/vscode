#include <stdio.h>
#include<math.h> 
#include<stdlib.h>


/************************************************************************/
/* 数塔问题                                                               */
/************************************************************************/
const int N = 50;//为了算法写起来简单，这里定义一个足够大的数用来存储数据(为了避免运算过程中动态申请空间，这样的话算法看起来比较麻烦，这里只是为了算法看起来简单)
int data[N][N];//存储数塔原始数据
int dp[N][N];//存储动态规划过程中的数据
int n;//塔的层数

/*动态规划实现数塔求解*/
void tower_walk()
{
    // dp初始化
    for (int i = 0; i < n; ++i)
    {
        dp[n - 1][i] = data[n - 1][i];
    }
    int temp_max;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            // 使用递推公式计算dp的值
//            temp_max = max(dp[i + 1][j], dp[i + 1][j + 1]);
			if(dp[i + 1][j]>dp[i + 1][j + 1]){
				temp_max=dp[i + 1][j];
			}else
				temp_max=dp[i + 1][j + 1];
			
            dp[i][j] = temp_max + data[i][j];
        }
    }
}

/*打印最终结果*/
void print_result()
{
    printf( "最大路径和：%d\n",dp[0][0]);
    int node_value;
    // 首先输出塔顶元素
    printf("最大路径：%d",data[0][0]);
    int j = 0;
    for (int i = 1; i < n; ++i)
    {
        node_value = dp[i - 1][j] - data[i - 1][j];
        /* 如果node_value == dp[i][j]则说明下一步应该是data[i][j]；如果node_value == dp[i][j + 1]则说明下一步应该是data[i][j + 1]*/
        if (node_value == dp[i][j + 1]) ++j;
        printf( "->%d",data[i][j]);
    }
    printf("\n");
}

int main()
{
    printf("输入塔的层数：");
    scanf("%d",&n);
    printf("输入塔的节点数据(第i层有i个节点)：\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            scanf("%d",&data[i][j]); 
        }
    }

    tower_walk();
    print_result();
}
