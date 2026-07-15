class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> hash;
        int sol=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(hash.find(s[r])!=hash.end()){
                hash.erase(s[l]);
                l++;
                continue;
            }
            hash[s[r]]=true;
            r++;
            sol=max(sol,r-l);
        }
        return sol;
    }
};
