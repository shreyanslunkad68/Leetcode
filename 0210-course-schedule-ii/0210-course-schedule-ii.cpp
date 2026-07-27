class Solution {
public:
    vector<int> findOrder(int numCourse, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourse);
        vector<int> indegree(numCourse, 0);

        for (auto p : prerequisites) {
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i=0; i<numCourse; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int neighbor: adj[node])
            {
                indegree[neighbor]--;

                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }

        if(ans.size() != numCourse)
            return {};
        
        return ans;
    }
};