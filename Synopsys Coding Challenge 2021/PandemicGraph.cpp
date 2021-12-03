#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
    Input Format

    n - number of entries
    i - Incomming rate
    */
    int n, i;
    cin >> n;
    while(n--){
        cin >> i;
        // get the cubic root of the incoming rate
        double root = pow(i, 1.0/3.0);
        // round the root to the nearest integer
        int r = round(root);
        // get the total number of people: function = x^3
        int total = 0;
        for(int i=1; i<=r; i++){
            total += i*i*i;
        }
        // days to recover = x^2
        int number = 1;
        while(total > 0){
            total -= number*number;
            number++;
        }
        cout << number-r-1 << endl;
    }   
}