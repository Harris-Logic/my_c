#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int i = 0;
		if (n - 1 == 0) return nums[n - 1] == target ? n - 1 : -1;
		int j = n - 1;


		while (i < j) {
			int mid = i + (j - i) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) {
				i = mid + 1;
			}
			if (nums[mid] > target) {
				if (mid - 1 < 0) break;
				j = mid - 1;
			}
		}
		return nums[j] == target ? j : -1;
	}
};

int main() {
	vector<int>nums = {2, 5};
	int target = 0;

	Solution sl;
	cout << sl.search(nums, target) << endl;

	return 0;
}
