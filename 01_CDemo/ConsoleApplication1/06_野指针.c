#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main06()
{
	//
	//Ұָ����ָָ�������ָ����ڴ�ռ䲻���ڣ������ã����߱��ͷš�
	//������ԭ��ָ�����������ָ����ڴ�ռ������������ͬ�ĸ���
	//�ͷ���ָ����ָ����ڴ�ռ䣬����ָ���������û�б�reset
	//Workaround, 1 & 2

	char *p1 = NULL;//1.����ָ���ͬʱ��ʼ��ΪNULL
	p1 = (char)malloc(100);
	if (p1 = NULL)
	{
		return;
	}
	strcpy(p1, "11112222");

	printf("p1:%s \n", p1);

	if (p1 = !NULL)
	{
		free(p1);//free����p1ָ����ڴ�ռ䣬p1����û��Ӱ��
		p1 = NULL; //2.�ͷ�ָ����ָ����ڴ�ռ�󣬰�ָ��resetΪNULL
	}

	if (p1 != NULL)
	{
		free(p1);
	}

	printf("hello....\n");
	system("pause");
	return;
}