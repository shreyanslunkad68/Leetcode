class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;

        for(int i=0; i<k; i++){
            sum+=arr[i];
        }

        int l = 0;
        int cnt = 0;
        if(sum/k>=threshold) cnt++;

        for(int i=k; i<n; i++){
            sum+=arr[i];
            sum-=arr[l];
            l++;
            int avg = sum/k;
            if(avg>=threshold) cnt++;
        }

        return cnt;
    }
};