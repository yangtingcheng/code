#include <stdio.h>
#include <malloc.h>
#include "List.h"
int main(void)
{
	Node *head =create();
	ShowList(head);
	ListSort(&head);
//	InsertByVaule(&head,6); // �����������һ��ֵ
//	ShowList(head);     //�����������µ�����
//	InsertByIndex(&head,4,6); //����λ�ò���һ��ֵ
//	ShowList(head);   //�����������µ�
//	printf("�ڵ�%d��λ��\n",FindByValue(head,5));  //����ֵ�ҳ�λ��
	printf("���ĸ���ֵΪ%d\n",FindByIndex(head,4)); //����λ���ҵ�ֵ
	return 0;
}
