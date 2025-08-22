#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int right = 0;
		int left = 0;
		int sublen = 0;
		int minlen = INT_MAX;//int minlen=0;

		int sum = 0;
		int n = nums.size();
		for ( right = 0; right < n; ++right) {
			sum = sum + nums[right];
			while (sum >= target) {
				//TODO
				sublen = right - left + 1;
				minlen = minlen < sublen ? minlen : sublen;
				sum = sum - nums[left];
				++left;
			}

		}
		return minlen == INT_MAX ? 0 : minlen;
	}
};
