#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//
int inverse01(char *str1) {
	if (str1 == NULL)
	{
		printf("parameter is error\n");
		return -1;
	}

	int length = strlen(str1);

	char *p1 = str1;
	char *p2 = str1 + length - 1;

	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;

		p1++;
		p2--;
	}
}

//�ݹ�ѧϰ��˳��
//1.�ݹ�ķ�ʽ�������ӡ
//2.ȫ�ֱ���������
//3.�ֲ�������������ָ������������

//1.�ݹ�ķ�ʽ�������ӡ
void inverse02(char *p) {
	if (p == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0')//�ݹ����������
	{
		return;
	}

	inverse02(p + 1);//��ʱû��ִ�д�ӡ������ִ���˺������á����ַ�����ÿ����ַ��ջ
	printf("%c", *p);
}

char g_buf[1000];

//2.�ݹ��ȫ�ֱ�����������Ľ�����������
void inverse03(char *p) {
	if (p == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0')//�ݹ����������
	{
		return;
	}

	inverse03(p + 1);//��ʱû��ִ�д�ӡ������ִ���˺������á����ַ�����ÿ����ַ��ջ
	strncat(g_buf, p, 1);
}

//3.�ݹ�;ֲ�������ָ������������
void inverse04(char *p, char *bufResult) {
	if (p == NULL || bufResult == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0')//�ݹ����������
	{
		return;
	}

	inverse04(p + 1, bufResult);//��ʱû��ִ�д�ӡ������ִ���˺������á����ַ�����ÿ����ַ��ջ
	strncat(bufResult, p, 1);
}

void main151() {
	char buf[] = "abcdefg";

	//inverse01(buf);
	//printf("buf:%s\n", buf);

	//�ݹ������ӡ
	//inverse02(buf);

	//�ݹ� -> ȫ�ֱ���
	//memset(g_buf, 0, sizeof(g_buf));
	//inverse03(buf);
	//printf("g_buf:%s\n", g_buf);

	//�ݹ� -> �ֲ�����
	char myBuf[1024] = { 0 };
	inverse04(buf, myBuf);
	printf("myBuf:%s\n", myBuf);

	system("pause");
}