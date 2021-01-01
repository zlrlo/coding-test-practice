function solution(answers) {
    var answer = [];

    const students = {
        answer : [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]],
        score : [0, 0, 0] 
    }

    students.score[0] = answers.filter((v, i) => v === students.answer[0][i % 5]).length
    students.score[1] = answers.filter((v, i) => v === students.answer[1][i % 8]).length;
    students.score[2] = answers.filter((v, i) => v === students.answer[2][i % 10]).length;

    const maxScore = students.score.reduce((prev, curr) => prev > curr ? prev : curr ); 

    students.score.forEach((v, i) => {
        if(v === maxScore) answer.push(i + 1); 
    })

    return answer;
}

solution([1, 2, 3, 4, 5]); 