#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
//		int nOldendIndex = nums.size() - 1;
		int countval = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == val)
				++countval;

//		nums.resize()
//		int nNewendIndex = nums.size() - 1 - countval;
		
//		当数组需要变小时，双指针的遍历方向是++
//		当数组需要变大时，双指针的遍历方向是--
		
		int fast = 0, slow = 0;
		while (fast < nums.size()) {
			if (nums[fast] != val) {
				nums[slow] = nums[fast];
				++slow;
				++fast;
			} else {//要删val，slow不动，准备着等下一个不删的元素
				++fast;
			}
			
		}
		return slow;
//		cout<<slow<<endl;
//
//		while (nOldendIndex >= 0) {
//			if (nums[nOldendIndex] != val) {
//				int tmp=nums[nNewendIndex];
//				nums[nNewendIndex--] = nums[nOldendIndex];//?
//
//			} else {
//				--nNewendIndex;
//			}
//			--nOldendIndex;
//
//		}


	}
};
