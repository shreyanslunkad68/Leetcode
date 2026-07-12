class Solution {
public:
    vector<string> ans;
    void f(int left, int right, int n, string s)
    {
        if(right == n && left == n)
        {
            ans.push_back(s);
        }

        if(left<n)
        {
        f(left+1, right, n, s+"(");
        }
        if(right<left)
        {
        f(left, right+1, n, s+")");
        }

    }
    vector<string> generateParenthesis(int n) {
        string s ="";
        f(0, 0, n, s);
        return ans;
    }
};