#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "des.h"

int main01() {
	int		ret = 0;
	char	*plain = "123123123";
	int		plainlen = strlen(plain);
	char	plain2[4096] = { 0 };
	int		plainlen2 = 0;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0)
	{
		printf("func DescEnc() err:%d \n");
		return ret;
	}
	ret = DesDec(cryptbuf, cryptlen, plain2, &plainlen2);

	if (plainlen != plainlen2)
	{
		ret = -2;
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� -> ��һ��\n");
	}

	if (memcmp(plain, plain2, plainlen2) == 0)
	{
		printf("���ܽ��ܺ������û�б仯\n");
	}
	else
	{
		printf("���ܺ��������ԭ���Ĳ�һ��\n");
	}

	system("pause");
	return;
}