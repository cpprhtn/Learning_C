#include "pch.h"
#include <iostream>
#include<cmath>
using namespace std;
#pragma warning(disable:4996)


int main()
{
	char arr[10000];
	gets_s(arr);
	for (int i = 0; i < 30; i++)
	{
		if (arr[i] == ' ')
		{
			printf("\n");
			i++;
		}
		printf("%c", arr[i]);
	}
}
/*float getLength(int a[2], int b[2]) {
	if (abs(a[0] - b[0]) != 0 && abs(a[1] - b[1]) != 0) {
		return sqrt(
			pow((float)a[0] - b[0], 2)
			+ pow((float)a[1] - b[1], 2)
		);
	}
	else {
		return abs(a[0] - b[0]) > abs(a[1] - b[1]) ? abs(a[0] - b[0]) : abs(a[1] - b[1]);
	}
}
int isSquare(int arr[][2], int a, int b, int c, int d) {
	if (getLength(arr[a], arr[b]) == getLength(arr[b], arr[c])
		&& getLength(arr[b], arr[c]) == getLength(arr[c], arr[d])
		&& getLength(arr[c], arr[d]) == getLength(arr[d], arr[a])
		&& getLength(arr[a], arr[d]) == getLength(arr[b], arr[a])
		) {
		return 1;
	}
	return 0;
}

int main()
{
	int n;
	float best = 0;
	scanf("%d", &n);
	int arr[100][2] = { 0 };

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	//4 point
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (i != j && i != k && i != l && j != k && j != l && k != l) {
						if (isSquare(arr, i, j, k, l) == 1) {
							float width = getLength(arr[i], arr[j]);
							best = best < width ? width : best;
							//printf("found %f  %d %d %d %d\n",width,i,j,k,l);
						}
						else {
							continue;
						}
					}
				}
			}
		}
	}
	printf("%.2f", best*best);
}*/











/*
int main()
{
	int n, count = 0;
	double best = 0;
	double a[50], b[50];
	scanf("%d", &n);
	double arr[100][2] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++)
		{
			a[count] = abs(arr[i][0] - arr[j][0]);
			b[count] = abs(arr[i][1] - arr[j][1]);
			count++;
		}
	}
	for (int i = 0; i < n*n; i++)
	{
		for (int j = 0; j < n*n; j++)
		{
			if (a[i] == b[j])
			{
				if (a[i] > best)
					best = a[i];
			}
		}
	}
	printf("%.2lf", best*best);

}*/
/*int main()
{
	int n;
	float best = 0;
	float a[50], b[50];
	scanf("%d", &n);
	int arr[100][2] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = abs(arr[i][0] - arr[i + 1][0]);
		b[i] = abs(arr[i][1] - arr[i + 1][1]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				if (a[i] > best)
					best = a[i];
			}
		}
	}
	printf("%.2f", best*best);

}
*/








/*int paper[111][111];
int main()
{
	int count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		int n;
		scanf("%d", &n);
		int sx, sy;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &sx, &sy);
			for (int x = sx; x < sx + 10; ++x)
				for (int y = sy; y < sy + 10; ++y)
					paper[x][y] = 1;
		}
		int res = 0;
		for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
				if (paper[i][j] == 1)res++;
		printf("%d\n", res);
	}

	return 0;
}*/

/*int main()
{
	int n, m;
	int input[2][1000] = { 0 };
	int count[101] = { 0 };
	int copy[101] = { 0 };
	int rem[101] = { 0 };
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &input[0][i], &input[1][i]);
	}
	for (int i = 0; i < m; i++)
	{
		count[input[0][i]] += 5;
		count[input[1][i]] += 3;
	}
	for (int i = 0; i < m; i++)
	{
		copy[i] = count[i];
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (count[j] < count[j + 1])
			{
			}
			int temp = count[j];
			count[j] = count[j + 1];
			count[j + 1] = temp;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < m; j++) {
			if (count[i - 1] == copy[j])
			{
				if(rem[j]==0)
					printf("%d %d %d\n", i, j+1, count[i - 1]);
				rem[j] += 1;
			}
		}
	}
}
*/
