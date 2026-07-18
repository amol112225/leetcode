class Solution {
public:
    bool bfs(int start,vector<vector<int>>& graph, vector<int>&color){
        int n = graph.size();
        queue<int>q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode : graph[node]){
                if(color[adjNode]==-1){
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode]==color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int>color(n,-1);
        for(int i=0; i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false) return false;
            }
        }
        return true;
    }
};