#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
int fun(char *sl,char *s2)
{ int i=0;
while(sl[i]==s2[i]&&s2[i]!='\0') i++;
return(sl[i]=='\0'&&s2[i]=='\0');
}

int main()
{
 char a[20],b[20];
 char *s1=NULL,*s2=NULL;
 int n;
 gets(a);
 gets(b);
 s1=a;
 s2=b;
 n=fun(s1,s2);
 printf("%d\n",n);
 return 0;
}
#endif
#if 0//1��1ֱ�Ӳ�������
void insertSort(int a[]);
int main()
{
 int a[]={49,38,65,97,76,13,27};
 int i;
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 insertSort(a);
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void insertSort(int a[])
{
 int i,j,t;
 for (i=1; i<7; ++i)// ��ʼ��ʱ����Ϊa[0]������ģ�����Ϊ���������С�
 {
  for (j=i; j>0; --j)//�Ӻ�������ȡԪ�����������������������ݣ�
   if (a[j]<a[j-1])  //�ñ����ķ����ҵ�Ӧ�ò����λ�ã�ÿ�ζ���������
   {
    t=a[j];
	a[j]=a[j-1];
	a[j-1]=t;
   }
 }
}
#endif
#if 0 //1.2ֱ�Ӳ������򣨼����ڱ���
void insertSort(int a[]);
int main()
{
 int a[]={0,49,38,65,97,76,13,27};
 int i;
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 insertSort(a);
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void insertSort(int a[])
{
 int i,j,k;
 for (i=2; i<8; ++i) //��ʼʱ��Ϊa[1]���������У�����Ϊ�������С�
   if (a[i]<a[i-1]) //�����������С�����һ���ؼ��֣���
	  {
	   a[0]=a[i];  //�Ƚ�����Ĺؼ��ָ���Ϊ�ڱ�
	   a[i]=a[i-1]; //��������������һ�����ݺ���һλ
	  for (j=i-2; j>0&&a[0]<a[j]; --j)//һ�߱Ƚ�һ�ߺ���
		  a[j+1]=a[j]; //�����������д����ڱ��ĵĲ����������һλ
	  a[j+1]=a[0];  //�ҵ����ʵ�λ�ã������ڱ�
      }
}
#endif
#if 0
void BinsertSort(int a[]);
int main()
{
 int a[]={0,49,38,65,97,76,13,27};
 int i;
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 BinsertSort(a);
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void BinsertSort(int a[]) //�۰����Ҳ���ڼ����ڱ��Ļ����϶��������н�����㷨����
{
 int low,high,m,i,j;
 for (i=2; i<8; ++i) //��ʼʱ��Ϊa[1]���������У�����Ϊ�������С�
 {
  a[0]=a[i];     //�Ƚ�����Ĺؼ��ָ���Ϊ�ڱ�
  low=1;high=i-1; 
  while (low <= high) //���۰���ҵķ�����ȷ����������������������Ӧ�ò����λ��
  {
   m=(low+high)/2;
   if (a[0]<a[m])
	   high=m-1;
   else
	   low=m+1;
  }
  for (j=i-1; j>= high+1; --j)  //�����������д��ڲ������ݵĶ�����һλ
	  a[j+1]=a[j];
  a[j+1]=a[0]; //����������ݷ�����ʵ�λ��
 }
}
#endif
#if 0 //�鲢����
void remsort(int a[],int b[],int left,int right);
void merge(int a[],int b[],int left,int mid,int right);
int main()
{ 
 int a[]={49,38,65,97,76,13,27,49};
 int b[20];
 int left,right,i;
 left=0;
 right=6;
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 remsort(a,b,left,right);
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void remsort(int a[],int b[],int left,int right)
{
 int mid=(left+right)/2; //��ԭ��¼����ƽ�ֳ������֣�
 if (left>=right)  //��ֻ��һ�����ݵ�ʱ�򣬱����������ģ���Ϊ�ݹ���ֹ������
	 return ;
 remsort(a,b,left,mid); //�ݹ�Ľ���ߵĲ��ֽ�������
 remsort(a,b,mid+1,right); //�ݹ�Ľ��ұߵ����н�������
 merge(a,b,left,mid,right); //��������������кϲ���һ���µ�����a
}
void merge(int a[],int b[],int left,int mid,int right)
{
 int i;
 int s1,s2,k;
 for (i=left; i <= right; ++i) //��a����������ȱ��浽b����ȥ��
	 b[i]=a[i];
 s1=left; //��s1����¼�׸�Ԫ��
 s2=mid+1;//��s2����¼�ڶ������׸�Ԫ��
 k=left; //��k����ʼ��λ��
 while (s1<=mid&& s2<= right) //��whileѭ�����������ֽ��кϲ� ������
 {
  if (b[s1]<=b[s2])
	  a[k++]=b[s1++];
  else 
	  a[k++]=b[s2++];
 }
 while (s1<=mid)    //�����ʣ��Ԫ��û���Ž�ȥ�ģ���while ѭ�����θ�ֵ��ȥ
	 a[k++]=b[s1++];
 while (s2<=right)
	 a[k++]=b[s2++];
}
#endif
#if 0//���������Ƕ�ð�ݷ��ĸĽ�
int quicksort(int a[],int left,int right);
void Qsort(int a[],int left,int right);
int main()
{
 int a[]={49,38,65,97,76,13,27,49};
 int left,right,i;
 left=0;
 right=6;
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 Qsort(a,left,right);
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void Qsort(int a[],int left,int right)
{
	int p; //���Ա�־�����λ��
 if (left <right)
 {
  p=quicksort(a,left,right); //ȷ���б�L�����������λ��
  Qsort(a,left,p-1); //�������󲿵����б��һ������
  Qsort(a,p+1,right); //�������Ҳ������б��һ������
 }
}
int quicksort(int a[],int left,int right)
{
 int k;
 k=a[left]; //��k������ÿ�εĹؼ���,Ϊ�˼��ٽ����Ĵ��������ؼ����ȱ��棬��ѭ��������Ҳ����ȷ��
            //����λ�õ�ʱ���ٽ����ƹ�ȥ��
 while (left<right) //��left=right��ʱ�򣬾�ȷ�������������λ�ã�
 {
  while (left <right&&a[right]>=k) //�����ƶ�right��Խ����С������ļ�¼�������һ��С������ļ�¼��
	  right--;    //
   a[left]=a[right];  //��С������ļ�¼�����ᡰ�뽻����
   while (left <right&&a[left]<=k) //�����ƶ�left��Խ��С������ļ�¼�������һ����������С�ļ�¼��
	   left++;   //����С������ļ�¼�������ύ��
   a[right]=a[left]; 
 }
 a[left]=k; //ȷ������������λ�ã����Խ����ƹ���
 return left; //������������λ��
}
#endif
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
