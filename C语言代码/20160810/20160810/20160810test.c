#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0 //����һ���ṹ�����(����������)����������ڱ������ǵڼ��죬ע���������⡣
typedef struct date
{
 int year;
 int months;
 int day;
}Date;
int main()
{
 Date number;
 int n=0,i;
 int a[2][13]={{0,31,29,31,30,31,30,31,31,30,31,30,31},
	          {0,31,29,31,30,31,30,31,31,30,31,30,31}};
 printf("������������\n");
 scanf("%d%d%d",&number.year,&number.months,&number.day);
 if (number.year%4 == 0 && number.year%100 != 0 || number.year%400 !=0)
	    {
			for (i=1; i<number.months; ++i)
				n=n+a[0][i];
	    }
	else 
		{
			for (i=1; i<number.months; ++i)
				n=n+a[1][i];
		}
	n=n+number.day;
 printf("�����Ǳ����еĵ�%d��\n",n);
 return  0;
}
#endif
#if 0 //дһ������days��ʵ�ֵ�һ��ļ��㣬���������������մ��ݸ�days������������������������������
typedef struct date
{
 int year;
 int months;
 int day;
}Date;
int count(Date number);
int main()
{
 Date number;
 int n;
 printf("������������\n");
 scanf("%d%d%d",&number.year,&number.months,&number.day);
 n=count(number);
 printf("�����Ǳ����еĵ�%d��\n",n);
 return  0;
}
int count(Date number)
{
	int a[2][13]={{0,31,29,31,30,31,30,31,31,30,31,30,31},
	              {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int n=0,i;
	if (number.year%4 == 0 && number.year%100 != 0 || number.year%400 !=0)
	    {
			for (i=1; i<number.months; ++i)
				n=n+a[0][i];
	    }
	else 
		{
			for (i=1; i<number.months; ++i)
				n=n+a[1][i];
		}
	n=n+number.day;
	return n;
}
#endif
#if 0 //��дһ������print,��ӡһ��ѧ���ĳɼ����飬����������5��ѧ�������ݼ�¼��ÿ����¼����num,name,score[3]
      //ÿ����¼����num,name,score[3],��������������Щ��¼����print���������Щ��¼��
typedef struct student
{
 int num;
 char name[20];
 int score[3];
}Stu;
void print(Stu a[]);
int main()
{
 int i;
 Stu a[5];
 for (i=0; i<5; ++i)
	 scanf("%d %s %d %d %d",&a[i].num,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
 print(a);
 return 0;
}
void print(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 printf("%d %s %d %d %d\n",a[i].num,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2]);
}
#endif
#if 0 //�ڵ�����Ļ����ϣ���дһ������input����������5��ѧ�������ݼ�¼��
typedef struct student
{
 int num;
 char name[20];
 int score[3];
}Stu;
void input(Stu a[]);
void print(Stu a[]);
int main()
{
 Stu a[5];
 input(a);
 print(a);
 return 0;
}
void input(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 scanf("%d %s %d %d %d",&a[i].num,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
}
void print(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 printf("%d %s %d %d %d\n",a[i].num,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2]);
}
#endif
#if 0 //��10��ѧ����ÿ��ѧ�������ݰ���ѧ�ţ�������3�ſγ̵ĳɼ����Ӽ�������10��ѧ�����ݣ�Ҫ��������ſγ�
      //����ƽ���ɼ����Լ���߷ֵ�ͬѧ�����ݣ�����ѧ�ţ����������ſγ̳ɼ���ƽ��������
/*  �ɼ���������
1 wang 56 57 58
2 yang 76 79 99
3 liu  87 88 86
4 wu   55 56 57
5 sun  67 68 69
*/
typedef struct student
{
 int num;
 char name[20];
 int score[3];
}Stu;
void input(Stu a[]);
void print(Stu a[]);
int main()
{
 Stu a[5];
 printf("������ѧ������:\n");
 input(a);
 print(a);
 return 0;
}
void input(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 scanf("%d %s %d %d %d",&a[i].num,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
}
void print(Stu a[])
{
 int i,sum=0;
 int max=a[0].score[0];
 int n=0;
 for (i=0; i<5; ++i)
	 {
		 sum=sum+a[i].score[0]+a[i].score[1]+a[i].score[2];
	 }
 for (i=0; i<5; ++i)
	 {
		 if (max < a[i].score[0])
		 {
			 max = a[i].score[0];
			 n=i;
		 }
		  if (max < a[i].score[1])
		 {
			 max = a[i].score[1];
			 n=i;
		 }
		  if (max < a[i].score[2])
		 {
			 max = a[i].score[2];
			 n=i;
		 }
	 }
 printf("���ſγ̵���ƽ���ɼ�Ϊ:%d\n",sum/15);
 printf("��߷�Ϊ��%dλѧ��\n",n+1);
 printf("ѧ��:%d,����:%s,�ɼ�1:%d,�ɼ�2:%d,�ɼ�3:%d,ƽ���ɼ�:%d\n",a[n].num,a[n].name,a[n].score[0],a[n].score[1],a[n].score[2],(a[n].score[0]+a[n].score[1]+a[n].score[2])/3);
}
#endif
#if 0  //13����Χ��һȦ���ӵ�һ���˿�ʼ˳�򱨺�1��2��3.������3���˳�Ȧ�ӡ��ҳ��������Ȧ���е���ԭ������š�
       //Ҫ��������ʵ��
typedef struct data
{
 int number;
 struct data *next;
}Data;
Data *creat();
Data* count(Data *head); 
void print(Data *head);
int main()
{
 Data *head = creat();
 print(count(head));
 return 0;
}
Data *creat()
{
 Data *head = NULL,*p1 = NULL,*p2 = NULL;
 p1 = (Data*)malloc(sizeof(Data));
 p1 ->next = NULL;
 while (1 == scanf("%d",&p1->number))
 {
  if (head == NULL)
	  head =p1;
  else 
	  p2->next = p1;
  p2 = p1;
  p1 = (Data*)malloc(sizeof(Data));
  p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 p2 ->next = head;
 return head;
}
Data* count(Data *head)
{
 Data *p1 = NULL,*p2=NULL,*p3=NULL;
 int k=1;
 p1 = p2 = head;
 while (p1->next != p1)
 {
  if (k == 3)  //��� k == 3�Ļ���
	  {
	   p3 = p1; //��p3ָ��p1
	   p1 = p1->next;//p1ָ����һ��
	   p2->next = p1;//��������������
	   free(p3);// ��Ҫɾ�����ͷŵ�
	   p3 = NULL;// ��p3ָ��ΪNULL
	   k = 0; //�ٽ�k������Ϊ0
	  }
  else 
  {
    p2 = p1; //������ǵĻ���p2ʼ��ָ�����p1ǰ���һ������
	p1 = p1->next;//p1��ָ����һ��
  }
  k++;  //ÿ��k�Լ�һ��
 }
 p1->next = NULL; //�������ѭ����ʱ�� p1->nextָ��Ϊ NULL
 return (p1);
}
void print(Data *head)
{
 Data *p = NULL;
 p=head;
 printf("%d\n",p->number);
}
#endif
#if 0 //�ڵھ�����9.9����9.10�Ļ����ϣ�дһ������del������ɾ����̬������ָ���Ľ��
typedef struct data
{
 int number;
 struct data *next;
}Data;
Data* creat();
Data* del(Data *head,int n);
Data* find(Data *head,int n); 
void print(Data *head);
int main()
{
 int n;
 Data *head =creat();
 printf("����Ҫɾ������:n=");
 getchar();
 scanf("%d",&n);
 head=del(head,n);
 print(head);
 return 0;
}
Data *creat()
{
 Data *head = NULL,*p1 = NULL,*p2 = NULL;
 p1 = (Data*)malloc(sizeof(Data));
 p1 ->next = NULL;
 while (1 == scanf("%d",&p1->number))
 {
  if (head == NULL)
	  head =p1;
  else 
	  p2->next = p1;
  p2 = p1;
  p1 = (Data*)malloc(sizeof(Data));
  p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
}
Data* find(Data *head,int n)
{
 Data *p1 = NULL,*p2 = NULL;
 p1 = head;
 if (head->number==n)
	 return NULL;
 else 
	 {
		 while (p1->next != NULL)
			 {
				 if (p1->next->number == n)
					 p2 = p1 ; 
				 p1 = p1->next;
			 }
		 if (p2 != NULL)
			 return p2;
		 return NULL;
	 }
}
Data* del(Data *head,int n)
{
 Data *p1 = NULL,*p2 = NULL,*p3 = NULL;
 p1 = head;
 p2 = find(head,n);
 if (head->number == n )
	 {
		 head = head->next;
		 free(p1);
		 p1= NULL;
	 }
 else 
	 {
       if (p2 == NULL)
			  { 
				 printf("Ҫɾ�������ݲ�������\n");
	             head = NULL;
			  }
	   else if (p2->next->number == n)
	   {
		   p3 = p2->next;
		   p2->next=p3->next;
		   free(p3);
		   p3 = NULL;
	   }
	 }
 return head;
}
void print(Data *head)
{
	Data *p = head;
	while(p != NULL)
	{
		printf("%d ",p->number);
		p = p->next;
	}
	printf("\n");
}
#endif
