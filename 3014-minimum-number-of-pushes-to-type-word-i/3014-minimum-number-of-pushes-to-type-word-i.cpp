class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cost = 0;
        for(int i=0; i<n; i++)
        {
            cost+=i/8+1;
        }
        return cost;
    }
};