#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void printMyArray(char **myArray, int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
		//printf("%s\n", *(myArray+i));
	}
}

void sortMyArray(char **myArray, int num) {
	int i = 0, j = 0;
	char *tmp = NULL;
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				tmp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void main()
{
	int i = 0, j = 0;
	int num = 0;

	//ָ�����飬�����е�ÿһ��Ԫ����ָ��
	char *myArray[] = { "aaa","bbb","ccc","wwww" };
	//��ӡ
	num = sizeof(myArray) / sizeof(myArray[0]);

	printf("����֮ǰ\n");
	printMyArray(myArray, num);

	sortMyArray(myArray, num);
	//����

	printf("����֮��\n");
	printMyArray(myArray, num);

	printf("hello....\n");
	system("pause");
	return;
}