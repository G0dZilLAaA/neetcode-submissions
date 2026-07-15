class Solution {
public:
    int maxArea(vector<int>& heights) {
        int sol=0;
        int l=0;
        int r=heights.size()-1;
        while(l<r){
            int curr=min(heights[l],heights[r])*(r-l);
            sol=max(sol,curr);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return sol;
    }
};
