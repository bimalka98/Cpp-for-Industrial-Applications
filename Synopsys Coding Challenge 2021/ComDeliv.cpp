#include <bits/stdc++.h>
using namespace std;

/*
Input Format
Number of KFC outlets N1
N1 space seperated weights from KFC outlets
Number of BurgerKing outlests N2
N2 space seperated weights from BurgerKing outlets
Capacity of the vehicle : K
*/


int main(){
    int n1,n2,k;
    cin>>n1; //number of KFC outlets
    int w1[n1];
    for(int i=0;i<n1;i++) cin>>w1[i];
    
    cin>>n2; //number of BurgerKing outlets
    int w2[n2];
    for(int i=0;i<n2;i++) cin>>w2[i];
    cin>>k;
    
    /*
    follow below guidelines when delivering foods for efficiency.
    1. Vehicle will deliver to one KFC outlet AND one Burger King outlet.
    2. Load of the delivery vehicle should be maximize.(load <= K)

    need to find maximum weight that can be loaded in the vehicle.

    algorithm should run in O(n1+n2) time.

    */
    sort(w1,w1+n1, greater<int>()); //sort the weights of KFC outlets
    sort(w2,w2+n2, greater<int>()); //sort the weights of BurgerKing outlets

    int i=0,j=0;
    int max_weight=0;

    while(i<n1 && j<n2){   
        if(w1[i]+w2[j]<=k){
            max_weight=max(max_weight,w1[i]+w2[j]);
            break;     
        }        
        if(w1[i]+w2[j+1] > w1[i+1]+w2[j]){
            j++;
        }
        else{
            i++;
        }
    }

    // int max_weight = 0;
    // for(int i=0;i<n1;i++){
    //     for(int j=0;j<n2;j++){
    //         if(w1[i]+w2[j]<=k){
    //             max_weight = max(max_weight,w1[i]+w2[j]);
    //         }
    //     }
    // } // only 15 points for this. o(n^2)!
    
    cout<<max_weight<<endl;

    return 0;
}
