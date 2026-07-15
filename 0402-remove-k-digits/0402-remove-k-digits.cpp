class Solution {
public:
    string removeKdigits(string nums, int k) {
        if (nums.length() <= k)
            return "0";
        if (k == 0)
            return nums;
        stack<char> st;
        st.push(nums[0]);
        string ans = "";
        for (int i = 1; i < nums.length(); i++) {
            while(!st.empty() && k>0 && nums[i]<st.top()) 
            {
                --k;
                st.pop();
            }
            st.push(nums[i]);

            if(st.size()==1 && st.top()=='0')
            {
                st.pop();
            }
        }
        while(!st.empty() && k)
        {
            --k;
            st.pop();
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.length()==0) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};