# define pr pair<int, int>
class Compare{
    public:
    bool operator() (pr p1, pr p2){
        return p1.first > p2.first;
    }
};

void dijkstra(vector<vector<pr>> &adj, vector<int> &dist, int n, int s) {
    priority_queue<pr, vector<pr>, Compare> pq;
    vector<bool> vis(n, false);
    int i;

    pq.push({0, 0}); 
    int finalized =  0;
        
    while(!pq.empty() && finalized < n) {
        pr curr = pq.top();
        pq.pop();
        int node = curr.second;
        
        if(vis[node]) continue;
        vis[node] = true;
        int currDist = curr.first;
        dist[node] = currDist;
        finalized++;
        
        for(i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i].first;
            if(vis[next]) continue;
            int edgeLen = adj[node][i].second;
            pq.push({currDist + edgeLen, next});
        }
    }
}

void edgesToAdjList(vector<vector<int>> &edges, vector<vector<pr>> &adj) {
    int n = adj.size();
    int e = edges.size();
    int i;
    for(i = 0; i < e; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int currDist = edges[i][2] + 1;
        adj[src].push_back({dest, currDist});
        adj[dest].push_back({src, currDist});
    }
}


