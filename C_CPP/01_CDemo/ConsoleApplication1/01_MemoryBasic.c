# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main01()
{
	int a;
	int b;
	a = 10;//ֱ�Ӹ�ֵ
	printf("&a: %d\n", &a);//3406084
	//*************ͨ���ڴ��ַ��Ӹ�ֵ******************
	//��Ӹ�ֵ ==> ֱ��ͨ���ڴ��ַ
	//*((int*)3406084) = 200;
	*((int*)&a) = 200;
	printf("a: %d\n", a);

	{
		char * p;
		p = &a;//���ݱ������ڴ��ַ
		*p = 300;
		printf("p: %d\n", a);
	}

	//*************ָ��Ĳ���******************
	int c[10];
	//c,&c��ͬ��c����������Ԫ�ص�ָ��
	//c+1��&c+1��ͬ��&c������������ĵ�ַ
	printf("c:%d,c+1:%d,&c:%d,&c+1:%d\n", c, c + 1, &c, &c + 1);


	printf("hello...\n");
	system("pause");
	return;
}