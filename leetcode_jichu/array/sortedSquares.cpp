#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			nums[i] = nums[i] * nums[i];
		}

		int left = 0;
		int right = nums.size() - 1;

		vector<int> result(nums.size(), 0);
//		int tmp = 0;
		for (int i = nums.size() - 1; i >= 0; --i) {
			if (nums[left] < nums[right]) {
				result[i] =  nums[right];
				--right;
			} else if (nums[left] > nums[right]) {
//				swap(nums[left],nums[right]);
				result[i] =  nums[left];
				++left;

//				tmp = nums[right];
//				nums[right] = nums[left];
//				//nums[left]存的是两个最大的里面的 次大的
//				nums[left]=tmp;
			} else if (nums[left] == nums[right]) {
				result[i] =  nums[right];
				--right;

//				tmp = nums[right];
//				nums[right] = nums[left];
			}
			//把最大的（nums[right]）放最后面nums[i]

		}
		return result;
	}
};

int main() {
	vector<int>nums = {-4, -1, 0, 3, 10};

	Solution sl;
	vector<int>result=sl.sortedSquares(nums);
	
	bool flag=false;
	for(auto it:result){
		if(flag) cout<<",";
		cout<<it;
		flag=true;
//		if(it!=result.end()) cout<<",";
	}
	cout<<endl;
//	cout<<result<<endl;
	return 0;
}
