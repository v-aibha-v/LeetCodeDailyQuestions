/*
 * @lc app=leetcode id=3741 lang=cpp
 *
 * [3741] Minimum Distance Between Three Equal Elements II
 */

// @lc code=start
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size(),mini=INT_MAX;
        for(int i=0;i<n;i++){
            //nothing is present in the vector
            if(mp[nums[i]].size()==0){ 
                mp[nums[i]].push_back(1);//initiated the value since element is added
                mp[nums[i]].push_back(i);
                }
            else{
                //element is al ready present
                mp[nums[i]][0]++;//inc val
                mp[nums[i]].push_back(i);
                if(mp[nums[i]][0]>=3){//if the size is valid
                    int m=mp[nums[i]].size()-1;
                    int a=mp[nums[i]][m],b=mp[nums[i]][m-2];
                    mini=min(mini,2*(a-b));
                }
            }
        }
        return mini==INT_MAX? -1: mini;
    }
};
// @lc code=end

