#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void getLen(int *p) {
	*p = 30;//*˭�ĵ�ַ���ͼ���޸�˭��ֵ
}

void main291() {
	int a = 10;
	int *p = NULL;

	a = 11;

	p = &a;
	*p = 20;
	{
		*p = 30;
	}

	system("pause");
	return;
}

//02
int getMem(char **p2/*out*/) {
	*p2 = 30;//����޸�p2��p�ĵ�ַ
	*p2 = (char **)malloc(1000);

	return 0;
}
void main292() {
	char *p = NULL;
	char **p2 = NULL;

	p = 1;
	p = 2;

	p2 = &p;
	*p2 = 10;//ֱ���޸�һ��ָ���ֵ
	{
		*p2 = 30;
	}

	system("pause");
	return;
}

//03
int getMem2(char ***p3/*out*/) {
	*p3 = 100;//ֱ���޸Ķ���ָ���ֵ

	return 0;
}
void main293() {
	char **p = NULL;
	char ***p3 = NULL;

	p = 1;
	p = 2;

	p3 = &p;
	*p3 = 10;//ֱ���޸Ķ���ָ���ֵ
	{
		*p3 = 30;
	}

	system("pause");
	return;
}

//04
int getMem4(char ********p8/*out*/) {
	*p8 = 30;//*ָ�����p7�ĵ�ַ�����Լ���޸���p7��ֵ��

	return 0;
}
void main293() {
	char *******p7 = NULL;
	char ********p8 = NULL;

	p7 = 1;
	p7 = 2;

	p8 = &p7;
	*p8 = 10;
	{
		*p8 = 30;//*ָ�����p7�ĵ�ַ�����Լ���޸���p7��ֵ��
	}

	system("pause");
	return;
}