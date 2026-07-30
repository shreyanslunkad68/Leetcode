class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;
            int rem = -nums[i];
            while (l < r) {
                int sum = nums[l] + nums[r];
                vector<int> temp(3, 0);
                if (sum == rem) {
                    temp = {nums[i], nums[l], nums[r]};
                    ans.push_back(temp);
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                } else if (sum < rem) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};