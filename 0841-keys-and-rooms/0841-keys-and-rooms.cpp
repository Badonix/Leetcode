class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        vector<bool> visited(rooms.size(), true);
        for(int i = 1; i < rooms.size(); i++){
            visited[i] = false;
        }

        while(!q.empty()){
            int curr_room = q.front(); q.pop();
            for(int n : rooms[curr_room]){
                if(!visited[n]){
                    q.push(n);
                    visited[n] = true;
                }
            }
        }

        for(bool is_visited : visited){
            if(!is_visited) return false;
        }
        return true;
    }
};