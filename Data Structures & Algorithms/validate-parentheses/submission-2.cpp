class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty())
                    return false;

                char t = stk.top();

                if ((s[i] == ')' && t != '(') ||
                    (s[i] == '}' && t != '{') ||
                    (s[i] == ']' && t != '['))
                    return false;

                stk.pop();
            }
        }

        return stk.empty();
    }
};