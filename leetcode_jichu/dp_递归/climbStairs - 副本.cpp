#include "bits/stdc++.h"
using namespace std;

class Solution {
public
	int climbStairs(int n) {
		 int countClimb = 0;
		 int count1bu = 0;
		 int count2bu = 0;
		if(n==0) return 0;
		if(n==1) return 1;
		if(n==2) return 2;
		vectorint dp(n + 1, 0);  vectorintdp(n+1)={0};int dp[n]={0};
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i  n+1; i++) {
			 TODO爬第n阶楼梯的方法数量，等于 2 部分之和：
						1、先爬一步，加上后面的n-1阶楼梯爬法
						2、先爬两步，加上后面的n-2阶楼梯爬法。
			dp[i] = dp[i - 1] + dp[i - 2];
		}
				(count1bu+ 2count2bu== n);
		
				countClimb=count1bu + count2bu;
		return dp[n];
	}
};
