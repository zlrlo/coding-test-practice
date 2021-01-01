function solution(answers) {
    var answer = [];

    const students = {
        answer : [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]],
        score : [0, 0, 0] 
    }

    answers.forEach((value, index) => {
        if(value === students.answer[0][index + 5 % 5]) {
            students.score[0] += 1; 
        }

        if(value === students.answer[1][index + 8 % 8]) {
            students.score[1] += 1; 
        }

        if(value === students.answer[2][index + 10 % 10]) {
            students.score[2] += 1; 
        }
    });

    const maxScore = students.score.reduce((prev, curr) => prev > curr ? prev : curr ); 

    students.score.forEach((v, i) => {
        if(v === maxScore) answer.push(i + 1); 
    })

    return answer;
}

solution([1]); 