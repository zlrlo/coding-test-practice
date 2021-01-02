const getMinDist = (y, x, board, boardY, boardX) => {
    let distY = 0;
    let distX = 0; 

    let dy = y; 
    let dx = x; 

    while(true) {
        if(dx >= boardX || board[y][dx] === 0) break;
        distX += 1; 
        dx += 1; 
    }

    while(true) {
        if(dy >= boardY || board[dy][x] === 0) break;
        distY += 1; 
        dy += 1; 
    }

    return Math.min(distY, distX); 
}

const checkBoard = (board, minDist, y, x) => {
    for(let i = 0; i < minDist; i++) {
        for(let j = 0; j < minDist; j++) {
            if(board[y + i][x + j] === 0) return false; 
        }
    }

    return true; 
}

function solution(board)
{
    var answer = 0;

    const boardY = board.length;
    const boardX = board[0].length;  
    for(let y = 0; y < boardY; y++){
        for(let x = 0; x < boardX; x++){
            if(board[y][x] === 1) {
                const minDist = getMinDist(y, x, board, boardY, boardX); 
                const isPossible = checkBoard(board, minDist, y, x); 
                if(isPossible && answer < minDist * minDist) answer = minDist * minDist;  
            }
        }
    }


    console.log(answer); 
    return answer;
}

solution([[0,0,1,1],[1,1,1,1]]);