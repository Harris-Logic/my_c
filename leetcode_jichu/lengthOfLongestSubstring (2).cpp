#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char,int>charcount;//unordered_map<int> map;
		
		int maxsublenth=0;
		int i=0;
		int j=0;
		while(i<s.size()){
			charcount[s[i]]++;
			++i;
			if(charcount[s[i]]==2) break;
		}
		if(maxsublenth < i-j) {
			maxsublenth = i-j;
		}
		charcount;
		
		
		return 0;
	}
};
