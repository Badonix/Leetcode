class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0) q.push({i, j});
            }
        }

        int curr_distance = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                pair<int, int> p = q.front(); q.pop();
                for(int di = -1; di <= 1; di++){
                    for(int dj = -1; dj <= 1; dj++){
                        if(abs(di) == abs(dj)) continue;
                        int newI = p.first + di;
                        int newJ = p.second + dj;
                        if(newI < 0 || newJ < 0 || newI >= mat.size() || newJ >= mat[0].size() || visited.count({newI, newJ}) != 0) continue;
                        if(mat[newI][newJ] == 1) mat[newI][newJ] = curr_distance;
                        visited.insert({newI, newJ});
                        q.push({newI, newJ});
                    }
                }
            }
            curr_distance++;
        }

        return mat;
    }
};