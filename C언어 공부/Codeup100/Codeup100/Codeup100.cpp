
#include "pch.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
/*//삼항연산-(조건?참:거짓)
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d \n", (a < b ? a : b) < c ? ((a < b) ? a : b) : c);

}
*/
/*int n;
int f(int n) //x 대신에 원하는 매개 변수명을 사용할 수 있다.
{
	if (n == 1) printf("hello\n");
	else if (n == 2) printf("world\n");
	else printf("\n");
	return 0; //생략 가능
}

int main()
{
	scanf("%d", &n);
	f(n);
	return 0;
}*/


/*int main() {
	char str[80];
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	puts(str);
	return 0;
}*/
/*int main() {
	char str[] = "This is a sample string";
	char *pch;
	printf("Looking for the 's' character in \"%s\"...\n", str);

	pch = strchr(str, 's');

	while (pch != NULL) {
		printf("found at %d\n", pch - str + 1);
		pch = strchr(pch + 1, 's');
	}

	return 0;
}*/
/*int main()
{
	int *p;
	int a;

	p = &a;

	printf("포인터 p 에 들어 있는 값 : %p \n", p);
	printf("int 변수 a 가 저장된 주소 : %p \n", &a);

	return 0;
}*/
/*int main()
{
	int Score;
	scanf_s(" %d", &Score);
	if (Score >= 90)
		printf("A 등급\n");
	else if (Score >= 80)
		printf("B 등급\n");
	else if (Score >= 70)
		printf("C 등급\n");
	else
		printf("D 등급\n");
	return 0;
}*/

/*int main() {
	char szKey[] = "apple";
	char szInput[80];
	do {
		printf("Guess my favourite fruit? ");
		scanf("%s", szInput);
	} while (strcmp(szKey, szInput) != 0);

	puts("Correct answer!");
	return 0;
	char arr[] = "school";
	char arr2[] = "hello";
	char arr3[] = "teacher";
	char arr4[] = "school";
	int a = strcmp(arr, arr2);
	int b = strcmp(arr, arr3);
	int c = strcmp(arr, arr4);
	printf("%d, %d, %d\n", a, b, c);
}*/
/*int main()
{
	int arr[20][20] = { 0 };
	int num, count = 0;
	int x[20] = { 0 };
	int y[20] = { 0 };
	scanf_s(" %d", &num);
	for (int i = 0; i < num; i++, count++) {
		scanf_s(" %d", &x[i]);
		scanf_s(" %d", &y[i]);
	}
	for (int i = 0; i < count; i++) {
		arr[x[i]-1][y[i]-1]++;
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}*/
//수열 축소

/*int main()
{
	int arr[100] = { 0 };
	int d = arr[2] - arr[1];
	int num;
	scanf_s(" %s", arr);
	scanf_s(" %d", &num);
	for (int i = 0; i < num; i++) {

	}
}*/

/*int num1()
{
	printf("1\n");
	return 0;
}
int num2(int x)
{
	printf("%d\n", 2 * x);
	return 0;
}
int num3(int x)
{
	printf("%d\n", (x*x) + 1);
	return 0;
}
int main()
{
	num1();
	num2(5);
	num3(7);
}*/

/*int main(void)
{
	int plus;
	int ice;
	while (1)
	{
		printf("■ 안녕하세요~ Cpp고수의 카페입니당 ■\n");
		printf("  ▼ 메뉴를 골라주세요! (종료 : 0)▼\n\n");
		int a = 4000, b = 4500, c = 5000, d = 5500;
		int menu_num; //메뉴를 고를때 사용할 변수
		printf("   1. 말차 버블티 : %d\n",b);
		printf("   2. 망고요거트 버블티 : %d\n",c);
		printf("   3. 초코 버블티 : %d\n",a);;
		scanf_s("%d", &menu_num); //메뉴 선택
		printf("펄을 추가할 시 500원이 추가됩니다.\n");
		printf("펄을 추가하시겠습니까? ( Yes=1 / No=0)\n");
		scanf_s("%d", &plus);
		printf("얼음을 빼면 500원이 차감됩니다.\n");
		printf("얼음을 빼시겠습니까? ( Yes=1 / No=0)\n");
		scanf_s("%d", &ice);
		if (menu_num == 1)
		{
			if (plus == 1)
				b += 500;
			if (ice == 1)
				b -= 500;
			printf("총 가격은 %d원 입니다. 갑사합니다.", b);
			menu_num = 0;
		}

		if (menu_num == 2)
		{
			if (plus == 1)
				c += 500;
			if (ice == 1)
				c -= 500;
			printf("총 가격은 %d원 입니다. 갑사합니다.", c);
			menu_num = 0;
		}

		if (menu_num == 3)
		{
			if (plus == 1)
				a += 500;
			if (ice == 1)
				a -= 500;
			printf("총 가격은 %d원 입니다. 갑사합니다.", a);
			menu_num = 0;
		}

		if (menu_num == 0)
		{
			break;
		}

	}
	return 0;
}*/

//문제 4.
int main()
{
	int a, b, c, d, e; //a는 출석, b는 과제, c는 중간, d는 기말, e는 총점
	float f = 0;// d는 평균
	printf("출석점수를 입력하세요.\n");
	scanf_s("%d", &a);
	printf("과제점수를 입력하세요.\n");
	scanf_s("%d", &b);
	printf("중간고사 점수를 입력하세요.\n");
	scanf_s("%d", &c);
	printf("기말고사 점수를 입력하세요.\n");
	scanf_s("%d", &d);
	e = a + b + c + d;
	f = e / 5;
	printf(" 총점은 %d 점 입니다.\n 평균은 %1.f 점 입니다.\n", e, f);
}
//문제 5.
int main()
{
	int a;// 사용자의 나이;
	printf("당신의 나이를 입력해주세요.\n");
	if (a >= 19)
		printf("성인입니다.");
	else
		printf("청소년입니다.");
}
//문제 6.
int main()
{
	int a, b; //a는 중간, b는 기말
	printf("프로그래밍 기초\n중간고사 점수를 입력하세요.\n");
	scanf_s("%d", &a);
	printf("기말고사 점수를 입력하세요.\n");
	scanf_s("%d", &b);
	if (a >= 90)
		if (b >= 90)
			printf("우수");
		else
			printf("보통");
	else
		printf("보통");
}
//문제 7.
int main()
{
	printf("원하시는 구구단 수를 입력하세요.\n입력 : ");
	int a;
	scanf_s("%d", &a);
	printf("구구단 %d단", a);
	for (int i = 1; i <= 9; i++)
		printf(" %d", a*i);
}
//문제 8.
int main()
{
	printf("세 수를 입력하세요.\n");
	int a, b, c;//세 수
	int big, small;//최대 최소
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	small = ((a < b ? a : b) < c ? ((a < b) ? a : b) : c);
	big = ((a > b ? a : b) > c ? ((a > b) ? a : b) : c);
	printf("최소 %d \n최대 %d", small, big);
}