void main() {
  print(euclid(68, 102));
} 

int euclid(int a, int b) {
  if ( b == 0 ) return a;
  return euclid(b, a % b);
}