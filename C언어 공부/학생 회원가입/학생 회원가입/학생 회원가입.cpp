#include "pch.h"
#include <stdio.h> //입출력 헤더
#include <string.h> //구조체(struct)선언 위한 헤더
#define MAX_STUDENT 100 //최대 학생수는 100명



struct student { //학생 구조체 선언
	char no[100]; // 학번
	char id[100]; // ID
	char passwd[20]; // Password
	char major[50]; // 전공
	char president[10]; // 학생대표여부   
	char name[10]; // 이름
	char gender[10]; // 성별
	char birth[20]; // 생년월일 1999-01-01
	char phone[20]; // 폰번호 010-1234-5678
	char address[100]; // 주소
	char time[100]; // 가입일
};

void Register(struct student *infor); //회원가입 함수
void Login(struct student *infor); //계정찾기 함수
void ChangePasswd(struct student *infor); //패스워드찾기 함수

int main(void)
{
	printf("■ 계정관련 페이지입니다! ■\n");
	printf("  ▼ 메뉴를 골라주세요! ▼\n\n");
	while (1)
	{
		struct student infor[MAX_STUDENT]; // 학생의 최대수는 100명
		int menu_num; //메뉴를 고를때 사용할 변수
		printf("   1. 신규가입\n");
		printf("   2. 로그인\n");
		printf("   3. 비밀번호변경\n");
		printf("   4. 종료\n");
		scanf_s("%d", &menu_num); //메뉴 선택 1~4

		if (menu_num == 1)
		{
			Register(infor);
			menu_num = 0;
		}

		if (menu_num == 2)
		{
			Login(infor);
			menu_num = 0;
		}

		if (menu_num == 3)
		{
			ChangePasswd(infor);
			menu_num = 0;
		}

		if (menu_num == 4)
		{
			break;
		}

	}
	return 0;
}

void Register(struct student *infor)
{
	int i, j;
	for (i = 0; i < 100; i++)
	{
		printf("회원가입을 계속 할까요?? (1 : YES , 2 : NO) : ");
		scanf_s("%d", &j);
		if (j == 1)
		{
			printf("학번을 입력하세요 : ");
			scanf_s(" %s", &infor[i].no);
			printf("\n");

			printf("아이디를 입력하세요 : ");
			scanf_s(" %s", infor[i].id);
			printf("\n");

			printf("비밀번호를 입력하세요 : ");
			scanf_s(" %s", infor[i].passwd);
			printf("\n");

			printf("전공을 입력하세요 : ");
			scanf_s(" %s", infor[i].major);
			printf("\n");

			printf("학생대표여부를 입력하세요 (Y/N) : ");
			scanf_s(" %s", infor[i].president);
			printf("\n");

			printf("이름을 입력하세요 : ");
			scanf_s(" %s", infor[i].name);
			printf("\n");

			printf("성별을 입력하세요 (남/여) : ");
			scanf_s(" %s", infor[i].gender);
			printf("\n");

			printf("생년월일 입력하세요 (990101) : ");
			scanf_s(" %s", infor[i].birth);
			printf("\n");

			printf("휴대폰번호를 입력하세요 (010-1234-1234) : ");
			scanf_s(" %s", infor[i].phone);
			printf("\n");

			printf("주소를 입력하세요 : ");
			scanf_s(" %s", infor[i].address);
			printf("\n");

			printf("가입날짜를 입력하세요 (190530) : ");
			scanf_s(" %s", infor[i].time);
			printf("\n");
		}
		if (j == 2) {
			break;
		}
	}
} // 회원가입 함수
void Login(struct student *infor) // 로그인 함수
{
	
}
void ChangePasswd(struct student *infor) //비밀번호 변경
{

}