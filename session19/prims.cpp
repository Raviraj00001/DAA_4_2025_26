#include <bits/stdc++.h>
using namespace std;
int primMST(int V, vector<vector<int>> &edges)
{
 
    vector<vector<pair<int,int>>> adj(V);

    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> visited(V,0);

    pq.push({0,0}); 

    int sum = 0;

    while(!pq.empty()){

        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node])
            continue;

        visited[node] = 1;

        sum += wt;

        for(auto &it : adj[node]){
            int adjNode = it.first;
            int adjWt = it.second;

            if(!visited[adjNode]){
                pq.push({adjWt, adjNode});
            }
        }
    }

    return sum;
}

int main()
{
    int V = 4;

    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    cout << "MST Sum = " << primMST(V, edges);

    return 0;
}