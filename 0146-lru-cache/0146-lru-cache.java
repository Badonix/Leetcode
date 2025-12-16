class LRUCache {

    private HashMap<Integer, Integer> map;
    private ArrayList<Integer> order;
    private int cap;
    public LRUCache(int capacity) {
        map = new HashMap<>();        
        order = new ArrayList<>();        
        cap = capacity;
    }
    
    public int get(int key) {
        if(map.containsKey(key)){
            order.remove(Integer.valueOf(key));
            order.add(key);
            return map.get(key);
        }        
        return -1;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            order.remove(Integer.valueOf(key));
            order.add(key);
            map.put(key, value);
            return;
        }
        if(map.size() < cap){
            map.put(key, value);
            order.add(key);
            return;
        }
        map.remove(order.get(0));
        order.remove(0);
        map.put(key, value);
        order.add(key);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */