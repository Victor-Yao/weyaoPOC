#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char *getStr() {
	char *tmp = NULL;
	tmp = "abcedfg";//�������������������ڴ�ռ䲻�ᱻ�ͷ�
	return tmp;
}

void main05()
{
	int a = 10;
	char *p1 = 100;
	char ****p2 = 1000;
	long *p3 = NULL;
	char *p4 = (char *)malloc(1);
	//�������ڶ��ϻ�����ջ�ϣ�������malloc���Ǳ�������ջ���Զ����䣬�����������͡�ָ������Ķ�������4���ֽڵ��ڴ档
	//�ǲ��ǿ�����Ϊ������ʲô���͵�ָ�������ָ�뱾����int���͵ġ�
	//�������ָ���ڴ���׵�ַ��ֵ��Ϊָ�������������������Ǳ�����ִ����ڴ��д���ֵ����������
	printf("a:%d, p1:%d, p2:%d, p3:%d, p4:%d\n", sizeof(a), sizeof(p1), sizeof(p2), sizeof(p3), sizeof(p4));
	printf("char:%d\n", sizeof(char));

	//*�����Կ�ף�����ͨ��һ����ַ(&A)ȥ�޸ı���a��ʾ���ڴ�ռ䡣
	//����a����������ʾ���ڴ�ռ䣬����Ҳռ�ڴ浫�Ǵ����ڴ�������a�൱������ʾ�ڴ�ռ��ַ�ı������ڴ�ռ䴢����ֵ
	//*p=��д�ڴ�
	//=*p�����ڴ�
	{
		int *p3 = NULL;
		p3 = &a;
		*p3 = 20;//*p3 == a, ����޸�a��ֵ

		int c = 0;
		c = *p3;//c=20
		printf("c:%d\n", c);
	}

	{
		//���ϸ�ָ�븳ֵ�����൱�ڲ�ͣ�ĸı�ָ���ָ��
		char *p5 = NULL;
		p5 = (char*)malloc(100);
		p5 = (char*)malloc(200);
	}

	{
		char *p = getStr();
		printf("p:%s\n", p);
		//�޸��ڴ���Ҫȷ��ָ����ڴ��ܹ����޸�
		*(p + 2) = 'r';//�����޸ĳ��������ڴ棬����
		printf("p:%s\n", p);
	}
	printf("hello... \n");
	system("pause");
	return;
}