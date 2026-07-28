class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {

        // Create adjacency list
        vector<pair<int,int>> adj[n];

        for(auto flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];

            adj[u].push_back({v, cost});
        }

        // Minimum cost to reach each node
        vector<int> fare(n, INT_MAX);
        fare[src] = 0;

        // {node, cost}
        queue<pair<int,int>> q;
        q.push({src, 0});

        int stops = 0;

        while(!q.empty() && stops <= k)
        {
            int size = q.size();

            while(size--)
            {
                auto [node, cost] = q.front();
                q.pop();

                for(auto [next, price] : adj[node])
                {
                    if(cost + price < fare[next])
                    {
                        fare[next] = cost + price;
                        q.push({next, cost + price});
                    }
                }
            }

            stops++;
        }

        return fare[dest] == INT_MAX ? -1 : fare[dest];
    }
};