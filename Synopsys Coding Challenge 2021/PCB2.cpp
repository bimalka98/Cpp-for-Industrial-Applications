#include <bits/stdc++.h>
using namespace std;

struct Node{
    int node;
    int delay; 
    int traces;
};

void getShortestPath(vector<vector<Node>> &graph, int source, int destination, map<int, pair<int, int>> &node_map_rev){
    // dijkstra's algorithm
    bool reachable = false;
    vector<int> dist(graph.size(), INT_MAX);
    vector<int> prev(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(u == destination){
            reachable = true;
            break;
        }
        if(visited[u]) continue;
        visited[u] = true;
        for(int i = 0; i < (int)graph[u].size(); i++){
            int v = graph[u][i].node;
            int w = graph[u][i].delay;
            int &t = graph[u][i].traces;
            if(dist[v] > dist[u] + w && t > 0){
                dist[v] = dist[u] + w;
              prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if(reachable){
        stack<int> path;
        int u = destination;
        while(u != -1){
            path.push(u);
            u = prev[u];
        }
        // path.push(source);
        // while(!path.empty()){
        //     cout << node_map_rev[path.top()].first << "," << node_map_rev[path.top()].second << " ";
        //     path.pop();
        // }
        u = path.top();
        path.pop();
        while(!path.empty()){
            // get first two nodes
            cout << node_map_rev[u].first << "," << node_map_rev[u].second << " ";
            int v = path.top();
            path.pop();
           // check if the two nodes are in the same row
            if(node_map_rev[u].first == node_map_rev[v].first){
                // if yes, then the path is horizontal
                // reduce the traces by one if the nbr is horizontal
                for(auto &nbr: graph[u]){
                    if(node_map_rev[u].first == node_map_rev[nbr.node].first){ // horizontal nbrs
                        nbr.traces--;
                    }
                }
            }
            else{
                // if no, then the path is vertical
                // reduce the traces by one if the nbr is vertical
                for(auto &nbr: graph[u]){
                    if(node_map_rev[u].second == node_map_rev[nbr.node].second){ // vertical nbrs
                        nbr.traces--;
                    }
                }
            }
            u = v;
        }
        cout << node_map_rev[u].first << "," << node_map_rev[u].second << endl;
    }
    else cout << "NC" << endl;

}
int main(){
    // get M rows and N columns
    int M, N; // m corresponds to y and n corresponds to x in the form of (x, y)
    cin >> M >> N;
    // get (Nht) number of horizontal, and (Nvt) number of vertical copper traces
    int Nht, Nvt;
    cin >> Nht >> Nvt;
    // horizontal direction: get the weights given by a matrix of size M x (N -1)
    vector<vector<int>> ht(M, vector<int>(N - 1));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> ht[i][j];
        }
    }
    // vertical direction: get the weights given by a matrix of size (M -1) x N
    vector<vector<int>> vt(M - 1, vector<int>(N));
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vt[i][j];
        }
    }
    // coordinates to node mapping
    int node = 0;
    map<pair<int, int>, int> node_map;
    map<int, pair<int, int>> node_map_rev;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            node_map[{n, m}] = node;
            node_map_rev[node] = {n, m};
            node++;
        }
    }
    // cout << "Node map: " << endl;
    // for (auto it = node_map.begin(); it != node_map.end(); it++) {
    //     cout << it->first.first << "," << it->first.second << " " << it->second << endl;
    // }
    // cout << "Generating graph..." << endl;
    // generate a graph of size M x N nodes: each node is a pair of (x, y) coordinates
    vector<vector<Node>> graph(M*N, vector<Node>(4));
    for(int m=0; m<M; m++){ 
        for(int n=0; n<N; n++){// itertae over x direction first
            // parent node is the node itself
            pair<int, int> parent = make_pair(n, m); // in the form of (x, y)
            // cout << "parent: " << parent.first << " " << parent.second << endl;
            // set of neighbour nodes
            set<pair<int, int>> neighbours;
            neighbours.insert(parent);
            neighbours.insert(make_pair(min(n + 1, N - 1), m)); // right neighbour
            neighbours.insert(make_pair(max(n - 1, 0), m)); // left neighbour
            neighbours.insert(make_pair(n, min(m + 1, M - 1))); // top neighbour
            neighbours.insert(make_pair(n, max(m - 1, 0))); // bottom neighbour
            // remove the parent node from the set of neighbours
            neighbours.erase(parent);
            // set the delay of each neighbour node to be the weight of the edge between the parent and the neighbour
            for(auto neighbour : neighbours){
                // cout << "neighbour: " << neighbour.first << " " << neighbour.second << endl;
                Node temp_node;
                temp_node.node = node_map[neighbour];
                int delay;
                int traces;
                if(neighbour.second == m){ // neighbour is in the same row
                    // delay = ht[M-1 - neighbour.second][neighbour.first -1];
                    // delay = ht[m][neighbour.first - 1];
                    // cout << "Same row: ";
                    delay = ht[M-1 -m][abs(max(parent.first, neighbour.first) -1)];
                    traces = Nht;
                    // cout << "delay: " << delay << endl;
                    
                }
                else{ // neighbour is in the same column
                    // delay = vt[M-1 - neighbour.second][neighbour.first];
                    // delay = vt[m][neighbour.first];
                    // cout << "Same column: ";
                    delay = vt[abs(M-1-max(neighbour.second, parent.second))][neighbour.first];
                    traces = Nvt;
                    // cout << "delay: " << delay << endl;
                }
                // cout << "Delaay: " << delay << "Traces: " << traces << endl;
                temp_node.delay = delay;
                temp_node.traces = traces;
                // cout << "Creating the node..." << endl;
                // cout << "Parent Coo: " << parent.first << " " << parent.second << endl;
                // cout << "Parent Ind: " << node_map[parent] << endl;
                graph[node_map[parent]].push_back(temp_node);
                // cout << "Node created." << endl;
            }
        }
    }
    // cout << "graph generated" << endl;

    // print the graph
    // for(int m=0; m<M; m++){
    //     for(int n=0; n<N; n++){
    //         cout << "Node: (" << n << ", " << m << ") " << endl;
    //         cout << "Neighbours: " << endl;
    //         for(auto neighbour : graph[n][m]){
    //             cout << "(" << neighbour.node.first << ", " << neighbour.node.second << ") ";
    //             cout << "Delay: " << neighbour.delay.first << " " << "Traces: " << neighbour.delay.second << endl;
    //         }
    //     }
    //     cout << endl;
    // }

    // test cases starting from here onward
    string start, end; // in the form: x1,y1 x2,y2
    while(cin >> start >> end) {
        // get the starting and ending point
        pair<int, int> src = {stoi(start.substr(0, start.find(','))), stoi(start.substr(start.find(',') + 1))};
        pair<int, int> dest = {stoi(end.substr(0, end.find(','))), stoi(end.substr(end.find(',') + 1))};
        // cout << "Start: " << start_point.first << "," << start_point.second << endl;
        // cout << "End: " << end_point.first << "," << end_point.second << endl;
        getShortestPath(graph, node_map[src], node_map[dest], node_map_rev);
    }
}

/*
3 3
3 4
5 4
3 2
7 5
3 5 2
4 8 1
*/