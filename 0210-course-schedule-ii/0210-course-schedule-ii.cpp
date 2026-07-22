class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&pathVis,stack<int>&st){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,st)==true)  return true;
            }
            else if(pathVis[it]==1) return true;
        }
        
        pathVis[node]=0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>&prerequisites) {
        vector<vector<int>> adj(n);

        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        
        stack<int>st;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis,st)==true) return {};
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};