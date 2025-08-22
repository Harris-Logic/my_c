#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	void myreverse(string& s, int l, int r) {
		for (int i = l, j = r; i < j; ++i, --j) swap(s[i], s[j]);
	}
	string reverseWords(string s) {

		int fast = 0;
		int slow = 0;
		while (fast < s.size()) {
			if (s[fast] == ' ') {
				++fast;
			} else {
				s[slow] = s[fast];
				++slow;
				++fast;
				break;
			}
		}

		while (fast < s.size()) {
			if (s[fast] == ' ' && s[fast - 1] == ' ') { //要删，slow不动，准备着等下一个不删的元素
				++fast;
			} else {
				s[slow] = s[fast];
				++slow;
				++fast;
			}
		}

		if (s[slow-1] == ' ') {//单独处理末尾多个空格的情况
			s.resize(slow - 1);
		} else {//正常处理，末尾空格全连续，无单独空格
			s.resize(slow);
		}


		fast = 0;
		slow = 0;

		while (fast < s.size()) {
			++fast;
			if (s[fast] == ' ') {
				myreverse(s, slow, fast - 1);
				slow = fast + 1;
			} else {

			}
		}
		myreverse(s, slow, s.size() - 1);//最后一个单词未被处理，需要循环结束后单独处理

		myreverse(s, 0, s.size() - 1);
		return s;
//		while(fast<s.size()){
//			if(s[fast]==' ') {
//				++fast;
//			}else {
//				s[slow]=s[fast];
//				++slow;
//				++fast;
//			}
//		}


//		bool seckonggeflag=false;
//		int countkongge=0;
//		for(int i=0;i<s.size();++i){
//			if(s[i]==' ')
//				++countkongge;
//		}

//		int countwords=0;
//		for(int i=0;i<s.size();++i){
//			if(isalpha(s[i])==1){
//
//			}
//		}
	}
};

int main() {
	string s = "  hello world  "; //="  the sky is blue ";

	Solution sl;
	cout << sl.reverseWords(s) << endl;

	return 0;
}
