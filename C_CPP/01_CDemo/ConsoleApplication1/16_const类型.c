#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//ָ�����ͱ�����ָ��
void getMem1601(const char *p) {
	p = 1;
	p = 3;
	//*p = "asd";
	//p[1] = 'a';
	return;
}

//��ָ��
void getMem1602(char *const p) {
	//p = 1;
	//p = 3;
	*p = 3;
	p[1] = 'a';
	return;
}

//ָ�����εĳ�ָ��
void getMem1603(const char * const p) {
	/*p = 1;
	p = 3;
	*p = 3;
	p[1] = 'a';*/
	return;
}

void main16()
{
	//������ͬ������һ��������
	const int a = 1;
	int const b = 1;

	//ָ�����ε�ָ�룬ָ��������Ա��޸ģ�����ָ����ڴ�ռ䲻�ܱ��޸�
	const char *c = "c";

	//��ָ�룬ָ����������Ա��޸ģ�����ָ����ڴ�ռ���Ա��޸�
	char * const d = "d";

	//ָ�����͵ĳ�ָ�룬ָ�������ָ����ڴ�ռ䶼���ܱ��޸�
	const char * const e = "e";

	//����c�����У�����ͨ��ָ���ӵ��޸�const���εı�����const���εı����Ǹ�α����
	const int p = 10;
	//p = 11;
	{
		int *p = &a;
		*p = 100;
		printf("a:%d \n", a);
	}

	printf("hello....\n");
	system("pause");
	return;
}