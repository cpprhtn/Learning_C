#include "pch.h"
#include<iostream>
#include<string>
#include<Windows.h>
#pragma warning (disable : 4996)
using namespace std;

struct Subject   // 과목 정보
{
	string SubName;   // 과목이름
	int Hakjum;      // 과목학점
	string Grade;   // 과목등급
	float GPA;      // 과목평점
};

struct Student   // 학생 정보
{
	string StdName;   // 학생 이름
	int Hakbun;      // 학번
	Subject* Sub;   // 과목
	int SubNum;      // 과목 수
	float AveGPA;   // 교과목 평균 평점
};

/* 전체 학생의 신상 정보 및 성적 정보를 입력하는 부분을 InputData() 함수로 구현*/
void InputData(Student* pSt, int StudentNum);

//메뉴 출력
inline void PrintMenu();
//교과목의 평점 계산
void CalcGPA(Subject& Sub);
//개인 학생의 평균 평점 계산 
float CalcAveGPA(Subject* Sub, int SubNumber);
//전체 학생 신상 / 성적 정보 출력 
void PrintAllData(const Student* pSt, int StudentNum);
//개인 학생 신상 / 성적 정보 출력 
void PrintOneData(const Student& rSt);
//학생 이름 검색 후 해당 학생의 정보가 있는 곳의 주소 리턴
Student* StdSearch(Student* pSt, int StudentNum);
// 추가
// 과목 검색
Subject* SubSearch(const Student* pSt);
//전체 학생 목록 보기 
void PrintAllStdList(Student* pSt, int StudentNum);

// 확장
// 학생 정보 수정 
void Modify(Student* pSt, int StudentNum);

inline void InputValue(string& str);
inline void InputValue(int& i);

int main()
{
	Student* SearchStd = NULL;
	int menu;

	int StdNum;
	printf("입력할 학생 수를 입력: ");
	InputValue(StdNum);
	Student* St = new Student[StdNum];

	while (true)
	{
		PrintMenu();   // 메뉴출력
		InputValue(menu);   // 메뉴선택

		//프로그램 종료
		if (menu == 6)
			break;

		switch (menu)
		{
		case 1:
			InputData(St, StdNum);   //학생 성적 입력
			break;
		case 2:
			PrintAllData(St, StdNum);   //전체 학생 성적 보기
			break;
		case 3:
			SearchStd = StdSearch(St, StdNum);   //학생 이름 검색
			if (SearchStd != NULL)
				//검색에 성공하면 해당 학생의 정보가 있는 곳의 주소
				PrintOneData(*SearchStd);
			break;
		case 4:
			PrintAllStdList(St, StdNum);   //전체 학생 목록 보기
			break;
		case 5:
			Modify(SearchStd, StdNum);
			break;
		default:
			continue;
		}
	}

	/* new 연산자와 delete 연산자를 사용하여 Student 및 Subject 구조체를 동적으로 할당한다. */
	for (int i = 0; i < StdNum; i++)   // 학생정보 삭제
		delete St[i].Sub;
	delete St;

	return 0;
}

// 개편 기능 : 학생의 정보 입력
void InputData(Student* pSt, int StudentNumber)
// pSt : 수정할 학생정보 포인터 매개변수
// StudentNum : 전체 학생 수
{
	int i, j;   // 반복함수

	for (i = 0; i < StudentNumber; i++)   // n번째 학생정보 입력
	{
		cout << "\n* " << i + 1 << " 번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(pSt[i].StdName);
		cout << "학번 : ";
		InputValue(pSt[i].Hakbun);

		printf("\n수강한 과목 수를 입력 : ");
		InputValue(pSt[i].SubNum);
		/* new 연산자와 delete 연산자를 사용하여 Student 및 Subject 구조체를 동적으로 할당한다. */
		pSt[i].Sub = new Subject[pSt[i].SubNum];

		cout << "\n\n\n* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.";
		for (j = 0; j < pSt[i].SubNum; j++)
		{
			cout << "\n교과목명 : ";
			InputValue(pSt[i].Sub[j].SubName);
			cout << "과목학점수 : ";
			InputValue(pSt[i].Sub[j].Hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(pSt[i].Sub[j].Grade);

			// 각 교과목의 평점 계산
			CalcGPA(pSt[i].Sub[j]);
		}

		// 개인 학생의 교과목 평균 평점 계산
		pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);
		cout << "\n\n\n";
	}
}

// 메뉴 출력
inline void PrintMenu()
{
	cout << "\n===== 메뉴 =====" << endl;
	cout << "1. 학생 성적 입력" << endl;
	cout << "2. 전체 학생 성적 보기" << endl;
	cout << "3. 학생 이름 검색" << endl;
	cout << "4. 전체 학생 목록 보기" << endl;
	cout << "5. 학생 정보 수정" << endl;
	cout << "6. 프로그램 종료" << endl;
	cout << "\n원하는 기능을 입력하세요 : ";
}

// 교과목 평점
void CalcGPA(Subject& Sub)
// Sub : 교과목 정보가 담긴 Subject 레퍼런스 변수
{
	float score;

	if (Sub.Grade == "A+")      // A+학점
		score = 4.5;
	else if (Sub.Grade == "A" || Sub.Grade == "A0")   // A학점
		score = 4;
	else if (Sub.Grade == "B+")   // B+학점
		score = 3.5;
	else if (Sub.Grade == "B" || Sub.Grade == "B0")   // B학점
		score = 3;
	else if (Sub.Grade == "C+")   // C+학점
		score = 2.5;
	else if (Sub.Grade == "C" || Sub.Grade == "C0")   // C학점
		score = 2;
	else if (Sub.Grade == "D+")   // D+학점
		score = 1.5;
	else if (Sub.Grade == "D" || Sub.Grade == "D0")   // D학점
		score = 1;
	else if (Sub.Grade == "F")   // F학점
		score = 0;

	Sub.GPA = Sub.Hakjum * score;   // 교과목의 평점 = 학점 * 등급
}

// 개인학생의 교과목 평균 평점
float CalcAveGPA(Subject* Sub, int SubNumber)
// Sub : 교과목 정보가 담긴 Subject 포인터 변수
{
	float sum = 0;   // 임시 합계함수
	int i;   // 반복함수

	for (i = 0; i < SubNumber; i++)
		sum += Sub[i].GPA;

	return sum / SubNumber;   // 교과목 평균 평점
}

// 전체 학생의 신상 정보와 성적 정보를 출력
void PrintAllData(const Student* pSt, int StudentNum)
// pSt : 학생정보가 담긴 Student 포인터 변수
// StudentNum :전체 학생 수
{
	int i, j;   // 반복함수

	cout << "\n        전체 학생 성적 보기\n";
	cout << "========================================================\n";

	for (i = 0; i < StudentNum; i++)
	{
		cout << "이름 :"; cout << pSt[i].StdName; cout << "  학번 : " << pSt[i].Hakbun;

		cout << "\n========================================================\n";
		cout.width(20); cout << "과목명"; cout.width(10); cout << "과목학점"; cout.width(10); cout << "과목등급"; cout.width(10); cout << "과목평점";
		cout << "\n========================================================\n";
		for (j = 0; j < pSt[i].SubNum; j++)
		{
			cout.width(15); cout << fixed; cout.precision(2);
			cout << pSt[i].Sub[j].SubName;
			cout.width(10);
			cout << pSt[i].Sub[j].Hakjum;
			cout.width(10);
			cout << pSt[i].Sub[j].Grade;
			cout.width(10);
			cout << pSt[i].Sub[j].GPA << endl;
		}
		cout << "========================================================\n";
		cout.width(40); cout << "평균평점"; cout.width(10); cout << pSt[i].AveGPA << "\n\n";
	}
}

// 개인 학생 신상 / 성적 정보 출력
void PrintOneData(const Student& rSt)
// rSt : 학생정보가 담긴 Student 레퍼런스 변수
{
	int i;   //반복함수

	cout << "이름 :"; cout << rSt.StdName; cout << "  학번 : " << rSt.Hakbun;

	cout << "\n========================================================\n";
	cout.width(20); cout << "과목명"; cout.width(10); cout << "과목학점"; cout.width(10); cout << "과목등급"; cout.width(10); cout << "과목평점";
	cout << "\n========================================================\n";
	for (i = 0; i < rSt.SubNum; i++)
	{
		cout.width(15); cout << fixed; cout.precision(2); // 소수점 이하 2자리만 출력하도록 고정
		cout << rSt.Sub[i].SubName;
		cout.width(10);
		cout << rSt.Sub[i].Hakjum;
		cout.width(10);
		cout << rSt.Sub[i].Grade;
		cout.width(10);
		cout << rSt.Sub[i].GPA << endl;
	}
	cout << "========================================================\n";
	cout.width(40); cout << "평균평점"; cout.width(10); cout << rSt.AveGPA << "\n\n";
}

// 특정 학생의 이름을 검색하여 해당 학생 정보가 있는 주소를 리턴
Student* StdSearch(Student* pSt, int StudentNum)
// pSt : 학생정보가 담긴 Student 포인터 변수
// 리턴값 : 해당 학생의 정보가 있는 곳의 주소
{
	Student* SearchStd = NULL;   // 학생이름 탐색 결과를 받을 구조체
	string SearchName;   // 검색할 학생이름

	cout << "\n\n\n";
	cout << "검색 할 학생 이름 : ";
	InputValue(SearchName);

	for (int i = 0; i < StudentNum; i++)
	{
		if (pSt[i].StdName == SearchName)   // 비교
			SearchStd = &pSt[i];   // 같으면 SearchStd는 해당 학생의 정보가 있는 곳의 주소
	}
	if (SearchStd == NULL)
		//성공하지 못하면 NULL을 리턴하고 에러 메시지 출력
		cout << "없는 학생입니다" << endl;
	return SearchStd;
}

Subject* SubSearch(const Student* pSt)
{
	Subject* SearchSub = NULL;   // 학생이름 탐색 결과를 받을 구조체
	string SearchName;   // 검색할 학생이름

	cout << "\n\n\n";
	cout << "검색 할 과목 이름 : ";
	InputValue(SearchName);

	for (int i = 0; i < pSt->SubNum; i++)
	{
		if (pSt->Sub[i].SubName == SearchName)   // 비교
			SearchSub = &pSt->Sub[i];   // 같으면 SearchStd는 해당 학생의 정보가 있는 곳의 주소
	}
	if (SearchSub == NULL)
		//성공하지 못하면 NULL을 리턴하고 에러 메시지 출력
		cout << "없는 과목 입니다." << endl;
	return SearchSub;
}

// 전체 학생의 목록(학번, 이름)을 출력
void PrintAllStdList(Student* pSt, int StudentNum)
// pSt : 학생정보가 담긴 Student 포인터 변수
// StudentNum : 전체 학생 수
{
	int i;   // 반복함수

	cout << "\n========================================================\n";
	cout.width(10); cout << "학번"; cout.width(10); cout << "이름";
	cout << "\n========================================================\n";
	for (i = 0; i < StudentNum; i++)
	{
		cout.width(10);
		cout << pSt[i].Hakbun;
		cout.width(10);
		cout << pSt[i].StdName << endl;
	}
	cout << "========================================================\n";
}

// 특정 학생의 이름과 학번 정보 수정
void Modify(Student* pSt, int StudentNum)
// pSt는 수정할 학생정보 포인터 매개변수
{
	Student* St = NULL;
	Subject* Sub = NULL;
	St = StdSearch(pSt, StudentNum);   //학생 이름 검색

	if (St != NULL)
	{
		string Type; //”학생정보” 또는 “과목정보” 문자열 저장용 string
		cout << "수정(학생정보/과목정보) : ";
		InputValue(Type); // Type 입력 함수 오버로딩 이용한 입력 함수

		if (Type == "학생정보")
		{
			// 학생 정보를 수정하는 부분
			cout << "* (" << St->StdName << ", " << St->Hakbun << ")의 정보를 수정하세요" << endl;
			cout << "이름 : ";
			InputValue(St->StdName);
			cout << "학번 : ";
			InputValue(St->Hakbun);
		}
		else if (Type == "과목정보")
		{
			Sub = SubSearch(St); // 교과목 탐색

			// 과목 탐색하고 수정하는 부분
			// 과목의 등급과 학점수가 바뀌면 평점도 바뀐다.
			cout << "*( " << Sub->SubName << ", 학점 : " << Sub->Hakjum << ", 등급 : " << Sub->Grade << ")의 정보를 수정하세요" << endl;
			cout << "교과목명 : ";
			InputValue(Sub->SubName);
			cout << "학점 : ";
			InputValue(Sub->Hakjum);
			cout << "등급 : ";

		}
	}
}

// 개별 데이타를 사용자로부터 입력
inline void InputValue(string& str)   // 이름, 과목명, 과목 등급
{
	getline(cin, str);
}
inline void InputValue(int& i)      // 메뉴번호, 전체학생 수, 과목 수, 학번, 학점
{
	cin >> i;
	cin.ignore();
}
