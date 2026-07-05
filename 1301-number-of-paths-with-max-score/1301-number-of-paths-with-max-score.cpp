class Solution {
public:
    int mod = 1e9 + 7;
    int n, m;

    // dpScore[i][j] = maximum score from (i,j)
    // dpWays[i][j] = number of ways for maximum score
    vector<vector<int>> dpScore, dpWays;
    vector<vector<int>> vis;

    pair<int,int> dfs(int i, int j, vector<string>& board)
    {
        // Out of boundary or blocked
        if(i >= n || j >= m || board[i][j] == 'X')
            return {-1, 0};

        // Reached destination
        if(board[i][j] == 'S')
            return {0, 1};

        if(vis[i][j])
            return {dpScore[i][j], dpWays[i][j]};

        vis[i][j] = 1;

        int best = -1;
        int ways = 0;

        vector<pair<int,int>> dir = {{1,0},{0,1},{1,1}};

        for(auto [dx,dy] : dir)
        {
            auto [score,cnt] = dfs(i+dx, j+dy, board);

            if(score == -1) continue;

            if(board[i][j] != 'E')
                score += board[i][j]-'0';

            if(score > best)
            {
                best = score;
                ways = cnt;
            }
            else if(score == best)
            {
                ways = (ways + cnt) % mod;
            }
        }

        dpScore[i][j] = best;
        dpWays[i][j] = ways;

        return {best, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board)
    {
        n = board.size();
        m = board[0].size();

        dpScore.assign(n, vector<int>(m, -1));
        dpWays.assign(n, vector<int>(m, 0));
        vis.assign(n, vector<int>(m, 0));

        auto [score, ways] = dfs(0,0,board);

        if(score == -1)
            return {0,0};

        return {score, ways};
    }
};