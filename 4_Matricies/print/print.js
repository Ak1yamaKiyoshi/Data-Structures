
// print array 
function printA(array) {
    let str;
    for (let i = 0; i < array.length; i++) {
      str = array[i].join(", ");
      console.log("[" + str + "]");
    }
  }