# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char* getChar1() {
	char *p1 = "abcdefg1";
	return p1;
}

char* getChar2() {
	char *p2 = "abcdefg1";
	return p2;
}

void main02()
{
	char* p1 = NULL;
	char* p2 = NULL;
	printf("&p1:%d;&p2:%d\n", &p1, &p2);
	p1 = getChar1();
	p2 = getChar2();
	//�����ᴢ�����ڴ������ĳ������У��������ָ�����ָ��ĳ�����ͬ����ô������ָ�������ֵ��ָ����ڴ��ַ����ͬ
	printf("p1:%s;p2:%s\n", p1,p2);//���ָ��ָ��ı�������
	printf("p1:%d;p2:%d\n", p1,p2);//���ָ���ַ
	printf("&p1:%d;&p2:%d\n", &p1, &p2);
	//��C�������ַ�����char[]���ڴ��ֽ��� = �ֽ���+1(�н�����)��
	//�����char���ͣ�ֱ�ӷ���4���ֽڵ��ڴ��intһ��
	printf("sizeof(str1):%d;sizeof(str2):%d\n", sizeof("abcdefg1"), sizeof('a'));

	int* p3 = NULL;
	printf("p3:%d\n", p3);

	p3 = 10;
	printf("p3:%d\n", p3);
	printf("p3:%d\n", &p3);

	int p4 = 20;
	printf("p4:%d\n", &p4);

	printf("hello...\n");
	system("pause");
	return;
}