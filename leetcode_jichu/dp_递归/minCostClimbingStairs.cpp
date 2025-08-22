#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n=cost.size();
		
		if(n<=1) return 0;
		if(n==2) return min(cost[0],cost[1]);
		//dp[i][j]是爬i阶楼梯所需要的最小花费，i是当前考虑i阶楼梯时，j是？
//		vector<vector<int>> dp(n+1,vector<int>(1,INT_MAX));
		vector<int>dp(n+1,INT_MAX);
		
		dp[0]=0;dp[1]=0;
		dp[2]=min(cost[1],cost[0]);//初始化
//		dp[3]=min(dp[2]+cost[2],cost[1]);
//		
//		dp[4]=min(dp[3]+cost[3],dp[2]+cost[2]);
		for(int i=3;i<=n;++i){
			dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
		}
		return dp[n];
	}
};
