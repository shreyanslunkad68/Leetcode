class Solution {
public:
    int maximumWidth(vector<int>& planks) {
          unordered_map<long long, long long> freq;
        for (int x : planks) {
            freq[x]++;
        }

        vector<pair<long long, long long>> vals;
        for (auto &[h, c] : freq) {
            vals.push_back({h, c});
        }

        unordered_map<long long, long long> possible;

        int n = vals.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long sum = vals[i].first + vals[j].first;
                possible[sum] += min(vals[i].second, vals[j].second);
            }
        }

        for (auto &[h, c] : vals) {
            possible[2 * h] += c / 2;
        }

        long long ans = 1;

        for (auto &[h, c] : freq) {
            ans = max(ans, c + possible[h]);
        }

        for (auto &[h, c] : possible) {
            ans = max(ans, c + freq[h]);
        }

        return (int)ans;
    }
};