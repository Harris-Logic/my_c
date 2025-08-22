#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		vector<int> dp(n + 1, 0);
		//		dp[i] dp是爬法数，i是指考虑当前共有i阶楼梯时，
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2; // 两个1，或者一个2
		
		// dp[3] = 1 * dp[2] + 2 * dp[1];
		for (int i = 3; i <= n; ++i) {
			dp[i] = 1 * dp[i - 1] + 1 * dp[i - 2];
		}
		return dp[n];
	}
};
