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

int n=0,arcs[MAX_LNT][MAX_LNT];//nΪ���и�����arcs[MAX_LNT][MAX_LNT]��¼���м��Ȩֵ 

void create(){
	int i,j;
	printf("������и�����\n");
	scanf("%d",&n);
	printf("������м����Ϣ: \n");
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
	printf("                           ����С������\n");
	printf("                  ________________________________\n\n");
	printf("                    1 �������֮�����Ϣ\n");
//	printf("                    2 �ж��Ƿ��ܹ���һ����С������\n");
	printf("                    3 �ÿ�³˹�����㷨������С������\n");
	printf("                    4 ������ķ�㷨������С������\n") ;
	printf("                    5 �˳�\n");
	printf("                  ________________________________\n\n");
	printf("                        ��������ѡ����1-5\n");
	scanf("%d",&m);
	return m;
  }
  
int main(){
while(1) 
 {
   switch(menu(  ))
   {
   case 1:create( );break;/*���������Ϣ*/
//   case 2:judge( );break;/*�ж��Ƿ��ܹ�������С������*/
//   case 3:Kruskal( );break;   /*��ʾ���ɵ���С������*/ 
//   case 4:prime();break;                                                
   case 5:exit(0);  
   }
 }
 return 0; 
}
