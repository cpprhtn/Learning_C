#include "pch.h"
#include <iostream>
using namespace std;
int GCD(int num1, int num2)
{
	int i;
	int gcd = 1;
	for (i = 2; i <= (num1 > num2 ? num2 : num1); i++) {
		if (num1%i == 0 && num2%i == 0)
			gcd = i;
	}
	return gcd;
}
int LCM(int num1, int num2, int gcd)
{
	return num1 * num2 / gcd;
}
int main()
{
	int gcd;
	int lcm;
	int num1, num2;
	cout << "숫자를 두개 입력해주세요." << endl;
	cin >> num1 >> num2;

	gcd = GCD(num1, num2);
	lcm = LCM(num1, num2, gcd);
	if (gcd == 1)
		cout << "최대공약수 : 서로소입니다." << endl;
	else
		cout << "최대공약수 : " << gcd << endl;
	cout << "최소공배수 : " << lcm << endl;
}