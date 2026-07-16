class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash;
        int l=0;
        int r=0;
        int maxf=0;
        int sol=0;
        while(r<s.size()){
            hash[s[r]]++;
            r++;
                        for(int i=0;i<26;i++){
                maxf=max(hash['A'+i],maxf);
            }
            if(r-l-maxf-k>0){
                hash[s[l]]--;
                l++;
                continue;
            }
            sol=max(sol,r-l);
        }
        return sol;
    }
};
