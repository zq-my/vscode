#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct jincheng_type{   //进程状态定义 
	int pid;          //进程 
	int youxian;     //进程优先级 
	int daxiao;      //进程大小 
	int zhuangtai;   //标志进程状态，0为不在内存，1为在内存，3为挂起 
	char info[10];   //进程内容 
}; 
struct jincheng_type neicun[20];
int shumu=0,guaqi=0,pid,flag=0;
 
//创建进程 
void create(){      
	if(shumu>=20) printf("\n内存已满，请先换出或结束进程\n");   //内存容量大小设置为20
	else{
		int i;
		printf("**当前默认一次性创建5个进程，内存容量20**"); 
		for(i=0;i<5;i++)  {              //默认一次创建5个进程
		//定位，找到可以还未创建的进程
		if(neicun[i].zhuangtai==1) break;  //如果找到的进程在内存则结束 ，初始设置都不在内存中（main函数中设置状态为0）
		scanf("%d",&(neicun[i].pid));
		for(int j=0;j<i;j++)
			if(neicun[i].pid==neicun[j].pid){
				printf("\n该进程已存在\n");
				return;
			}
		printf("请输入新进程优先级\n");
		scanf("%d",&(neicun[i].youxian)); 
		printf("请输入新进程大小\n");
		scanf("%d",&(neicun[i].daxiao)); 
		printf("请输入新进程内容\n");
		scanf("%s",&(neicun[i].info)); 
		//创建进程，使标记位为1
		neicun[i].zhuangtai=1;
		printf("进程已成功创建！"); 
		shumu++;
		}
	}
}
 
//进程运行状态检测 
void run(){   
	printf("运行进程信息如下："); 
	for(int i=0;i<20;i++){
		if(neicun[i].zhuangtai==1){
			//如果进程正在运行，则输出此运行进程的各个属性值	
			printf("\n  pid=%d ",neicun[i].pid); 
			printf(" youxian=%d  ",neicun[i].youxian); 
			printf(" daxiao=%d  ",neicun[i].daxiao); 
			printf(" zhuanbgtai=%d  ",neicun[i].zhuangtai); 
			printf(" info=%s  ",neicun[i].info); 
			flag=1;
		} 
	}
	if(!flag) 
	printf("\n当前没有运行进程！\n");
}
 

//进程换出
void huanchu(){
	if(!shumu){
		printf("当前没有运行进程！\n");
		return;
	}
	printf("\n请输入换出进程的ID值");
	scanf("%d",&pid);
	for(int i=0;i<20;i++){
		//定位，找到要换出的进程，根据其状态进行相应处理
		if(pid==neicun[i].pid) {
			if(neicun[i].zhuangtai==1){
				neicun[i].zhuangtai=2;
				guaqi++;
				printf("\n已经成功换出进程\n");
			}
			else if(neicun[i].zhuangtai==0) printf("\n要换出的进程不存在\n");
			else printf("\n要换出的进程已被挂起\n");
			flag=1;
			break;
		}
	}
	//找不到，则说明进程不存在
	if(flag==0) printf("\n要换出的进程不存在\n"); 
} 
 
//结束（杀死）进程 
void kill(){
	if(!shumu){
		printf("当前没有运行进程！\n");
		return;
	}
	printf("\n输入杀死进程的ID值");
	scanf("%d",&pid);
	for(int i=0;i<20;i++){
		//定位，找到所要杀死的进程，根据其状态做出相应处理
		if(pid==neicun[i].pid){
			neicun[i].zhuangtai = 0;
			shumu--;
			printf("\n已经成功杀死进程\n");
		}
		else if(neicun[i].zhuangtai==0) printf ("\n要杀死的进程不存在\n");
       //https://blog.csdn.net/weixin_45425975/article/details/110049786
		else printf("\n要杀死的进程已被挂起\n");
		flag=1;
		break;
	} 
	//找不到，则说明进程不存在
	if(!flag) printf("\n 要杀死的进程不存在\n");
 
} 
 
//唤醒进程
void huanxing(){
	if (!shumu) {
		printf("当前没有运行进程\n");
		return;
	}
	if(!guaqi){ 
		printf("\n当前没有挂起进程\n");
		return;
	}
	printf("\n输入进程pid:\n");
	scanf ("%d",&pid);
	for (int i=0; i<20;i++) {
		//定位，找到所要杀死的进程，根据其状态做相应处理
		if (pid==neicun[i].pid) {
			flag=false;
			if(neicun[i].zhuangtai==2){
				neicun[i].zhuangtai=1;
				guaqi--;
				printf ("\n已经成功唤醒进程\n");
			}
			else if(neicun[i].zhuangtai==0) printf("\n要唤醒的进程不存在\n");
			else printf("\n要唤醒的进程已被挂起\n");
			break;
		}
	}
	//找不到，则说明进程不存在
	if(flag) printf("\n要唤醒的进程不存在\n");
}
 
//主函数 
int main()
{
	int n = 1;
	int num;
	//一开始所有进程都不在内存中 
	for(int i=0;i<20;i++)
		neicun[i].zhuangtai = 0;
	while(n){
		printf("\n******************************************");
		printf("\n*		进程演示系统	   	 *");
		printf("\n******************************************");
		printf("\n*1.创建新的进程		2.查看运行进程 	 *");
		printf("\n*3.换出某个进程		4.杀死运行进程 	 *");
		printf("\n*5.唤醒某个进程		6.退出系统 	 *");
		printf("\n******************************************");
		printf("\n请选择（1~6）\n");
		scanf("%d",&num);
		switch(num){
			case 1: create();break;
			case 2: run();break;
			case 3: huanchu(); break;
			case 4: kill();break;
			case 5: huanxing(); break;
			case 6: printf("已退出系统");exit(0);
			default: printf("请检查输入数值是否在系统功能中1~6");n=0;
		}
		flag = 0;//恢复标记  
	} 
	return 0;
} 
 
  
