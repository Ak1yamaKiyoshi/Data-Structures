import 'dart:io';

void main() {
  int userInput = -1;
  dynamic max = null;
  while (userInput != 0) {
    stdout.write("\n Enter num: ");
    userInput = int.parse(stdin.readLineSync() ?? "");
    if (max == null || max > userInput) max = userInput;
  }
  print(max);
  

}