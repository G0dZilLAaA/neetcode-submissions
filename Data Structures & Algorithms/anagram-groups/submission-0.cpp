class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<int, bool> hash;
        vector<vector<string>> ans;

        vector<vector<int>> freq(strs.size(), vector<int>(26, 0));

        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                freq[i][strs[i][j] - 'a']++;
            }
        }

        for (int i = 0; i < strs.size(); i++) {

            if (!hash[i]) {

                vector<string> sol;
                sol.push_back(strs[i]);

                for (int j = 0; j < strs.size(); j++) {

                    if (j != i && !hash[j]) {

                        int k;

                        for (k = 0; k < 26; k++) {
                            if (freq[i][k] != freq[j][k])
                                break;
                        }

                        if (k == 26) {
                            sol.push_back(strs[j]);
                            hash[j] = true;
                        }
                    }
                }

                ans.push_back(sol);
            }
        }

        return ans;
    }
};