#include <iostream>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) 
	{
		while (n > 1)
		{
			A[n-2] ^= A[n-1];
			n--;
		}
		return A[0];
	}
};
