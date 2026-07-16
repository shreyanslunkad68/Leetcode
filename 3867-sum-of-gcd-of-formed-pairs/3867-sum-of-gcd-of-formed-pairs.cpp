class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> temp(n);

        for(int i=0; i<n; i++)
        {
            maxi=max(maxi,nums[i]);
            temp[i] = gcd(maxi, nums[i]);
        }

        sort(temp.begin(),temp.end());
    
        int l = 0;
        int r = n-1;
        long long sum = 0;
        while(l<r)
        {
            sum+=gcd(temp[l],temp[r]);
            l++;
            r--;
        }
        return sum;
    }
};