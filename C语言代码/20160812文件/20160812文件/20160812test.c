#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys\stat.h>
#if 0
void sort(char *a,int n);
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 int size=0,n;
 char a[20] = "";
 p1 = fopen("1.txt","r"); //��ʾ������Ϊ1.txt���ļ���ʹ�÷�ʽΪ���� rΪread����˼
 p2 = fopen("2.txt","wb");//��ʾΪ��������ݣ���һ���������ļ���
 if (p1 == NULL)
	 printf("error\n");
 fseek(p1,0,2); //fseek ������ָ������ƶ������Ըı��ļ���λ��
 size = ftell(p1);
 rewind(p1); //rewind ��ָ��ָ���ļ���ʼ��λ�� ������fseek(p1,0,0)Ҳ�����ƶ�λ�á�
 n=fread(a,size,1,p1);//fread�����ķ���ֵΪ�ɹ��Ĵ�����
 printf("%d\n",n);   //fread�Ǵ�p1ָ����ļ�����1��size�ֽڵ����ݡ�
 puts(a);
 sort(a,size);
 puts(a);
 fwrite(a,size,1,p2);//fwrite�ǽ���a��ָ��ĵ�ַ����1��size�ֽڵ����ݴ浽p2��ȥ
 fclose(p1);
 fclose(p2);//�ļ�ʹ�ý�����Ҫʹ��fclose�������ر� ��ָ�벻ָ���ļ���λ��
}
void sort(char *a,int n)
{
	int i,j;
	char t;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
#endif
#if 0
/*
EOF ���ļ������ı�־
*/
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 char a;
 int n,size = 0;
 p1 = fopen("1.txt","r");
 p2 = fopen("2.txt","wb"); //fgetc��ÿ����p1��ָ����ļ�����һ���ַ� 
 while ( (a = fgetc(p1)) != EOF ) //fputc�ǽ��ַ�д��p2��ָ����ļ���
 {
  putchar(a);
  fputc(a,p2);
 }
 printf("\n");
 return 0;
}
#endif
#if 0
/*
-stat ԭ�;��� int _stat(const char *path,struct-stat *buffer)
*/
int main()
{
 FILE *p1 = NULL,*p2=NULL;
 //char a[20];
 struct _stat buf;  //ʹ��ʱ����ͷ�ļ�
 int n,size = 0;
 int a,b;
 p1 = fopen("1.txt","r");
 p2 = fopen("2.txt","wb");
 _stat("1.txt",&buf);
 size = buf.st_size;
 //fgets(a,size+1,p1);//�����ǽ�p1��ָ����ļ�����һ������Ϊsize���ַ��������ں������һ��'\0'�ַ�
                    //Ȼ��size+1���ַ���ŵ��ַ�����a����ȥ��
 //fputs(a,p2);  // ��a��ָ����ַ���д��p2��ָ����ļ���ȥ��
 fscanf(p1,"%2d%3d",&a,&b); //�ǽ������ļ��е����ݶ�ȡ�����ֱ��͸�����a��b��
 fprintf(p2,"a=%d,b=%d",a,b); //��int �ͱ���a��b�ֱ������p2��ָ����ļ���ȥ��
 fprintf(p2,"asdfasdfad");
 fclose(p1);
 fclose(p2);
 return 0;          //
}
#endif
#if 0
#include <malloc.h>
#include <string.h>
typedef struct data
{
	char a[3];
	char num[7];  //�Զ����ƶ�ȡ��ʱ��û��Ҫ���������� 
}Data;            //���ı���ȡ��ʱ��ֻ��һ��
void sort(Data *p,int n);
int main()
{
 Data *p = NULL;
 FILE *p1 = fopen("1.txt","r");
 FILE *p2 = fopen("2.txt","w");
 int size = 0,n=0,i;
 struct _stat buf;
 _stat("1.txt",&buf);
 size =buf.st_size; //����������ܳ���
 n = size / sizeof(Data); //���������
 p = (Data *)malloc(n*sizeof(Data));//��p�����ڴ�ռ�
 for(i = 0;i<n;i++)
	{
		fread(&p[i],sizeof(Data),1,p1);
	}
 sort(p,n);
 for(i = 0;i<n;i++)
	{
		fwrite(&p[i],sizeof(Data),1,p2);
	}
 fclose(p1);
 fclose(p2);
 return 0;
}
void sort(Data *p,int n)
{
	int i,j;
	Data t;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n-i-1;j++)
		{
			if(strncmp(p[j].num,p[j+1].num,7) > 0) //��Ϊ��������ݶ�û����'\0'������
			{                                      //���ԱȽϵ�ʱ��Ҫ��strncmp�����бȽϡ�
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
		}
	}
}

#endif
#if 0 //�Ӽ�������һ���ַ����������е�Сд��ĸȫ��ת��Ϊ��д��ĸ��Ȼ�������һ�������ļ���test���б���
                                               //������ַ�����'��'������
int main()
{
 FILE *p = NULL;
 char ch;
 if ((p = fopen("test.txt","wb")) == NULL)
 {
  printf("�޷��򿪴��ļ�\n");
  exit(0);
 }
 printf("������Ҫ�洢���ַ���(�ԣ�����):");
 while ((ch = getchar()) != '!')
 {
	 if (ch >= 'a' && ch <= 'z')
      fputc(ch+'A'-'a',p);
	 else 
      fputc(ch,p);
 }
 fclose(p);
 return 0;
 return 0;
}

#endif
#if 0 //�����������ļ�A��B�����Դ��һ����ĸ����Ҫ����������ļ��е���Ϣ�ϲ�(����ĸ˳������)
                                                  //�����һ���µ��ļ���C��ȥ
int main()
{
 FILE *p1 = NULL,*p2 = NULL,*p3 = NULL;
 char a[100],ch;
 int i=0,n,j;
 p1 = fopen("A.txt","r");
 p2 = fopen("B.txt","r");
 p3 = fopen("C.txt","wb");
 while ((ch = fgetc(p1)) != EOF)
 {
  a[i++] = ch;
 }
 i--;
 while ((ch = fgetc(p2)) != EOF)
 {
  a[i++] = ch;
 }
 a[i] = '\0';
 n = strlen(a);
 for (i=0; i<n-1; ++i)
	 for (j=0; j<n-1-i; ++j)
		 {
		  if (a[j]>a[j+1])
			  {
			   ch = a[j];
			   a[j] = a[j+1];
			   a[j+1] = ch;
			  }
		 }
 fputs(a,p3);
 fclose(p1);
 fclose(p2);
 fclose(p3);
 return 0;
}
#endif
#if 1 //��5��ѧ����ÿ��ѧ����3�ſγ̵ĳɼ����Ӽ�������ѧ������(����ѧ�ţ����������ſγ̳ɼ�)
                                  //�����ƽ���ɼ�����ԭ�����ݺͼ������ƽ����������ڴ����ļ�stud��
typedef struct student
{
	char number[10];
	char name[10];
	int score[3];
	int average;
}Stu;
/*
1 wang 98 97 96
2 yang 88 87 86
3 liu  78 77 76
4 sun  68 67 66
5 li   58 57 56
*/
int main()
{
 Stu a[5],b[5];
 FILE *p = NULL;
 FILE *p1 = NULL;
 int i,n,sum=0;
 p = fopen("stud.txt","wb");
 for (i=0; i<5; ++i)
	 scanf("%s%s%d%d%d",a[i].number,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
 for (i=0; i<5; ++i)
 {
  sum = 0;
  sum = a[i].score[0]+a[i].score[1]+a[i].score[2];
  a[i].average = sum/3;
 }
 for (i=0; i<5; ++i)
	{
     fprintf(p,"%s %s %d,%d,%d,%d\r\n",a[i].number,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2],a[i].average);
	}
 fclose(p); //
 p1 = fopen("stud.txt","rb");
 //rewind(p);
 for (i=0; i<5; ++i)
 {
  n=fscanf(p1,"%s%s%d,%d,%d,%d",b[i].number,b[i].name,&b[i].score[0],&b[i].score[1],&b[i].score[2],&b[i].average);
  printf("%s,%s,%d,%d,%d,%d\n",b[i].number,b[i].name,b[i].score[0],b[i].score[1],b[i].score[2],b[i].average);
 }
 fclose(p);
 fclose(p1);
 return 0;
}
#endif
