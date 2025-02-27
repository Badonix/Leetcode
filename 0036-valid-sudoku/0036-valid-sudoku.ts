function isValidSudoku(board: string[][]): boolean {
  let rows = true;
  let columns = true;
  let boxes = true;
  row_loop: for (let i = 0; i < board.length; i++) {
    let rowHash = {};
    for (let j = 0; j < board[i].length; j++) {
      if (board[i][j] != ".") {
        if (rowHash[board[i][j]] == undefined) {
          rowHash[board[i][j]] = j;
        } else {
          rows = false;
          break row_loop;
        }
      }
    }
  }
  if (!rows) {
    return false;
  }
  column_loop: for (let i = 0; i < board[0].length; i++) {
    let columnHash = {};
    for (let j = 0; j < board[i].length; j++) {
      if (board[j][i] != ".") {
        if (columnHash[board[j][i]] == undefined) {
          columnHash[board[j][i]] = j;
        } else {
          columns = false;
          break column_loop;
        }
      }
    }
  }
  if (!columns) {
    return false;
  }

  let boxIntervals = [
    { x1: 0, y1: 0, x2: 2, y2: 2 },
    { x1: 0, y1: 3, x2: 2, y2: 5 },
    { x1: 0, y1: 6, x2: 2, y2: 8 },
    { x1: 3, y1: 0, x2: 5, y2: 2 },
    { x1: 3, y1: 3, x2: 5, y2: 5 },
    { x1: 3, y1: 6, x2: 5, y2: 8 },
    { x1: 6, y1: 0, x2: 8, y2: 2 },
    { x1: 6, y1: 3, x2: 8, y2: 5 },
    { x1: 6, y1: 6, x2: 8, y2: 8 },
  ];

  boxes_loop: for (let box = 0; box < boxIntervals.length; box++) {
    let currentBox = {};
    let boxCoords = boxIntervals[box];
    for (let i = boxCoords.x1; i <= boxCoords.x2; i++) {
      for (let j = boxCoords.y1; j <= boxCoords.y2; j++) {
        if (board[i][j] != ".") {
          if (currentBox[board[i][j]] == undefined) {
            currentBox[board[i][j]] = i;
          } else {
            boxes = false;
            break boxes_loop;
          }
        }
      }
    }
  }
  if (!boxes) {
    return false;
  }

  return true;
};