#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//һ��ָ��ĵ����÷�
//������ַ���

//C���Է����ַ���
//1.��0��β���ַ���,0��int���͵�
//2.û���ַ������ͣ�ͨ���ַ�������ģ��
//3.�ַ������ڴ���䣬�� ջ ȫ����
void main91() {
	//1��ָ������
	char buf2[100] = { 'a','b','c','d' };//δָ����[4]-[99]��������棨��ͬ�ı������Ƿ�᲻һ������
	//char buf3[2]= { 'a','b','c','d' };//���벻ͨ��

	//2����ָ������
	char buf1[] = { 'a','b','c','d' };//�༭�������Ԫ�ظ���


	printf("buf2:%s \n", buf2);
	printf("buf2[88]:%s \n", buf2[88]);

	system("pause");
	return;
}

//���ַ�������ʼ���ַ�����
//strlen() �ַ����ĳ��ȣ�������0
//sizeof() �ڴ��Ĵ�С
void main92() {
	char buf3[] = "abcd";//buf3 ��Ϊ�ַ����� 5���ֽڣ���Ϊ�ַ�����4���ֽ�

	//�ַ���
	int len = strlen(buf3);
	printf("buf3�ַ����ĳ���:%d \n", len);//4���ַ����ĳ��ȣ�������0

	//���飬������һ���������ͣ��������͵ı����ǹ̶���С�ڴ��ı���
	int size = sizeof(buf3);
	printf("buf3������ռ�ڴ�ռ��С:%d \n", size);//5���ڴ��Ĵ�С

	{
		char buf4[128] = "wert";
		printf("buf[100]:%d \n", buf4[100]);
	}

	printf("hello....\n");
	system("pause");
	return;
}

//ͨ�������±��ָ��������飬����[]��*p�ı���
void main93() {
	char *p = NULL;
	char buf5[128] = "abcdefg";//buf

	printf("strlen(buf5):%d\n", strlen(buf5));//7,����������strlenֻȡ����һ��0λ��
	printf("sizeof(buf5):%d\n", sizeof(buf5));//128

	//�ַ�����β��0�������λ��0����int���͵ģ�������һ��0�ַ����ͽ���
	{
		char buf6[100] = "qwe0120qwe";
		printf("strlen(buf6):%d\n", strlen(buf6));
	}

	//[]��*p��������һ���ģ�[]��Ϊ�˷����˵��Ķ�ϰ�ߣ�
	//buf5[i]===>buf5[0+i]===>*(buf5+i)�������������������Ƶ�ת��

	for (int i = 0; i < strlen(buf5); i++)
	{
		printf("%c", buf5[i]);
	}
	printf("\n");

	p = buf5;//buf5������������Ԫ�صĵ�ַ
	for (int i = 0; i < sizeof(buf5); i++)
	{
		if (i < strlen(buf5))
			printf("%c", *(p + i));
		else
			printf("%d", *(p + i));//�������
	}
	printf("\n");

	//ֱ����buf5����
	for (int i = 0; i < strlen(buf5); i++)
	{
		printf("%c", *(buf5 + i));
	}
	printf("\n");

	printf("hello....\n");
	system("pause");
	return;
}

//Ϊʲô����ֱ�Ӳ�����������������Լ��ͨ��ָ�����
//��ָͨ��������ڴ��׵�ַ������
//buf5��һ��ָ�룬ֻ���ĳ��� buf5��һ������ָ�룬�����ڴ��ʱ��֤buf5��ָ����ڴ�ռ䰲ȫ�ͷš�
//���buf5�ܹ�������ĸ�ֵ��ָ���������ڴ�ռ䡣OS���ܹ�����֮ǰ��ָ����ڴ�ռ䡣
//{
//	//buf5 = buf5 + 1;
//	//buf5 = 0x11;
//}