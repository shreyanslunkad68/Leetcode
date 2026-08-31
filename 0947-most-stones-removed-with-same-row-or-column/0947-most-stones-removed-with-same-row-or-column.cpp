class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if(parent[x]==x) return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;

        if(rank[pa]<rank[pb]){
            parent[pa] = pb;
        }
        else if(rank[pb]<rank[pa]){
            parent[pb] = pa;
        }
        else{
            parent[pa] = pb;
            rank[pb]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int offset = 20002;
        int size = 30003;

        parent.resize(size);    
        rank.resize(size, 0);

        for(int i=0; i<size; i++) parent[i] = i;

        for(auto s: stones){
            int row = s[0];
            int col = s[1] + offset;

            unite(row, col);
        }    

        unordered_set<int> components;

        for(auto s: stones){
            int row = s[0];
            components.insert(find(row));
        }

        return n - components.size(); 
    }
};