#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//encapsulation, print
//����ı��ʣ��ڴ�ģ��2��myArray+1 �� �ڴ�ģ��1��myArray+1 ��һ����
//ָ��Ĳ�����һ������Ϊָ����ָ����ڴ�ռ���������Ͳ�һ����
//void printMyArray1_err(char **myArray, int num) {
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%s\n", myArray[i]);
//		//printf("%s\n", *(myArray+i));
//	}
//}

void printMyArray02(char myArray[10][30], int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
		//printf("%s\n", *(myArray+i));
	}
}

void sortMyArray02(char myArray[10][30], int num) {
	int i = 0, j = 0;
	char tmpBuf[30];

	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				strcpy(tmpBuf, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}
}

//�ڶ����ڴ�ģ��
void main()
{
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];

	char myArray[10][30] = { "aaa","bbbb","ccccc","ddddddd" };
	//myArray, ������ֻ��������������ڴ�ķ��䣬�����鹲�м��м��У�������10��30�У�
	//myArray+1����ά������ +1 �������ָ����һ�е��ڴ棬������30�У�������ָ����һ�С�����Ƕ�ά����ı���
	{
		int len1 = sizeof(myArray);
		int len2 = sizeof(myArray[0]);
		int size = len1 / len2;
		printf("len1:%d, len2:%d size:%d\n", len1, len2, size);
	}

	printf("sort before\n");
	//print
	printMyArray02(myArray, num);

	sortMyArray02(myArray, num);

	printf("sort after\n");
	printMyArray02(myArray, num);

	printf("hello....\n");
	system("pause");
	return;
}