class Solution {

    public boolean calculateBobPath(int bob, List<Integer>[] adjList, 
                HashMap<Integer, Integer> bobPath, int hopCount) {
        
        bobPath.put(bob, hopCount);

        if(bob == 0) return true;

        for(int nei: adjList[bob]) {
            if(!bobPath.containsKey(nei) && 
                        calculateBobPath(nei, adjList, bobPath, hopCount+1)) {
                return true;
            }
        }

        bobPath.remove(bob);
        return false;
    }

    public int maxAlicePath(int alice, List<Integer>[] adjList, int hopCount,
                int reward, int parent, HashMap<Integer, Integer> bobPath, int[] amount) {
        
        int currentNodeReward = 0;

        if (bobPath.containsKey(alice) && hopCount >= bobPath.get(alice)) {
            int bobHopCount = bobPath.get(alice);
            if(hopCount == bobHopCount) currentNodeReward = amount[alice]/2;
        } else {
            currentNodeReward = amount[alice];
        }

        currentNodeReward += reward;
        
        int maxReward = Integer.MIN_VALUE;
        for(int nei: adjList[alice]) {
            if(nei != parent) {
                maxReward = Math.max(maxReward, 
                    maxAlicePath(nei, adjList, hopCount+1, currentNodeReward, alice, bobPath, amount));
            }
        }
        
        return maxReward != Integer.MIN_VALUE? maxReward: currentNodeReward;

    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int nodes = amount.length;
        List<Integer>[] adjList = new ArrayList[nodes];

        for(int i = 0; i < nodes; i++) {
            adjList[i] = new ArrayList<>();
        }

        for(int[] edge: edges) {
            int u = edge[0], v = edge[1];
            adjList[u].add(v);
            adjList[v].add(u);
        } 

        HashMap<Integer, Integer> bobPath = new HashMap<>();
        calculateBobPath(bob, adjList, bobPath, 0);
        
        //Calculate Alice path
        return maxAlicePath(0, adjList, 0, 0, -1, bobPath, amount);

    }
}