/*
Find Triangles
There's a big triangle. There are some number of points marked on each edge. 
In addition to those you should consider 3 vertices also as points. 
You are requested to find the number of trianlges which can be created using above points as vertices.

Input Format

Three numbers sperated by space. These three numbers (n1 n2 n3) will reprecent the number of points marked on three edges. eg: 3 4 2

Constraints

0 <= n1, n2, n3 <= 300

Output Format

Print the number of triangles

*/
#include <bits/stdc++.h>
using namespace std;

// nCr using dynamic programming
int nCr(int n, int r)
{   
    if(n<r) return 0;
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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    // total dots = 3 dots of the default triangle + n1 dots of the first edge + n2 dots of the second edge + n3 dots of the third edge
    int totalDots = 3 + n1 + n2 + n3;
    // To find the answer, there are two challenges to balance 
    //— actually counting every single triangle, 
    // and avoiding counting any set of three dots that don’t form a triangle.
    int total_triangles = nCr(totalDots, 3) - nCr(n1+2, 3) - nCr(n2+2, 3) - nCr(n3+2, 3);// reduce the triangloes formed by collinear points
    cout << total_triangles << endl;   
}