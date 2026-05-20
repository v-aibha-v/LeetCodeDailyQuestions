/*
 * @lc app=leetcode id=2657 lang=cpp
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        unordered_map<int, int> mp1, mp2;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            if (a[i] == b[i])
            {
                count++;
            }
            else
            {
                // cout<<i<<":" <<a[i]<<" "<<b[i]<<endl;
                mp1[a[i]]++;
                mp2[b[i]]++;
                unordered_map<int, int> mp3 = mp1;
                for (auto x : mp1)
                {
                    if (mp2.find(x.first) != mp2.end())
                    {
                        count++;
                        if (mp2[x.first] == 1)
                            mp2.erase(x.first);
                        else
                            mp2[x.first]--;
                        if (mp3[x.first] == 1)
                            mp3.erase(x.first);
                        else
                            mp3[x.first]--;
                    }
                }
                mp1 = mp3;
            }
            if (i == 0)
                ans[i] = count;
            else
                ans[i] = ans[i - 1] + count;
        }
        return ans;
    }
};
// @lc code=end
