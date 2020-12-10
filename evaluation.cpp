/** CS515 Assignment 2
 * File: evaluation.cpp
 * Name: mily pagan
 * Section: 01
 * Date: 09/23/20
 * Collaboration Declaration: piazza */


// infix expression evaluation
// implemented with STL vector
// evalues expression with multiple digit numbers, * / + - and {} [] () paratheis
// assume the expression is well formatted with balanced braces.

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

//----------------------------------------------------------------
// Generates a stack of string tokens representing postfix
// notation for the input line
void generateRPN(string line, stack<string> &postfix);

//----------------------------------------------------------------
// Returns a the result of evaluating the passed postfix token
// stack as a decimal string
string evaluateRPN(stack<string> &st)
{
    stack<int> stk;
    while (st.top() != "n") {
        string s = st.top();
        st.pop();
        if (isdigit(s[0])) {
            stringstream intvalue(s);
            int num = 0;
            intvalue >> num;
            stk.push(num);
        } else {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            if (s == "+") {
                stk.push(num2 + num1);
            } else if (s == "-") {
                stk.push(num2 - num1);
            } else if (s == "*") {
                stk.push(num2 * num1);
            } else if (s == "/") {
                stk.push(num2 / num1);
            }
        }
    }
    int n = stk.top();
    string out = to_string(n);
    return out;
}

//----------------------------------------------------------------
int main(int argc, char ** argv)
{
    string line;
    cout << "Expression: ";
    while ( getline(cin, line) )
    {
        // skip empty line
        if (line.length() == 0)
            continue;
        if (line == "exit") {
            exit(0);
        }
        stack<string> postfix;
        postfix.push("n");

        generateRPN(line, postfix);

        string c = "";
        stack<string> st;
        st.push("n");
        while (postfix.top() != "n") {
            c = postfix.top();
            postfix.pop();
            st.push(c);
        }

        cout << "Answer: " << evaluateRPN(st) << endl;
        line.clear();
        cout << "Expression: ";
    }
    return 0;
}
