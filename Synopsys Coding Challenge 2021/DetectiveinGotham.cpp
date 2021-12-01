#include <bits/stdc++.h>
using namespace std;

/*
Input Format

First line of input gives the number of cases you have to solve, T. T test cases follow.

Each test case begins with a single line containing two positive integers K and N. 
K is the number of keys you have at the begining & N is the number of rooms in the place.
This is followed by a line containing K integers, representing the types of the keys that you start with.
After that, there will be N lines, each representing a single room.
Each line will begin with integers Ti and Ki, 
Ti == indicating the key type needed to open the chest 
and Ki==the number of keys inside the chest. 
These two integers will be followed by Ki more integers, indicating the types of the keys contained within the chest.
*/

/*
Output Format

For each test case, output one line containing "Case #x: C1 C2 ... CN", 
where x is the case number (starting from 1), and where Ci represents the 
index (starting from 1) of the i th room that you should open.

used key cannot be used again.

If there are multiple ways of opening all the rooms, 
choose the "lexicographically smallest" way. i.e. make Ri small as possible. 
In above example, both 2, 1, 4, 3 and 2, 4, 3, 1 are will help to open all the doors. But print 2, 1, 4, 3 as the answer.
*/

vector<int> backtrack(vector<int>& path, vector<int>& keys_at_hand, map<int, int>& key_types, vector<vector<int>> rooms, int room, vector<bool>& visited, int N) {    
    if (path.size() == N) {
        return path;
    }

    vector<int> keys_inside = rooms[room];

    // if the room can not be opened, return empty vector
    if (!(find(keys_at_hand.begin(), keys_at_hand.end(), key_types[room]) != keys_at_hand.end())) return vector<int>();
    // if the room can be opeened, visit the room
    else {
        visited[room] = true; // mark as visited
        path.push_back(room); // add the room to the path
        // remove key from keys_at_hand
        keys_at_hand.erase(find(keys_at_hand.begin(), keys_at_hand.end(), key_types[room]));
        // add keys_inside to keys_at_hand
        keys_at_hand.insert(keys_at_hand.end(), keys_inside.begin(), keys_inside.end());
        // sort keys_at_hand
        sort(keys_at_hand.begin(), keys_at_hand.end());
        // recursively call backtrack
        for(int i=0; i<N; i++) {
            if (visited[i]) continue;
            else {
                path.push_back(i); // add newly visited room to the path
                // do the same for newly visited room
                vector<int> temp = backtrack(path, keys_at_hand, key_types, rooms, i, visited, N);
                if (temp.size() > 0) {
                    path.insert(path.end(), temp.begin(), temp.end());
                    return path;
                }
                else {
                    path.pop_back(); // remove newly visited room from the path
                    visited[i] = false; // mark as unvisited
                }
            }    
        }
    }
    return path;
}



int main(){

    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> K >> N;
        vector<int> keys(K); // type of keys that we start with
        for(int i=0;i<K;i++) cin >> keys[i];
        
        vector<vector<int>> rooms(N);
        map<int, int> key_types;
        for(int i=0;i<N;i++){
            int Ti, Ki;
            cin >> Ti >> Ki;
            key_types[i] = Ti; // type of key needed to open the chest
            for(int j=0;j<Ki;j++){
                int key;
                cin >> key;
                rooms[i].push_back(key); // type of key inside the chest
            }
        }
        vector<int> path;
        vector<bool> visited(N, false);
        bool all_rooms_visited = false;
        for(int start=0;start<N;start++){ // specify the room to start the investigation
            vector<int> keys_at_hand = keys;    
            // fucntion call to get the possible path to visit all the rooms
            vector<int> visited_path = backtrack(path, keys_at_hand, key_types, rooms, start, visited, N);
            if(visited_path.size() == N){
                all_rooms_visited = true;
                break;
            }
        }
        if(all_rooms_visited){
            cout << "Case #" << T+1 << ": ";
            for(int i=0;i<path.size();i++) cout << path[i] << " ";
            cout << endl;
        }
        else cout << "Case #" << T+1 << ": IMPOSSIBLE" << endl;

        
    }
    return 0;
}