#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "des.h"

#define MaxSize 4096

int FileSymFunc(const char *pfile1, const char *pfile2) {
	int ret = 0;
	if (pfile1 == NULL || pfile2 == NULL)
	{
		ret = -1;
		goto End;
	}

	FILE *fp1 = NULL, *fp2 = NULL;
	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;
	}
	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		ret = -1;
		goto End;
	}

	unsigned char plain[4096] = { 0 };
	int plainlen = 0, tmplen = 0;
	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	while (!feof(fp1))//feof(),�ļ�û�н����ͷ���0�������˾ͷ��ط���ֵ
	{
		plainlen = fread(plain, 1, 4096, fp1);
		if (feof(fp1))//��ȡ�����ݺ��ж��ļ��Ƿ����
		{
			break;
		}

		ret = DesEnc_raw(plain, plainlen, cryptbuf, &cryptlen);//������ȡ4096���ֽڵ����ݣ���padding
		if (ret != 0)
		{
			printf("Func DesEnc() err:%d\n", ret);
			goto End;
		}

		tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
		if (tmplen != cryptlen)
		{
			ret = -1;
			printf("д�����4K�ļ�ʧ�ܣ������Ƿ��������\n");
			goto End;
		}
	}

	//����С��4k���ļ�
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0)
	{
		printf("Func DesEnc() err:%d\n", ret);
		goto End;
	}

	tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
	if (tmplen != cryptlen)
	{
		ret = -1;
		printf("д��С��4K�ļ�ʧ�ܣ������Ƿ��������\n");
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}
	return ret;
}

int FileSymDec(const char *pfile1, const char *pfile2) {
	int ret = 0;
	FILE *fp1 = NULL, *fp2 = NULL;
	if (pfile1 == NULL || pfile2 == NULL)
	{
		ret = -1;
		goto End;
	}

	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;
	}
	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		ret = -1;
		goto End;
	}

	unsigned char encData[MaxSize] = { 0 }, decBuf[MaxSize] = { 0 };
	int	encDatalen = 0, decBuflen = 0, tmpLen = 0;

	while (!feof(fp1))
	{
		encDatalen = fread(encData, 1, MaxSize, fp1);
		if (feof(fp1)) {//�����ļ����ж��Ƿ������δ�������ȡ���ݵ��ֽ� = 4096�����һ�ξͶ�ȡ���ֽ���С�ڵ���4096
			break;
		}

		//����4k�ļ�
		ret = DesDec_raw(encData, encDatalen, decBuf, &decBuflen);
		if (ret != 0)
		{
			printf("Func DesEnc() err:%d\n", ret);
			goto End;
		}
		tmpLen = fwrite(decBuf, 1, decBuflen, fp2);
		if (tmpLen != decBuflen)
		{
			printf("д��С��4K�ļ�ʧ�ܣ������Ƿ��������\n");
			ret = -1;
			goto End;
		}
	}

	//����С��4k�ļ�
	ret = DesDec_raw(encData, encDatalen, decBuf, &decBuflen);
	if (ret != 0)
	{
		printf("Func DesEnc() err:%d\n", ret);
		goto End;
	}
	tmpLen = fwrite(decBuf, 1, decBuflen, fp2);
	if (tmpLen != decBuflen)
	{
		printf("д��С��4K�ļ�ʧ�ܣ������Ƿ��������\n");
		ret = -1;
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}

	return ret;
}

int main() {
	int		ret = 0;
	const char *file1 = "c:/VDownload/plain.txt";
	const char *file2 = "c:/VDownload/Encrption.txt";
	const char *file3= "c:/VDownload/Decrption_1.txt";

	//ret = FileSymFunc(file1, file2);
	ret = FileSymDec(file2, file3);
	if (ret != 0)
	{
		printf("Func FileSymFunc err\n");
	}
	system("pause");
	return;
}