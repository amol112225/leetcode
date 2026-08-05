class Solution {
public:
    void dfs(int node, vector<vector<int>>&invocations, vector<int>&vis){
        vis[node]=1;
        for(auto it: invocations[node]){
            if(!vis[it]) dfs(it,invocations,vis);
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        int m = invocations.size();
        for(int i=0; i<m; i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int>vis(n,0);
        dfs(k,adj,vis);
        vector<int>ans;
        for(int i=0; i<n; i++) ans.push_back(i);
        for(int i=0; i<m; i++){
            if(vis[invocations[i][0]]==0 && vis[invocations[i][1]]==1){
                return ans;
            }
        }
        vector<int>finalAns;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                finalAns.push_back(i);
            }
        }
        return finalAns;

    }
};