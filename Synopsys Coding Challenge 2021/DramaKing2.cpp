#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &memo, int n, int w, vector<int>& v, int i, int sum) {
    
    if(sum==w) return 1; // if sum of weights is equal to w, then return 1

    if (i == n) { // if all the weights are exhausted, then return 0
        if (sum == w) return 1;
        return 0;
    }
    // if memo[i][sum] is not -1, then return memo[i][sum]
    if (memo[i][sum] != -1) return memo[i][sum];

    int ans = 0;
    for (int j = i; j < n; j++) {
        if (sum + v[j] <= w) {
            ans += dfs(memo, n, w, v, j + 1, sum + v[j]);
        }
    }
    memo[i][sum] = ans;
    return ans;
}

int main(){
    int n,w;
    cin >> n >> w;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    // use memoization to store the values to increase the efficiency
    // i and sum changes for every iteration
    // max of i and sum is n and w respectively
    // intialize the memoization array with -1
    vector<vector<int>> memo(n+1, vector<int>(w+1, -1));

    cout << dfs(memo, n,w,v,0,0);
    return 0;
    
}
// only 10.91/80 of the submissions on the leaderboard