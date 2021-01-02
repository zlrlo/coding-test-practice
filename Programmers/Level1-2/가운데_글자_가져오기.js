function solution(s) {
    var answer = '';

    const sLen = s.length; 
    let mid = Math.floor(sLen / 2); 
    
    answer = sLen % 2 === 0 ? s[mid - 1] + s[mid] : s[mid]; 

    return answer;
}

solution("abcde");