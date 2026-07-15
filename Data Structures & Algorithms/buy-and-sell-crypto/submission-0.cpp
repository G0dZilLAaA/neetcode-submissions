class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best=INT_MAX;
        int sol=0;
        for(int i=0;i<prices.size();i++){
            sol=max(sol,prices[i]-best);
            best=min(best,prices[i]);
        }
        return sol;
    }
};
