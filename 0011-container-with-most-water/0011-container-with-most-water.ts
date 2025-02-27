function maxArea(height: number[]): number {
  let max = 0;
  let left = 0;
  let right = height.length - 1;
  while (left < right) {
    let currHeight = Math.min(height[left], height[right]);
    let currArea = currHeight * (right - left);
    if (currArea > max) {
      max = currArea;
    }
    if (height[left] > height[right]) {
      right--;
    } else {
      left++;
    }
  }
  return max;
}