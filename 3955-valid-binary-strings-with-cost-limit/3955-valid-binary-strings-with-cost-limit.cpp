class Solution {
public:
    vector<string> ans;
    void f( int ind, int n, int k, int cost, bool prev, string& s)
    {
        if(cost>k) return;

        if(ind==n)
        {
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        f(ind+1,n,k,cost,false,s);
        s.pop_back();

        if(!prev)
        {
            s.push_back('1');
            f(ind+1,n,k,cost+ind,true,s);
            s.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string s="";
        f(0,n,k,0,false,s);
        return ans;
    }
};