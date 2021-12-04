#include <bits/stdc++.h>
using namespace std;

struct Node{
    pair<int, int> node; // in the form of (x, y)
    pair<int, int> delay; // in the form (-delay, traces)
};

void getShortestPath(pair<int, int> src, pair<int, int> dest, vector<vector<vector<Node>>> &graph){
    bool reachable = false;
    // use dijkstra's algorithm to find the shortest path
    // use Node.delay.first as the metric to find the shortest path
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, src}); // distance, node
    vector<vector<bool>> all_used(graph.size(), vector<bool>(4, false));
    vector<vector<int> > dist(graph.size(), vector<int>(4, INT_MAX));
    dist[src.first][src.second] = 0;
    vector<vector<pair<int, int>>> prev(graph.size(), vector<pair<int, int>>(4, {-1, -1}));
    while(!pq.empty()){
        pair<int, pair<int, int>> curr = pq.top(); // distance, node(x, y)
        pq.pop();
        if(all_used[curr.second.first][curr.second.second]){
            continue;
        }
        all_used[curr.second.first][curr.second.second] = true;
        if(curr.second.first == dest.first && curr.second.second == dest.second){
             reachable = true;
             break;
        }
        for(auto &nextNode: graph[curr.second.first][curr.second.second]){
            if(!all_used[nextNode.node.first][nextNode.node.second] && nextNode.delay.second != 0){
                // cout << "Next node: " << nextNode.node.first << " " << nextNode.node.second << endl;
                int newDist = curr.first + nextNode.delay.first;
                if(newDist < dist[nextNode.node.first][nextNode.node.second]){
                    dist[nextNode.node.first][nextNode.node.second] = newDist;
                    prev[nextNode.node.first][nextNode.node.second] = curr.second;
                    pq.push({-newDist, nextNode.node});
                    // cout << "Prev # Traces: " << nextNode.delay.second << endl;
                    nextNode.delay.second--;
                    // cout << "Remaining #Traces: " << nextNode.delay.second << endl;
                }
            }
        }
    }
    // print the path
    if(reachable){
        int curr_x = dest.first;
        int curr_y = dest.second;
        stack<pair<int, int>> path;
        // path.push({curr_x, curr_y});
        while(curr_x != src.first || curr_y != src.second){
            // cout << "(" << curr_x << "," << curr_y << ") ";
            path.push({curr_x, curr_y});
            curr_x = prev[curr_x][curr_y].first;
            curr_y = prev[curr_x][curr_y].second;
        }
        path.push({curr_x, curr_y});
        while(path.size() != 0){
            pair<int, int> curr = path.top();
            path.pop();
            cout << curr.second << "," << curr.first << " ";
        }
        // cout << "(" << curr_x << "," << curr_y << ") ";
        // break;
    }else{
        cout << "NC" << endl;
    }
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
    // generate a graph of size M x N nodes: each node is a pair of (x, y) coordinates
    vector<vector<vector<Node>>> graph(M, vector<vector<Node>>(N, vector<Node>()));
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
                temp_node.node = neighbour;
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
                temp_node.delay = make_pair(delay, traces);
                graph[n][m].push_back(temp_node);
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
        getShortestPath(src, dest, graph);
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