class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        set<int> visited;
        queue<int> q;

        q.push(start);
        visited.insert(start);

        while(!q.empty()){
            int currIndex = q.front();
            q.pop();
            int currValue = arr[currIndex];
            if(currValue == 0){
                return true;
            }
            int newSub = currIndex - currValue;
            int newSum = currIndex + currValue;
            if(newSub >= 0 && !visited.contains(newSub)){
                q.push(newSub);
                visited.insert(newSub);
            }
            if(newSum < arr.size() && !visited.contains(newSum)){
                q.push(newSum);
                visited.insert(newSum);
            }
        }
        return false;
    }
};