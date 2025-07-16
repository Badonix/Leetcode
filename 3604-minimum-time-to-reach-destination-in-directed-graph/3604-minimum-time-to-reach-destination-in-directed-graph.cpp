class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<tuple<int, int, int>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2], edges[i][3]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> distances(n, INT_MAX);
        distances[0] = 0;

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            int currNode = curr.second;
            int currTime = curr.first;
            pq.pop();
            if(currTime > distances[currNode]) continue;
            if (currNode == n - 1)
                return currTime;
            for (tuple<int, int, int> t : adj[currNode]) {
                int neighborIndex = get<0>(t);
                int startTime = get<1>(t);
                int endTime = get<2>(t);
                // if(currTime >= distances[neighborIndex]) continue;
                if(startTime > currTime){
                    if(currTime + 1 < distances[neighborIndex]){
                        distances[neighborIndex] = min(distances[neighborIndex], startTime + 1);
                        pq.push({startTime+1, neighborIndex});
                    }
                }
                if(currTime >= startTime && currTime <= endTime){
                    if(currTime + 1 < distances[neighborIndex]){
                        distances[neighborIndex] = min(distances[neighborIndex], currTime + 1);
                        pq.push({currTime+1, neighborIndex});
                    }
                }
            }
        }
        return -1;
    }
};