function solution(array, commands) {
    var answer = [];

    // 직관적으로 변경 가능
    // const [sPosition, ePosition, position] = command

    commands.forEach(function(command) {
        const newArray = array.filter(function(v, i) {
            if(i >= command[0] - 1 && i <= command[1] - 1) return true; 
            return false; 
        })

        newArray.sort(function(a, b) {
            return a - b; 
        }); 

        answer.push(newArray[command[2] - 1]); 
    });

    console.log(answer); 
    return answer;
}

solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]);