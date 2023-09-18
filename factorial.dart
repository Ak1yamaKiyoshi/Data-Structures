void main() {
  print(

  fac(5)
  );
}

int fac(int num) {
  if (num > 1) {
    num *= fac(num-1);
  }
  return num;

}