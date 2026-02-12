function factorial(number){
    if(number == 0 || number == 1){
        return 1;
    }

    let result = number;

    for(i = number - 1; i >= 1; i--){
    result = result * i;
    }
    return result;
}
