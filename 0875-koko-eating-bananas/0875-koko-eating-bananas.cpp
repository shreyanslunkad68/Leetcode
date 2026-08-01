class Solution {
    private:
    bool isvalid(int mid, int h, vector<int>& piles){
        int n = piles.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt+=(piles[i]+mid-1)/mid;
        }
        return cnt<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l<r){
            int mid = l + (r - l)/2;
            if(isvalid(mid, h, piles)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};