function tupleSameProduct(nums: number[]): number {
  const map = {};

  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      let product = nums[i] * nums[j];

      if (!map[product]) {
        map[product] = [];
      }
      map[product].push([nums[i], nums[j]]);
    }
  }

  let count = 0;
  for (let key in map) {
    let length = map[key].length;
    if (length >= 2) {
      count += 8 * (length * (length - 1)) / 2;
    }
  }

  return count;
}
