/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let answ = []
    let i = 0;
    let j = i;
    const LEFT = 1
    const RIGHT = 2
    const BOTTOM = 3
    const UP = 4
    let direction = RIGHT
    let upWall = 0;
    let rightWall = matrix[0].length;
    let bottomWall = matrix.length
    let leftWall = -1;
    while(answ.length != matrix[0].length * matrix.length){
        if(direction == RIGHT){
            while(j < rightWall){
                answ.push(matrix[i][j])
                j++
            }
            rightWall--
            j--;
            i++
            direction = BOTTOM
        }else if(direction == BOTTOM){
            while(i < bottomWall){
                answ.push(matrix[i][j])
                i++
            }
            bottomWall--
            j--
            i--
            direction = LEFT
        }else if(direction == LEFT){
            while(j > leftWall){
                answ.push(matrix[i][j])
                j--
            }
            leftWall++
            i--
            j++
            direction = UP
        }else{
            while(i > upWall){
                answ.push(matrix[i][j])
                i--
            }
            upWall++
            j++
            i++
            direction = RIGHT
        }
    }
    return answ
};