class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        set<int> not_visited;
        for(int i = 1; i < rooms.size(); i++){
            not_visited.insert(i);
        }

        while(!q.empty()){
            int curr_room = q.front(); q.pop();
            for(int n : rooms[curr_room]){
                if(not_visited.count(n) != 0){
                    q.push(n);
                    not_visited.erase(n);
                }
            }
        }

        return not_visited.empty();
    }
};