# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//��
char *getMem(int num) {
	char *p1 = NULL;//��ʱ����������ջ�ϣ��ɱ������Զ������ͷţ�
	p1 = (char*)malloc(sizeof(char) *num);//malloc���ڴ�����ڶ��ϣ�����һ���ɳ���Ա�����ͷţ���������ʱ�ɲ���ϵͳ�ͷ�
	if (p1 == NULL) {
		return NULL;
	}
	//�ں�������ʱ��ָ�����p1ռ�õ��ڴ�ᱻ�������ͷţ�����p1��ָ����ڴ�ռ�������malloc�����ģ������ڶ��ϣ���������ʱ�����ᱻ���ա�
	return p1;
}

//ջ
//���ָ��Ĺؼ����ڴ棬û���ڴ��û��ָ��
char *getMem2() {
	char buf[64];
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;//return�Ĳ��������ڴ�飨64���ֽڣ������ǰ��ڴ����׵�ַ��0xaa11��
}

void main03()
{
	char *tmp = NULL;
	tmp = getMem(10);//����malloc�����ڴ�ռ���׵�ַ��
	if (tmp == NULL)
	{
		return;
	}
	//strcpy(tmp, "111222333444111222333444111222333444111222333444");//�ڴ�Ӧ�û���������֡�ntdll.pdb not loaded��
	strcpy(tmp, "11444");

	tmp = getMem2();
	printf("hello... tmp:%s.\n", tmp);

	//�ڴ��ַ��ʵ��һ�����֣����Դ���ָ���У�Ҳ���Դ���int�����С�
	//����ָ�벻�����Ա����ڴ��ַ��ͬʱ���Զ���ָ����ڴ洢��ı������������͡�
	int * pint = NULL;
	pint = (int *)malloc(sizeof(int));
	int a = (int *)malloc(sizeof(long));
	printf("pint:%d\n", pint);
	printf("a:%d\n", a);

	//��ӡһ�²�ͬ���ͱ����ĳ���
	printf("###################\n");
	printf("int length:%d\n", sizeof(int));
	printf("char length:%d\n", sizeof(char));
	printf("long length:%d\n", sizeof(long));
	printf("short length:%d\n", sizeof(short));
	printf("double length:%d\n", sizeof(double));
	printf("char[8] length:%d\n", sizeof(char[8]));
	printf("int[8] length:%d\n", sizeof(int[8]));

	system("pause");
	return;
}