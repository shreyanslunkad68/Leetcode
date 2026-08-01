class Solution {
private:
    bool isvalid(int mid, int k, vector<int>& nums){
        int sum  = 0;
        int cnt = 1;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                sum = nums[i];
                cnt++;
            }
        }
        return cnt<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
     int l = *max_element(nums.begin(), nums.end());
     long long r = accumulate(nums.begin(), nums.end(), 0LL);

     while(l<r){
        long long mid = l + (r-l)/2;
        if(isvalid(mid, k, nums)){
            r=mid;
        }
        else{
            l=mid+1;
        }
     }   
     return l;
    }
};