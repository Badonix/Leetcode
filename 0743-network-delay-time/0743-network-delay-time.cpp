class Solution {

private:
    struct Edge {
        int to;
        int distance;
    };
    struct NodeDist {
        int index;
        int distance;
        bool operator>(const NodeDist& other) const {
            return distance > other.distance;
        }
    };

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<Edge>> m;
        for (vector<int> v : times) {
            m[v[0]].push_back({v[1], v[2]});
        }
        int* data = new int[n+1];
        for (int i = 1; i <= n; i++) {
            data[i] = INT_MAX;
        }
        data[k] = 0;
        priority_queue<NodeDist, vector<NodeDist>, greater<NodeDist>>
            pq;
        unordered_set<int> visited;
        pq.push({k, 0});
        while(!pq.empty()){
            NodeDist curr = pq.top();
            int node = curr.index;
            pq.pop();
            if(visited.count(node) != 0) continue;
            vector<Edge> neighbors = m[node];
            for(int i = 0; i < neighbors.size(); i++){
                Edge currEdge = neighbors[i];
                int currDistance = currEdge.distance;
                int dest = currEdge.to;
                if(data[dest] > data[node] + currDistance){
                    data[dest] = data[node] + currDistance;
                    pq.push({dest, data[dest]});
                }
            }
        }
        int maxTime = -1;
        for(int i = 1; i <= n; i++){
            if(data[i] == INT_MAX) return -1;
            maxTime = max(maxTime, data[i]);
        }
        return maxTime;
    }
};