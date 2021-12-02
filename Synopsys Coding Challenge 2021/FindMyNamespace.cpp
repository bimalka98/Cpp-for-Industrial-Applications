/*
Language “MyBinary” has a special criterion in selecting valid variable names.



It accepts only “0” and “1” characters while writing variable names.
There should be same number of “0” and “1” characters in a name
The prefix of the name has the property where NumberOf(‘1’) ≥ NumberOf(‘0’)

or a given “n” number of “0” characters, find how many valid variable names can be generated

Eg:
Number of “0” characters (n) = 3
Valid name patterns =>
111000
101100
101010
110010
110100
Number of valid patterns => 5

Input Format

3

Constraints

It accepts only “0” and “1” characters while writing variable names.
There should be same number of “0” and “1” characters in a name
The prefix of the name has the property where NumberOf(‘1’) ≥ NumberOf(‘0’)

Output Format

5
*/
#include <bits/stdc++.h>
using namespace std;

// nCr using dynamic programming
int nCr(int n, int r)
{
    int C[n + 1][r + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][r];
}

int main(){
    int n;
    cin >> n;
    int max_ones = n;
    int min_ones = 0;
    if(n%2 == 0) min_ones = n/2;
    else min_ones = (n+1)/2;
    // number of different prefixes
    int ans =0;
    for(int i=min_ones;i<=max_ones;i++){
        // for each prefix, number of valid names
        int num_zeros_in_suffix = i; // number of zeros in suffix equals to number of ones in prefix
        ans+=nCr(n,i)*nCr(n,num_zeros_in_suffix);

    }
    cout << ans << endl;
}