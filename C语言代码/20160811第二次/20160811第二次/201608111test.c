#include<stdio.h>
#include<stdio.h>
#if 0  //�������Ҳ������ѡ�������е�һ�֣������ô��ѵķ�ʽ��Ч�ʱȽϸߡ�
//void sort(int a[],int len);
//void print(int a[],int len);
void creatheap(int a[],int root,int len);
int GetMin(int array[], int Length,int k);
void Swap(int* a,int* b);
void Kmin(int array[] , int Length , int k); 
int main()
{
 int a[101]={0}; //ʹ����������ʱ��Ҫ��������±���иı䣬a[0]�����Ԫ��
 int i,k=10;
 for (i=1; i<=100;++i)
	 a[i] = i;
 Kmin(a,100,10);
 return 0;
}

/*void print(int a[],int len)
{
 int i;
 for (i=1; i<=len; ++i)
	 printf("%d ",a[i]);
 printf("\n");
}
*/
/*
void sort(int a[],int len)
{
 int i;
 int t;
 for (i=len/2; i>=1; --i)  //������ʼ�ѣ��ӳ��ȵ�һ���λ�ÿ�ʼ������
	 creatheap(a,i,len);
 print(a,100);
 for (i=len; i>=1; --i)  //���Ѷ���Ԫ���Ƶ���󣬲�������Ĳ����ٴ����´���Ϊ��
 {
  t=a[1];
  a[1]=a[i];
  a[i]=t;
  creatheap(a,1,i-1);
 }
}
*/
void creatheap(int a[],int root,int len) //���� ���Ը����Լ�����Ҫ��������ѻ���С����
{
 int i=2*root;    //�Ӹ��ڵ㿪ʼ���Źؼ��ֱȽϴ�Ľ�㿪ʼ����ɸѡ��
 int t=a[root];   //�Ƚ�������ֵ��������������֮��ıȽϺ͸�ֵ��
 int flag=0;      //��һ���м�ֵ���ж��Ƿ񸸽������ӽ�㡣
 while (i <= len && flag == 0)
 {
  if (i<len)  //���i<len ˵���������ӽ��
  {
   if (a[i]>a[i+1]) //�ҵ��ӽ���������Ƚϴ�� ��i���Ϊ�Ƚϴ��.
	   i++;
  }
  if (t <= a[i])  //������������ӽ��Ļ� �Ϳ��Բ���ȥ���� ���ҽ���ѭ����
	  flag=1;      
  else
  {               //��������С���ӽ��Ļ���Ҫ�Ƚ�������ֵ���佻�� �ٽ�i��ֵ����Ϊ������
   a[i/2]=a[i];   //�ٴν���ѭ�� ���ж� ���i��С���ܵĳ��ȵĻ� ˵�������滹�����ӽ��� 
   i=i*2;         //��Ҫ�ٴν���Ƚϣ����i�ĳ��ȴ����ܵĳ��ȵĻ���˵������û���ӽ���ˡ�
  }               //�Ϳ����˳�ѭ��
 }
 a[i/2]=t;   //�˳�ѭ����Ҫ����ԭʼҪ������ֵ�ŵ����Ӧ��λ�á�
}
int GetMin(int array[], int Length,int k)   
	{   
	int min=array[1]; // С�����е�һ��Ԫ������С�ģ��ȱ�������   
	int child,temp;   //
	int i=0,j=k-1;    //i = 0,
	Swap(&array[1],&array[Length]); //�ѵ�һ��Ԫ�غ�������Ԫ���ཻ����    
	for (temp=array[1]; j>0 && 2*i+1<=Length; --j,i=child)//   
	{  //�Ƚ��ϴ��Ԫ�ر��棬�ҵ�����λ�ú��ٷ���     //j����Ҫ���ƵĴ��� 
	child = 2*i+1; //1   
	if(child < Length-1 && array[child+1] < array[child])   
    child++;     //�ҵ��������ӵ��н�С���Ǹ�
	if (temp > array[child])   //�����һ��Ԫ�ر��������ӣ���Ļ�
	array[i] = array[child];   //�ͽ���һ��Ԫ�ظ�ֵΪ���Ķ����н�С���Ǹ�
	else   
	break;   //����ӽڵ�ȸ�����ֵ��Ļ���������ѭ�� ��Ϊ���������С���ѵ�����
	array[child] = temp;   
	}   
        
	return min;   
	}  
void Swap(int* a,int* b)   
	{      
	int t;
	t = *a;
	*a = *b;
	*b = t;
	}  
void Kmin(int array[] , int Length , int k)   
	{   
		int i=Length/2;
		int j=Length;
	for(; i>=1; --i)    
	//��ʼ���ѣ�ʱ�临�Ӷ�ΪO(n)   
	creatheap(array,i,Length);   
        
	//int j=Length;   
	for(i=k;i>0;--i,--j)    
	//k��ѭ����ÿ��ѭ���ĸ��Ӷ����Ϊk�ν��������Ӷ�Ϊo(k^2)   
	{   
	int min=GetMin(array,j,i);   
	printf("%d,", min);   
	}   
	}   
#endif