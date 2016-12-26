#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUM 100
void zcd();
void input();
void sort();
void search();
void print();
void print1();
void print2();
void modify();
struct student
{  int term;
      int num;
      int classes;
      char name[10];
      int score[4];
      int sum;
      float average;
}stu[NUM];
void main()
{
	zcd();
}
//����������//


void zcd()
{
int n=0;
	char m;
	system("cls");   //����//
	   printf("��������������˵�\n ");   //��������������˵�//
       printf("--------------------------------------------------------------------------\n");
       printf("\t\t\t\t\t����ʯ�ʹ�ѧ��ӭ��\n");
       printf("\n\t\t\t--------- ��ӭʹ��ѧ������ϵͳ\n\n\t\t\t\t\t-----------\n");
 printf("--------------------------------------------------------------------------\n");
       printf("\t\t\t1. ����ѧ���ɼ���¼ Input the record\n");   //����ѧ���ɼ���¼//
       printf("\t\t\t2. ���� Sort to make new a file\n");   //����//
	   printf("\t\t\t3. ���༶��ʾ�ɼ��� Print the record\n");   //��ʾ//
       printf("\t\t\t4. ��ѯ���˳ɼ� Search record on name\n");   //��ѯ//
       printf("\t\t\t5. �޸ĳɼ� Modify a record\n");   //�޸�//
       printf("\t\t\t6. �˳� Quit\n");   //�˳�//
       printf("--------------------------------------------------------------------------\n");
       printf("\n\t\t\t�������ѡ��Enter your choice(1~7):");
       fflush(stdin);
	   m=getchar();
	do
	{
		switch(m)
		{
		   case '1':input();zcd();break;
           case '2':sort();system("pause");zcd();break;
		   case '3':print();system("pause");break;
           case '4':search();zcd();break;
           case '5':modify();system("pause");zcd();break;
           case '6':exit(0); //��˵�����ֵΪ7��������//
		   default:printf("ָ����󣬳������"); getchar();zcd();
		}
	} while(1);

}


void input()
{
   system("cls");
    int i;
	char a;
	for(i=0;i<NUM;i++)
	{  printf(" \n������ѧ����ѧ�ڣ�");
	  scanf("%d",&stu[i].term);

printf(" \n������ѧ����ѧ�ţ�");
	  fflush(stdin);
	  scanf("%d",&stu[i].num);

	  printf(" \n������ѧ���İ༶��");
	  scanf("%d",&stu[i].classes);

	  printf("\n������ѧ����������");
	  scanf("%s", stu[i].name) ;

	  printf("\n������ѧ���ĸ����ɼ���");
	  scanf("%d",&stu[i].score[0]);
	  printf("\n������ѧ��������ɼ���");
	  scanf("%d", &stu[i].score[1]);
	  stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3];  //�����ֺܷ�ƽ����//
      stu[i].average=(double)stu[i].sum/4.0;

	   printf("�Ƿ�Ҫ�������(��N&n�˳�)");
	  fflush(stdin);
	  a=getchar();
	  if(a=='n'||a=='N')
		 break;
	}
}


void sort()
{
    int i,j=0;
	float temp;
    for(i=0;i<NUM;i++)
    {
	   stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3];
       stu[i].average=(float)stu[i].sum/4.0;
    }
	for(i=0;i<NUM-1;i++)
	{
		for(j=i+1;j<NUM;j++)
		{
			if(stu[i].sum<stu[j].sum)
			{
				temp=stu[i].sum;
                stu[i].sum=stu[j].sum;
                stu[j].sum=temp;
			}
		}
 	}
   printf("ѧ��\t����\t�༶ ���� ���� �ܷ� ƽ����\n");
   for(i=0;i<NUM;i++)
      printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
		     stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //���ѧ����Ϣ//
	system("pause");system("cls");print();
}


void search()
{
   system("cls");   //����//
   int number=0,i;
   printf("\t\t\t ������Ҫ����ѧ����ѧ��:");
   scanf("%d",&number);
   printf("ѧ��\t����\t�༶ ���� ���� �ܷ� ƽ����\n");
	  	for(i=0;i<NUM;i++)

	  if(number==stu[i].num) break;   //�����ж�//
	   if(i<NUM)
	{printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //���ѧ����Ϣ//
	   }
	 else
			printf("δ�ҵ���ѧ������Ϣ\n");
	system("pause");


}
void print()
{
    system("cls");
	char a;
    printf("1����ѧ�����\n");
	printf("2�����༶���\n");
	printf("3������\n");
	fflush(stdin);
	a=getchar();
	switch(a)
	{
	case '1':print1();
	case '2':print2();
	case '3':zcd();
	default:print();
	}
}
void print1()   //��ѧ�ڲ�ѯ//
{
	int i,m;
	printf("�������ѯ��ѧ�ڣ�\n");
	scanf("%d",&m);
	printf("ѧ��\t����\t�༶  ���� ���� �ܷ� ƽ����\n");
	for(i=0;i<NUM;i++)
	{
	  if(m==stu[i].term)
      printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
		     stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //��ѧ����Ϣ//
	}
	system("pause");system("cls");print();
}


void print2()  //���༶��ѯ//
{
	int i,j,k;
	printf("�������ѯ�İ༶��\n");
	scanf("%d",&k);
    printf("ѧ��\t����\t�༶ ���� ���� �ܷ� ƽ����\n");
	for(i=0;i<NUM;i++)
	{
	  if(k==stu[i].classes)
	  {
		  stu[i].sum=stu[i].score[0]+stu[i].score[1];
          stu[i].average=stu[i].sum/2.0;
          printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
		  stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //���ѧ����Ϣ//
	  }
	}
	printf("���������ѧ���������ɼ���\n");
	printf("ѧ��\t����\t�༶ ���� ����\n");
	for(i=0;i<NUM;i++)
	{for(j=0;j<2;j++)
	  {
		  if(stu[i].score[j]<60&&k==stu[i].classes)   //���������ѧ���������ɼ�//
          printf("%d\t%s\t%d%5d%5d\n",stu[i].num,stu[i].name,stu[i].classes,
		     stu[i].score[0],stu[i].score[1]);
		  break;
	  }
	}
	system("pause");system("cls");print();
}
void modify()
{
system("cls");
   int number,i;
   printf("\t\t\t������Ҫ�޸���Ϣ��ѧ��ѧ��:");
   scanf("\t\t\t%d",&number);
   for(i=0;i<NUM;i++)
        if(number=stu[i].num)  break;   //�����ж�//
	   if(i<NUM)   //�����ж�//

	   {
          printf("�������޸ĺ��ѧ������Ϣ��");

printf(" \n������ѧ����ѧ�ڣ�");
	      scanf("%d",&stu[i].term);

	      printf(" \n������ѧ����ѧ�ţ�");
	      fflush(stdin);
	      scanf("%d",&stu[i].num);

	      printf(" \n������ѧ���İ༶��");
	      scanf("%d",&stu[i].classes);

	      printf("\n������ѧ����������");
	      scanf("%s", stu[i].name) ;

	      printf("\n������ѧ���ĸ����ɼ���");
	      scanf("%d",&stu[i].score[0]);

	      printf("\n������ѧ��������ɼ���");
	      scanf("%d", &stu[i].score[2]);

	   }
   else
			printf("δ�ҵ���ѧ������Ϣ\n");

	system("paues");system("cls");zcd();
}
