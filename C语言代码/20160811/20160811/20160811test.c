#if 1 
//copyright@ ������   2. //July��2010.06.02��   
//@lingyun310���ȶ�Ԫ������ԭ�ؽ���С�ѣ�O(n)��Ȼ����ȡK�Σ�����ÿ����ȡʱ��   
//����������Ԫ��ֻ��Ҫ���ƶ���k�ξ��㹻�ˣ����ƴ�����μ��١����ַ����ĸ��Ӷ�ΪO(n+k^2����   
#include <stdio.h>   
#include <stdlib.h>   
#define MAXLEN 1000   
#define K 10         
void HeapAdjust(int array[], int i, int Length) //����   
{   
 int child,temp;   

 for(temp = array[i]; 2*i+1 < Length; i = child)   
	{   
		child = 2*i+1;   
		if(child < Length-1 && array[child+1] < array[child])   
		child++;   
		if (temp > array[child])   
		array[i] = array[child];   
		else   
		break;   
		array[child] = temp;   
	}   
}       
	void Swap(int* a,int* b)   
	{   
	//*a=*a^*b;   
	//*b=*a^*b;   
	//*a=*a^*b;   
	int t;
	t = *a;
	*a = *b;
	*b = t;
	}   
    
	int GetMin(int array[], int Length,int k)   
	{   
	int min=array[0]; // С�����е�һ��Ԫ������С�ģ��ȱ�������   
	int child,temp;   //
	int i=0,j=k-1;    //i = 0,
	Swap(&array[0],&array[Length-1]); //�ѵ�һ��Ԫ�غ�������Ԫ���ཻ����    
	for (temp=array[0]; j>0 && 2*i+1<Length; --j,i=child)//   
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
   
	void Kmin(int array[] , int Length , int k)   
	{   
		int i=Length/2;
		int j=Length;
	for(; i>=0; --i)    
	//��ʼ���ѣ�ʱ�临�Ӷ�ΪO(n)   
	HeapAdjust(array,i,Length);   
     for (i=0; i<100;++i)
		 printf("%d ",a[i]);
     printf("\n");
	//int j=Length;   
	for(i=k;i>0;--i,--j)    
	//k��ѭ����ÿ��ѭ���ĸ��Ӷ����Ϊk�ν��������Ӷ�Ϊo(k^2)   
	{   
	int min=GetMin(array,j,i);   
	printf("%d,", min);   
	}   
	}   
    
	int main()   
	{   
	int array[MAXLEN]; 
	int i=MAXLEN;
	for(; i>0; --i)   
	array[MAXLEN-i] = i;   
        
	Kmin(array,MAXLEN,K);   
	return 0;   
	}   
#endif
#if 0
#include<stdio.h>
#define MAXLEN 100   
#define K 10 
void Kmin(int a[],int length,int k);
void creatheap(int a[],int root,int len);
int main()
{
 int a[MAXLEN];
 int i= MAXLEN;
 for(; i>0; --i)
	 a[i-1] = MAXLEN-i;
 a[0]=0;
 Kmin(a,MAXLEN,K); 
 return 0;
}
void Kmin(int a[],int length,int k)
{
 int i=length/2;
		int j=length;
		int t;
	for(; i>=1; --i)       //��ʼ���ѣ�ʱ�临�Ӷ�ΪO(n)   
	creatheap(a,i,MAXLEN); 
	for (i=1; i<MAXLEN; ++i)
		printf("%d ",a[i]);
	printf("\n");
	for(i=k; i>0; --i,--j) //k��ѭ����ÿ��ѭ���ĸ��Ӷ����Ϊk�ν��������Ӷ�Ϊo(k^2)   
	{     
	 t=a[1];
     a[1]=a[j];
     a[j]=t;
	 printf("%d,", t);
	 creatheap(a,i,j);
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
#endif

