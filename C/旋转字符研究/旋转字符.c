#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0//�ַ���������ʽ������!!!---------------------------------------------------------------------------1��
Reverse(char* arr,int b,int e);
RightShift(char*arr,int N,int K);
int main()
{
	char ch[20];
    int N;
	int K;	
	printf("�����һ���ַ�����");
	gets(ch);
	 N=strlen(ch);
	 printf("�������Ҫ��ת�ĸ�����");
	 scanf("%d",&K);
	RightShift(ch,N,K);
	return 0;
}
RightShift(char*arr,int N,int K)
{
	K%=N;
	Reverse(arr,0,N-K-1);//ǰ�벿������
	Reverse(arr,N-K,N-1);//��벿������
	Reverse(arr,0,N-1);//��������
	puts(arr);
	

}
Reverse(char*arr,int b,int e)//�ַ�������
{
	for(;b<e;b++,e--)
	{
		int temp=arr[e];
		arr[e]=arr[b];
		arr[b]=temp;
	}
}
#endif
#if 0//�ַ���ָ����ʽ������!!!˼·����ͬ-------------------------------------------------------------------2��
char *invert(char *start,char *end);
char *left(char*s,int pos);
int main()
{
	char s[20];
	int len,k;
	printf("���һ���ַ�����");
	gets(s);
	len = strlen(s);
	printf("�����Ҫ��ת�ĸ�����");
	scanf("%d",&k);
    puts(left(s,k));
	return 0;
}
char *invert(char *start,char *end)
{
	char tmp,*ptmp=start;
	while(start!=NULL&&end!=NULL&&start<end)
	{
		tmp=*start;
		*start=*end;
		*end=tmp;
		start++;
		end--;
	}
	return ptmp;
}
char *left(char*s,int pos)//posΪҪ��ת���ַ������򳤶�
{
	int len=strlen(s);
	invert(s,s+(pos-1));//abc--cba
	invert(s+pos,s+(len-1));//def--fed
	invert(s,s+(len-1));//cbafed--defabc
	return s;
}
#endif








#if 0
#define positiveMod(m,n) ((m)%(n)+(n))%(n)
void rotate(char *ch,int m);
void  swap(char *a,char *b);
void rotate(char *ch,int m)//m�������n,��m�����Ǹ�������ת�����෴��

{
	int n=strlen(ch);
	int p1=0,p2;
	int k;
	
	 int r; 

	if(n==0)
		return ;
	m=positiveMod(m,n);
	if(m==0)
		return;
	p2=m;/*k����p2�ƶ��ľ���
	*/
	while(p2+m-1<n)//�±�
	{
		k=m;
	  while(k--)
		{
			swap(&ch[p1],&ch[p2]);
			p1++;
			p2++;
		}
	}
	//ʣ��Ĳ���m����ĸ�𲽽���
     r=n-p2;
		 	/*
r��β�ͣ���abcdefghijk  p1ָ��a,p2ָ��j,defghiabcjk,��ʱjk����β��
*/
	while(r--)
	{
		int i=p2;
		while(i>p1)
		{
			swap(&ch[i],&ch[i-1]);
			i--;
		}
		p2++;
		p1++;
	}
}
int main()
{
	char ch[20];
	gets(ch);
	rotate(ch,3);
	puts(ch);
	return 0;
}
void  swap(char *a,char*b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
#endif
#if 0
void rotate(char *str,int n,int m,int head,int tail,int q);
void swap(char *a,char *b);
int main()//�ݹ鷽�������ַ���
{
	char str[20];
	int len,i=3;

	gets(str);
	len=strlen(str);
	rotate(str,len,i%len,0,len-1,1);
	puts(str);
	return 0;
}


void rotate(char *str,int n,int m,int head,int tail,int q)
{
	int i=0;
	int p1,p2,k;
	if(head==tail||m<=0)
		return ;
	if(q==1)//�ж������������� ���� 1 ���� 0
	{
	       p1=head;
	       p2=head+m;
		   k=(n-m)-n%m;//n-m�ǿ�ʼp2��ĩβ�ĸ�����n%m��β�͵ĸ�����
		for(i=0;i<k;i++,p1++,p2++)
			swap(&str[p1],&str[p2]);
		rotate(str,n-k,n%m,p1,tail,0);
	}
	else
	{
		     p1=tail;//abcjk  p1-k p2-c
		     p2=tail-m;
		     k=(n-m)-n%m;
      for(i=0;i<k;i++,p1--,p2--)
		  swap(&str[p1],&str[p2]);
	  rotate(str,n-k,n%m,head,p1,1);
	}
}
void  swap(char *a,char*b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
#endif
















#if 0//m�������n,��m�����Ǹ�������ת�����෴��!!!!!!!!---------------------------------------------------------------3��
#define positiveMod(m,n) ((m)%(n)+(n))%(n)
void rotate(char *ch,int m);
void  swap(char *a,char *b);
void rotate(char *ch,int m)
{
	int n=strlen(ch);
	int p1=0,p2;
	int k,r;
	if(n==0)
		return ;
	m=positiveMod(m,n);
	if(m==0)
		return;
	//if(m % n <= 0)
	//	return ;
	p2=m;
	while(p2+m-1<n)
	{
		k=m;
	

		while(k--)
		{
			swap(&ch[p1],&ch[p2]);
			p1++;
			p2++;
		}
	}

	r=n-p2;
	while(r--)
	{
		int i=p2;
		while(i>p1)
		{
			swap(&ch[i],&ch[i-1]);
			i--;
		}
		p2++;
		p1++;
	}
}
int main()
{
	char ch[20];
	int k;
	printf("�����һ���ַ�����");
	gets(ch);
	printf("�������Ҫ��ת�ĸ�����");
	scanf("%d",&k);
	rotate(ch,k);
	puts(ch);
	return 0;
}
void  swap(char *a,char*b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
#endif
#if 0//�ݹ鷽�������ַ���-----------------------------------------------------------------------------------------4��
void rotate(char *str,int n,int m,int head,int tail,int q);
void swap(char *a,char *b);
int main()
{
	char str[20];
	int len,i=3;

	gets(str);
	len=strlen(str);
	rotate(str,len,i%len,0,len-1,1);
	puts(str);
	return 0;
}


void rotate(char *str,int n,int m,int head,int tail,int q)
{
	int i=0;
	int p1,p2,k;
	if(head==tail||m<=0)
		return ;
	if(q==1)//�ж������������� ���� 1 ���� 0
	{
	       p1=head;
	       p2=head+m;
		   k=(n-m)-n%m;
		for(i=0;i<k;i++,p1++,p2++)
			swap(&str[p1],&str[p2]);
		rotate(str,n-k,n%m,p1,tail,0);
	}
	else
	{
		     p1=tail;
		     p2=tail-m;
		     k=(n-m)-n%m;
      for(i=0;i<k;i++,p1--,p2--)
		  swap(&str[p1],&str[p2]);
	  rotate(str,n-k,n%m,head,p1,1);
	}
}
void  swap(char *a,char*b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
#endif
#if 0//STL�㷨----------------------------------------------------------------����----------------------------5��
int gcd(int m,int n);
void sort(char *str,int n,int k);
int gcd(int m,int n)
{
	int r;
	do 
	{
		r = m % n;
		if(r == 0)
		{
			return n;
			break;
		}
		else
		{
			m = n;
			n = r;
	
		}
	}while( r != 0);
}

int main()
{
	char a[20];
	int len,k;
	printf("������һ���ַ�����");
	gets(a);
	len=strlen(a);
	printf("�������Ҫ��ת�ĸ�����");
	scanf("%d",&k);
	gcd(len,k);
	sort(a,len,k);
}


void sort(char *str,int n,int k)//d��Ҫ����Щ���ֳɼ�����������Ŀ�ꣻ//(n/d)��ÿ��Ҫѭ�����β�����ɣ�
{
	int d=gcd(n,k);//t=(t+k)%n�Ǽ�����Ҫ�ŵ�λ�ã�
	int i,j,t; 
	char b0,b1;
	for(i=0;i<d;i++)
	{
        b0=str[i];
        t=i;
		for(j=0;j<(n/d);j++)
		{
            t=(t+k)%n;
            b1=str[t];
			str[t]=b0;
			b0=b1;
		}
       
	}
	puts(str);

}


/*void my_rotate(char str[],int len,int k)
{
	int d = 0,i = 0,j = 0,last = 0;
	char temp;
	d = gcd (len , k);
	for(i = 0;i < d;i++)
	{
		temp = str[i];
		for(j = (i+k) % len; j != i;j = (j+k) % len)
		{
			str[last] = str[j];
			last = j;
		}
		str[last] = temp;
	}
}
void main ()
{
/*	int a,b,g = 0;//ע��gҪ�ȸ���ֵ��ʼ���� 
	a = 544;
	b = 119;
	g = gcd(a,b);
	printf("%d",g);
	

    char ch[20] ;
    int len,k;
    printf("������һ���ַ�����"); 
    gets(ch);
	len = strlen(ch);
	printf("��������Ҫ��ת�ĸ�����");
	scanf("%d",&k);
    my_rotate(ch,len,k);
    puts(ch);
}*/
#endif