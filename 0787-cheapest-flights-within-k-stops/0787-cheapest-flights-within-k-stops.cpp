class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>price(n,1e9);
        price[src] = 0;
        q.push({0,{src,price[src]}});
       
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int p = q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjP = it.second;
                if(adjP+p<price[adjNode] && stops<=k){
                    price[adjNode] = adjP+p;
                    q.push({stops+1,{adjNode,price[adjNode]}});
                }
            }

        }
        if(price[dst]==1e9) return -1;
        return price[dst];
    }
};