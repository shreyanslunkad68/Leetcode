class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for(int i: cardPoints){
            total+=i;
        }

        int l = 0;
        int r = n-k;

        int sum = 0;
        for(int i=0; i<n-k; i++){
            sum+=cardPoints[i];
        }

        int minWindow = sum;

        while(r<n){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            minWindow = min(minWindow, sum);
            l++;
            r++;
        }
        return total - minWindow;
    }
};