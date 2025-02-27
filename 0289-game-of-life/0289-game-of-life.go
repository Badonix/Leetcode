func gameOfLife(board [][]int) {
    rows := len(board)
    cols := len(board[0])
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            neighbours := countNeighbours(board, i, j)
            if board[i][j] == 1 {
                if neighbours < 2 || neighbours > 3 {
                    board[i][j] = 2
                }
            } else {
                if neighbours == 3 {
                    board[i][j] = -1
                }
            }
        }
    }
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if board[i][j] == 2 {
                board[i][j] = 0
            } else if board[i][j] == -1 {
                board[i][j] = 1
            }
        }
    }
}
func countNeighbours(board [][]int, x, y int) int {
    count := 0
    rows := len(board)
    cols := len(board[0])
    for _, dir := range [][]int{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1},
    } {
        newX := x + dir[0]
        newY := y + dir[1]
        if newX >= 0 && newX < rows && newY >= 0 && newY < cols {
            if board[newX][newY] == 1 || board[newX][newY] == 2 {
                count++
            }
        }
    }
    return count
}
