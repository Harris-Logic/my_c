#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;
	cin >> s;

	int sOldendIndex = s.size() - 1;

	int countnum = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] >= '0' && s[i] <= '9') countnum++;
	s.resize(s.size() + 5 * countnum);

	int sNewendIndex = s.size() - 1;
	
//		当数组需要变小时，双指针的遍历方向是++
//		当数组需要变大时，双指针的遍历方向是--
	
	while (sOldendIndex>=0) {
		if (s[sOldendIndex] >= '0' && s[sOldendIndex] <= '9') {
			s[sNewendIndex--] = 'r';
			s[sNewendIndex--] = 'e';
			s[sNewendIndex--] = 'b';
			s[sNewendIndex--] = 'm';
			s[sNewendIndex--] = 'u';
			s[sNewendIndex--] = 'n';
		} else {
			s[sNewendIndex] = s[sOldendIndex];
			--sNewendIndex;
		}
		--sOldendIndex;
	}

//	for(int i=0,j=0;i<s.size();++i,++j){
//
//		if(isdigit(s[j])){
//			int k=i+6;
//			s.erase(j);
//			s.insert(j,"number");
//			j=j+6;
//		}
//	}
	cout << s << endl;
	return 0;
}
