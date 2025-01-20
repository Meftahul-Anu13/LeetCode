// Check if a Parentheses String Can Be Valid
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         stack<char>st;
//         for(int i=0;i<s.length();i++)
//         {
//             if(s[i]=='(')st.push(s[i]);
//             else {
//                 if(!st.empty()&& (s[i]==')'&&locked[i]=='0'))
//                 {
//                     s[i]='(';
//                     locked[i]='1';
//                     st.pop();
//                 }
//                 if(!st.empty()&&(st.top()=='('&&s[i]==')'))
//                 st.pop();
//                 else return false ;
//             }
//         }
//         return st.empty();
//     }
// };

// int main ()
// {
//     Solution s;
//     string str="))()))";
//     string ind ="010100";
//     int res= s.canBeValid(str,ind);
//     cout<<res<<endl;
// }
// Check if a Parentheses String Can Be Valid
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validparen(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else
            {
                if (!st.empty() && (st.top() == '(' && s[i] == ')'))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
    bool canBeValid(string s, string locked)
    {
        if (s.length() % 2 != 0)
            return false;
        if(validparen(s)) return true;
        int open = 0, close = 0, wildcards = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (locked[i] == '0')
                wildcards++;
            else if (s[i] == '(')
                open++;
            else
                close++;
            if (close > open + wildcards)
                return false;
        }
        open = close = wildcards = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (locked[i] == '0')
                wildcards++;
            else if (s[i] == ')')
                close++;
            else
                open++;
            if (open > close + wildcards)
                return false;
        }
        return true;
    }
};
