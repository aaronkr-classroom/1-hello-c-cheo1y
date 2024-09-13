// chp1/cypher.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void cypher(char* msg, int sft)
{
	char ch;
	int i;

	for (i = 0; msg[i] != '\0'; ++i)
	{
		ch = msg[i];

		// 암호(소문자)
		if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + sft;

			if (ch > 'Z')
				ch = ch - 'Z' + 'A' - 1;
			else if (ch < 'A')
				ch = ch + 'Z' - 'A' + 1;

			msg[i] = ch;
		}
		
		// 암호(소문자)
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch + sft;

			if (ch > 'z')
				ch = ch - 'z' + 'a' - 1;
			else if (ch < 'z')
				ch = ch + 'z' - 'a' + 1;

			msg[i] = ch;
		}
	}
}

int main()
{
	// 사용자에게 메시지를 받아요.
	char message[100]; 
	printf("Enter a message: ");
	fgets(message, sizeof(message), stdin);

	// 암호 값 주기(문자를 몇 개씩 이동하기?) 
	int shift;
	printf("Enter shift value: ");
	scanf_s("%d", &shift);

	// 암호로 변경하기 
	cypher(message, shift);

	// 암호된 메시지를 출력하기 
	printf("Encrypted! %s", message);

	return 0;
}