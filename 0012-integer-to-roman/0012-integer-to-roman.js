/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let M = ["", "M", "MM", "MMM"];
    let C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    let X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    let I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
          
    // Converting to roman
    let P = Math.floor(num / 1000);
    let Q = Math.floor((num % 1000) / 100);
    let R = Math.floor((num % 100) / 10);
    let S = num % 10;
  
    let thousands = M[P];
    let hundreds = C[Q];
    let tens = X[R];
    let ones = I[S];
          
    return thousands + hundreds + tens + ones;
};