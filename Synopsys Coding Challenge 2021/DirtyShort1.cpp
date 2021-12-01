#include <bits/stdc++.h>
using namespace std;


int main(){
    int T,I,C;
    cin>>T;
    while(T--){
        cin>>I>>C;
        vector<vector<int>> v(I,vector<int>(I,0)); // 0 means no connection, 1 means connection: adjacency matrix
        for(int i=0;i<C;i++){
            int a,b;
            cin>>a>>b;
            v[a-1][b-1]=1; // a is the output of inverter gate a, b is the input of inverter gate b
        }
        bool flag=false;
        for(int i=0;i<I;i++){
            for(int j=0;j<I;j++){
                if(v[i][j]==1){ // if there is a connection between i and j
                    // check if there is any connection between ancestors of i and predecessors of j
                    // such that the number of connections between any ancestor and a predecessors is even
                    // if there is such a connection, then there is a dirty short
                    for(int k=0;k<I;k++){
                        if(v[k][i]==1 && v[k][j]==1){
                            flag=true;
                            break;
                        }
                    }
                    

                }
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}