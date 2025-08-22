#include "bits/stdc++.h"
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
//lengthOfLongestSubstring

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char,int> char_map;
		int maxlength_ = 0 ;
//		int left_,right_ = 0;//非常容易错的初始化
		int left_ =0;
		int right_ =0;
		
		if(s.size() <= 1) return s.size();  // 同时处理空串和单字符情况
		for(right_=0; right_ <= s.size() - 1; right_++){//非常容易错的 边界条件判定
//		for(right_=0; right_ < s.size(); right_++){
			char currchar_= s[right_];
			

			if(char_map.find(currchar_) != char_map.end() && char_map[currchar_] >= left_ ){//当遇到重复字符时，如果该字符上次出现的位置在当前窗口内，则将left移动到该位置的下一位。
				left_=char_map[currchar_] + 1;
			}
			
			char_map[currchar_] = right_;//更新当前字符 最新位置
			
			maxlength_ = max(maxlength_, right_ - left_ + 1);//计算当前窗口长度，更新最大子串长度值			
		}
		
		return maxlength_;
	}
};


//		unordered_map<char, int> charMap; // 存储字符及其最新出现的位置
//		int maxLength = 0;
//		int left = 0; // 滑动窗口的左边界
//		
//		for (int right = 0; right < s.size(); right++) {
//			char currentChar = s[right];
//			
//			// 如果字符已经在哈希表中，并且其位置在窗口内，则移动左边界
//			if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left) {
//				left = charMap[currentChar] + 1;
//			}
//			
//			// 更新字符的最新位置
//			charMap[currentChar] = right;
//			
//			// 计算当前窗口长度并更新最大值
//			maxLength = max(maxLength, right - left + 1);
//		}
//		
//		return maxLength;
