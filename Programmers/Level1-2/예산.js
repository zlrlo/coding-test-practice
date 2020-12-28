function solution(d, budget) {
    var answer = 0;

    // 정렬
    d.sort((a, b) => {
        return a - b; 
    })

    if(d[0] > budget) {
        answer = 0; 
        return answer; 
    }

    // budget 초과하는 시점 찾기
    let sum = 0; 
    d.forEach((currentValue, index) => {
       sum += currentValue; 
       if(sum <= budget) {
           answer = index + 1; 
       }
    })

    return answer;
}

solution([2, 2, 3, 3], 10); 