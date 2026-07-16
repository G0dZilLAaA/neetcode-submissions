class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Count required characters
        for (char c : t)
            need[c]++;

        int required = need.size();   // Number of unique chars needed
        int formed = 0;               // Number of chars currently satisfied

        int l = 0;
        int r = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {

            char c = s[r];
            window[c]++;

            // Check if this character just became satisfied
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try to shrink while valid
            while (formed == required) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char left = s[l];
                window[left]--;

                // Removing this character broke the requirement
                if (need.count(left) &&
                    window[left] < need[left])
                    formed--;

                l++;
            }

            r++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};