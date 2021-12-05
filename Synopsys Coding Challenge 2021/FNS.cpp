/*
Language “MyBinary” has a special criterion in selecting valid variable names.



It accepts only “0” and “1” characters while writing variable names.
There should be same number of “0” and “1” characters in a name
The prefix of the name has the property where NumberOf(‘1’) ≥ NumberOf(‘0’)
*/

#include <bits/stdc++.h>
using namespace std;

void getNameCount(int n, int zeros, int ones, string name, int &count1 )
{   
    
    if((int)name.length() == 2*n){
        
        if((count(name.begin(), name.begin()+n, '1') >= count(name.begin(), name.begin()+n, '0')) && name[0] == '1' && name[2*n-1] == '0'){
            // cout << "name: " << name <<  endl;
            if(count(name.begin(), name.end(), '1') == count(name.begin(), name.end(), '0')){
                count1++;
            }
        }
    }
    if(zeros == 0 && ones == 0) return;
    
    if(ones >0){
        // cout << "Adding 1 to " << name << endl;
        getNameCount(n, zeros, ones-1, name+'1', count1);
    }
    if(zeros >0){
        // cout << "Adding 0 to " << name << endl;
        getNameCount(n, zeros-1, ones, name+'0', count1);
    }
}
// nCr using dynamic programming


int main(){
    int n;
    cin >> n; // number of zeros
    int count1 = 0;
    //int allowed_zeros = n/2;
    getNameCount(n, n, n, "", count1);
    cout << count1 << endl;
}