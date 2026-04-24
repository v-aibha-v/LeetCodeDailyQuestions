/*
 * @lc app=leetcode id=2833 lang=cpp
 *
 * [2833] Furthest Point From Origin
 */

// @lc code=start
class Solution {
public:
    // int maxi=0;
    // void rec(string & moves,int idx, int sum ,int n){
    //     if(idx>=n){
    //         maxi=max(maxi,abs(sum));
    //         return;
    //     }
    //     if(moves[idx]=='L') rec(moves,idx+1,sum+1,n);
    //     else if(moves[idx]=='R') rec(moves,idx+1,sum-1,n);
    //     else{
    //         rec(moves,idx+1,sum-1,n);
    //         rec(moves,idx+1,sum+1,n);
    //     }
    // }
    int furthestDistanceFromOrigin(string moves) {
        // rec(moves,0,0,moves.size());
        // return maxi;
        int n=moves.size();
         vector<int> dpp(n+1,0);
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(moves[i-1]=='L') dp[i]=1+dp[i-1];
            // else if(moves[i-1]=='R') dp[i]=dp[i-1]-1;
            // else dp[i]=max(dp[i-1]-1,1+dp[i-1]);
            else dp[i]=dp[i-1] -1;
            if(moves[i-1]=='R')  dpp[i]=dpp[i-1] -1;
            else dpp[i]=1+dpp[i-1];
            
        }
        //  vector<int> dpp(n+1,0);
        // for(int i=1;i<=n;i++){
        //     if(moves[i-1]=='R')  dpp[i]=dpp[i-1] -1;
        //     // else if(moves[i-1]=='R') dpp[i]=dpp[i-1]-1;
        //     // else dpp[i]=max(dpp[i-1]-1,1+dpp[i-1]);
        //     else dpp[i]=1+dpp[i-1];
        // }
        return max(abs(dp[n]),abs(dpp[n]));
    }
};
// @lc code=end

