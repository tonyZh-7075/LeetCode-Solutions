/*
Friday, April 10th, 2026

Topic: Stack, Hash Map, String

Basic Idea:
To solve the Valid Parentheses problem, we can use a stack to keep track of the 
opening parentheses.
We iterate through the input string, and for each character, we check if it is an opening or closing parenthesis.
If it is an opening parenthesis, we push it onto the stack. If it is a closing parenthesis, we check if the stack is empty or if the top of the stack does not
match the corresponding opening parenthesis. If either of these conditions is true, we return false. Otherwise, we pop the top of the stack.
After iterating through the string, if the stack is empty, we return true, indicating that all parentheses are valid. If the stack is not empty, we return false, indicating that there are

Time Complexity: O(n), where n is the length of the input string, since we need to iterate through the string once.
*/


#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (mp[st.top()] == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};