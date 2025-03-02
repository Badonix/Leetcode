function mergeArrays(nums1: number[][], nums2: number[][]): number[][] {
    let map = new Map<number, number>();

    nums1.forEach(([key, value]) => {
        map.set(key, value);
    });

    nums2.forEach(([key, value]) => {
        map.set(key, (map.get(key) || 0) + value);
    });

    const sortedArray = [...map.keys()]
        .sort((a, b) => a - b)
        .map(key => [key, map.get(key)]);

    return sortedArray;
}
