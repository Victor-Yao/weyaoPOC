#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//*****************************1��ָ������**********************************

//��ʵ�ε��ڴ��ַ���ݸ��βΣ�����ջ�����·����ָ�������ָ����Ը����ڴ��ַָ���ڴ�ռ���м�ӵ��޸ġ�
int getFileLen(int *p) {
	*p = 50;
}

//��ͨ�β�ר�ݵ��Ǳ�����ֵ����ջ�����·������֮�����ʵ��û����ϵ�ˡ�
//�βε����ԣ�����ͨ���βδ���ʵ�εķ�ʽ����ʼ������
int getFileLen3(int b) {
	b = 100;
	return b;
}

//1��ָ�룬��������޸ı�����ֵ
void main71() {
	int a = 10;
	int *p = NULL;

	a = 20;//ֱ���޸�a��ֵ
	p = &a;
	*p = 30;//����޸� -> p��ֵ��a�ĵ�ַ��*pָ����ڴ�ռ����a���ڴ�ռ�
	printf("a:%d\n", a);

	getFileLen(*p);//ͨ��ָ��ʵ�Σ���ӵ��޸�ָ����ָ����ڴ�ռ�ı���ֵ
	printf("a:%d\n", a);
	getFileLen3(a);//����Ƿ�ָ��
	printf("a:%d\n", a);

	printf("hello....\n");
	system("pause");
	return;
}

//*****************************2��ָ������**********************************

//�ڱ���ǰ�����ж��ٸ�*, ������ͨ��ָ��������м���*���Ǽ���ָ���������ʵ����ָ������ָ�򱣴���һ������ֵ���ڴ��ַ
void getMem3(char **p2) {
	*p2 = 400;//p2��ֵ��pa�ĵ�ַ
}

//����β���1��ָ�룬p2��ֵ�ǹ�Ȼ��p1�ĵ�ַ��
void getMem4(char *p2) {
	//printf("&p2:%d\n", p2);
	//printf("*p2:%d\n", *p2);
	//*p2 = 800;//��������ȱ��*���޷�ָ��p1���ڴ�ռ䣬����p2�������κθ��Ķ���p1�޹�
	//printf("&p2:%d\n", p2);
	//printf("*p2:%d\n", *p2);

	*p2 = 800;//��������ȱ��*���޷�ָ��p1���ڴ�ռ䣬����p2�������κθ��Ķ���p1�޹�
}

//2��ָ�룬��������޸�1��ָ�������ֵ
void main72() {
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 0x11;
	p2 = 0x22;

	p1 = 0x111;//ֱ���޸�p1��ֵ
	printf("p1:%d\n", p1);

	p2 = &p1;//p2��p1�ĵ�ַ
	*p2 = 100;//����޸�p1��ֵ
	printf("p1:%d\n", p1);

	{
		*p2 = 200;//����޸�p1��ֵ
		printf("p1:%d\n", p1);
	}

	getMem3(&p1);
	printf("p1:%d\n", p1);

	getMem4(&p1);
	printf("p1:%d\n", p1);
}

//*****************************��Ӹ�ֵ������**********************************
//�������ͱ����ú���ͨ���ڴ潻��������
int getMem5(char **myP1, int *myLen1, char **myP2, int *myLen2) {
	int ret = 0;
	char *tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "113223");

	//��Ӹ�ֵ
	*myLen1 = strlen(tmp1);//1��ָ��
	*myP1 = tmp1;//2��ָ��

	tmp2 = (char *)malloc(200);
	strcpy(tmp2, "aaadddccc");
	*myLen2 = strlen(tmp2);
	*myP2 = tmp2;

	return ret;
}

void main73() {
	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;
	ret = getMem5(&p1, &len1, &p2, &len2);
	if (ret != 0) {
		printf("func getMem5() err:%d\n", ret);
		return ret;
	}

	printf("p1:%d\n", p1);
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}

	printf("p2:%d\n", p2);
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	system("pause");
}

//*****************************��Ӹ�ֵ������**********************************
//�������ͱ����ú���ͨ���ڴ潻��������
void main74() {
	//����1��������������������֮�䣬�βκ�ʵ�Σ�
	//����2����������ȡ������ַ����ֵ��ָ�루��ʵ�ε�ַ�����βΣ�
	//����3��*p���βμ���޸�ʵ�ε�ֵ

	//#################Ӧ�ó���#####################
	//����1��1,2,3д��һ��������
	//����2���������ã�1��2���������У�3�ڱ����ú�����
	//����3����װ��1��һ�飬23��һ�飻C++�л���

	//����1 as below
	char from[128];
	char to[128] = { 0 };
	char *p1 = from;
	char *p2 = to;

	strcpy(from, "aabbccdd");
	while (*p1 != '\0') {
		*p2 = *p1;
		p2++;
		p1++;
	}

	printf("to: %s\n", to);
	system("pause");
	return;
}