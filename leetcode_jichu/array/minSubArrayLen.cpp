#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int slow = 0;
		int fast = 0;
		int sum = 0;
		int minlen = nums.size() + 1;

		while (fast < nums.size()) {
			sum += nums[fast];
			++fast;
			while (sum >= target ) {
				if ( minlen > fast - slow ) {
					minlen = fast - slow ;
				}
				sum -= nums[slow];
				++slow;
			}
		}
		//		if (sum < target) return -1;
//		return sum >= target ? minlen : 0;
		return minlen == nums.size() + 1 ? 0 : minlen;
	}
};

int main() {
	int target = 15;
//	7;

	vector<int> nums = {1, 2, 3, 4, 5};
//	{2, 3, 1, 2, 4, 3};

	Solution sl;
	cout << sl.minSubArrayLen(target, nums) << endl;
	return 0;
}
