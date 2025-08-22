#include "bits/stdc++.h"
using namespace std;
//uniquePaths

class Solution {
public:
	int uniquePaths(int m, int n) {
		if(m==1 &&n==1) return 1;
		//dp[i][j]是当前从0,0到i,j矩阵有多少个路径
		vector< vector<int>> dp(m+1,vector<int>(n+1,0));
		
		dp[0][0]=1;//?
		for(int i=1;i<m;i++) dp[i][0]=1;
		for(int i=1;i<n;i++) dp[0][i]=1;
//		dp[0][1]=1;
//		dp[1][0]=1;
		dp[1][1]=2*dp[0][0];
		
		for(int i=1;i<m;i++){
			for(int j=1;j<n;++j){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];//dp[i][j]=2*dp[i-1][j-1];
			}
		}
		return dp[m-1][n-1];
	}
};
