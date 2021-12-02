/*
Problem Definition:
we have two logic circuits. Both the circuits has same primary inputs. And each produces one output.
Let's name two ciructs as CircuitA and CircuitB. CircuitA's output is poA (po denotes Primary output) and CircuitB's output is poB. Circuit designer wants to know whether output of these two circuits are
a. Equal for all the possible inputs i.e (for all input combinations poA == poB)
b. Completely inverted for all the possible inputs (for all input combinations poA == ~ poB)
c. None of the above
Each circuit is made up using following logic functions.
a. Two input AND, NAND, XOR, XNOR, OR, NOR gates
b. one input NOT gate
c. One input BUF gate (just a buffer)
*/

#include <bits/stdc++.h>
using namespace std;

int evaluate_expression(string expression, int input1, int input2)
{
    int result = 0;
    if (expression == "AND")
    {
        result = input1 & input2;
    }
    else if (expression == "NAND")
    {
        result = ~(input1 & input2);
    }
    else if (expression == "XOR")
    {
        result = input1 ^ input2;
    }
    else if (expression == "XNOR")
    {
        result = ~(input1 ^ input2);
    }
    else if (expression == "OR")
    {
        result = input1 | input2;
    }
    else if (expression == "NOR")
    {
        result = ~(input1 | input2);
    }
    else if (expression == "NOT")
    {
        result = ~input1;
    }
    else if (expression == "BUF")
    {
        result = input1;
    }
    return result;
}

string simplify(vector<string> circuit){
    // replece evrything by primary inputs
    continue;
}

int main(){
    /*
    Input Format:
    line 1 - N number of primary inputs
    line 2 - this will always be CircuitA to denote the start of CircuitA. 
    After line 2 there will be variable number of lines to represent logical operation in the circuit.
    format of a operation: output-variable logical-operation operand1 operand2

    Note that operand2 is not applicable for buf, not operations.

    */
    int n;
    cin >> n;
    string s;
    cin >> s;
    // ---------------------circuit A--------------------
    vector<string> CircuitA;
    // get the inputs and push them to CircuitA until "CircuitB" is encountered
    while(s != "CircuitB"){
        CircuitA.push_back(s);
        cin >> s;
    }
    // remove first element of CircuitA
    CircuitA.erase(CircuitA.begin());

    // ---------------------circuit B--------------------
    vector<string> CircuitB;
    // push everyline after "CircuitB" to CircuitB
    while(cin >> s){
        CircuitB.push_back(s);
    }
    
    // print the elements of CircuitA
    cout << "CircuitA: ";
    for(auto i : CircuitA) cout << i << endl;
    // print the elements of CircuitB
    cout << "CircuitB: ";
    for(auto i : CircuitB) cout << i << endl;
    return 0;
}