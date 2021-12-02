/*
Problem Definition:
Once upon a time there was a king who loved dramas. 
He built a new stage in his palace to visualize dramas. 
This stage can hold maximum of W weight. 
He bought up set of new rules to his citizens to fulfil 
his satisfaction by watching dramas. Followings were those rules.


Every day, there should be a new drama.
Every drama should have different combination of performers: no repetitions!
The stage should be fully occupied from W weight: deapth first search!

There are N number of people in the city and their weights are given.
Assuming all the people in the city (N) can perform dramas, how many days, this country will manage to present dramas to their king?
*/

#include <bits/stdc++.h>
using namespace std;

void getCombination(vector<int> array, int w, vector<int> &currentList, vector<vector<int>> &combinations, int sum, int index){
    if(sum>w) return;
    else if(sum==w){
        if(find(combinations.begin(), combinations.end(), currentList) == combinations.end()){
            combinations.push_back(currentList);
            // for(auto i:currentList) cout<<i<<" ";
            // cout<<endl;
            return;
        }       
    }
    else{
        for(int i=index; i<array.size(); i++){
            currentList.push_back(array[i]);
            getCombination(array, w, currentList, combinations, sum+array[i], i+1);
            currentList.pop_back();
        }
    }
}

int main(){
    int n,w;
    cin >> n >> w;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    // create a set using vector v
    set<int> s(v.begin(),v.end());
    // create a map to keep the count of numbers in the set
    map<int,int> m;
    for(auto i:s){
        m[i] = count(v.begin(),v.end(),i);
    }
    // use memoization to store the values to increase the efficiency
    // i and sum changes for every iteration
    // max of i and sum is n and w respectively
    // intialize the memoization array with -1
    // vector<vector<int>> memo(n+1, vector<int>(w+1, -1));
    
    vector<int> array;
    for(auto i:s){
        array.push_back(i);
    }

    vector<int> currentList;
    vector<vector<int>> combinations;
    int sum = 0;
    int index = 0;
    getCombination(array, w, currentList, combinations, sum, index);
    set<vector<int>> s1(combinations.begin(), combinations.end());
    // for(auto vec: combinations){
    //     for(int x:vec){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    int total_days = 0;
    for(auto vec: s1){
        int perm = 1;
        for(int i=0;i<vec.size();i++)
            perm *= m[vec[i]];
        total_days += perm; 
    }
    cout<<total_days<<endl;
    return 0;
}