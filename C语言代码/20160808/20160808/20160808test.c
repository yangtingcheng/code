#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0  //�������Ҳ������ѡ�������е�һ�֣������ô��ѵķ�ʽ��Ч�ʱȽϸߡ�
void sort(int a[],int len);
void print(int a[],int len);
void creatheap(int a[],int root,int len);
int main()
{
 int a[]={0,49,38,65,97,76,13,27,49}; //ʹ����������ʱ��Ҫ��������±���иı䣬a[0]�����Ԫ��
 int len=sizeof(a)/sizeof(a[0])-1;
 sort(a,len);
 print(a,len);
 return 0;
}
void print(int a[],int len)
{
 int i;
 for (i=1; i<=len; ++i)
	 printf("%d ",a[i]);
 printf("\n");
}
void sort(int a[],int len)
{
 int i;
 int t;
 for (i=len/2; i>=1; --i)  //������ʼ�ѣ��ӳ��ȵ�һ���λ�ÿ�ʼ������
	 creatheap(a,i,len);
 for (i=len; i>=1; --i)  //���Ѷ���Ԫ���Ƶ���󣬲�������Ĳ����ٴ����´���Ϊ��
 {
  t=a[1];
  a[1]=a[i];
  a[i]=t;
  creatheap(a,1,i-1);
 }
}
void creatheap(int a[],int root,int len) //���� ���Ը����Լ�����Ҫ��������ѻ���С����
{
 int i=2*root;    //�Ӹ��ڵ㿪ʼ���Źؼ��ֱȽϴ�Ľ�㿪ʼ����ɸѡ��
 int t=a[root];   //�Ƚ�������ֵ��������������֮��ıȽϺ͸�ֵ��
 int flag=0;      //��һ���м�ֵ���ж��Ƿ񸸽������ӽ�㡣
 while (i <= len && flag == 0)
 {
  if (i<len)  //���i<len ˵���������ӽ��
  {
   if (a[i]<a[i+1]) //�ҵ��ӽ���������Ƚϴ�� ��i���Ϊ�Ƚϴ��.
	   i++;
  }
  if (t >= a[i])  //������������ӽ��Ļ� �Ϳ��Բ���ȥ���� ���ҽ���ѭ����
	  flag=1;      
  else
  {               //��������С���ӽ��Ļ���Ҫ�Ƚ�������ֵ���佻�� �ٽ�i��ֵ����Ϊ������
   a[i/2]=a[i];   //�ٴν���ѭ�� ���ж� ���i��С���ܵĳ��ȵĻ� ˵�������滹�����ӽ��� 
   i=i*2;         //��Ҫ�ٴν���Ƚϣ����i�ĳ��ȴ����ܵĳ��ȵĻ���˵������û���ӽ���ˡ�
  }               //�Ϳ����˳�ѭ��
 }
 a[i/2]=t;   //�˳�ѭ����Ҫ����ԭʼҪ������ֵ�ŵ����Ӧ��λ�á�
}
#endif
#if 0 //Ҫ���������������ַ��������Ҳ���ʹ�õ�����������
void fput(char *a);
int main()
{
	char a[]="abcdefgh";
	fput(a);
	putchar('\n');
	return 0;
}
void fput (char *a)
{
	
	if(*a == '\0')
		return ;
	else
	{
		fput(++a);
		putchar(*(--a));
	}
}

#endif
#if 0 //�õݹ��㷨�ж�����a[N]�Ƿ�Ϊһ���������顣
int fun(int a[],int n);
int main()
{
 int a[10]={1,2,3,4,5,6,7,8,9,0};
 int n;
 n=fun(a,10);
 if (n==1)
 printf("�ǵ�������\n");
 else
 printf("���ǵ�������\n");
 return 0;
}
int fun(int a[],int n)
{
 if (n==1)
 return 1;
 else 
  {
   if (fun(a,n-1)==1&&a[n-1]<a[n])
       return 1;
    else return 0;
  } 
}
#endif
void update(char a[]);
#if 0 //��ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
void update(char a[]);
int main()
{
 char a[100]={"we are happay"};
 update(a);
 return 0;
}
void update(char a[])
{
 int i,j,n=0;
 for (i=0; a[i]!='\0'; ++i)
	 if (a[i]==' ')
		 n++;

 for (j=strlen(a)+2*n; j >= 0; )
 {
  if (a[i]!=' ')
	  {
		  a[j--]=a[i];
		  i--;
	  }
  else 
	  {
	   a[j--]='0';
	   a[j--]='2';
	   a[j--]='%';
	   i--;
	  }
 }
puts(a);
}
#endif
#if 0 //��1+2+3+....+n Ҫ����ʹ�ó˳��� for while if else switch case �ȹؼ��ּ������ж����
int f1(int n);
int f2(int n);
int (*p[2]) (int)={f1,f2};
int main()
{
 int n;
 printf("������һ����:n=");
 scanf("%d",&n);
 f2(n);
 printf("��Ϊ:%d\n",f2(n));
 return 0;
}
int f1(int n)
{
 return 0;
}
int f2(int n)
{
 return n+p[!!n](n-1);
}
#endif
#if 0
/*�ṹ��ĳ��֣��ܹ�����ͬ����������ɵ�����͵����ݽṹ���ṹ�����͵�һ����ʽΪ
 struct �ṹ���� {��Ա�б�}
 ����ṹ��ı��������ַ�����
 1.�������ṹ�����ͣ��ٶ�������͵ı�����
  struct student
{
	int number;
	char name[20];
	char sex;
}��       ����������������   struct student stu1; stu1����һ���ṹ�����͡�
 2.���������͵�ͬʱ���������
 struct student
{
	int number;
	char name[20];
	char sex;
}a;
3.���������͵�ͬʱ����������ṹ��������ʡ�ԣ�typedef ����һ�����ӵ�����
 typedef struct data
{
	char b;
	int number;
	char c;
}DATA;    ������DATA�����塣����: DATA a a����һ���ṹ�������ˡ�
*/
//�ṹ������ĳ�ʼ��������
struct student
{
	int number;
	char name[20];
	char sex;
};
typedef struct data
{
	char b;
	int number;
	char c;
}DATA;

int main()
{
 //int i;
 //typedef struct student STU;
 //struct student stu ={1,"list",'m'}; //�����ڶ����ʱ���ʼ��
 //printf("%d\n",sizeof(stu)); //������ڿ����ڴ��ʱ�򣬲��õ����ֽڶ��롣С�������ߵĻ�����ȡ���Ƿֱ���룬С����һ�ѵĻ�������һ�������ˡ�
 /* ���ýṹ������г�Ա��ֵ��ʱ�����÷�ʽΪ�� �ṹ�������.��Ա�� 
 ע�⣺����ͨ������ṹ����������ﵽ����ṹ����������г�Ա��ֵ��
 ͬ�����͵Ľṹ����������໥��ֵ��
 */
    struct student stu ={1,"lisi",'m'} ;
	struct student stu1;
	typedef struct student STU;
	int i;
	STU *p = &stu;
	STU a[5] = {{1,"111",'1'},{2,"222",'2'},{3,"333",'3'},
	{4,"444",'4'},{5,"555",'5'}};
//	DATA a;
//	printf("%d\n",sizeof(stu));
	printf("%d %s %c\n",stu.number,stu.name,stu.sex);
	stu.number = 5;
	strcpy(stu.name,"asd");//gets(stu.name);
	stu.sex = 'm';
	printf("%d %s %c\n",stu.number,stu.name,stu.sex);
	
	scanf("%d",&stu.number);
	getchar();
	gets(stu.name);
	scanf("%c",&stu.sex);
	printf("%d %s %c\n",stu.number,stu.name,stu.sex);
	
	stu1 = stu;
	printf("%d %s %c\n",stu1.number,stu1.name,stu1.sex);
	
	for(i = 0;i<5;i++)
		printf("%d %s %c\n",a[i].number,a[i].name,a[i].sex);
//	for(i = 0;i<5;i++)
//		scanf("%d %s %c",&a[i].number,a[i].name,&a[i].sex);
	printf("%d,%d\n",p->number,(*p).number);
	p = a;
}
#endif
/*
�ṹ������ 
���壺
1.
struct �ṹ����
{��Ա�б�} ������[���鳤��]
2.
������һ���ṹ������
�ṹ������ ������[���鳤��}
��ֵ�Ļ�������ѭ�����丳ֵ��Ҳ�����ڶ����ʱ��ֵ��
�ṹ��ָ��
���壺
1.�ȶ��� struct student *pt �ٽ�pָ��һ���ṹ������Ϳ�����
���ã�  (*p).��Ա��  p->��Ա��  �����ַ������ǿ��Եġ�
ָ��ṹ�������ָ��
  (1)������һ���ṹ�����ͣ����Ҷ���ṹ�����飬ͬʱ��ʼ����
  (2)����һ��ָ��ṹ�����͵�ָ�����p��
  (3)��pָ��ṹ���������Ԫ�أ��������
 */
#if 0
typedef struct student
{
 int number;
 int name[20];
}STU;
void sort(STU *a,int n);
void print(STU *a,int n);
void input(STU *a,int n);
int main()
{
 STU a[5];
 input(a,5);
 sort(a,5);
 print(a,5);
 return 0;
}
void input(STU *a,int n)
{
 int i;
 for (i=0; i<5; ++i)
	 scanf("%d %s",&a[i].number,a[i].name);
}
void sort(STU *a,int n)
{
 int i,j;
 STU t;
 for (i=0; i<n-1; ++i)
	 for (j=0; j<n-1-i; ++j)
		 if (a[j].number>a[j+1].number )
		 {
		  t=a[j];
		  a[j]=a[j+1];
		  a[j+1]=t;
		 }
}
void print(STU *a,int n)
{
 int i;
 for (i=0; i<5; ++i)
	 printf("%d %s\n",a[i].number,a[i].name);
}
#endif
#if 0 //��̬���� ���ھ�̬�����ʹ�ò����ر�Ķ࣬���ԵĿ�һ�´�������ˡ�
typedef struct node
{
	int n;
	struct node *next;
}Node;
int main()
{
 void main()
{
	Node a,b,c,d;
	Node *head = NULL,*p = NULL;
	head = &a;
	a.n = 1;
	a.next = &b;
	b.n = 2;
	b.next = &c;
	c.n = 3;
	c.next = &d;
	d.n = 4;
	d.next = NULL;

	p = head;
	while(p!= NULL)
	{
		printf("%d ",p->n);
		p = p->next;
	}
}
}
#endif
#if 0 //��̬����Ĵ���
typedef struct node
{
	int n;
	struct node *next;
}Node;
Node *creat();
void print(Node *head);
int main()
{
 Node *head = creat();
 print(head);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*pnew=NULL,*ptail=NULL; //�ȶ�������ָ�룬�ֱ�ָ���
 pnew=(Node*)malloc(sizeof(Node));  //�ȸ�pnew�����ڴ�ռ�
 pnew->next = NULL;                 //��pnew->next ָ���
 while (1==scanf("%d",&pnew->n))    //�����������һֱ��������ʱ ��һֱִ��ѭ��
 {
  if (head == NULL)     // ��һ�ε�ʱ��head ָ��pnew
	  head = pnew;      //head ʼ��ָ���һ�����׵�ַ
   else 
	  ptail->next = pnew; //ʼ�ս� ptail->next ָ��pnew��λ��
  ptail=pnew;      //��ptailָ��pnew��λ��
  pnew = (Node*)malloc(sizeof(Node)); //�ٴ�Ϊpnew�����ڴ�ռ�
  pnew->next = NULL;  //��pnew->next ָ���
 }
 free(pnew);
 pnew = NULL;
 return head; //���׵�ַ����
}
void print(Node *head)
{
 Node *p=head;
 while (p != NULL)
 {
	 printf("%d ",p->n);
	 p = p->next;
 }
 printf("\n");
}
#endif