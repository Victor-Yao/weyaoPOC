#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//1���ڱ����ú������ͷ��ڴ�
int getContentLen01(const char *filename, char **buf, int *len) {
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (tmp == NULL)
	{
		return -1;
	}
	strcpy(tmp, "aaaaaaaaa");
	*len = 10;
	*buf = tmp;//��Ӹ�ֵ

	return 0;
}

int getContentLen02(const char *filename, char *buf, int *len) {
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (buf == NULL)
	{
		*len = 10;//��һ�ε������ڴ�
	}
	else
	{
		strncpy(tmp, "aaaaaaaaaaaaa", 10);
		*len = 10;
	}
	return 0;
}

int main28() {
	const char *filename = "";
	char *p = NULL;
	int len = 0;

	getContentLen01(filename, &p, &len);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	//��һ�ε����󳤶�
	getContentLen02(filename, NULL, &len);
	p = (char *)malloc(len);
	if (p == NULL)
	{
		return;
	}
	//�ڶ��ε���������
	getContentLen02(filename, p, &len);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
	return;
}