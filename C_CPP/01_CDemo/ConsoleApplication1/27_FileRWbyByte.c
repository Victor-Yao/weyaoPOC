#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
//**************************
//1�����ַ���д�ļ�
void myfputc() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//ͳһ����45�ȣ�����unix��windowsϵͳ
	char a[27] = "abcdqwer";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");

	for (i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);
}
void myfgetc() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//ͳһ����45�ȣ�����unix��windowsϵͳ
	char a[27] = "abcdqwer";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");

	while (!feof(fp))
	{
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}
	printf("\n");
	if (fp != NULL)
	{
		fclose(fp);
	}
}

//****************************
//2�����ж�д�ļ�
void myfputs() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//ͳһ����45�ȣ�����unix��windowsϵͳ
	char a[27] = "asasdasdasd";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");

	fputs(a, fp);

	if (fp != NULL)
	{
		fclose(fp);
	}
}
void myfgets() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//ͳһ����45�ȣ�����unix��windowsϵͳ
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");
	char buf[1024];
	//1��C������� һ��һ�� ��copy���ݵ�bufָ����ָ���ڴ�ռ��У����ұ��C�����ַ���
	//2����\nҲcopy�����ǵĵ�ַ��

	//3���ڴ����������ڴ��׵�ַ + �ڴ泤�ȣ�
	while (!feof(fp))
	{
		char *p = fgets(buf, 2014, fp);
		if (p == NULL)
		{
			goto End;
		}
		printf("%s", buf);
	}
	printf("\n");

End:
	if (fp != NULL)
	{
		fclose(fp);
	}
}

//****************************
//3�������д�ļ�
typedef struct Teacher {
	char name[20];
	int age;
} Teacher;

void myfwrite() {
	int i = 0;
	Teacher myTeacher[3];
	for (i = 0; i < 3; i++)
	{
		sprintf(myTeacher[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		myTeacher[i].age = i + 1;
	}

	FILE *fp = NULL;
	char *fileName = "c:/test/3.data";
	fp = fopen(fileName, "wb");
	if (fp == NULL)
	{
		printf("create file failed\n");
		return;
	}
	int myCount = 0;
	for (i = 0; i < 3; i++)
	{
		//�ڴ����������ڴ�鿪ʼ��ַ + д���ڴ泤��
		/*_In_reads_bytes_(_ElementSize * _ElementCount) void const* _Buffer,//�ڴ�鿪ʼ�ĵ�ַ
			_In_     size_t      _ElementSize,//Ԫ�صĴ�С
			_In_     size_t      _ElementCount,//д��Ԫ�صĸ�������д���ٴ�
			_Inout_  FILE*       _Stream*///д�뵽�ļ�ָ����ָ����ļ���
		myCount = fwrite(&myTeacher[i], sizeof(myTeacher), 1, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
	}
}

void myfread() {
	int i = 0;
	Teacher myTeacher[3];

	FILE *fp = NULL;
	char *fileName = "c:/test/3.data";
	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		printf("open file failed\n");
		return;
	}
	int myCount = 0;
	for (i = 0; i < 3; i++)
	{
		//myCount = fwrite(&myTeacher[i], sizeof(Teacher), 1, fp);
		myCount = fread(&myTeacher[i], sizeof(Teacher), 1, fp);
	}

	for (i = 0; i < 3; i++)
	{
		printf("name:%s, age:%d\n", myTeacher[i].name, myTeacher[i].age);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}



int main() {
	//1�����ַ���д�ļ�
	//myfputc();
	//myfgetc();

	//2�����ж�д�ļ�
	//myfputs();
	//myfgets();

	//3�������д�ļ�
	//myfwrite();
	myfread();

	printf("hello.....\n");
	system("pause");
	return;
}