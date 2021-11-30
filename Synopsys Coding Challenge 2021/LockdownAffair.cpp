#include <bits/stdc++.h>
using namespace std;

/*
Input Format

The first line contains two space seperate integers, N and E, denoting the number of nodes and edges

From second line onwards insert edges as two space seperated integers line by line until all edges are inserted. 
Then insert number of locked down areas(L) as integer. 
Then insert index of locked down areas line by line as integers while all locked down areas are inserted.
you can not visit any locked down area.

Output Format

Print number of areas that you pass to reach the destination. it should be the shortest route. 
Print -1 if you can't reach the destination.
*/

int main(){
    int n,e,l;
    cin>>n>>e; // number of nodes and edges
    vector<vector<int>> adj(n); // adjacency list of undirected graph 
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>l; // number of locked down areas
    vector<int> locked(l);
    for(int i=0;i<l;i++){
        cin>>locked[i];
    }

    vector<bool> visited(n,false); // visited nodes
    vector<int> parent(n,-1); // parent of nodes: parent of source is -1.
    bool flag=false; // flag to check if destination is reachable

    //---------------------------BFS to find whether destination is reachable or not--------------------------

    queue<int> q; // queue of nodes for BFS
    q.push(0); // starting node: You are always in first area 0 (0) Your fiance always in last area N-1 (9)
    visited[0]=true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i< (int)adj[u].size();i++){ // for all adjacent nodes
            int v=adj[u][i]; // consider one adjacent node
            if(visited[v]){ // if node is already visited then continue
                continue;
            }
            if(find(locked.begin(),locked.end(),v)!=locked.end()){ // if node is a locked down area then continue
                continue;
            }
            // if node is not visited and not locked then add it to queue and mark it visited
            visited[v]=true;
            q.push(v);
            parent[v]=u; // track parent of nodes to find shortest path
            if(v == n-1){ // if you reach the destination
                flag=true;
                break;
            }
        }
    }

    // ------if destination is reachable: find the minimum number of areas to pass to reach the destination------

    if(flag){ 
        int passed_areas = 0; // number of areas to pass  in order to reach destination
        int u=n-1; // start from the destination(n-1) node
        while(parent[u]!=-1){ // while source(0) is not reached: parent of source is -1  
            passed_areas++;
            u=parent[u];
        }
        cout<< passed_areas<<endl; // print number of nodes in shortest path 
    }else{
        cout<<-1<<endl; // if destination is not reachable
    }
    return 0;
}
