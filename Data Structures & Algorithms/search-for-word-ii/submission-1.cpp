class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             vector<vector<bool>>& vis,
             string& word,
             int i,
             int j,
             int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return false;

        if (vis[i][j])
            return false;

        if (board[i][j] != word[idx])
            return false;

        vis[i][j] = true;

        bool found =
            dfs(board, vis, word, i + 1, j, idx + 1) ||
            dfs(board, vis, word, i - 1, j, idx + 1) ||
            dfs(board, vis, word, i, j + 1, idx + 1) ||
            dfs(board, vis, word, i, j - 1, idx + 1);

        vis[i][j] = false;      

        return found;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        vector<string> ans;

        for (string& word : words) {

            bool found = false;

            vector<vector<bool>> vis(
                board.size(),
                vector<bool>(board[0].size(), false));

            for (int i = 0; i < board.size() && !found; i++) {
                for (int j = 0; j < board[0].size() && !found; j++) {

                    if (dfs(board, vis, word, i, j, 0)) {
                        ans.push_back(word);
                        found = true;
                    }
                }
            }
        }

        return ans;
    }
};