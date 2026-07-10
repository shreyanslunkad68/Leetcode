class Solution {
public:
    bool f(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(sum == 0) return true;
        if(ind == 0)
        {
            return nums[ind] == sum;
        }

        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool not_take = f(ind-1, sum, nums,dp);
        bool take = false;

        if(sum-nums[ind]>=0)
        {
            take = f(ind-1, sum - nums[ind], nums, dp);
        }
        return dp[ind][sum] = take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return sum%2==0?f(n-1, sum/2, nums, dp):false;
    }
};