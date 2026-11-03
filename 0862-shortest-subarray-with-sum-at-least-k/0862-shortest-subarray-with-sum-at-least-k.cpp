class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        deque<int> dq;
        vector<long long> pref(n+1, 0);
        int sum = 0;

        for(int i=0; i<n; i++){
            pref[i+1] = pref[i] + nums[i];
        }

        for(int i=0; i<=n; i++){
            while(!dq.empty() && pref[i]-pref[dq.front()]>=k){
                ans = min(ans, i-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && pref[dq.back()]>=pref[i]) dq.pop_back();
            dq.push_back(i);
        }

        return ans==INT_MAX?-1:ans;
    }
};