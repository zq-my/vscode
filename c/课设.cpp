#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  max 20
#define  MAX_LNT 10
typedef struct node{
	int str;
	int end;
	int dis;
}node;

int n=0,arcs[MAX_LNT][MAX_LNT];//n为城市个数，arcs[MAX_LNT][MAX_LNT]记录城市间的权值 

void create(){
	int i,j;
	printf("输入城市个数：\n");
	scanf("%d",&n);
	printf("输入城市间的信息: \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&arcs[i][j]);
		}
	}
}



int menu(  ) 
  {	
	int m;
	printf("...................................................\n\n");
	printf("                           求最小生成树\n");
	printf("                  ________________________________\n\n");
	printf("                    1 输入城市之间的信息\n");
//	printf("                    2 判断是否能构成一个最小生成树\n");
	printf("                    3 用克鲁斯卡尔算法生成最小生成树\n");
	printf("                    4 用普里姆算法生成最小生成树\n") ;
	printf("                    5 退出\n");
	printf("                  ________________________________\n\n");
	printf("                        请输入所选功能1-5\n");
	scanf("%d",&m);
	return m;
  }
  
int main(){
while(1) 
 {
   switch(menu(  ))
   {
   case 1:create( );break;/*输入城市信息*/
//   case 2:judge( );break;/*判断是否能够生成最小生成树*/
//   case 3:Kruskal( );break;   /*显示生成的最小生成树*/ 
//   case 4:prime();break;                                                
   case 5:exit(0);  
   }
 }
 return 0; 
}
