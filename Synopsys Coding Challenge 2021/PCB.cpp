#include <bits/stdc++.h>
using namespace std;

struct Node{
    pair<int, int> node;
    int cost;
};

void getShortestPath(pair<int, int> src, pair<int, int> dest, vector<vector<Node>> &graph){
    //dijkstra's algorithm to find the shortest path from src to dest using priority queue

}

int main(){
    // get M rows and N columns
    int M, N;
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
    // generate a graph of size M x N
    vector<vector<Node>> graph(M, vector<Node>(N));

    // test cases starting from here onward
    string start, end; // in the form: x1,y1 x2,y2
    while(cin >> start >> end) {
        // get the starting and ending point
        pair<int, int> src = {stoi(start.substr(0, start.find(','))), stoi(start.substr(start.find(',') + 1))};
        pair<int, int> dest = {stoi(end.substr(0, end.find(','))), stoi(end.substr(end.find(',') + 1))};
        // cout << "Start: " << start_point.first << "," << start_point.second << endl;
        // cout << "End: " << end_point.first << "," << end_point.second << endl;
    }
}