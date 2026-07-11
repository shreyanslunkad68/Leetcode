class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int lastindex = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1), hash(n,0) , ans;
        int maxi = 1;
        
        for(int i =0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0) && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
                if(dp[i]>maxi)
                {
                    maxi = dp[i];
                    lastindex = i;
                }
            }
        }
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        return ans;
    }
};