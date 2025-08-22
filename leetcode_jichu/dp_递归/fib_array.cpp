#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int fib(int n) {
		if(n==0) return 0;
		if(n==1) return 1;
		
		vector<vector<int>> dp(n,vector<int>(n,0));//?
//		dp[i][j]j是斐波那契数列的当前深度，i是0到1表示是否访问过。
		dp[0][0]=0;
		dp[0][1]=1;
		int i=0;
		for(int j=2;j<n;j++){
			dp[i][j]=dp[i][j-1]+dp[i][j-2];
		}
		return dp[i][n];
		
		
	}
};


