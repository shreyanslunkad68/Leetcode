class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int len = n/2;

        sort(s.begin(), s.begin()+ len);
        
        for(int i=0; i<len; i++)
        {
            s[n-i-1] = s[i];
        }
        return s;
    }
};