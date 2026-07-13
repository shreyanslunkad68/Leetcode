class Solution {
public:
    int f(int ind, string& s, vector<int>& dp) {
        if (ind == s.size()) {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int cnt = INT_MAX;

        for (int k = ind; k < s.size(); k++) {
            if (ispalindrome(ind, k, s)) {
                cnt = min(cnt, 1 + f(k + 1, s, dp));
            }
        }
        return dp[ind] = cnt;
    }
    bool ispalindrome(int start, int end, string& s) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return f(0, s, dp)-1;
    }
};