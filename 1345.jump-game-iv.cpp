/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n=arr.size(),count=0;
        for(int i=0;i<n;i++) {
            if(mp.find(arr[i])!=mp.end()) mp[arr[i]].push_back(i);
            else mp[arr[i]]={i};
        }
        // for (auto x: mp){
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second) cout<<y<<" ";
        //     cout<<endl;
        // }
        vector<int> visited(n,-1);
        queue<int> qu;
        qu.push(0);qu.push(-1);
        while(not qu.empty()){
            if(qu.size()==1) break;
            int idx=qu.front();
            // cout<<idx<<" ";
            qu.pop();
            if(idx==-1) {count++;qu.push(-1);continue;}
            if(idx==n-1) return count;
            if(visited[idx]==0) continue;
            visited[idx]=0;
            // if(visited[idx]==0) continue;
            // if(idx==n-1) return count;
            // if(idx==-1) {count++;continue;}
            // visited[idx]=0;
            int prev=idx-1,next=idx+1;
            if(prev>=0 and visited[prev]!=0) qu.push(prev);
            if(next<n and visited[next]!=0) qu.push(next);
            for(auto x: mp[arr[idx]]){
                if(visited[x]!=0) qu.push(x);
            }
            mp.erase(arr[idx]);//   //IMPORTANT OPTIMIZATION
        }
        return 0;
    }
};
// @lc code=end

