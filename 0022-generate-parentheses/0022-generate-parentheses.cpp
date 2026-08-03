class Solution {
public:
    vector<string> ans;
    void f(int left, int right, int n, string temp){
        if(2*n==temp.size()){
            ans.push_back(temp);
            return;
        }

        if(left<n){
            f(left+1, right, n, temp+'(');
        }
        if(right<left){
            f(left, right+1, n, temp+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        f(0, 0, n, "");
        return ans;
    }
};