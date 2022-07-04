   bool c(int i, vector<int> adj[],vector<bool> vis){
        queue<pair<int,int>>q;
        vis[i]=true;
        q.push({i,-1});
        while(!q.empty()){
            int node= q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(vis[it]==false){
                    q.push({it,node});
                }
                else if(vis[it]==true && par!=node){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V+1,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                 if (c(i,adj,vis)==true){
                     return true;
                     
                 }
                
            }
        }
        return false;
        // code here
    }