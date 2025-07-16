/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int answ = 0;
        
        unordered_map<int, pair<vector<int>, int>> m;
        for(Employee* e : employees){
            m[e->id].first = e->subordinates;
            m[e->id].second = e->importance;
        }
        
        queue<int> q;
        unordered_set<int> s;
        q.push(id);
        s.insert(id);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            answ += m[curr].second;
            for(int n : m[curr].first){
                if(s.count(n) == 0) q.push(n);
            }
        }
        return answ;
    }
};