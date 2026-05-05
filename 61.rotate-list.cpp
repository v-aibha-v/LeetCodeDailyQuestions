/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
/**
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode *help(ListNode*head){
    //     ListNode*temp=head;
    //     while(temp and temp->next and temp->next->next){
    //         temp=temp->next;
    //     }
    //     ListNode*a = temp->next;
    //     temp->next=nullptr;
    //     a->next=head;
    //     return a;
    // }
    int size(ListNode*head){
        ListNode*temp=head;
        int s=1;
        while(temp and temp->next){
            temp=temp->next;
            s+=1;
        }
        return s;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)return head;
        // for(int i=0;i<k;i++){
        //     head=help(head);
        // }
        int siz=size(head);
        // cout<<siz;
        k=k%siz;
        if(k==0)return head;
        siz=siz-k;
        ListNode *temp=head;
        for(int i=0;i<siz-1;i++){
            temp=temp->next;
        }
        ListNode*a=temp->next,*ans=a;
        temp->next=nullptr;
        while( a and a->next){
            a=a->next;
        }
        a->next=head;
        return ans;
    }
};
// @lc code=end

