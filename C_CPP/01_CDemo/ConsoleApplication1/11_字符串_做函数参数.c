#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main111() {
	char a[] = "i am a student";
	char b[64];
	int i = 0;

	//ʵ���ַ�����copy
	for (i = 0; i < *(a + i) != '\0'; i++)//�ַ�����'\0'��β
	{
		//ȡ��(a + i)ָ����ڴ�ռ��ֵ�ٸ�ֵ��(b + i)ָ����ڴ�ռ�
		*(b + i) = *(a + i);
	}
	//0û��copy��b��buf��
	b[i] = '\0';//��Ҫ

	printf("a:%s \n", a);
	printf("b:%s \n", b);

	system("pause");
	return;
}

//�ַ���copy������������
//�β�from, to��ֵ�ڲ�ͣ�ı仯, ���ϵ��޸�from��to��ָ��
void cpy_str0(char *from, char *to) {
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';//����c�����ַ���
}

//�Ż�1
//* �� ++���������ȼ� ++���ȼ���
void cpy_str1(char *from, char *to) {
	for (; *from != '\0';)
	{
		*to++ = *from++; //�� *to=*from; ��from++, to++
	}
	*to = '\0';
}

//�Ż�2
void cpy_str2(char *from, char *to) {
	while ((*to = *from) != '\0') //���ʽ(*to = *from)��ֵ����*from��ֵ
	{
		from++;
		to++;
	}
}

//�Ż�3
void cpy_str3(char *from, char *to) {
	//1��ִ�� *to=*from�����ʽ(*to++ = *from++)==*from
	//2��ִ�� from++, to++
	//3���ж�(*to++ = *from++) ��= '\0'
	while ((*to++ = *from++) != '\0')
	{
		;
	}
}

//�Ż�4
//��������������÷��������ú��������ڴ棬�������ú���ʹ��
void cpy_str4(char *from, char *to) {
	while ((*to++ = *from++))
	{
		;
	}
}

//�Ż�5
//��������������÷��������ú��������ڴ棬�������ú���ʹ��
int cpy_str5(char *from, char *to) {
	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while ((*to++ = *from++));
}

void main112() {
	char *from = "abcd";
	char buf[100];
	cpy_str0(from, buf);
	printf("buf0:%s \n", buf);

	cpy_str1("efgh", buf);
	printf("buf1:%s \n", buf);

	cpy_str2("qwer", buf);
	printf("buf2:%s \n", buf);

	cpy_str3("rtyu", buf);
	printf("buf4:%s \n", buf);

	cpy_str4("dfgh", buf);
	printf("buf4:%s \n", buf);

	{
		//test the scenario of what copt a string const to a char array but the size of char array is less then string const.
		//the result is the size of array doesn't changed, but the string length of the variable is changed.
		char testBuf[1];
		printf("sizeof(testBuf):%d\n", sizeof(testBuf));
		printf("strlen(testBuf):%d\n", strlen(testBuf));
		cpy_str4("dfgh", testBuf);
		printf("testBuf:%s \n", testBuf);
		printf("sizeof(testBuf):%d\n", sizeof(testBuf));
		printf("strlen(testBuf):%d\n", strlen(testBuf));
	}

	{
		//������
		char *myto = NULL;//ֻ�Ƕ�����ָ����������ǲ�û�з����ڴ棻*(0x00000000),NULL���ڴ����ϵͳ�����ģ����ܹ������ġ�
		//cpy_str4(from, myto);//ֱ�ӵ���myto����������쳣��
		int ret = 0;
		ret = cpy_str5(from, myto);
		if (ret != 0)
		{
			printf("func_cpy_str5 err:%d", ret);
			return ret;
		}
	}

	system("pause");
	return;
}

//�Ż�6
//��Ҫ���׸ı��βε�ֵ�����븨��ָ����������βνӹ�ȥ����
int cpy_str6_good(char *from, char *to) {
	char *tmpFrom = from;
	char *tmpTo = to;
	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*tmpTo++ = *tmpFrom++);
	printf("from:%s \n", from);
}
int cpy_str6_err(char *from, char *to) {

	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*to++ = *from++);
	printf("from:%s \n", from);
}

void main113() {
	//Ϊʲô�ַ��������������룿
	char txtBuf[] = { 'a','c','r','f' };
	char *txtP = txtBuf;
	printf("txtPValue:%s\n", txtP);
	printf("txtPAddress:%x\n", &txtP);
	strcpy(txtP, txtBuf);
	printf("txtStrValue:%s\n", txtP);

	char *from = "abcd";

	char buf1[100];
	printf("cpy_str6_err start\n");
	cpy_str6_err(from, buf1);
	printf("cpy_str6_err finish\n");
	printf("buf1:%s \n", buf1);

	char buf2[100];
	printf("cpy_str6_err start\n");
	cpy_str6_good(from, buf2);
	printf("cpy_str6_err finish\n");
	printf("buf2:%s \n", buf2);

	printf("pause");
	return;
}