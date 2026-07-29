class Solution {
public:
    vector<int> parent, rank;

    int find(int node)
    {
        if(node==parent[node]) return node;

        return parent[node] = find(parent[node]);
    }
    
    void Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px]<rank[py])
        {
            parent[px] = py;
        }
        else if(rank[py]<rank[px])
        {
            parent[py] = px;
        }
        else
        {
            parent[px] = py;
            rank[py]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int size = 20005;
        parent.resize(size);
        rank.assign(size, 0);
        unordered_set<int> nodes;

        for(int i = 0; i < size; i++) parent[i] = i;
        int cnt = 0;

        for(auto it: stones)
        {
            int u = it[0];
            int v = it[1] + 10001;

            Union(u, v);

            nodes.insert(u);
            nodes.insert(v);
        } 

        int components = 0;

        for(int node : nodes)
        {
            if(find(node) == node)
                components++;
        }

        return n - components;
    }
};