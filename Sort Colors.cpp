#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(int A[], int n) {
		int red=0, white=0, blue=0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == 0) red++;
			else if (A[i] == 1) white++;
			else if (A[i] == 2) blue++;
		}
		int j;
		for (j = 0; j < red; ++j)
			A[j] = 0;
		for (j = red; j < red+white; ++j)
			A[j] = 1;
		for (j = red+white; j < n; ++j)
			A[j] = 2;
	}
};

int main()
{
	Solution sl;
	int a[5] = { 0, 1, 2, 2, 1 };
	sl.sortColors(a, 5);
	for (int i = 0; i < 5; ++i)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
