/**
 * @param {number[][]} grid
 * @param {number} x
 * @return {number}
 */
var minOperations = function(grid, x) {
    let arr = [] 
    for(let i = 0; i < grid.length; i++){
        for(let j = 0; j < grid[0].length; j++){
            arr.push(grid[i][j])
        }
    }
    arr = arr.sort((a, b)=>a-b)
    for(let i = 1; i < arr.length; i++){
        if(Math.abs(arr[i] - arr[0]) % x != 0){
            return -1
        }
    }
    let middle = arr[parseInt(arr.length / 2)]
    let operations = 0;
    arr.forEach((el)=>{
        operations += Math.abs(el - middle) / x
    })
    return operations;
};