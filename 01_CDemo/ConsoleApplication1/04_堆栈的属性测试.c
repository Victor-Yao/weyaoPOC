#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void TestStackOrientation()
{
	//�ٶ���a>b���������£�a<b����������
	//ջ�Ŀ��ڷ�����release��debug�¿��ڷ���ͬ�����ݲ���ϵͳ�Ĳ�ͬ��ջ���ڵķ���Ҳ��һ����
	//ͨ��ջ�Ŀ������£�Ϊ��ջ���������Ϊ�ڽ���ջ��ʱ�򣬵�һ��Ԫ�صĵ�ַΪ���ֵ�� ����ѹ���Ԫ������ջ�ĵ�ַ���μ�С����ֹ��ջ�������
	int a;
	int b;

	//����ջ�Ŀ��ڷ��������ϻ������£�buf���ڴ��ַbuf+1�������ϵ�
	char buf[128];
	printf("&a: %d, &b: %d\n", &a, &b);
}

void main04()
{
	TestStackOrientation();
	printf("hello... \n");
	system("pause");
	return;
}