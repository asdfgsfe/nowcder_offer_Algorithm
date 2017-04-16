#include<stdio.h>
using namespace std;

	bool isUglyNum(int num)
	{
		while (num % 2 == 0)
			num /= 2;
		while (num % 3 == 0)
			num /= 3;
		while (num % 5 == 0)
			num /= 5;

		return (num==1)? true:false;
	}

	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;

		int num = 0;
		int uglyFound = 0;
		while (uglyFound < index)
		{
			++num;
			if (isUglyNum(num))
				uglyFound++;
		}
		return num;
	}

	int main()
	{
		int num = GetUglyNumber_Solution(11);
	
		printf("%d\n", num);
		return 0;
	}
