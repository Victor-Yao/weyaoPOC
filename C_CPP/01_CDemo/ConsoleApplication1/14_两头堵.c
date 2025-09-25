#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//��ǿո���ַ�������
int getStrCount(char *str, int *pCount) {
	char *p = str;
	int nCount = 0;
	int i, j = 0;

	if (str == NULL || pCount == NULL)
	{
		return -1;
	}
	i = 0;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j] && p[j] != '\0'))
	{
		j--;
	}

	nCount = j - i + 1;
	*pCount = nCount;

	return 0;
}

int trimSpace(char *str, char *out, int *pCount) {
	char *p = str;
	char *newStr = out;
	int nCount = 0;
	int i, j = 0;

	if (str == NULL || out == NULL || pCount == NULL)
	{
		return -1;
	}
	i = 0;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j] && p[j] != '\0'))
	{
		j--;
	}

	nCount = j - i + 1;
	strncpy(newStr, p + i, nCount);
	newStr[nCount] = '\0';

	*pCount = nCount;

	return 0;
}

//src��ָ����ڴ�ռ䣬���Ա��޸Ĳ���
//�����������������ָ����Ҫ�ر�ע�⣬ָ��ָ����ڴ�ռ��Ƿ���Ա��޸ġ�����ǳ����Ͳ��ܱ��޸�
int trimSpace2(char *str, int *pCount) {
	if (str == NULL || pCount == NULL)
	{
		return -1;
	}

	char *p = str;
	int nCount = 0;
	int i = 0, j = 0;

	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j] && p[j] != '\0'))
	{
		j--;
	}

	nCount = j - i + 1;
	strncpy(str, str + i, nCount);
	str[nCount] = '\0';

	*pCount = nCount;

	return 0;
}

void main141() {
	char *str = "   qwer    ";
	int count = 0;
	char result[20];
	//getStrCount(str, &count);
	//trimSpace(str, result, &count);
	trimSpace2(str, &count);
	printf("str:%s\n", result);
	printf("str len:%d\n", count);

	system("pause");
}