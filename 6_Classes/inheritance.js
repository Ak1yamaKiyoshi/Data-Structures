class Triangle {
    constructor(a, b, angleA) {
        this._a = a;
        this._b = b;
        this._c = angleA;
        this.angleA = 51.34; // deg
    }

    getC() {
        return Math.sqrt(this._a * this._a + this._b * this._b);
    }
    setC(value) {
        this.c = value;
    }

    getA() {
        return this._a;
    }
    setA(value) {
        this._a = value;
    }

    getB() {
        return this._a;
    }
    setB(value) {
        this._a = value;
    }

    periemeter () {
        return this._a + this._b + this._c;
    }
    
    semiperiemeter() {
        return (this._a + this._b + this._c)/2;
    }

    height() {
        return (this._a * this._b) / this._c;
    }
}


class Triangle2 extends Triangle { 
    constructor(a, b, angleA) {
        super(a, b, angleA); // deg
    }

    getAnotherA() {
        return this._a;
    }
}



let tri = new Triangle(5, 4, 5.099);
console.log(tri.c);
console.log(tri.getC);
console.log(tri.setC(6.01));
console.log(tri.getC(6.01));
console.log(tri.height());
console.log(tri.periemeter());

let tri1 = new Triangle2(4, 5, 5.1);
console.log(tri1.getA());
console.log(tri1.height());
console.log(tri1.getAnotherA());
//
