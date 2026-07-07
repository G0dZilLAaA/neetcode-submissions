class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> hash1,hash2;
        for(int i=0;i<s.size();i++){
            hash1[s[i]]++;
            hash2[t[i]]++;
        }
        if(hash1.size()!=hash2.size()) return false;
        for(int i=0;i<26;i++){
            if(hash1['a'+i]!=hash2['a'+i]) return false;
        }
        return true;
    }
};
