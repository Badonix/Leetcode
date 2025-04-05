class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        pair<int, int> entrancePair = make_pair(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';
        q.push(entrancePair);

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();

                if (curr.first == 0 || curr.first == maze.size() - 1 ||
                    curr.second == 0 || curr.second == maze[0].size() - 1) {
                    if (curr != entrancePair) {
                        return steps - 1;
                    }
                }

                pair<int, int> newNeighbor1 =
                    visitNeighbor(maze, curr.first, curr.second + 1);
                if (newNeighbor1.first != -1) {
                    q.push(newNeighbor1);
                }

                pair<int, int> newNeighbor2 =
                    visitNeighbor(maze, curr.first, curr.second - 1);
                if (newNeighbor2.first != -1) {
                    q.push(newNeighbor2);
                }
                pair<int, int> newNeighbor3 =
                    visitNeighbor(maze, curr.first - 1, curr.second);
                if (newNeighbor3.first != -1) {
                    q.push(newNeighbor3);
                }
                pair<int, int> newNeighbor4 =
                    visitNeighbor(maze, curr.first + 1, curr.second);
                if (newNeighbor4.first != -1) {
                    q.push(newNeighbor4);
                }
            }
        }
        return -1;
    }
    pair<int, int> visitNeighbor(vector<vector<char>>& maze, int row, int col) {
        if (row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size() &&
            maze[row][col] != '+') {
            pair<int, int> res = make_pair(row, col);
            maze[row][col] = '+';
            return res;
        }
        return make_pair(-1, -1);
    }
};