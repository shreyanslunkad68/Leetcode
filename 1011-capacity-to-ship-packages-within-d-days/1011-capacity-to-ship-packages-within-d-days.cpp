class Solution {
private:
    bool isvalid(int mid, int days, vector<int>& weights){
        int n  = weights.size();
        int cnt = 1;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(sum + weights[i] <= mid){
                sum+=weights[i];
            }
            else{
                cnt++;
                sum=weights[i];
            }
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l<r){
            int mid = l + (r-l)/2;
            if(isvalid(mid, days, weights)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};