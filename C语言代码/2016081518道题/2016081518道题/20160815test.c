#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0 // ��дһ��C�������ӱ�׼�����ȡCԴ���룬����֤���еĻ������Ƿ���ȷ�ĳɶԳ��֣�
                                   //���ص���ע���ڲ����ַ��������ڲ����ַ�������ʽ�Ļ����š�
int main()
{
 char ch;
 int n = 0;
 while ((ch = getchar()) != '0')
 {
  if (ch == '{')
	  n++;
  if (ch == '}')
  {
    if (n == 0)
   {
	   printf("not\n");
	   exit(0);
   }
   else 
	   n--;
  }
 }
 if (n != 0)
	  printf("not\n");
 else 
	 printf("yes\n");
 return 0;
}
#endif
#if 0 //��
int main()
{
	char ch;
	int count = 0;
	while((ch = getchar()) != '\n')
	{
		if(ch == '{')
			count+=1;
		if(ch == '}')
		{
			if(count == 0)
				printf("not\n");
			else
				count-=1;
		}
	}
	if(count>0)
		printf("%d\n",count);
	return 0;
}
#endif
#if 0  //����n��ƽ��������ͨ������һϵ�н���ֵ����ã�ÿһ������ֵ����ǰһ�����ӽӽ���ȷ��ֵ����һ��
                                       //��һ������ֵ��1���������Ľ���ֵ��ͨ������Ĺ�ʽ�����
int main()
{
 float n;
 float newnumber,oldnumber;
 printf("������һ������:n=");
 scanf("%f",&n);
 newnumber = 1;
 do 
 {
  oldnumber = newnumber;
  newnumber = (oldnumber + n/oldnumber)/2;
  printf("%f\t",newnumber);
 }while (newnumber != oldnumber);
 printf("%f��ƽ����Ϊ:%f\n",n,oldnumber);
 return 0;
}
#endif
#if 0 //��
int main()
{
	float new_num;
	float last_num;
	float num;
	printf("enter a number\n");
	scanf("%f",&num);
	if(num < 0)
	{
		printf("error\n");
		return 0;
	}
	new_num = 1;
	do
	{
		last_num = new_num;
		new_num = (last_num + num/last_num)/2;
		printf("%f\n",new_num);
	}while(new_num != last_num);
	printf("sqrt root of %g is %g\n",num,new_num);
	return 0;
}
#endif
#if 0//��д����copy_n,����ԭ��Ϊ void copy_n(char dest[],char src[],int n)
void copy_n(char dest[],char src[],int n);
int main()
{
 char dest[100],src[100];
 int n;
 gets(dest);
 gets(src);
 printf("��������Ҫ���Ƶĸ���:n=");
 scanf("%d",&n);
 copy_n(dest,src,n);
 puts(dest);
 return 0;
}
void copy_n(char dest[],char src[],int n)
{
 int i;
 if (n > strlen(src))
 {
  for (i=0; i<strlen(src); ++i)
	  dest[i] = src[i];
  for (; i<n; ++i)
	  dest[i] = NULL;
 }
 if (n <= strlen(src))
 {
  for (i=0; i<n; ++i)
      dest[i] = src[i];
 }
}
#endif
#if 0
void copy_n(char dst[],char src[],int n)
{
	int dst_index,src_index;
	src_index = 0;
	for(dst_index = 0;dst_index < n;dst_index ++)
	{
		dst[dst_index] = src[src_index];
		if(src[src_index] != 0)
			src_index ++;
	}
	dst[n] = '\0';
}

int main()
{
	char src[40] = "abcdefghijklmnopqrstuvwxyz";
	char dest[40];
	copy_n(dest,src,10);
	puts(dest);
	return 0;
}
#endif
#if 0      //��һ�����Ķ�����λ�����������ν��н���Ȼ�����

int main()
{
 int n,i=0,a[32],j,k,l;
 unsigned newnumber=0,s=0;
 printf("������Ҫת������:n=");
 scanf("%d",&n);
 while (n != 0)
 {
  a[i] = n%2;
  n=n/2;
  i++;
 }
 l=i--;
 for (i=0,k=0; i<=l; i++,++k)
 {
	 s=0;
  if (a[i] == 1)
	  for (j=1,s=1; j<=31-k; j++)
	     s = 2*s;
  newnumber = newnumber+s;
 }
 printf("ת�������Ϊ:%u\n",newnumber);
 return 0;
}
#endif
#if 0
unsigned int reverse_bits(unsigned int value)
{
	unsigned int answer;
	unsigned int i;
	answer = 0;
	for(i = 1;i != 0;i <<= 1)
	{
		answer <<= 1;
		if(value & 1)
			answer |= 1;
		value>>=1;
	}
	return answer;
}
int main()
{
	unsigned int num;
	scanf("%d",&num);
	num = reverse_bits(num);
	printf("the result is ��%u\n",num);
	return 0;
}
#endif
#if 0 //���ַ������������ת��
void reverse(char *p);
int main()
{
 char a[20],*p,*q;
 gets(a);
 p = a;
 reverse(p);
 puts(a);
 return 0;
}
void reverse(char *p)
{
 int i,n=0;
 char *q,t;
 for (i=0; *(p+i) != '\0'; i++)
	 n++;
 q = p+n-1;
 for (i=0; i<n/2; ++i)
 {
  t = *p;
  *p = *q;
  *q = t;
  p++;
  q--;
 }
}
#endif
#if 0
void reverse_str(char *str)
{
	char *last_char;
	char temp;
	for(last_char = str;*last_char != '\0';++last_char);
	--last_char;
	while(str < last_char)
	{
		temp = *str;
		*str++ = *last_char;
		*last_char-- = temp;
	}
}
int main()
{
	char str[100];
	char *pstr = str;
	gets(str);
	reverse_str(pstr);
	puts(pstr);
	return 0;
}
#endif
#if 0      //���ܶ���ʽ
int hermit(int n,int x);
int main()
{
 int n,x;
 printf("������n��x��ֵ:");
 scanf("%d%d",&n,&x);
 printf("���ܶ���ʽ��ֵΪ:%d\n",hermit(n,x));
 return 0;
}
int hermit(int n,int x)
{
 if (n <= 0)
	 return 1;
 if (n == 1)
	 return 2*x;
 if (n >= 2)
	 return (2*x*hermit(n-1,x)-2*(n-1)*hermit(n-2,x));
}
#endif
#if 0 //�������ַ�ת��Ϊ���������ҷ�������
int ascinteger(char *p);
int main()
{
 char a[20],*p = NULL;
 p = a;
 gets(a);
 printf("%d\n",ascinteger(p));
 return 0;
}
int ascinteger(char *p)
{
 int n=0,i=0;
 while (p[i]>='0'&&p[i]<='9')
 {
  n=n*10+p[i]-'0';
  i++;
 }
 if (p[i] != '\0')
	 n = 0;
 return n;
}
#endif
#if 0 //Ϊ����������дһ������
float singletax(float income);
int main()
{
 float income;
 printf("������Ĺ���;income=");
 scanf("%f",&income);
 printf("����Ҫ����˰��Ϊ:%f\n",singletax(income));
 return 0;
}
float singletax(float income)
{
 if (income>=0&&income<=23350)
	 return (0.15*income);
 if (income>23350&&income<=56550)
	 return (3502.02+0.28*income);
 if (income>56550&&income<=117950)
	 return (12798.50+0.31*income);
 if (income>117950&&income<=256550)
	 return (31832.50+0.36*income);
 if (income>256550)
	 return (81710.05+0.396*income);
}
#endif
#if 1
static double ins[] = {0,23350,56550,117950,256500};
static double ba[] = {0,3502.5,12798.5,31832.5,81710.5};
static double pe[] = {0.15,0.28,0.31,0.36,0.396};
double single_tax(double in)
{
	int cate;
	for(cate = 1;in >= ins[cate];cate++);
	cate--;
	return ba[cate]+pe[cate]*(in-ins[cate]);
}
int main()
{
	float result = 85649.5;
	printf("%f\n",single_tax(result));
	return 0;
}
#endif
#if 0 //��дһ�����������ά������ˣ�
void matrix_multiply(int *a,int *b,int *c,int x,int y,int z);
int main()
{
 int a[3][2]={{2,-6},{3,5},{1,-1}};
 int b[2][4] = {{4,-2,-4,-5},{-7,-3,6,7}};
 int c[3][4];
 int i,j;
 matrix_multiply(a[0],b[0],c[0],3,2,4);
 for (i=0; i<3; ++i)
 {
	 for (j=0; j<4; ++j)
		 printf("%-4d",c[i][j]);
 printf("\n");
 }
 return 0;
}
void matrix_multiply(int *a,int *b,int *c,int x,int y,int z)
{
 int *p1,*p2;
 int i,j,k;
 for (i=0; i<x; ++i)
 {
  for (j=0; j<z; ++j)
  {
   p1 = a+i*y;
   p2 = b+j;
   *c = 0;
   for (k=0; k<y; ++k)
   {
    *c += *p1 * *p2;
	p1 += 1;
	p2 += z;
   }
   c++;
  }
 }
}
#endif
#if 0 //��дmy_strlen����
int my_strlen(char a[]);
void str(char a[]);
int main()
{
 char a[20];
 printf("������һ���ַ���:");
 str(a);
 printf("�ַ�������Ϊ:%d\n",my_strlen(a));
 return 0;
}
int my_strlen(char a[])
{
 int n=0,i=0;
 while (a[i] != '*')
 {
  n++;
  i++;
 }
 return n;
}
void str(char a[])
{
 char ch,i=0;
 while ((ch = getchar()) != '*')
 {
  a[i] = ch;
  i++;
 }
 a[i] = '*';
}
#endif
#if 0  //дһ��mystrcpy���� 
char *mystrcpy(char a[],char b[]);
int main()
{
 char a[20],b[20];
 printf("������һ���ַ���:");
 gets(b);
 mystrcpy(a,b);
 puts(a);
}
char *mystrcpy(char a[],char b[])
{
 int i;
 char *p = NULL;
 for (i = 0; b[i] != '\0'; ++i)
	 a[i] = b[i];
 a[i] = '\0';
 return p;
}
#endif
#if 0 //ͳ�Ƶ���the�ĸ���
int count(char a[]);
int main()
{
 char a[100];
 printf("������һ���ַ���");
 gets(a);
 printf("the�ĸ���Ϊ:%d\n",count(a));
 return 0;
}
int count(char a[])
{
 int n,i=0,num=0;
 char b[] = "' '";
 char *c[30];
 char *tok = NULL;
 for(tok=strtok(a,b);tok!=NULL;tok=strtok(NULL,b))
 {
  c[i] = tok;
  i++;
 }
 n = i;
 for (i=0; i<n; ++i)
	 if (strcmp(c[i],"the") == 0)
		 num++;
 return num;
}
#endif
#if 0 //��дһ���������ڴ�ӡ������ʱ�����Լ��Ӷ���
void dollars(char *dst,char *src)
{
	int len,i;
	if(NULL == dst || NULL == src)
		return;
	*dst++ = '$';
	len = strlen(src);
	if(len >= 3)
	{
		for(i = len-2;i>0;)
		{
			*dst++ = *src++;
			if(--i>0 && i % 3 == 0)
				*dst++ = ',';
		}
	}
	else
		*dst ++ = '0';
	*dst++ = '.';
	*dst++ = len < 2 ? '0':*src++;
	*dst++ = len < 1 ? '0':*src;
	*dst = '\0';
}
int main()
{
	char str[30];
	char convert[42];
	char *p = convert;
	printf("������һ���ַ���:\n");
	gets(str);
	dollars(p,str);
	printf("%s\n",p);
	return 0;
}
#endif
#if 0 //14.��дһ���������ӱ�׼�����ȡһ������������Щֵ�洢��һ����̬����������в������������
                        //����ĵ�һ���������������ֵ�ĸ��������ĺ��������Щ����ֵ
#include<stdlib.h>
#define N 10
void input();                        
int main()
{
 input();
 return 0;
}
void input()
{
 int *p;
 int size = N;
 int count =0;
 int a,i;
 p = (int*)malloc((size+1)*sizeof(int));
 printf("������һ������:(���ַ��������ո�Ϊ�ָ���)\n");
 while (1 == scanf("%d",&a))
 {
  count++;
  if (count >= size)
	  {
	   size = size + N;
	   p = (int*)realloc(p,(size+1)*sizeof(int));
	  }
	  p[count] = a;
 }
 if (count < size)
 p = (int*)realloc(p,(count+1)*sizeof(int));
 p[0] = count;
 for (i=0; i<=count; ++i)
 printf("%d,",p[i]);
 free(p);
 p = NULL;
 
}
#endif
#if 0 //��дһ�����������ڼ���һ��������ڵ�ĸ���������Ψһ��������һ��ָ�������һ���ڵ��ָ�롣
           //��д���������ʱ�������֪����Щ��Ϣ�����������������ִ������������
typedef struct NODE
{
 int value;
 struct NODE *next;
} Node;
Node *creat();
int count(Node*head);
int main()
{
 Node *head = creat();
 printf("�ڵ����Ϊ:%d\n",count(head));
 return 0;
}
 Node *creat()
 {
  Node *head = NULL,*p1 = NULL,*p2 = NULL;
  p1 = (Node*)malloc(sizeof(Node));
  while(1 == scanf("%d",&p1->value))
  {
   if (head == NULL)
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
 int count(Node*head)
 {
  int n = 1;
  Node *p1 = head;
  if (head == NULL)
   return 0;
   else 
   {
    for (; p1->next != NULL; p1 = p1->next)
    n++;
   }
   return n;
 }       
#endif
#if 0 //�ӵ��������Ƴ�һ���ڵ㣬������ԭ��Ӧ�����£�
      //int sll_remove(struct NODE **root,struct NODE*node);
typedef struct NODE
{
 int value;
 struct NODE *next;
} Node;
Node *creat();
void insert(Node*p1,Node*head);
int removeNode(Node*head,Node*p1);
void print(Node*head);
int main()
{
 Node *head = creat();
 print(head);
 Node *p1 = (Node*)malloc(sizeof(Node));
 p1->value = 5;
 insert(p1,head);
 print(head);
  if (removeNode(head,p1) == 1)
  printf("delete data\n");
  else 
  printf("not exist\n");
  print(head);
 return 0;
}
Node *creat()
 {
  Node *head = NULL,*p1 = NULL,*p2 = NULL;
  p1 = (Node*)malloc(sizeof(Node));
  while(1 == scanf("%d",&p1->value))
  {
   if (head == NULL)
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
 void insert(Node*p1,Node*head)
 {
  Node *p2 = NULL;
  p2 = head->next;
  head->next = p1;
  p1->next = p2;
 } 
 int removeNode(Node*head,Node*p1)
 {
  Node *p2 = NULL,*p3 = NULL;
  p2 = head;
  for (; p2->next != NULL; p3 = p2,p2 = p2->next )
     if (p2->value == p1->value)
     {
      p3->next = p2->next;
      free(p2);
      p2 = NULL;
      break;
     }
     if (p2 != NULL)
     return 0;
     else 
     return 1;
 }
 void print(Node*head)
 {
  Node *p1 = NULL;
  for (p1 = head; p1->next != NULL; p1 = p1->next)
      printf("%d,",p1->value);
      printf("%d,",p1->value);
      printf("\n");
 }
#endif
#if 0  //��ʵ��һ��˫������Ĳ��뺯��������ԭ������:
       //int dll_insert(Node *root,int value);
typedef struct NODE
{
 int value;
 struct NODE *front;
 struct NODE *next;
}Node;      
Node* creat();   
void sort(Node*head);
Node* insert(Node*head,int value);
void print(Node*head);   
int main()
{
 Node *head = creat();
 sort(head);
 print(head);
 head=insert(head,5);
 print(head);
 return 0;
}
Node* creat()
{
 Node *head = NULL,*p1 = NULL,*p2 = NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1 -> front = NULL;
 p1 -> next = NULL;
 while (1 == scanf("%d",&p1 -> value))
 {
  if (head == NULL)
  head = p1;
  else
  {
  p2 -> next = p1;
  p1 -> front = p2;
  }
  p2 = p1;
  p1 = (Node*)malloc(sizeof(Node));
  p1 -> front = NULL;
  p1 -> next = NULL;
 }
 free(p1);
 p1 -> next = NULL;
 p1 -> front = NULL;
 return head;
}
void sort(Node*head)
{
 int i,j,n=0,t;
 Node*p1 = NULL,*p2 = NULL;
 p1 = head;
 if (p1 == NULL)
 return;
 for (; p1 -> next != NULL; p1 = p1 -> next)
      n++;
 for (i=0; i<n-1; ++i)
  for (j=0,p1 = head; j<n-i-1; ++j,p1 = p1 ->next)
        {
         p2 = p1 -> next;
         if (p1 -> value > p2 -> value)
         {
          t = p1 -> value;
          p1 -> value = p2 -> value;
          p2 ->value = t;
         }
        }
}
Node* insert(Node*head,int value)
{
 Node *p1 = NULL,*p2 = NULL,*p3 = NULL;
 p3 = (Node*)malloc(sizeof(Node));
 p3 -> value = value;
 p3 -> next = NULL;
 p3 -> front = NULL;
 if (head == NULL)
 return p3;
 if (value < head -> value)
 {
  p3 -> next = head;
  head -> front = p3;
  p3 -> front = NULL;
  head = p3; 
 }
 else
  for (p1 = head; p1 ->next != NULL; p1 = p1 -> next)
          if (value > p1->value && value < p1->next->value || p1->next ==NULL)
          {
           p2 = p1 ->next;
           p1 ->next = p3;
           p3 ->front = p1;
           p3 ->next = p2;
           p2 ->front = p3;
          }
          return head;
}
void print(Node*head)
 {
  Node *p1 = NULL;
  for (p1 = head; p1->next != NULL; p1 = p1->next)
      printf("%d,",p1->value);
      printf("%d,",p1->value);
      printf("\n");
 }
#endif
#if 0 //��дһ��������ͨ������һ��1��6���������ģ����ɸ�ӣ�ע����6��ֵ���ֵĸ���Ӧ��
      //��ͬ�������������һ�ε���ʱ����Ӧ���õ���ĵ�ǰʱ����Ϊ���������������
#include<time.h>
int main()
{
 int i;
 srand((unsigned)time(NULL));
 for (i=0; i<10; ++i)
 printf("%d\n",(rand()%6)+1);
 return 0;
}
#endif



























