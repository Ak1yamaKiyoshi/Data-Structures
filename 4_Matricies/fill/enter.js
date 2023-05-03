// enter array from kbd
function enterA(array) {
    const prompt = require("prompt-sync")();
    for (let i = 0; i < array.length; i++) {
      for (let j = 0; j < array[i].length; j++) {
        const input = prompt("enter array elem:");
        array[i][j] = parseInt(input);
      }
    }
  }
  