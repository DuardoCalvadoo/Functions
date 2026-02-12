function retangularArea(length, width){
    let area = length*width;
    let perimeter = (length*2) + (width*2);
    return{
        area : area, perimeter: perimeter};
} 
let result = retangularArea(5,5)
console.log(result.area);
console.log(result.perimeter);


function retangularArea2(length2, width2){
    return{
        area2: length2 * width2, perimeter2: (length2 * 2) + (width2*2)
    };
}

let {area2, perimeter2} = retangularArea2(5, 5);

console.log(`the area is ${area2}`);
console.log(`the perimeter is ${perimeter2}`);
