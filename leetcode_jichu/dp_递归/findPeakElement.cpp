#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return 0;

		int left = 1;
		int right = n - 2; //?

		if (nums[0] > nums[1]) return 0; //	++left;
		if (nums[n - 1] > nums[n - 2]) return n - 1; //	--right;

		//二分查找

		int flag = -1;
		int ans =-1;

		while (left <= right && flag == -1) {
			//TODO
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid - 1]) {
				right = mid - 1;
			} else if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			} else {
				flag = 1;
				ans=mid;
				break;
			}
		}
//		return -1;
//		int n=nums.size();
//		if(n==1) return 0;
//
//		int left=0;int right = n-1;//?
//
//		if(nums[left]>nums[left +1]) return left;
//		if(nums[right]>nums[right-1]) return right;
//
//		//二分查找
//		int mid=(left+right)/2;
//
//		for(;mid>left && mid<right;){
//			if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;//直接到找峰值位置之一
//			else if(nums[mid]<nums[mid-1]){
//				mid=(left+mid)/2;
//			}else if(nums[mid]<nums[mid+1]){
//				mid=(right+mid)/2;
//			}
//		}
//		return -1;
		return ans;
	}
};

int main() {
	vector<int> nums = {1, 2, 5, 4, 3, 2, 1};
	
	Solution sl;
	return sl.findPeakElement(nums);
	
//	
//	int n = nums.size();
//	if (n == 1) return 0;
//
//	int left = 1;
//	int right = n - 2; //?
//
//	if (nums[0] > nums[1]) return 0; //	++left;
//	if (nums[n - 1] > nums[n - 2]) return n - 1; //	--right;
//
//	//二分查找
//
//	int flag = -1;
//
//	while (left <= right && flag == -1) {
//		//TODO
//		int mid = left + (right - left) / 2;
//		if (nums[mid] < nums[mid - 1]) {
//			right = mid - 1;
//		} else if (nums[mid] < nums[mid + 1]) {
//			left = mid + 1;
//		} else {
//			flag = 1;
//			return mid;
//		}
//	}
//	return -1;

//	while(left <= right){//while(left<right){//for(;mid>left && mid<right;){
//		int mid=(left+right)/2;
//		if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
//			return mid;//直接到找峰值位置之一
//		else if(nums[mid]<nums[mid-1]){
//			right=mid-1;
////			mid=(left+mid-1)/2;
//		}else{//}else if(nums[mid]<nums[mid+1]){
//			left=mid+1;
////			mid=(right+mid+1)/2;
//		}
//	}
//
//	return -1;
}
