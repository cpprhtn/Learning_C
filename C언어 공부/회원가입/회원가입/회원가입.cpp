#include "pch.h"
#pragma warning(disable:4996)

#include <stdio.h>

#include <conio.h>

#include <Windows.h>


#define MaxLen 21

#define MaxMember 10


#define LOGIN_FILE "login.txt"


#define TRUE 1

#define FALSE 0


#define MAN 'M'

#define WOMAN 'W'

#define NONE 'N'


typedef char String[MaxLen];


typedef struct _member

{

	String name;

	String id;

	String password;

	char gender;

	String favorite;

} Member;


typedef struct _logininfo

{

	int numOfMember;

	Member mem[MaxMember];

} LoginInfo;


int Login(void);

void Register(void);

void Delete(void);


void Input(void);

Member * StartLogin(void);


LoginInfo lgnInf;


int main(void)

{

	Member * mem;

	int i;

	char ch;

	Input();


	while (TRUE)

	{

		mem = StartLogin();


		// 메인 다이얼로그

		printf("===================================================\n");

		printf("? ? ? ? ? ? ? ? ?♡LOVE OBSERVER♡? ? ? ? ? ? ? ? ?\n");

		printf("===================================================\n");

		printf("\n");


		printf("검색중");


		// 아이디가 존재하는지 여부 확인

		for (i = 0; i < lgnInf.numOfMember; i++)

		{

			if ((i + 1) % (lgnInf.numOfMember / 6 + 1) == 0)

			{

				printf(".");

			}

			if (!strncmp(lgnInf.mem[i].name, mem->favorite, 1)) // 일치하는 아이디가 있으면

			{

				break;

			}

		}

		printf("\n");


		if (i == lgnInf.numOfMember || strcmp(lgnInf.mem[i].favorite, mem->name) || lgnInf.mem[i].gender == mem->gender)

		{

			printf("꽝!\n\n");

		}

		else

		{

			printf("%s ♡ %s\n최고의 커플입니다!\n\n", mem->name, lgnInf.mem[i].name);

		}


		printf("종료하시겠습니까? (Y/N)");

		ch = getch();

		switch (ch)

		{

		case 'Y':

		case 'y':

			return 0;

			break;


		default:

			system("cls");

			continue;

			break;

		}

	}


	return 0;

}


int Login(void)

{

	String id;

	String password;

	int i;


	// 메인 다이얼로그

	printf("===================================================\n");

	printf("? ? ? ? ? ? ? ? ? ? ? 로그인? ? ? ? ? ? ? ? ? ? ? ?\n");

	printf("===================================================\n");

	printf("\n");


	while (TRUE)

	{

		// 아이디 입력

		printf("ID : ");

		scanf("%s", id);

		printf("\n");


		// 패스워드 입력

		printf("Password : ");

		scanf("%s", password);

		printf("\n");


		// 입력한 아이디가 존재하는지 여부 확인

		for (i = 0; i < lgnInf.numOfMember; i++)

		{

			if (!strcmp(lgnInf.mem[i].id, id)) // 일치하는 아이디가 있으면

			{

				break;

			}

		}


		// 아이디가 틀렸을 때

		if (i == lgnInf.numOfMember)

		{

			printf("[WARNING] 입력하신 아이디가 존재하지 않습니다.\n");

			continue;

		}


		// 아이디에 해당하는 패스워드와 사용자가 입력한 패스워드가 다르면

		if (strcmp(lgnInf.mem[i].password, password))

		{

			printf("[WARNING] 비밀번호가 틀렸습니다.\n");

			continue;

		}


		// 아이디와 패스워드가 모두 맞았을 때

		printf("환영합니다, %s님!\n", lgnInf.mem[i].name);

		break;

	}


	return i;

}


void Register(void)

{

	FILE * fp;

	String name;

	String id;

	String password;

	String repw;

	String favorite;

	char gender, ch;

	int i;


	// 메인 다이얼로그

	printf("===================================================\n");

	printf("? ? ? ? ? ? ? ? ? ? ?회원가입? ? ? ? ? ? ? ? ? ? ? \n");

	printf("===================================================\n");

	printf("\n");


	// 이름 입력

	printf("Name : ");

	scanf("%s", name);

	printf("\n");


	while (TRUE)

	{

		// 아이디 입력

		printf("ID : ");

		scanf("%s", id);

		printf("\n");


		// 입력한 아이디가 이미 존재할 때

		for (i = 0; i < lgnInf.numOfMember; i++)

		{

			if (!strcmp(lgnInf.mem[i].id, id)) // 일치하는 아이디가 있으면

			{

				break;

			}

		}


		if (i != lgnInf.numOfMember)

		{

			printf("[WARNING] 입력하신 아이디가 이미 존재합니다.\n");

			continue;

		}


		break;

	}


	while (TRUE)

	{

		// 패스워드 입력

		printf("Password : ");

		scanf("%s", password);

		printf("\n");


		// 패스워드 다시 입력

		printf("비밀번호를 한번 더 입력해주세요.\n");

		printf("Password : ");

		scanf("%s", repw);

		printf("\n");


		// 입력한 패스워드와 다시 입력한 패스워드가 다를 때

		if (strcmp(password, repw))

		{

			printf("[WARNING] 입력한 패스워드와 다시 입력한 패스워드가 일치하지 않습니다.\n");

			continue;

		}


		break;

	}


	printf("남성이시면 M을, 여성이시면 W를 입력하세요.");

	do

	{

		ch = getch();


		switch (ch)

		{

			// 남성이면

		case 'M':

		case 'm':

			printf("\n\n");

			gender = MAN;

			break;


			// 여성이면

		case 'W':

		case 'w':

			printf("\n\n");

			gender = WOMAN;

			break;


		default:

			gender = NONE;

			break;

		}

	} while (gender == NONE);


	// 좋아하는 것 입력

	printf("좋아하는 것 : ");

	scanf("%s", favorite);

	printf("\n");


	fp = fopen(LOGIN_FILE, "a");

	fprintf(fp, "%s|%s|%s|%c|%s|$\n", name, id, password, gender, favorite);

	fclose(fp);


	strcpy(lgnInf.mem[lgnInf.numOfMember].name, name);

	strcpy(lgnInf.mem[lgnInf.numOfMember].id, id);

	strcpy(lgnInf.mem[lgnInf.numOfMember].password, password);

	lgnInf.numOfMember++;

	printf("%s님, 가입이 완료되었습니다. 축하합니다!\n", name);

}


void Delete(void)

{

	FILE * fp;

	String id;

	String password;

	int i, j;


	// 메인 다이얼로그

	printf("===================================================\n");

	printf("? ? ? ? ? ? ? ? ? ? ?회원탈퇴? ? ? ? ? ? ? ? ? ? ? \n");

	printf("===================================================\n");

	printf("\n");


	while (TRUE)

	{

		// 아이디 입력

		printf("ID : ");

		scanf("%s", id);

		printf("\n");


		// 패스워드 입력

		printf("Password : ");

		scanf("%s", password);

		printf("\n");


		// 입력한 아이디가 존재하는지 여부 확인

		for (i = 0; i < lgnInf.numOfMember; i++)

		{

			if (!strcmp(lgnInf.mem[i].id, id)) // 일치하는 아이디가 있으면

			{

				break;

			}

		}


		// 아이디가 틀렸을 때

		if (i == lgnInf.numOfMember)

		{

			printf("[WARNING] 입력하신 아이디가 존재하지 않습니다.\n");

			continue;

		}


		// 아이디에 해당하는 패스워드와 사용자가 입력한 패스워드가 다르면

		if (strcmp(lgnInf.mem[i].password, password))

		{

			printf("[WARNING] 비밀번호가 틀렸습니다.\n");

			continue;

		}


		// 아이디와 패스워드가 모두 맞았을 때

		fp = fopen(LOGIN_FILE, "w");

		for (j = 0; j < lgnInf.numOfMember; j++)

		{

			if (j != i)

			{

				fprintf(fp, "%s|%s|%s|%c|%s|$\n", lgnInf.mem[j].name, lgnInf.mem[j].id, lgnInf.mem[j].password, lgnInf.mem[j].gender, lgnInf.mem[j].favorite);

			}

		}

		lgnInf.numOfMember = 0;

		fclose(fp);

		Input();


		break;

	}

}


void Input(void)

{

	FILE * fp;

	char temp;

	int i, j;


	fp = fopen(LOGIN_FILE, "r");

	if (fp == NULL)

	{

		fopen(LOGIN_FILE, "w");

		fp = fopen(LOGIN_FILE, "r");

	}


	memset(lgnInf.mem[0].name, 0, sizeof(lgnInf.mem[0].name));

	memset(lgnInf.mem[0].id, 0, sizeof(lgnInf.mem[0].id));

	memset(lgnInf.mem[0].password, 0, sizeof(lgnInf.mem[0].password));

	lgnInf.mem[0].gender = NONE;

	memset(lgnInf.mem[0].favorite, 0, sizeof(lgnInf.mem[0].favorite));


	i = 0;

	j = 0;

	while ((temp = fgetc(fp)) != EOF)

	{

		switch (temp)

		{

		case '|':

			j++;

			break;


		case '$':

			j = 0;

			i++;

			memset(lgnInf.mem[i].name, 0, sizeof(lgnInf.mem[i].name));

			memset(lgnInf.mem[i].id, 0, sizeof(lgnInf.mem[i].id));

			memset(lgnInf.mem[i].password, 0, sizeof(lgnInf.mem[i].password));

			lgnInf.mem[i].gender = NONE;

			memset(lgnInf.mem[i].favorite, 0, sizeof(lgnInf.mem[i].favorite));

			lgnInf.numOfMember++;

			break;


		case '\n':

			break;


		default:

			switch (j)

			{

			case 0:

				sprintf(lgnInf.mem[i].name, "%s%c", lgnInf.mem[i].name, temp);

				break;


			case 1:

				sprintf(lgnInf.mem[i].id, "%s%c", lgnInf.mem[i].id, temp);

				break;


			case 2:

				sprintf(lgnInf.mem[i].password, "%s%c", lgnInf.mem[i].password, temp);

				break;


			case 3:

				lgnInf.mem[i].gender = temp;

				break;


			case 4:

				sprintf(lgnInf.mem[i].favorite, "%s%c", lgnInf.mem[i].favorite, temp);

				break;

			}

			break;

		}

	}


	fclose(fp);

}


Member * StartLogin(void)

{

	int idx;

	char in;


	while (TRUE)

	{

		if (lgnInf.numOfMember == 0)

		{

			Register();

		}

		else if (lgnInf.numOfMember == MaxMember)

		{

			Login();

			break;

		}

		else

		{

			printf("로그인하시려면 L, 회원가입하시려면 R, 탈퇴하시려면 D를 입력하세요.");

			in = getch();

			printf("\n");

			system("cls");


			switch (in)

			{

			case 'L':

			case 'l':

				idx = Login();

				fflush(stdin);

				system("pause");

				system("cls");

				return &lgnInf.mem[idx];

				break;


			case 'R':

			case 'r':

				Register();

				fflush(stdin);

				system("pause");

				system("cls");

				continue;

				break;


			case 'D':

			case 'd':

				Delete();

				fflush(stdin);

				system("pause");

				system("cls");

				continue;

				break;


			default:

				fflush(stdin);

				system("cls");

				continue;

				break;

			}

		}

	}

}
