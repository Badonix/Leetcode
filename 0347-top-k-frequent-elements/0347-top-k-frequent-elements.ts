function topKFrequent(nums: number[], k: number): number[] {
  let bucket = [];
  let hashmap = {};
  nums.forEach((el) => {
    hashmap[el] = hashmap[el] != undefined ? hashmap[el] + 1 : 1;
  });
  for (let property in hashmap) {
    if (bucket[hashmap[property]]) {
      bucket[hashmap[property]].push(property);
    } else {
      bucket[hashmap[property]] = [property];
    }
  }
  let arr = [];
  bucket = bucket.flat();

  while (k > 0) {
    if (bucket[bucket.length - 1]) {
      k--;
      arr.push(bucket[bucket.length - 1]);
      bucket.length -= 1;
    }
  }
  return arr;
};