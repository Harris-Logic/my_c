#include "bits/stdc++.h"
using namespace std;

//findPeakGrid
class Solution {
public:
	vector<int> findPeakGrid(vector<vector<int >> & mat) {
		int m = mat.size(); // 获取行数（高度）
		int n = mat[0].size();// 获取列数（宽度）
		if(m == 1 && n == 1) return {0, 0};

		vector<int> ans = {-1, -1};

		int left = 1;
		int right = n - 2;
		int up = 1;
		int down = m - 2;



		if (mat[0][0] > mat[1][0] && mat[0][0] > mat[0][1]) return {0, 0};
		if (mat[m - 1][0] > mat[m - 2][0] && mat[m - 1][0] > mat[m - 1][1]) return {m - 1, 0};
		up = 1;
		down = m - 2;
		while (up <= down) {
			int mid = up + (down - up) / 2;
			if (mat[mid][0] < mat[mid - 1][0]) {
				down = mid - 1;
			} else if (mat[mid][0] < mat[mid + 1][0]) {
				up = mid + 1;
			}else if(mat[mid][0] < mat[mid][1]){
				continue;//这里存在逻辑问题，死循环在这里。无法继续二分，没有下一步的条件。
			}else {
				ans = {mid, 0};
				break;
			}
		}
		up = 1;
		down = m - 2;
		while(up<=down){
			int mid = up + (down - up) / 2;
			if (mat[mid][n-1] < mat[mid - 1][n-1]) {
				down = mid - 1;
			} else if (mat[mid][n-1] < mat[mid + 1][n-1]) {
				up = mid + 1;
			} else if(mat[mid][n-1] < mat[mid][n-2]){
				continue;
			}else {
				ans = {mid, n-1};
				break;
			}
		}

		if (mat[0][n - 1] > mat[1][n - 1] && mat[0][n - 1] > mat[0][n - 2]) return {0, n - 1};
		if (mat[m - 1][n - 1] > mat[m - 2][n - 1] && mat[m - 1][n - 1] > mat[m - 1][n - 2]) return {m - 1, n - 1};
		left = 1;
		right = n - 2;
		while(left<=right){
			int mid = left+(right-left)/2;
			if(mat[0][mid] < mat[0][mid-1]){
				right=mid-1;
			}else if(mat[0][mid] < mat[0][mid +1]){
				left=mid+1;
			}else if(mat[0][mid] < mat[1][mid]){
				continue;
			}else{
				ans = {0,mid};
				break;
			}
		}
		left = 1;
		right = n - 2;
		while(left<=right){
			int mid = left+(right-left)/2;
			if(mat[m-1][mid] < mat[m-1][mid-1]){
				right=mid-1;
			}else if(mat[m-1][mid] < mat[m-1][mid +1]){
				left=mid+1;
			}else if(mat[m-1][mid] < mat[m-2][mid]){
				continue;
			}else{
				ans = {m-1,mid};
				break;
			}
		}

//		if(mat[0][0] > mat[1][0] && mat[0][0] > mat[0][1]) return {0, 0};
//		if (mat[n - 1][0] > mat[n - 2][0] && mat[n - 1][0] > mat[n - 1][1]) return {n - 1, 0};
//		if (mat[0][m - 1] > mat[1][m - 1] && mat[0][m - 1] > mat[0][m - 2]) return {0, m - 1};
//		if (mat[n - 1][m - 1] > mat[n - 2][m - 1] && mat[n - 1][m - 1] > mat[n - 1][m - 2]) return {n - 1, m - 1};


		while (left <= right || up <= down) {
			//TODO
			int midM = up + (down - up) / 2;
			int midN = left + (right - left) / 2;

			if (mat[midM][midN] < mat[midM - 1][midN]) {
				right = midM - 1;
			} else if (mat[midM][midN] < mat[midM + 1][midN]) {
				left = midM + 1;
			} else {
				ans = {midM, midN};
				break;
			}

			if (mat[midM][midN] < mat[midM][midN - 1]) {
				down = midN - 1;
			} else if (mat[midM][midN] < mat[midM][midN + 1]) {
				up = midN + 1;
			} else {
				ans = {midM, midN};
				break;
			}
		}
		return ans;
	}
//	vector<int> baolifindGrid(vector<vector<int >> & mat) {
//		int m = mat.size();
//		int n = mat[0].size();
//		for(int i = 0; i<m; ++i) {
//			for(int j = 0; j<n; ++j) {
//				//TODO
//				bool isPeak = true;
//				if(i>0)
//				}
//		}
//	}
};

class Solution2 {
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
		int ans = -1;

		while (left <= right && flag == -1) {
			//TODO
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid - 1]) {
				right = mid - 1;
			} else if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			} else {
				flag = 1;
				ans = mid;
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
//	vector<vector<int>> mat = { //{{1,10},{50,500},{40,2},{30,3},{20,4}};
//		{55, 77, 9, 50, 49, 77, 60, 68, 33, 71, 2, 88, 93, 15, 88, 69, 97, 35, 99, 83, 44, 15, 38},
//		{56, 21, 59, 1, 93, 34, 65, 98, 23, 65, 14, 81, 39, 82, 65, 78, 26, 20, 48, 98, 21, 70, 100},
//		{68, 1, 77, 42, 63, 3, 15, 47, 40, 31, 8, 31, 73, 11, 94, 63, 9, 98, 69, 99, 17, 85, 61},
//		{71, 22, 34, 68, 78, 55, 28, 70, 97, 94, 89, 26, 92, 40, 52, 86, 84, 48, 57, 67, 58, 16, 32},
//		{29, 9, 44, 3, 76, 71, 30, 76, 29, 1, 10, 91, 81, 8, 30, 9, 5, 43, 10, 66, 31, 36, 86},
//		{63, 28, 70, 17, 93, 74, 61, 32, 61, 53, 25, 13, 85, 56, 46, 55, 53, 60, 94, 7, 87, 84, 83},
//		{13, 8, 52, 94, 44, 14, 32, 25, 69, 58, 18, 55, 24, 36, 60, 32, 10, 57, 71, 13, 7, 70, 2}
//	};
	vector<vector<int>> mat ={{10,20,15},{21,30,14},{7,16,32}};

	Solution sl;
//	return sl.findPeakElement(nums);
//	return sl.findPeakGrid(*mat);
	vector<int> result = sl.findPeakGrid(mat);
	cout << result[0] << " " << result[1] << endl;
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
