class Solution {
public:
    void recur(vector<int>& nums, int k , vector<vector<int>>& sol , vector<int> curr , int sum,int i){
        if(sum==k){
            sol.push_back(curr);
            return ;
        }
        if(sum>k||i>=nums.size()) return;
        recur(nums , k , sol , curr,sum,i+1);
        curr.push_back(nums[i]);
        recur(nums , k , sol , curr,sum+nums[i],i);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        recur(nums , target , sol , {} , 0,0);
        return sol;
    }
};
