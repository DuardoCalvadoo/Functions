let sum = 0;
let numberOfValues = prompt("Type the number of values");

while(numberOfValues == null || numberOfValues.trim() === "" || isNaN(numberOfValues) || Number(numberOfValues) < 1){
   numberOfValues = prompt("Error! Please enter a valid number for the total count");
}

numberOfValues = Number(numberOfValues);

for(i = 1; i <= numberOfValues; i++){
    let input = prompt(`type the value of the number ${i} position`);
    let number= Number(input);

    while(input == null || input.trim() === "" || isNaN(Number(input))){
        input = prompt(`Error! Please enter a valid number for value ${i}:`);
        number = Number(input);
    }
    sum += number;
}

let average = sum/numberOfValues;
alert(`The average is: ${average}`);
