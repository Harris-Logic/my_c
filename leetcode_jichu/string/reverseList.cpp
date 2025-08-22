#include "bits/stdc++.h"
using namespace std;
///**
// * Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// */

class Solution {
public:
	ListNode* myreverse_itr(ListNode* head) {
		ListNode* pre = head;
		if (pre == nullptr) return head;
		ListNode* cur = head->next;
//		if(pre==nullptr) return head;
		if (cur == nullptr) return head;

		while (cur != nullptr) {
			ListNode* tmp = cur->next;
			cur->next = pre; //断开连接

			if (pre == head) pre->next = nullptr;

			pre = cur;
			cur = tmp;
		}
		return pre;
	}
	ListNode* myreverse_digui(ListNode* pre,ListNode* cur){
		if(cur==nullptr) return pre;
		
		ListNode* tmp=cur->next;
		cur->next=pre;
//		pre=cur;
//		cur=tmp;
		
		return myreverse_digui(cur,tmp);		
	}
//	ListNode* myreverse_digui(ListNode* head, ListNode* pre, ListNode* cur) {
////		ListNode* cur = pre->next;
//		if(cur==nullptr) return pre;
//		if(cur->next==nullptr) {
//			cur->next=pre;
//			return pre;
//		}
//		ListNode* tmp = cur->next;
////		ListNode* pre=head;
//
//		if (pre == head) pre->next = nullptr;
//
//		cur->next = pre;
//		pre = cur;
//
//		return myreverse_digui(head, cur, tmp);
//
//	}
	ListNode* myreverse_last(ListNode* head){
		if(head==nullptr) return nullptr;
		if(head->next==nullptr) return head;
		
		ListNode* last=myreverse_last(head->next);
		
		ListNode* tmp= head->next;
		tmp->next=head;
		//递归处理到这里的时候，递归结束，head为尾节点，head->next置为空。
		head->next=nullptr;
		return last;
	}
	ListNode* reverseList(ListNode* head) {
//		if(head->next==nullptr) return head;
		
//		return myreverse_itr(head);
//		return myreverse_digui(nullptr,head);//(head,head,head->next);
		return myreverse_last(head);

//		ListNode* itnode=head;
//		int i=0;
//		for(;itnode!=nullptr;i++){
//			itnode=itnode->next;
//		}
//		const int n=i;
//		vector<vector<ListNode*>>dp(n,vector<ListNode*>(n,nullptr));//list< ListNode*<ListNode*>>dp;//vector<ListNode> dp();
////		dp.insert()
//		//dp[i][j]是把头结点为i的链表反转了之后的链表,j是i->next
//		ListNode* cur=head->next;
//		ListNode* pre=head;
//
//		dp[]
//		if(cur==nullptr) return pre;
//		ListNode* tmp=cur->next;
//		cur->next=pre;
//
//		dp[pre][cur]=dp[cur][tmp];
	}
};
