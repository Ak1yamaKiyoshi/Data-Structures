void main() {
  print(isPrime(13));
}

bool isPrime(int i) {
  for (var j = 2; j < i; j++) {
    if (i % j == 0) {
      return false;
    }
  }
  return true;
}