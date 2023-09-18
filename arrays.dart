import 'dart:math';

void main() {
  List <int> array = fill(10, 5, 7);
  List <int> array1= [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
  print("fill rand 5 <num< 7: $array");
  array = fillSq(10);
  print("fill with sequence : $array");
  array = shiftCycle(array, true, 3);
  print("shift cycle left 3 : $array");
  array = shiftCycle(array, false, 3);
  print("shift cycle right 3: $array");
  array = shift(array, true, 3);
  print("shift       left 3 : $array");
  array = shift(array, false, 2);
  print("shift       right 2: $array");
  print("array1 before copy : $array1");
  array1 = copy(array, array1);
  print("array1 after  copy : $array1");
  print(" max of array      : ${maxInArray(array)}");
  print(" min of array      : ${minInArray(array)}");
  print(" sum of array      : ${sumOfArray(array)}");
  print("  is array sorted  : ${isSorted(array)}");
  array = shift(array, false, 1);
  print("shift       right 1: $array");
  print("  is array sorted  : ${isSorted(array)}");
  print(" binary search 3   : ${binarySearch(array, 3)}");
  print(" binary search 10  : ${binarySearch(array, 10)}");
  array = reverse(array);
  print(" reversed array    : $array");
  array = bubbleSort(array);
  print(" bubble sort       : $array");
  array = fill(10, 0, 10);
  print("fill rand 0 <num<10: $array");
  array = insertionSort(array);
  print(" insertion sort    : $array");
}


List<int> insertionSort(List<int> array) {
  for (int i = 1; i < array.length; i++ ) {
    int num = array[i], j = i-1;
    while (j >= 0 && num < array[j]) 
      array[j+1] = array[j--];
    array[j+1] = num; 
  }
  return array;
}

List<int> bubbleSort(List<int> array) {
  for (int i = 0; i < array.length-1; i++) {
    bool flag = false;
    for (int j = 0; j <array.length-1-i; j++) 
      if ( array[j] > array[j+1] ) {
        var temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        flag = true;
      }
    if (!flag) break;
  }
  return array;
}

List<int> reverse(List<int> array) {
  for (var i = 0, j = array.length-1; i < array.length/2; i++, j--) {
    var temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
  return array;
}

bool binarySearch(List <int> array, int target) {
  int left = 0,  right = array.length-1, middle;
  if( !isSorted(array)) return false;
  while (array[left] < target && array[right] > target && (right - left ) > 1 ) {
    middle = ((right + left + 1) / 2).round();
    if (target > array[middle]) left = middle;
    else right = middle;
  }
  if (array[left] == target || array[right] == target) 
    return true;
  return false;
}

bool isSorted(List <int> array) {
  for (var i = 0; i < array.length-1; i++) 
    if (array[i] > array[i+1]) return false;
  return true;
}

int sumOfArray(List<int> array) {
  return array.reduce((value, element) => value + element);
}

int minInArray(List<int> array) {
  return array.reduce((value, element) => min(value, element));
}

int maxInArray(List<int> array) {
  return array.reduce((value, element) => max(value, element));
}

List<int> copy(array1, array2) {
  List<int> arr = [];
  for( int i = 0; i < array1.length; i++ ) {
    arr.add(array1[i]);
  }
  array2 = arr;
  return array2;
}

List<int> fill(int len, int from, int to){
  var rand = Random();
  List <int> array = [];
  for ( int i = 0; i < len; i++ ) {
    array.add( from + rand.nextInt(to-from) );
  }
  return array;
}

List<int> fillSq(int len) {
  List <int> array = [];
  for ( int i = 0; i < len; i++ ) 
    array.add( i+1 );
  return array;
}


List<int> shift(List<int> array, bool toLeft, int shiftSize) {
    for (int i=0; i<shiftSize; i++) 
        if (toLeft == true) {
            for (int j=0; j<array.length-1; j++)
                array[j] = array[j+1];
            array[array.length-1] = 0;
        } else {
            for (int j=array.length-1; j>0; j--)
                array[j] = array[j-1];
            array[0] = 0;
        }
    return array;
}

List<int> shiftCycle(List<int> array, bool toLeft, int shiftSize) {
    for(int j = 0; j < shiftSize; j++) 
        if (toLeft == true) {
            var temp = array[0];
            for (int i = 0; i < array.length-1; i++)
                array[i] = array[i+1];
            array[array.length-1] = temp;
        }
        else {
            var temp = array[array.length-1];
            for (int i = array.length-1; i > 0; i--)
                array[i] = array[i-1];
            array[0] = temp;
        }
    return array;
}
