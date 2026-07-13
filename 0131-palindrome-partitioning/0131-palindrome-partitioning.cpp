class Solution {
public:
    void solve(string s,int ind, vector<vector<string>>& ans,vector<string> ds)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = ind;i<s.size();i++)
        {
            if(ispalindrome(ind,i,s))
            {
                ds.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,ans,ds);
                ds.pop_back();
            }
        }
    }

    bool ispalindrome(int start, int end, string s)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s,0,ans,ds);

        return ans;
    }
};