//pb 1
#include <stdio.h>
//#include <iostream>

//using namespace std;

int prime(int x)
{
	if (x != 2)
		for (int d = 2; d <= x / 2; d ++)
			if (x % d == 0)
				return 0;
	if (x == 1)
		return 0;
	return 1;
}
void a(int n)
{
	for (int i = 1; i < n; i++)
		if (prime(i) == 1)
			printf("%d ", i);
			//cout << i << " ";
}

int b(int v[], int n, int v1[])
{
	int start = 0, end = 0, s = 0, lmax = 0, startmax = 0, endmax = 0;
	for (int i = 0; i < n-1; i++)
	{
		s = v[i] + v[i + 1];
		if (prime(s) == 1)
		{
			end = i + 1;
			if (end - start + 1 > lmax)
			{
				lmax = end - start + 1;
				startmax = start;
				endmax = end+1;
			}
		}
		else
		{
			start = i;
			end = i;
		}
		s = 0;
	}
	//cout << "aaa";
	//printf("%d %d", startmax, endmax);
	//if (startmax == 0 && endmax == 0)
	//	return 0;
		//printf("No subsequence\n");
		//cout << "No subsequence";
	int ctr = 0;
	for (int k = startmax; k < endmax; k++)
		v1[ctr++] = v[k];
	return ctr;
	/*
	else
	{
		printf("The subsequence starts from %d and ends at %d \n", startmax + 2, endmax + 1);
		//cout << "The subsequence starts from " << startmax + 1 << " and ends at " << endmax + 1<<endl;
		for (int i = startmax + 1; i <= endmax; i++)
			printf("%d ", v[i]);
			//cout << v[i] << " ";
	}*/
}
int gcd(int a, int b)
{
	int gcd;
	for (int i = 1; i <= a && i <= b; i++)
		if (a % i == 0 && b % i == 0)
			gcd = i;
	return gcd;
}

int pb2_b(int v[], int n, int v1[])
{
	int start = 0, end = 0, s = 0, lmax = 0, startmax = 0, endmax = 0;
	for (int i = 0; i < n - 1; i++)
	{
		s = gcd(v[i], v[i + 1]);
		if (s==1)
		{
			end = i + 1;
			if (end - start + 1 > lmax)
			{
				lmax = end - start + 1;
				startmax = start;
				endmax = end + 1;
			}
		}
		else
		{
			start = i;
			end = i;
		}
		s = 0;
	}
	//cout << "aaa";
	//printf("%d %d", startmax, endmax);
	//if (startmax == 0 && endmax == 0)
	//	return 0;
		//printf("No subsequence\n");
		//cout << "No subsequence";
	int ctr = 0;
	for (int k = startmax; k < endmax; k++)
		v1[ctr++] = v[k];
	return ctr;



	/*
	int start = 0, end = 0, s = 0, lmax = 0, startmax = 0, endmax = 0;
	for (int i = 0; i < n ; i++)
	{
		if (gcd(v[i], v[i+1]) == 1)
		{
			end = i + 1;
			if (end - start + 1 > lmax)
			{
				lmax = end - start + 1;
				startmax = start;
				endmax = end + 1;
			}
		}
		else
		{
			start = i;
			end = i;
		}
		s = 0;

		int ctr = 0;
		for (int k = startmax; k < endmax; k++)
			v1[ctr++] = v[k];
		return ctr;

	}
	//cout << "aaa";
	/*
	printf("st: %d end: %d", startmax, endmax);
	if (startmax == 0 && endmax == 0)
		printf("No subsequence\n");
	//cout << "No subsequence";
	else
	{
		printf("The subsequence starts from %d and ends at %d \n", startmax + 2, endmax + 1);
		//cout << "The subsequence starts from " << startmax + 1 << " and ends at " << endmax + 1<<endl;
		for (int i = startmax + 1; i <= endmax; i++)
			printf("%d ", v[i])
		//cout << v[i] << " ";
	}*/
}

void readArray(int v[], int n)
{
	/*
	printf("n= ");
	scanf_s("%d", &n);*/
	for (int i = 0; i < n; i++)
	{
		printf("v[i] = ");
		scanf_s("%d", &v[i]);
	}
}

int main()
{
	int cmd, n;
	int v[100];
	//n = 13;
	///int v[] = { 1, 2, 3, 15, 1, 3, 2, 9, 8, 7, 10, 13, 15 };
	/*int ddd = gcd(4, 6);
	printf("%d", ddd);*/
	printf("1. Generate all the prime numbers smaller than a given natural number n.\n");
	printf("2. Given a vector of numbers, find the longest increasing contiguous subsequence, such the sum of that any 2 consecutive elements is a prime number.\n");
	printf("3. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.\n");

	printf("Choose 1, 2 or 3: ");
	//cout << "Choose 1 or 2: ";
	scanf_s("%d", &cmd);
	//cin >> cmd;
	if (cmd == 1)
	{
		printf("n = ");
			//cout << "n = ";
		scanf_s("%d", &n);
		//cin >> n;
		a(n);
	}
	else
		if (cmd == 2)
		{
			printf("n = ");
			scanf_s("%d", &n);
			readArray(v, n);
			int startmax = 0, endmax = 0;
			int v1[100];
			int ctr = b(v, n, v1);
			if(ctr == 0)
				printf("No subsequence\n");
			else
			{
				
				
				for (int i = 0; i < ctr; i++)
				{
					printf("%d ", v1[i]);
				}
				/*
				printf("The subsequence starts from %d and ends at %d \n", startmax + 2, endmax + 1);
				//cout << "The subsequence starts from " << startmax + 1 << " and ends at " << endmax + 1<<endl;
				for (int i = startmax + 1; i <= endmax; i++)
					printf("%d ", v[i]);
				//cout << v[i] << " ";*/
			}

		}
		else
			if(cmd == 3)
			{
				//printf("%d", gcd(2, 4));
				int n1, v2[100],v3[100];
				printf("n = ");
				scanf_s("%d", &n1);
				readArray(v2, n1);
				int startmax = 0, endmax = 0;
				int v1[100];
				int ctr1 = pb2_b(v2, n1, v3);
				if (ctr1 == 0)
					printf("No subsequence\n");
				else
				{


					for (int i = 1; i < ctr1; i++)
					{
						printf("%d ", v3[i]);
					}
					/*
					printf("n = ");
					scanf_s("%d", &n);
					readArray(v, n);
					pb2_b(v, n);*/
				}
			}
			
			else
				printf("Wrong input");
				//cout << "Wrong input";

	// print din b il scot in afara
	return 0;
}

