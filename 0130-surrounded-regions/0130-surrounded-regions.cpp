class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<n ;i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0]='S';
                q.push({i,0});
            }
            if(board[i][m-1]=='O')
            {
                board[i][m-1]='S';
                q.push({i,m-1});
            }
        }
        for(int i=0; i<m ;i++)
        {
            if(board[0][i]=='O')
            {
                board[0][i]='S';
                q.push({0,i});
            }
            if(board[n-1][i]=='O')
            {
                board[n-1][i]='S';
                q.push({n-1,i});
            }
        }

        while(!q.empty())
        {
            auto[r, c] = q.front();
            q.pop();

            int dr[] = {-1, 1, 0, 0};        
            int dc[] = {0, 0, -1, 1};

            for(int i=0;i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O')
                {
                    board[nr][nc] = 'S';
                    q.push({nr, nc});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='S')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};