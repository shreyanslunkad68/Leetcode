class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0) st.push(asteroids[i]);
            
            else{
                bool destroyed = false;
                while(!st.empty() && st.top()>0)
                {
                    if (abs(asteroids[i]) > st.top()) {
                        st.pop();                // positive destroyed
                    }
                    else if (abs(asteroids[i]) == st.top()) {
                        st.pop();                // both destroyed
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true;        // negative destroyed
                        break;
                    }
                }
                if (!destroyed) {
                    st.push(asteroids[i]);
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};