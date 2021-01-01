const Run = (numbers, target, value, level) => {
    if(level === numbers.length) {
        if(value === target) return 1; 
        return 0; 
    }

    let cnt = 0; 
    cnt += Run(numbers, target, value + numbers[level], level + 1); 
    cnt += Run(numbers, target, value - numbers[level], level + 1);

    return cnt; 
}

function solution(numbers, target) {
    var answer = 0;

    answer = Run(numbers, target, 0, 0); 

    return answer;
}

solution([1, 1, 1, 1, 1], 3); 