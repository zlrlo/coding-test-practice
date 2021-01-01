const checkStack = (data, num, k, total) => {
    for(let i = data.stack.length - 1; i >=0; i--){
        if(data.cnt === k) break; 

        if(data.stack[i] < num) {
            data.stack.pop();
            data.cnt += 1; 
        }
        else {
            if(data.stack.length < total)
            data.stack.push(num); 
            return; 
        } 
    }

    data.stack.push(num); 
}

function solution(number, k) {
    var answer = '';

    const numbers = number.split(''); 

    let data = {
        stack : [], 
        cnt : 0
    }

    let cntFlag = false; 
    
    const total = numbers.length - k; 

    numbers.forEach((num) =>{
        if(data.cnt === k || data.stack.length === 0) {
            data.stack.push(num); 
        }
        else {
            checkStack(data, num, k, total); 
        }

    }); 

    answer = data.stack.join(''); 

    return answer;
}

solution("1111", 2); 