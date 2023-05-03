
function euclideanAlg(a, b) {
    if (b == 0) {
        return a;
    }
    else {
        return euclideanAlg(b, a % b);
    }
}
console.log(euclideanAlg(68, 102));

