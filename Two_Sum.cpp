#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> result;
		vector<int>::iterator it;
		vector<int>::iterator it2;
		for (it = numbers.begin(); it != numbers.end(); ++it)
		{
			for (it2 = it + 1; it2 != numbers.end(); ++it2)
			{
				if (*it + *it2 == target)
				{
					result.push_back(it - numbers.begin() + 1);
					result.push_back(it2 - numbers.begin() + 1);
					break;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution sol;
	int p[]= { 2, 7, 11, 15 };
	vector<int> numbers(p, p + 4);
	int target = 26;
	vector<int> result=sol.twoSum(numbers, target);
	cout << result.front() << endl;
	cout << result.back() << endl;
	return 0;
}
