#include <bits/stdc++.h>
using namespace std;


int findParent(int x, vector<int> &parent){
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x], parent);
}


void unionSet(int a, int b, vector<int> &parent, vector<int> &rankv){

    a = findParent(a, parent);
    b = findParent(b, parent);

    if(a != b){
        if(rankv[a] < rankv[b])
            parent[a] = b;
        else if(rankv[b] < rankv[a])
            parent[b] = a;
        else{
            parent[b] = a;
            rankv[a]++;
        }
    }
}


int kruskalMST(int V, vector<vector<int>> &edges){

    vector<int> parent(V), rankv(V,0);

    for(int i=0;i<V;i++)
        parent[i] = i;


    sort(edges.begin(), edges.end(),
        [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });

    int sum = 0;

    for(auto &e : edges){

        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(findParent(u,parent) != findParent(v,parent)){
            sum += w;
            unionSet(u,v,parent,rankv);
        }
    }

    return sum;
}

int main(){

    int V = 4;

    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    cout << "MST Sum = " << kruskalMST(V,edges);

    return 0;
}