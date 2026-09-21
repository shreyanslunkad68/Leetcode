class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long st = 0 , end = nums.size() - 1 , sum = 0;
        while(st <= end){
            if(st == end){
                sum += (nums[st]*nums[st]);
                break;
            }
            sum += (nums[end]*nums[end]) - (nums[st]*nums[st]);
            st++,end--;
        }
        return sum;
    }
};