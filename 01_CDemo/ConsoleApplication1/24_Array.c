#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

void main241() {
	//����Ķ��巽ʽ
	int a[] = { 1,2 };
	int b[100] = { 1,3 };
	int c[200] = { 0 };//����ʱ�����Ѿ�ȷ�����е�ֵΪ��

	memset(c, 0, sizeof(c));//��ʾ�������ڴ��

	//��һά���� C�涨:
	//c ��������Ԫ�صĵ�ַ c+1 ���� 4���ֽ�
	//&c ����������ĵ�ַ  &c+1 ���� 200*4

	typedef int(MyArrayType)[5];//������һ���������ͣ�������������
	MyArrayType myArray;//int myArray[5];

	for (int i = 0; i < 5; i++)
	{
		myArray[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", myArray[i]);
	}

	printf("myArray����������Ԫ�صĵ�ַ myArray:%d, myArray+1:%d \n", myArray, myArray + 1);
	printf("&myArray������������ĵ�ַ &myArray:%d, &myArray+1:%d \n", &myArray, &myArray + 1);//&myArray+1�Ĳ�����4*5=20
}

void main242() {
	char *MyArray1[] = { "111","aaa","bbb" };//ָ�����飬ָ�����������
	//��������ָ������ķ���1
	//���������� *
	{
		//����ָ�룬ָ�������ָ��
		typedef int(MyArrayType)[5];//�������������ͣ�������������

		MyArrayType myArray;//���Զ�����������Ͷ������
		MyArrayType *pArray;//����һ��ָ�������ָ��һ������
		{
			//��ָͨ�������ֵ
			int a;
			int *p = NULL;
			p = &a;

			//����ָ��
			int myArray2[5];//�൱��һ��ָ��
			pArray = &myArray2;//�൱�ڶ���ָ��
			for (int i = 0; i < 5; i++)
			{
				//(*pArray)[i] = i;
				myArray2[i] = i;
			}
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", (*pArray)[i]);
			}
		}


		printf("hello....\n");
		system("pause");
		return;
	}
}

//��ά�������������˻�����
void printArray01(int a[3][5]) {
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray02(int a[][5]) {
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray03(int(*a)[5]) {
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
//��֤��ά�������Դ洢, ��ά���鰴һά�����ӡ
void printArray04(int *myArray, int size) {
	if (myArray == NULL)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", myArray[i]);
	}
}

void printKeyWord(char **myArray) {
	if (myArray == NULL)
	{
		return;
	}
	for (int i = 0; myArray[i] != NULL; i++)
	{
		printf("%s\n", myArray[i]);
	}
}

void main243() {
	int a[3][5], i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	printf("printArray01\n");
	printArray01(a);
	printf("printArray02\n");
	printArray02(a);
	printf("printArray03\n");
	printArray03(a);
	printf("printArray04: ��ά����Ҳ�ǰ����Դ����\n");
	printArray04(a, 15);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");

	//a��ά������������?
	printf("a:%d, a+1:%d\n", a, a + 1);//a+1�Ĳ�����20���ֽڣ�5*4
	printf("&a:%d, &a+1:%d\n", &a, &a + 1);
	{
		//����һ��ָ�������ָ�����
		int(*pArray)[5];//���߱�����������4���ֽڵ��ڴ�
		pArray = a;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				printf("%d ", pArray[i][j]);
			}
		}
		printf("\n");
	}
	//��ά�������ı��ʣ�������ָ�룻������һά����ĳ���
	//(a+i) ����������i�еĵ�ַ���Ƕ���ָ��
	//*(a+i) ����1��ָ�룬��i����Ԫ�صĵ�ַ
	//*(a+i) + j ===> &a[i][j]
	//*(*(a+i) + j) ===> a[i][j]Ԫ�ص�ֵ

	//==============================================
	//ָ����������ҽ�������, '\0', 0, NULL�����ַ����Ľ�����־
	printf("��������ҽ���\n");
	char *c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};
	char *c_keyword2[] = {
		"while",
		"case",
		"static",
		"do",
		0
	};
	char *c_keyword3[] = {
		"while",
		"case",
		"static",
		"do",
		NULL
	};
	printf("*c_keyword[]\n");
	printKeyWord(c_keyword);
	printf("*c_keyword2[]\n");
	printKeyWord(c_keyword2);
	printf("*c_keyword3[]\n");
	printKeyWord(c_keyword3);


	printf("hello....\n");
	system("pause");
	return;
}