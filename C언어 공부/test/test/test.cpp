
#include "pch.h"
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int count = 0;
int money = 10000;

int buyItem(int sum)
{
	cout << "아이템을 "<<sum<<"개 구매하셨습니다" << endl;
	money -= 100 * sum;
	printf("남은돈은 %d 원입니다\n", money);
	return 0;
}
int main()
{
	int sum = 0;
	while (money > 0) {
		scanf("%d", &sum);
		buyItem(sum);
	}
	/*for (; money > !0;)
	{
		scanf("%d", &sum);
		buyItem(sum);
	}*/
}

