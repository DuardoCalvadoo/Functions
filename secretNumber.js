alert("Welcome!");

const max = 5;
const min = 1;
let secretNumber = Math.floor(Math.random() * (max - min + 1) + min);
console.log(secretNumber);
let chosedNumber;
let tries = 0;

while(chosedNumber != secretNumber){
    let input = prompt(`Choose a number between ${min} and ${max}`);

    while(input == null || input.trim() === "" || isNaN(input) || Number(input) < 1){
        input = prompt("Error! Please enter a valid number for the game!");
    }

    chosedNumber = Number(input);

    if(chosedNumber == secretNumber){
    alert(`You choose the correct number! ${secretNumber}`);
    }else{
        if(secretNumber > chosedNumber){
        alert(`The secret number is bigger than the chosed number(${chosedNumber})`);
        }else{
            if(secretNumber < chosedNumber ){
            alert(`The secret number is minor than the chosed number (${chosedNumber})`);
            }
        }
    }
    tries++;
}

let trieWord = tries > 1 ? `tries` : `try`;

alert(`${trieWord}:${tries}`);
