class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int largest = nums[0];
        int freq = 1;

        for(int i = 1; i<n; i++)
        {
            if(nums[i]==largest)
            {
                freq++;
            }
            else if(freq==0)
            {
                freq = 0;
                largest = nums[i];
            }
            else
            {
                freq--;
            }
        }

        int cnt = 0;
        for(int &x:nums)
        {
            if(x==largest) cnt++;
        }

        if(cnt>n/2)
        {
            return largest;
        }
        return -1;
    }
};