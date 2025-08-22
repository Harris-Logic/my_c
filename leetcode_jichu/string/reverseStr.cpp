#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	void myreverse(string& s, int begin, int end) {//(string s, int begin, int end)错误，必须是引用，不然改不了s里的元素
		for (int i = begin, j = end; i < j; ++i, --j) swap(s[i], s[j]);
	}
	string reverseStr(string s, int k) {
		int n = s.size();
		int j = k - 1;
		int l = k - 1;
		if (k == 0) return s;
		if (k == 1) return s;

		for (int i = 0; i < n; i = i + 2 * k) { //?
			if (i + k - 1 >= n - 1) myreverse(s, i, n - 1);
			else myreverse(s, i, i + k - 1);
		}
//
//		for(int i=0;i<n-k-k/2;++i){
//			while(j>i){
//				swap(s[i],s[j]);
//				--j;
//			}
//			l=l+2*k;
//			j=l;
//		}
		return s;
	}
};
