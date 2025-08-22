#include "bits/stdc++.h"

using namespace std;

void bagging(vector<int>spaceused, vector<int>value, vector<int>path, int size, vector<vector<int >> ans) {
	vector<vector<int>> dp;

}

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> spaceused(m);
	for (int i = 0; i < m; i++) {
		//TODO
		cin >> spaceused[i];
	}

	vector<int> value(m);
	for (int i = 0; i < m; i++) {
		cin >> value[i];
	}

	vector<vector<int>>dp(spaceused.size(), vector<int>(n+1, 0)); //(m,vector<int>(m,0));//vector<vector<int>> dp(m,m,0);
//	dp[1][4]=max(dp[0][4],dp[0][4-spaceused[1]]+value[1]);

	for (int j = spaceused[0]; j <= n; ++j) { //dp[0][0];初始化，n是输入的小明包的总容量空间，spaceused[0]是第一个物品的占用容量空间
		dp[0][j] = value[0];
	}

	// int result=0;
	for (int i = 1; i < spaceused.size(); ++i) { //for(int i=0;i<m;++i){
		for (int j = 0; j <= n; ++j) { //(int j=value[i];j<=n;++j){
			if (j < spaceused[i]) dp[i][j] = dp[i - 1][j];  //如果 i个东西占用空间比 当前所有可用背包空间都要大，
												            //就只能让dp[i][j]可以装的最大价值 等同于前i-1个东西在可用背包空间j时，
														    //背包里所能装载的最大价值
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - spaceused[i]] + value[i]);
			// result=dp[i][j];
		}
	}
	cout << dp[m - 1][n] << endl; //cout<<result<<endl;//dp[i][j]<<endl;

	return 0;
}

