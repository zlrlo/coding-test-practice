function solution(s) {
    var answer = '';

    let p1 = 0; 
    let p2 = s.length - 1; 

    while(true) {
        let v1 = s[p1]; 
        let v2 = s[p2]; 

        if(p1 === p2) {
            answer = v1; 
            break; 
        }

        if(p1 > p2) {
            answer = (s[p2] + s[p1]); 
            break; 
        }

        p1 += 1; 
        p2 -= 1; 
    }

    return answer;
}

solution("q"); 