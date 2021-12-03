/*
Problem Definition:
we have two logic circuits. Both the circuits has same primary inputs. And each produces one output.
Let's name two ciructs as CircuitA and CircuitB. CircuitA's output is poA (po denotes Primary output) and CircuitB's output is poB. Circuit designer wants to know whether output of these two circuits are
a. Equal for all the possible inputs i.e (for all input combinations poA == poB)
b. Completely inverted for all the possible inputs (for all input combinations poA == ~ poB)
c. None of the above
*/

#include <bits/stdc++.h>
using namespace std;

int evaluate(string oprtr, int input1, int input2){
    int result = 0;
    if (oprtr == "and") result = input1 & input2;
    else if (oprtr == "nand") result = ~(input1 & input2);
    else if (oprtr == "xor") result = input1 ^ input2;
    else if (oprtr == "xnor") result = ~(input1 ^ input2);
    else if (oprtr == "or") result = input1 | input2;
    else if (oprtr == "nor") result = ~(input1 | input2);
    else if (oprtr == "not") result = ~input1;
    else if (oprtr == "buf") result = input1;
    return result;
}

/*
CircuitA
t1 or pi0 pi1
t2 or t1 pi2
t3 or t2 pi3
poA buf ~t3
CircuitB
new_n1 and ~pi0 ~pi1
new_n2 and new_n1 ~pi2
new_n3 and new_n2 ~pi3
poB not new_n3
*/
int simplify(string cct, vector<string> circuit, bitset<20> number){
    // replece evrything by primary inputs
    int ans = 0; // ans is the output of the circuit
    // bitset<20> primary_inputs = number;
    map<string, int> values;
    for(int i =0; i <20; i++){
        // concatenate  "pi" + i
        string pi = "pi" + to_string(i);
        values[pi] = number[i];
    }
    int index = 1;
    while(index <= (int)circuit.size()){
        //output-variable, logical-operation, operand1, operand2
        string oprtr = circuit[index];
        /*
        Each circuit is made up using following logic functions.
        a. Two input and, nand, xor, xnor, or, nor gates
        b. one input not gate
        c. One input not gate (just a buffer)
        */
        if(oprtr == "and" || oprtr == "nand" || oprtr == "xor" || oprtr == "xnor" || oprtr == "or" || oprtr == "nor"){
            string output = circuit[index-1];
            string operand1 = circuit[index+1];
            string operand2 = circuit[index+2];
            int value1, value2;
            if(operand1[0] == '~'){
                operand1 = operand1.substr(1);
                value1 = ~values[operand1];
            }else{
                value1 = values[operand1];
            }
            if(operand2[0] == '~'){
                operand2 = operand2.substr(1);
                value2 = ~values[operand2];
            }else{
                value2 = values[operand2];
            }
            int result = evaluate(oprtr, value1, value2);
            values[output] = abs(result);
            circuit.erase(circuit.begin()+index-1, circuit.begin()+index+3);
            index = 1;
        }
        else if(oprtr == "not"){
            string output = circuit[index-1];
            string operand1 = circuit[index+1];
            int value1;
            if(operand1[0] == '~'){
                operand1 = operand1.substr(1);
                value1 = ~values[operand1];
            }else{
                value1 = values[operand1];
            }
            int result = evaluate(oprtr, value1, 0);
            values[output] = abs(result);
            circuit.erase(circuit.begin()+index-1, circuit.begin()+index+2);
            index = 1;
        }
        else if(oprtr == "buf"){
            string output = circuit[index-1];
            string operand1 = circuit[index+1];
            int value1;
            if(operand1[0] == '~'){
                operand1 = operand1.substr(1);
                value1 = ~values[operand1];
            }else{
                value1 = values[operand1];
            }
            int result = evaluate(oprtr, value1, 0);
            values[output] = abs(result);
            circuit.erase(circuit.begin()+index-1, circuit.begin()+index+2);
            index = 1;
        }
    }
    if(cct == "CircuitA"){
        ans =  values["poA"];
    }
    else if(cct == "CircuitB"){
        ans  = values["poB"];
    }
    return ans;
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
    // cout << "CircuitA: ";
    // for(auto i : CircuitA) cout << i << endl;
    // // print the elements of CircuitB
    // cout << "CircuitB: ";
    // for(auto i : CircuitB) cout << i << endl;
    // ---------------------simplify--------------------
    // get the simplified circuit
    // int out1 = abs(simplify("CircuitA", CircuitA, bitset<20>(0)));
    // int out2 = abs(simplify("CircuitB", CircuitB, bitset<20>(0)));
    // // print the simplified circuit
    // cout << "CircuitA: " << out1 << endl;
    // cout << "CircuitB: " << out2 << endl;
    /*
    check whether output of these two circuits are
    a. Equal for all the possible inputs i.e (for all input combinations poA == poB)
    b. Completely inverted for all the possible inputs (for all input combinations poA == ~ poB)
    c. None of the above
    */
    // check whether output of these two circuits are equal for all the possible inputs
    bool identical = true;
    bool inverted = true;
    for(int i = n/4; i < 3*n/4; i++){
        bitset<20> number(i);
        int out1 = abs(simplify("CircuitA", CircuitA, number));
        int out2 = abs(simplify("CircuitB", CircuitB, number));
        if(out1 != out2){
            identical = false;
            break;
        }
    }
    // check whether output of these two circuits are completely inverted for all the possible inputs
    for(int i = n/4; i < 3*n/4; i++){
        bitset<20> number(i);
        int out1 = abs(simplify("CircuitA", CircuitA, number));
        int out2 = abs(simplify("CircuitB", CircuitB, number));
        if(out1 != ~out2){
            inverted = false;
            break;
        }
    }
    if(identical){
        cout << "Identical" << endl;
    }
    if(inverted){
        cout << "Inverted" << endl;
    }
    if(!identical && !inverted){
        cout << "None" << endl;
    }
}