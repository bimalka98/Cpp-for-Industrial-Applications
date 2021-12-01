/*
Problem:
There is a static check requested by a leading chip design company and you are given this task to drive.
Normally multi-driven nets are not recommended in designs since it can cause unintended behaviors. 
However, the customer is giving an exception to this by accepting multi-driven nets as long as 
different polarities are not applied at the convergence point which could potentially cause a short. 
Customer named this scenario as 'Clean-Short' (CS). When different polarities applied, 
it is called 'Dirty-Short' (DS).

Input Format

Number of Test scenarios T
Number of inverters I and Number of connections between them C
C number of lines having two numbers i and j (0 < i,j <= I) separated by a single space representing 
a connection between ith inverter gate's output and jth inverter gate's input

Output Format

Print T lines of 'YES' or 'NO' for each Test scenario.
Print 'YES' if the design has atleast one DS.
Print 'NO' otherwise.

*/
#include <bits/stdc++.h>
using namespace std;

struct MyData{
    int dist;
    vector<int> predecessors;
};

MyData get_data(int node1, int node2, vector<vector<int>> &graph, vector<int> nodes_to_avoid) {
    MyData data; 
    bool reacheable = false;
    vector<int> parent(graph.size(), -1);
    queue<int> q;
    q.push(node1);
    vector<bool> visited(graph.size(), false);
    visited[node1] = true;
    // BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i <(int) graph[node].size(); i++) {
            // parent[graph[node][i]] = node;
            if(find(nodes_to_avoid.begin(), nodes_to_avoid.end(), graph[node][i]) != nodes_to_avoid.end()) {
                continue;  
            }
            if (graph[node][i] == node2) {
                parent[graph[node][i]] = node;
                reacheable = true;
                break;
            }
            if (!visited[graph[node][i]]) {
                visited[graph[node][i]] = true;
                q.push(graph[node][i]);
                parent[graph[node][i]] = node;
            }
        }
    }
    data.predecessors = parent;

    if (!reacheable) {
        data.dist = -1;
    }else{
        int distance = 0;
        int node = node2;
        while (parent[node] != -1) {
            distance++;
            node = parent[node];
        }
        data.dist = distance;
    }  
    return data; 
}

vector<int> getParents(int node, vector<vector<int>> &graph) {
    vector<int> parents;
    for(int i=1; i<(int)graph.size(); i++) {
        if(find(graph[i].begin(), graph[i].end(), node) != graph[i].end()) {
            parents.push_back(i);
        }
    }
    return parents;
}

int main(){
    int T,I,C;
    cin>>T;
    while(T--){
        cin>>I>>C;
        vector<vector<int>> adj(I+1);
        while(C--){
            int i,j;
            cin>>i>>j;
            adj[i].push_back(j); // creating the directed graph 
        }
        bool hasDirtyShort = false; // flag to check if there is a dirty short
        for(int i=1;i<=I;i++){
            for(int j=1;j<=I;j++){
                if(i!=j){
                    vector<int> nodes_to_avoid = {};
                    MyData data = get_data(i,j,adj, nodes_to_avoid);
                    // debugging
                    cout << "source: " << i << " dest: " << j << " Distance1: " << data.dist << endl;
                    // for(int k=0;k<(int)data.predecessors.size();k++){
                    //     cout << data.predecessors[k] << " ";
                    // }
                    // cout << endl;

                    if(data.dist!=-1){ // if distance is not -1, then there is a connection between i and j
                        vector<int> parents = getParents(i,adj);
                        // debugging
                        cout << "Parents: ";
                        for(int parent: parents) {
                            cout << parent << " ";
                        }
                        cout << endl;
                        // int predecessor = data.predecessors[i];
                        // check there is a connection between prdecessor of i and successor of j
                        if(parents.size()>0){                        // if(predecessor!= -1){
                            for(int parent: parents){
                                for(int successor: adj[j]){ // for each successor of j
                                    vector<int> nodes_to_avoid = {i,j};
                                    MyData data2 = get_data(parent,successor,adj, nodes_to_avoid);
                                    // debugging
                                    cout << "pred: " << parent << " succes: " << successor << " Distance2: " << data2.dist << endl;
                                    // for(int k=0;k<(int)data2.predecessors.size();k++){
                                    //     cout << data2.predecessors[k] << " ";
                                    // }
                                    // cout << endl;
                                    if(data2.dist!=-1 && data2.dist%2==0){
                                        hasDirtyShort = true;
                                        break;
                                    }
                                }
                            }    
                        }   
                    }
                }
            }
        }
        if(hasDirtyShort)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}