class LRUCache {

  private HashMap<Integer, Integer> map;
  private ArrayList<Integer> order;
  // {1: 1, 2: 2}
  //
  // [2, 1]

  private int cap;

  public LRUCache(int capacity) {
    cap = capacity;
    map = new HashMap<>();
    order = new ArrayList<>();
  }

  public int get(int key) {
    if (map.containsKey(key)) {
      order.remove(Integer.valueOf(key));
      order.add(key);
      return map.get(key);
    }
    return -1;
  }

  public void put(int key, int value) {
    if (map.size() < cap) {
      if (map.containsKey(key)) {
        map.put(key, value);
        order.remove(Integer.valueOf(key));
        order.add(key);
      } else {
        map.put(key, value);
        order.add(key);
      }
      return;
    }

    if (map.containsKey(key)) {
      map.put(key, value);
      order.remove(Integer.valueOf(key));
      order.add(key);
      return;
    }

    int toDelete = order.get(0);
    map.remove(toDelete);
    order.remove(0);
    order.add(key);
    map.put(key, value);
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
