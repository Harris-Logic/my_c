#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
//		if(n==0) return 0;
		if(n==1) return {{1}};
		vector<vector<int>>mymatrix(n,vector<int>(n,0));
		int j=n-1;
		int nn=n*n;
		int loop = n/2;
		int k=1;
		while(k<nn){
			for(int l=0;l<4;++l){
				if(l==0)
					for(int i=n-1-j;i<j;++i){
						mymatrix[n-1-j][i]=k;
						++k;
					}
				else if(l==1)
					for(int i=n-1-j;i<j;++i){
						mymatrix[i][j]=k;
						++k;
					}
				else if(l==2)
					for(int i=j;i>n-1-j;--i){
						mymatrix[j][i]=k;
						++k;
					}
				else if(l==3)
					for(int i=j;i>n-1-j;--i){
						mymatrix[i][n-1-j]=k;
						++k;
					}
			}
			--j;
			
		}
		if(n%2 ==1) mymatrix[n/2][n/2]=n*n;
		return mymatrix;
	}
};

int main(){
	Solution sl;
	sl.generateMatrix(5);
	
	return 0;
}

