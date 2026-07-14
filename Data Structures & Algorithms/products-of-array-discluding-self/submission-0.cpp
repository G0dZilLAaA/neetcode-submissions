class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tot=1;
        int zero=0;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
                ind=i;
            }
            else{
                tot=tot*nums[i];
            }
        }
        vector<int> sol(nums.size(),0);
        if(zero>1) return sol;
        if(zero==1){
            sol[ind]=tot;
            return sol;
        }
        for(int i=0;i<nums.size();i++){
            sol[i]=tot/nums[i];
        }
        return sol;
    }
};
