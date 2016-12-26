#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
typedef struct node
{
 int n;
 struct node *next;
}Node;
Node *creat();
void print(Node *head);
Node *sort(Node *head);  //����
Node *swap(Node *head);  //����
int main()
{
 Node *head = creat();
 print(head);
 head=sort(head);
 print(head);
 head=swap(head);
 print(head);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
 }
void print(Node *head)
{
 Node *p = head;
 while (p !=NULL)
 {
	 printf("%d ",p->n);
	 p = p->next;
 }
 printf("\n");
}
Node *sort(Node *head)
{
 Node *newhead=NULL,*newtail=NULL,*p,*min,*minf;
 if (head == NULL || head->next == NULL)
	 return head;
 while (head != NULL)
 {
  p = min = head;
  for (; p->next!=NULL ; p = p->next )
  { 
     if (p->next ->n <min ->n) //��һ���ȱ���һ���ҵ���С�ģ�minʼ��ָ����С�ġ�
	 {                         //��minfʼ��ָ��minǰ�����һ����
	  min = p->next ;
	  minf =p; 
	 }
  }
   //2
	 if (newhead==NULL)   //��һ�ε�ʱ�� newhead �� newtail��ָ��min;
		 {
		  newhead = newtail =min;
		 }
	 else    //��һ�ε�ʱ�� ��newtail->next ������ ��һ�α�������Сֵ��
	 {       //�ٽ�newtailָ��min
	   newtail->next = min;
	   newtail = min;
	 }
	 //3  ɾ��
	 if (min ==head) //����ҵ�����Сֵ�պ���head�Ļ����ͽ�headָ��head����һ��
		 head = head->next ;
	 else 
		 minf->next = min->next;  //����Ļ� ��minf�����nextָ��min����һ��
  }
 if (newhead!=NULL)
	 newtail->next =NULL; //�����һ�������nextָ��ΪNULL
 return newhead;
 }
Node *swap(Node *head)
{
  Node *p=NULL,*pf=NULL,*pn=NULL;
  if (head ==NULL ||head->next ==NULL)
	  return head;
  pf = head;   //�Ƚ�pfָ��head
  p =pf->next ; //��pָ��head����һ����
  pf->next =NULL; //�Ƚ�pf->nextָ��Ϊ0
  while (p ->next !=NULL)
  {
        pn = p->next; //����pnָ��p����һ��
		p->next = pf; //��p->next��ָ��pf
		pf = p;   //�ٽ�pfָ��p
		p = pn;   //p��ָ��pn
  }
  p ->next =pf;
  head = p;
  return head;
}
#endif
#if 0
typedef struct node
{
 int n;
 struct node *next;
}Node;
void test(Node *head); //����ҵ�������м�λ�ã���������ָ�룬��ָ��head,����һ��ָ��ÿ���������Σ���
int main()               //һ��ָ��ÿ������һ�Ρ�����һ��ָ���ߵ���β��ʱ�򣬵ڶ���ָ������м�
{
 Node *head;
 head=test(head);
 return 0;
}
void test(Node *head)
{
 Node *p1=NULL,*p2=NULL;
 p1 = p2 =NULL;
 while (p1 != NULL)
 {
  p1 = p1->next ;
  if (p1 != NULL)
  {
	  p1 = p1->next;
	  p2 = p2->next; 
  }
 }
}
#endif
#if 0
typedef struct data    //ѭ������ �����һ��������治ָ��Ϊ0��ָ��head��
{
	int n;
	struct data *next;
}Node;
Node *create();
void print(Node *head);
int main()
{
 Node *head=create();
 print(head);
 return 0;
}
Node *create()
{
	Node *head=NULL,*p1=NULL,*p2=NULL;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
	while(1 == scanf("%d",&p1->n))
	{
		if(head == NULL)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (Node*)malloc(sizeof(Node));
		p1->next = NULL;
	}
	free(p1);
	p1 = NULL;
	p2->next = head;
	return head;
}
void print(Node *head)
{
	Node *p = head;
	do         //ѭ�������������ʱ��Ӧ�ð��ж��������ˡ�
	{
		printf("%d ",p->n);
		p = p->next;
	}while(p != head);
	printf("\n");
}
#endif
#if 0
typedef struct data
{
	int n;
	struct data *next;
	struct data *front;
}Node;
Node *create();
void print(Node *head);
int main()
{
 Node *head =create();
 print(head);
 return 0;
}
Node *create()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1=(Node*)malloc(sizeof(Node));
 p1->front = NULL;
 p1->next  = NULL;
 while (1 == scanf("%d",&p1->n ))
 {
  if (head ==NULL)
     head =p1;
  else
  {
   p2->next =p1; //˫ָ������ڶ���һ�����ǰ���ַ��ָ�롣
   p1->front =p2;  //
  }
  p2 = p1;
  p1=(Node*)malloc(sizeof(Node));
  p1->front = NULL; //ÿ���ڶ����µ�ָ���ʱ��ǵý�ָ��ָ��Ϊ�վ����ˡ�
  p1->next  = NULL; //
 }
 free(p1);
 p1 = NULL;
 return head;
}
void print(Node *head)
{
 Node *p = head,*p1 = NULL;  //�����˫ָ���ʱ��ֻҪ�ǵý�����ָ��ķֱ��ŵĵ�ַ��ʲô�Ϳ���Ū���
	while(p != NULL)
	{
		p1= p;
		printf("%d ",p->n);
		p = p->next;
	}
	printf("\n");
	while(p1 != NULL)
	{
		printf("%d ",p1->n);
		p1 = p1->front;
	}
	printf("\n");
}
#endif
#if 0  //����Ĳ���
typedef struct data
{
	int n;
	struct data *next;
}Node;
Node *creat();
Node *find(Node *head,int key);     //�ҵ��ؼ��ֵ�λ��
void insert(Node *head,int newdata,int key);  //����
void print(Node *head);
int main()
{
 int key,newdata=9;
 Node *head;
 printf("����Ҫ�����Ǹ����ĺ��棺key=");
 scanf("%d",&key);
 printf("input numbers:\n");
 head=creat();
 insert(head,9,key);
 print(head);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
 }
Node *find(Node *head,int key)  //�ҵ��ؼ��ֵ�λ��
{
 Node *p1 =NULL,*p2 = NULL;
 p1 =head;
 for (;p1->next !=NULL; p1 =p1->next )
 {
	 if (p1->n ==key)
		 p2 = p1;
 }
 if (p2 !=NULL)
	 return p2;
 else 
	 return NULL;
}
void insert(Node *head,int newdata,int key)
{
 Node *newnode = NULL;  //�½�һ�����
 Node *p1 =find(head,key); //p1�ǲ���λ��֮ǰ�Ľ��ָ��
 newnode=(Node *)malloc(sizeof(Node)); //����㿪���µ��ڴ�
 newnode->n =newdata;   //newdata���½�������
  if (head ==NULL||p1==NULL)  //�������û�н�� �����Ҳ����ؼ��ֵĽ��
  {
	  newnode->next=head; //�Ͳ��뵽��ͷλ��   ����������
	  head =newnode;  // �ٶϿ�
  }
  else   
  {
	  newnode->next=p1->next;  //���� �Ͳ�����p1�ĺ��棬 ������
	  p1->next=newnode;  //�ٶϿ�
  }
}
void print(Node *head)
{
	Node *p = head;
	while(p != NULL)
	{
		printf("%d ",p->n);
		p = p->next;
	}
	printf("\n");
}
#endif
#if 0
typedef struct data
{
	int n;
	struct data *next;
}Node;
Node *creat();
void print(Node *head);
Node* find(Node *head,int key);
void Delete(Node *head,int key);
int main()
{
 Node *head;
 int key=5;
 printf("input numbers:");
 head=creat();
 //printf("Ҫɾ���Ĺؼ���:key=");
 //scanf("%d",&key);
 Delete(head,key);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
 }
Node* find(Node *head,int key)
{
 Node *p1=head,*p2=NULL,*p3=NULL;
 if (head->n ==key)
	 return p2;
 else
 {
	 for (; p1->next !=NULL;p3=p1, p1 =p1->next )
	 {   
	  if (p1->n == key)
		  p2 =p3;
	 }
	 if (p2 !=NULL)
		 return p2;
	 else 
		 return NULL;
 }
}
void Delete(Node *head,int key)
{
 Node *p=NULL,*p1=find(head,key);

 if (head!=NULL)
 {
    if (head->n ==key)
		{
	     p=head;
		 head=head->next;
		 free(p);
		 print(head);
		}
	else 
		{
	     while (p1!=NULL)
		 {
			 if (p1->next->n==key)
			 {
				 p=p1->next;
				 p1->next=p->next;
				 free(p);
				 print(head);
				 p1 =NULL;
			 }
		 }
		}
 }
 else 
 printf("û�ҵ��ؼ��ֻ�������Ϊ��\n");
}
void print(Node *head)
{
	Node *p = head;
	while(p != NULL)
	{
		printf("%d ",p->n);
		p = p->next;
	}
	printf("\n");
}
#endif
#if 0  //�ж�һ���������Ƿ�ɻ�
typedef struct data
{
	int n;
	struct data *next;
}Node;
Node *creat();
b
int main()
{
 Node *head=NULL;
 head=creat();
 judge(head);
}
Node *creat()
{
  Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 p2->next=head->next;
 return head;
}
#endif