class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i<n ;i++)
        {
            if(grid[i][0]==1)
            {
                grid[i][0]=2;
                q.push({i,0});
            }
            if(grid[i][m-1]==1)
            {
                grid[i][m-1]=2;
                q.push({i,m-1});
            }
        }

        for(int i = 0; i<m ;i++)
        {
            if(grid[0][i]==1)
            {
                grid[0][i]=2;
                q.push({0,i});
            }
            if(grid[n-1][i]==1)
            {
                grid[n-1][i]=2;
                q.push({n-1,i});
            }
        }

        while(!q.empty())
        {
            auto[r, c] = q.front();
            q.pop();
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1)
                {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};