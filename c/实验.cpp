#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//system("cls");����
#include <string.h> 
 
 struct Staff {  //Ա����Ϣ�ṹ��
	int Number;        //ְ���ź�
	char name[20];     //����
	char sex;        // �Ա�
	int  age;          // ����
	char education[20]; //ѧ��
	float wages;        //����
	char  addr[20];     //סַ
	char Tel[15];      //�绰
};
struct Staff Staffer[100],Staffer1;
 
//���ܺ�������
void menu();  //���˵�
void input();  //����Ա����Ϣ
void save(int m);   //�洢��Ϣ
int  read();    // ��ȡ��Ϣ
void display();//�����Ϣ
void add()  ;   //���
void search();  //����
void search_name();  //����Ų���
void search_EDU();  //��ѧ������
void search_wages();  //�����ʲ���
void Delete();  //ɾ������
void change();  //�޸Ĳ���
void order();   //�������
void order_Num();  //��ְ��������    //�����Ϣʱ����ְ������С����˳������
void order_name();//��ְ����������
void order_age();//��ְ����������
 
//������
 
int main()   
{   int n,f;
	while(1)
	{  
		do {          
			menu(); //*���ò˵�����*
			printf("����������Ҫ���������(1-8):  ");
			scanf("%d",&n);          
			if(n>=1&&n<=8)  {          
				f=1;         break;
			}             
			else {        
				f=0; 
				system("cls");
				printf("\n\t\t\t����������������ѡ��!");
			}  
		}while(f==0); 
		switch(n)   {       
			case 1:   system("cls");
					  printf("\n");
					  printf("\t\t\t  ¼��ְ����Ϣ\n\n");
					  input();  
					  break;         
			case 2:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t���ְ����Ϣ\n");
					  display();
					  printf("\n��Enter������\n"); 
					  getchar();  
					  getchar();
					  system("cls");
					  break;
			case 3:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t��ѯְ����Ϣ\n");
					  search();  
					  break;         
			case 4:   system("cls");
					  printf("\n");
					  printf("\t\t\t\tɾ��ְ����Ϣ\n\n"); 
					  Delete();  
			case 5:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t�޸�ְ����Ϣ\n");
					  display();                     /* �����������*/  
					  change();
					  break; 
			case 6:   system("cls");
					  printf("\n");
					  printf("\t\tְ����Ϣ����\n");
					  order();
					  break;     
			case 7:   system("cls");
					  printf("\n");
					  printf("\t\t���ְ����Ϣ\n\n");
					  add()  ;
					  break;     
			case 8:	  system("cls");        
					  printf("\n\n\n\n\n\n\t\t\tThank you for using !\n\n\n\n\n\n");
					  getchar();
					  getchar();
					  exit(8);
					  break;
			}  
	}
}
 
//��������
 
void menu()   /*�˵�����*/
{      
	printf("\n\n");
	printf("                             Welcome to                          \n"); 
	printf("            Staff Information Management System (SIMS)           \n\n"); 
	printf("*****************************************************************\n");
	printf("*          1.¼��ְ����Ϣ");	printf("	��	2.���ְ����Ϣ          *\n");
	printf("*          3.��ѯְ����Ϣ");	printf("	��	4.ɾ��ְ����Ϣ          *\n");
    printf("*          5.�޸�ְ����Ϣ");	printf("	��	6.ְ����Ϣ����          *\n");
    printf("*          7.���ְ����Ϣ");	printf("	��	8.�˳�ְ��ϵͳ          *\n");
	printf("*****************************************************************\n");
	printf("\n");     
}
 
void input()   /*¼�뺯��*/ 
{   int i,m,num=0;     
	printf("��������Ҫ������Ϣ��ְ������(1--100): ");
    scanf("%d",&m); 
	system("cls");
	printf("\n");
	if(m>100)  
	{
		printf("\t\t\t������Χ�����������롣\n");
		input();
	}
	else{ 
		for (i=0;i<m;i++)   
		{   printf("��%d��Ա����Ϣ���루���س�ȷ�����룩��\n", i+1);
			printf("������ְ���ţ� ");
			scanf("%d",&num);
			for(int j=0;j<i;j++)
				if(Staffer[j].Number==num)
				{	printf("ְ����Ϊ %d ��Ա���Ѵ��ڣ����������룺",num);
					scanf("%d",&num);
					j=0;
				}
			Staffer[i].Number=num;
			printf("������������  ");  
			scanf("%s",Staffer[i].name);
			printf("�������Ա�F/M����  "); 
			getchar();
			scanf("%c",&Staffer[i].sex); 
			printf("���������䣺  "); 
			scanf("%d",&Staffer[i].age);  
			printf("������ѧ����  ");  
			scanf("%s",Staffer[i].education);  
			printf("�����빤�ʣ�  ");   
			scanf("%f",&Staffer[i].wages);
			printf("������סַ��  ");   
			scanf("%s",Staffer[i].addr);
			printf("������绰��  ");   
			scanf("%s",Staffer[i].Tel);
			system("cls"); 
			printf("\nһ����ְ������Ϣ����������ϣ�\n\n");        
		 }       
		save(m);
		printf("");
	} 
} 
 
void save(int m)  /*�����ļ�����*/ 
{    int i;
     FILE *fp;
     if ((fp=fopen("D:\\Staff_list.dat","wb"))==NULL) /*�����ļ����ж��Ƿ��ܴ�*/    
	 {  printf ("cannot open file!\n");
		exit(0); 
	 }     
	 for (i=0;i<m;i++) /*���ڴ���ְ������Ϣ����������ļ���ȥ*/  
	if (fwrite(&Staffer[i],sizeof(struct Staff),1,fp)!=1)
		printf("file write error!\n");   
	fclose(fp); 
}  
 
int read()  /*���뺯��*/ 
{   FILE*fp;  
	int i=0;    
	if((fp=fopen("D:\\Staff_list.dat","rb"))==NULL)
	{   printf ("cannot open file!\n");
		exit(0);      
    } 
	else 
	{   
		do {         
			fread(&Staffer[i],sizeof(struct Staff),1,fp); 
			i++;
			}while(feof(fp)==0); 
	}  
	fclose(fp);
	return(i-1); 
}      
 
void display()  /*�������*/
{   int i; 
    int m=read();
	printf("\n��˾����ְ����Ϣ:\n"); //printf("\n ԭ��ְ����Ϣ:\n"); 
	printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰   \n"); 
	order_Num();
	for(i=0;i<m;i++)        
		printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
	printf("\n");
} 
 
  
void Delete()   /*ɾ������*/ 
{	int m=read();
	int i,j,t,n, f,Num;
	display();  /*�����������*/
	printf("������Ҫɾ����ְ����ְ����:  "); 
	scanf("%d",&Num);  
	for(f=1,i=0;f&&i<m;i++) 
	{    if(Staffer[i].Number==Num)
		{    
			printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n"); 
			printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n"); 
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
			printf("\nȷ��ɾ���밴 1��ȡ��ɾ���밴 0: ");    
			scanf("%d",&n);              
			if(n==1)   /*���ɾ��������������Ϣ����ǰ��һ��*/   
			{ 	for(j=i;j<m-1;j++)
					 Staffer[j]=Staffer[j+1];      /*���ҵ���j��ְ��ʱ,for����j�Լ���1,���������Ӧ�ðѸĺ��  ��Ϣ��ֵ����j-1����*/      
				f=0; 
			}
			else f=2;
		} 
 
	}
	system("cls");
   switch(f){
		case 0: m=m-1;
				printf("\n\t\t\t\tɾ���ɹ���\n"); 
				save(m);     /*���ñ��溯��*/    
			    display();  /*�����������*/
				break;
		case 1: printf("\n\t\t\t�Բ��𣬹�˾û�и�Ա��!\n");    
			    display();  /*�����������*/
				break;
		case 2: printf("\n\t\t\t\tȡ��ɾ����\n");
				break;
	}   
      //display();  /*�����������*/
   printf("\n����ɾ���밴1���������˵��밴0: "); 
   scanf("%d",&t); 
   system("cls");
   switch(t) 
   {    case 1:  Delete(); 
			     break;     
		case 0:  system("cls");
				 main();
				 break; 
		default: break;
   }
    system("cls"); 
} 
 
void add()  /* ��Ӻ���*/
{   int n=read();  
	int i,m,num=0;    
	printf("��������Ҫ�����Ϣ��ְ������: ");    
	scanf("%d",&m);    
	if(m+n>100)  {
		system("cls");
		printf("\n�Բ�������������ְ������������Χ�����������루0��%d֮�䣩��\n\n",100-n);
		add();
	}
	else{
		for (i=n;i<m+n;i++)    
		{	printf("��%d��Ա����Ϣ���루���س�ȷ�����룩�� \n", i+1);
			printf("������ְ���ţ� ");
			scanf("%d",&num);
			for(int j=0;j<i;j++)
				if(Staffer[j].Number==num)
				{	printf("ְ����Ϊ %d ��Ա���Ѵ��ڣ����������룺",num);
					scanf("%d",&num);
					j=0;
				}
			Staffer[i].Number=num;
			printf("������������  ");  
			scanf("%s",Staffer[i].name);
			printf("�������Ա�F/M����  "); 
			getchar();
			scanf("%c",&Staffer[i].sex); 
			printf("���������䣺  "); 
			scanf("%d",&Staffer[i].age);  
			printf("������ѧ����  ");  
			scanf("%s",&Staffer[i].education);  
			printf("�����빤�ʣ�  ");   
			scanf("%f",&Staffer[i].wages);
			printf("������סַ��  ");   
			scanf("%s",&Staffer[i].addr);
			printf("������绰��  ");   
			scanf("%s",&Staffer[i].Tel);
			system("cls"); 
			printf("\nһ��ְ������Ϣ����������ϣ���������һ��ְ������Ϣ\n"); 
			printf("\n");        
		}      
		save(m+n);
		system("cls"); 
		printf("\n���ְ���������!  \n"); 
		display();
		printf("\n��Enter������\n"); 
		getchar();  
		getchar();
		system("cls");
	}
 }
 
void search()/*��ѯ����*/
{   int t,f;
	do {      
		printf("\n��������ѯ�밴 1;  ��ѧ����ѯ�밴 2;  �����ʲ�ѯ�밴 3;  �������˵��� 0: ");
		scanf("%d",&t);     
		if(t>=0&&t<=4)    
		{     f=1;     break;     } 
		else {    f=0;     printf("����������������ѡ��!");     }
	}while(f==0);
	system("cls");
	while(f==1) {      
		switch(t)     
		{   case 0: main();
				    break;
			case 1: printf("\n��������ѯ\n");
					search_name();
					break;      
			case 2: printf("\n��ѧ����ѯ\n");
				    search_EDU();
					break; 
			case 3: printf("\n�����ʲ�ѯ\n");
				    search_wages();
					break; 
			default:break; 
		}      
		system("cls");     
	} 
}  
 
void search_name()/*���������Һ���*/ 
{   char name1[20];   
	int i,t,n=0;    
	int m=read();   
	printf("\n������Ҫ���ҵ�����:  "); 
	scanf("%s",name1);   
	for(i=0;i<m;i++)      
		if(strcmp(name1,Staffer[i].name)==0) 
		{   
			if(n==0) 
			{	printf("\n���ҵ�������Ϣ��\n");
				printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n"); 
			}
			n++;
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		}     
	if(n==0)  
	{	printf("\n�Բ��𣬹�˾û�и�Ա��!\n"); 
		getchar();getchar();
	}
	else  
	{	printf("\n��ѯ���� %d ��Ա������Ҫ��\n",n);
		printf("\n");    
		printf("ɾ��Ա���밴 1���޸���Ϣ�밴 2��������ѯ�밴 3��������һ���밴 4��\n\n\t\t\t�������˵��밴 0 ��");
		scanf("%d",&t);    
		switch(t)
		{	case 0: system("cls");   
					main();
					break;  
			case 1: Delete();
					break;  
			case 2: change();
					break; 
			case 3: break;
			case 4: system("cls");   
					search();
					break;
			default:break;    
		}  
	}
}  
 
void search_EDU()/*��ѧ�����Һ���*/ 
{   char education1[20];  
	int i,t,n=0; 
	int m=read(); 
	printf("\n������Ҫ���ҵ�ѧ��: ");
	scanf("%s",education1);  
	for(i=0;i<m;i++)      
		if(strcmp(education1,Staffer[i].education)==0) 
		{   
			if(n==0)   
			{	printf("\n���ҵ�����Ա�������¼Ϊ��\n"); 
				printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n"); 
			}
			n++;
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		}
	if(n==0)  
	{	printf("\n�Բ��𣬹�˾û�и�Ա��!\n"); 
		getchar();getchar();
	}
	else 
	{	printf("\n��ѯ���� %d ��Ա������Ҫ��\n",n);
		printf("\n");    
		printf("ɾ��Ա���밴 1���޸���Ϣ�밴 2��������ѯ�밴 3��������һ���밴 4��\n\n\t\t\t�������˵��밴 0 ��");
		scanf("%d",&t);    
		switch(t)
		{	case 0: system("cls");   
					main();
					break;  
			case 1: Delete();
					break;  
			case 2: change();
					break; 
			case 3: break;
			case 4: system("cls");   
					search();
					break;
			default:break;    
		}
	}
} 
 
void search_wages()/*�����ʲ��Һ���*/ 
{   float wages1;  
	int i,t,n=0; 
	int m=read(); 
	printf("\n������Ҫ���ҵĹ�������:  ");
	scanf("%f",&wages1);  
	for(i=0;i<m;i++)      
		if(wages1==Staffer[i].wages) 
		{   
			if(n==0)
			{	printf("\n���ҵ���Ա�������¼Ϊ��\n"); 
				printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n"); 
			}
			n++;
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
			break; 
		}     
	if(n==0)  
	{	printf("\n�Բ��𣬹�˾û�и�Ա��!\n"); 
		getchar();
		getchar();
	}
	else  
	{	printf("\n��ѯ���� %d ��Ա������Ҫ��\n",n);
		printf("\n");    
		printf("ɾ��Ա���밴 1���޸���Ϣ�밴 2��������ѯ�밴 3��������һ���밴 4��\n\n\t\t\t�������˵��밴 0 ��");
		scanf("%d",&t);    
		switch(t)
		{	case 0: system("cls");   
					main();
					break;  
			case 1: Delete();
					break;  
			case 2: change();
					break; 
			case 3: break;
			case 4: system("cls");   
					search();
					break;
			default:break;    
		} 
	}
} 
	
void change()  /*�޸ĺ���*/ 
{   int Number;        //ְ���ź�
	char name[20];     //����
	char sex;        // �Ա�
	int  age;          // ����
	char education[20]; //ѧ��
	float wages;        //����
	char  addr[20];     //סַ
	char Tel[15];      //�绰
	int b=1,c,i,n,t,k=0; 
	int m=read();               /*�����ļ��ڵ���Ϣ*/ 
	printf("\n");      
	printf("������Ҫ�޸ĵ�ְ����ְ����:  ");
	scanf("%d",&Number);
	system("cls");
	for(i=0;i<m;i++)
	{   if(Staffer[i].Number==Number) 
		{  	k=1;
			printf("\n���ҵ���ְ����Ա�������¼Ϊ��\n"); 
			printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n");
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
			printf("\nȷ���޸��밴1��ȡ���޸��밴0��");
			scanf("%d",&n);             
			if(n==1)      
			{   printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.ְ����  2.����  3.�Ա�  4.����  5.ѧ��  6.����  7.סַ  8.�绰  \n");
				printf("�����������޸ĵ���һ�����:  ");  
                scanf("%d",&c);               
				do  {       
					switch(c)     
					{   case 1: printf("ְ���Ÿ�Ϊ: ");
								scanf("%d",&Number);                   
								Staffer[i].Number=Number;                
								break;                  
						case 2: printf("������Ϊ: "); 
								scanf("%s",name);         
								strcpy(Staffer[i].name,name);
								break;     
						case 3: printf("�Ա��Ϊ��"); 
								scanf("%c",&sex);
								Staffer[i].sex=sex;
								break;   
						case 4: printf("�����Ϊ: "); 
								scanf("%d",&age);
								Staffer[i].age=age;
								break; 
						case 5: printf("ѧ����Ϊ: "); 
								scanf("%s",education);
								strcpy(Staffer[i].education,education);
								break; 
						case 6: printf("�������ʸ�Ϊ: "); 
								scanf("%f",&wages);
								Staffer[i].wages=wages; 
								break;      
						case 7: printf("סַ��Ϊ: ");
								scanf("%s",&addr); 
								strcpy(Staffer[i].addr,addr);
								break;               
						case 8: printf("�绰��Ϊ: ");  
								scanf("%s",Tel); 
								strcpy(Staffer[i].Tel,Tel);  
								break;               
					}            
					printf("\nȷ���޸� �밴1���������� �밴2:   "); 
					scanf("%d",&b); 
					if(b==1)
					{
						system("cls");
						save(m);//�����޸ĺ������
						printf("\n");    
						display();//����޸ĺ������
					}
				} while(b==2);
			}        	
		} 
 
		else if(i==(m-1)) i++;        
	}   
	if(k==0) {
		printf("\n�Բ�������������!\n");
	    getchar();
		getchar();
	}
	else{
		printf("\n�����޸��밴 1���˳��޸��밴 0:  "); 
	    scanf("%d",&t);
	}
	system("cls");
	switch(t) 
	{   case 1: display();
				change();//�����޸ĺ���
				break; 
		case 0: break;   
		default:break; 
	}
	system("cls"); 
}  
 
 void order()/*������*/    
 {  int d,f;
	do {     
		printf("\n�����������밴 1�������������밴 2���������˵��밴 0:  "); 
		scanf("%d",&d);     
		if(d>=0&&d<=2) 
		{    f=1;     break;     }  
		else    
		{   f=0;    
			printf("�Բ�������������������ѡ��!");
		}
	}while(f==0);
	system("cls");
	while(f==1) {     
		switch(d) 
		{   case 1: printf("\n����������Ϊ(��ĸ��С��������)��\n");
					order_name();
					break;   
			case 2: printf("\n����������Ϊ(�ɵ͵�������)��\n");
					order_age();
					break;      
			case 0: system("cls");
					main();
					break;      
    
		}      
		system("cls");
	}     
}
 
 void order_Num()/*��ְ����������*/    //�����Ϣʱ����ְ������С����˳������
{  int i,j;   
   int m=read();
   for(i=0;i<m-1;i++)
	   for(j=0;j<m-1-i;j++) 
		   if(Staffer[j].Number>Staffer[j+1].Number)/*����*/   
		   {    Staffer1=Staffer[j];
				Staffer[j]=Staffer[j+1];
				Staffer[j+1]=Staffer1;
		   }  
   save(m); //��ְ������С�����˳��洢
} 
 
void order_name()/*������������*/ 
{  int i,j,k; 
   int m=read();
   for(i=0;i<m-1;i++)
	   for(j=0;j<m-1-i;j++)/*ð�ݷ�����*/ 
		   if(strcmp(Staffer[j].name,Staffer[j+1].name)>0)
		   {    Staffer1=Staffer[j];
				Staffer[j]=Staffer[j+1];
				Staffer[j+1]=Staffer1;
		   }    
		save(m);   //�������洢
		printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n"); 
	    for(i=0;i<m;i++)        
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		printf("\n������һ���밴 1���������˵��밴 0:  ");   
		scanf("%d",&k);   
		switch(k) 
		{   case 1: system("cls");
					order(); //����������
					break;        
			case 0: system("cls");	
					main();
					break;    
			default:break;   
		}
	system("cls"); 
}  
 
void order_age()/*������������*/    
{  int i,k,j;   
   int m=read();
   for(i=0;i<m-1;i++)
	   for(j=0;j<m-1-i;j++) 
		   if(Staffer[j].age>Staffer[j+1].age)/*����*/   
		   {    Staffer1=Staffer[j];
				Staffer[j]=Staffer[j+1];
				Staffer[j+1]=Staffer1;
		   }  
		save(m); //�������ɵ͵���˳��洢 
		printf("\nְ����\t����\t�Ա�\t����\tѧ��\t    ����\tסַ\t �绰    \n"); 
	    for(i=0;i<m;i++)        
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		printf("\n������һ���밴 1���������˵��밴 0:  "); 
		scanf("%d",&k);    
		switch(k)    
		{    case 1: system("cls");
					 order();
			   	   	 break;      
			 case 0: system("cls"); 
					 main();
					 break;    
			 default:break;    
		}
	system("cls"); 
} 
