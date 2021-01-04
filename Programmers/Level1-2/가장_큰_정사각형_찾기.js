const makeAccBoard = (accBoard, board, boardY, boardX) => {
    accBoard[0][0] = board[0][0]; 

    for(let y = 1; y < boardY; y++){
        accBoard[y][0] = accBoard[y - 1][0] + board[y][0]; 
    }

    for(let x = 1; x < boardX; x++){
        accBoard[0][x] = accBoard[0][x - 1] + board[0][x]; 
    }

    for(let y = 1; y < boardY; y++){
        for(let x = 1; x < boardX; x++){
            accBoard[y][x] = accBoard[y - 1][x] + accBoard[y][x - 1] - accBoard[y - 1][x - 1] + board[y][x]; 
        }
    }
}

const getMaxArea = (y, x, accBoard, boardY, boardX, board, n) => {
    let dy, dx;
    let maxArea = 1;  

    if(n === 0) n = 1; 

    while(true) {
        dy = y + n; 
        dx = x + n; 
        if(dy < 0 || dy >= boardY || dx < 0 || dx >= boardX) break; 

        if(board[dy][dx] === 0) break; 
        let sum = 0; 
        sum += accBoard[dy][dx]; 
        if(x - 1 >= 0) sum -= accBoard[dy][x - 1];
        if(y - 1 >= 0) sum -= accBoard[y - 1][dx];
        if(y - 1 >= 0 && x - 1 >= 0) sum += accBoard[y - 1][x - 1];  

        if(sum === ((n + 1)*(n + 1))) {
            maxArea = sum;
            n += 1;
        }
        else break;  
         
    }

    return maxArea; 
}

function solution(board)
{
    var answer = 0;

    const boardY = board.length; 
    const boardX = board[0].length;
    
    let accBoard = Array.from(Array(boardY), () => new Array(boardX)); 

    makeAccBoard(accBoard, board, boardY, boardX); 

    for(let y = 0; y < boardY; y++){
        for(let x = 0; x < boardX; x++){
            if(board[y][x] === 1) {
                const maxArea = getMaxArea(y, x, accBoard, boardY, boardX, board, Math.sqrt(answer)); 
                if(answer < maxArea) answer = maxArea;  
            }
        }
    }

    return answer;
}

solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]); 