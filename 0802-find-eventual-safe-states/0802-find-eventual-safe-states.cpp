class Solution {
public:
    bool dfscheck(int node,vector<vector<int>>& graph,vector<int>&vis, vector<int>&pathVis,vector<int>&check){

        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfscheck(it,graph,vis,pathVis,check)==true) return true;
            }
            else if(pathVis[it]==1){
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int>vis(m,0);
        vector<int>pathVis(m,0);
        vector<int>check(m,0);

        for(int i=0; i<m; i++){
            if(!vis[i]){
                dfscheck(i,graph,vis,pathVis,check);
            }
        }
        vector<int>safeNode;
        for(int i=0; i<m; i++){
            if(check[i]==1) safeNode.push_back(i);
        }
        return safeNode;
    }
};