class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for (int i = 0; i < strs.size(); i++) {
            s = s + to_string(strs[i].size()) + "#" + strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            j++;

            string curr = s.substr(j, len);

            strs.push_back(curr);

            i = j + len;
        }

        return strs;
    }
};