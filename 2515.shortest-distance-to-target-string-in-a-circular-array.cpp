/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        if(words[start]==target) return 0;
        int mini=INT_MAX, n=words.size();
        for(int i=0;i<n;i++){
            int t=(start+i)%n,tt=(n+start-i) %n;
            if(words[t]==target) {
                if(start<t) mini=min(mini,t-start);
                else mini=min(mini,n-start+t);
            }
            if(words[tt]==target){
                if(start>tt) mini=min(mini,-tt+start);
                else mini=min(mini,n+start-tt);
            }
        }
       
        return mini==INT_MAX? -1: mini;
    }
};
// @lc code=end

