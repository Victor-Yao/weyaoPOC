#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>


//�������ڴ�ģ��
void main20()
{
	int i = 0, j = 0;
	char **p2 = NULL;
	int num = 5;
	p2 = (char **)malloc(sizeof(char *) *num);

	for (i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	printf("����֮ǰ\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	char *tmp = NULL;
	char tmpBuf[100];
	//���� -> ����ָ���ָ��
	/*for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}*/

	//���� -> �����ڴ��ֵ
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				strcpy(tmpBuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpBuf);
			}
		}
	}

	printf("����֮��\n");
	//����֮��
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//�ͷ��ڴ�
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	printf("hello....\n");
	system("pause");
	return;
}

//*****************��д******************
char **getMem03(int num) {
	char **p2 = NULL;
	int i = 0;
	p2 = (char **)malloc(sizeof(char *) *num);
	if (p2 == NULL)
	{
		return p2;
	}

	for (i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	return p2;
}

void printMyArray03(char **myArray, int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
		//printf("%s\n", *(myArray+i));
	}
}
void sortMyArray03(char **myArray, int num) {
	if (myArray == NULL)
	{
		printf("sortMyArray error\n");
		return;
	}

	int i = 0, j = 0;
	char *tmp = NULL;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				tmp = myArray[i];//���������ڴ��
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}
void freeMem(char **p2, int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
}

void main201()
{
	int i = 0, j = 0;
	char **p2 = NULL;
	int num = 5;
	p2 = getMem03(num);

	printf("����֮ǰ\n");
	printMyArray03(p2, num);

	char *tmp = NULL;
	char tmpBuf[100];
	//���� -> ����ָ���ָ��
	sortMyArray03(p2, num);

	printf("����֮��\n");
	printMyArray03(p2, num);

	//�ͷ��ڴ�
	freeMem(p2, num);

	printf("hello....\n");
	system("pause");
	return;
}