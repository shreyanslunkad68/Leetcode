class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxi, mini;
        int l=0, ans=INT_MIN;

        for(int r = 0; r<n; r++){
            while(!maxi.empty() && nums[maxi.back()]<nums[r]){
                maxi.pop_back();
            }
            while(!mini.empty() && nums[mini.back()]>nums[r]){
                mini.pop_back();
            }
            maxi.push_back(r);
            mini.push_back(r);

            while(nums[maxi.front()]-nums[mini.front()]>limit){
                if (maxi.front() == l) maxi.pop_front();
                if (mini.front() == l) mini.pop_front();
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};