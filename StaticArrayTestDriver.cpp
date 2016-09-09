// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <iostream>
#include <vector>
using namespace std;

#include<cassert>

#include "StaticArray.h"
#include "StaticArray.h"

int main2(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  StaticArray<int, 100> a;
  cout << "Using int values:" << endl;
  cout << "Testing Array::Array\n";
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);

  cout << "\nTesting the Array::operator[ ] setter\n";
  a[1] = 123;
  a[2] = 546;
  cout << "EXPECTED: 123 for a[1]\n";
  cout << "ACTUAL: " << a[1] << endl;
  assert(123 == a[1]);
  cout << "EXPECTED: 546 for a[2]\n";
  cout << "ACTUAL: " << a[2] << endl;
  assert(546 == a[2]);
  a[-1000] = 222;
  cout << "EXPECTED: 222 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(123 == a[1]);
  assert(546 == a[2]);
  assert(222 == a[-3]);
  assert(222 == a[100]);
  assert(222 != a[11]);
  assert(222 != a[0]);

  cout << "\nTesting the Array::operator[ ] getter\n";
  const StaticArray<int, 100> b = a;
  for (int i = 0; i < 10; i++)
    assert(a[i] == b[i]);

  cout << "\nConst object test" << endl;
  const StaticArray<int, 100> c;
  assert(c.capacity());
  assert(c[0] == c[0]);
  //-----------------------------------------------------
  StaticArray<bool, 100> a1;
  cout << "\nUsing bool values:" << endl;
  cout << "Testing Array::Array\n";
  for (int i = 0; i < a1.capacity(); i++)
    assert(a1[i] == 0);

  cout << "\nTesting the Array::operator[ ] setter\n";
  a1[1] = true;
  a1[2] = false;
  cout << "EXPECTED: true (1) for a[1]\n";
  cout << "ACTUAL: " << a1[1] << endl;
  assert(true == a1[1]);
  cout << "EXPECTED: false (0) for a[2]\n";
  cout << "ACTUAL: " << a1[2] << endl;
  assert(false == a1[2]);
  a1[-1000] = true;
  cout << "EXPECTED: true (1) for a[-1000]\n";
  cout << "ACTUAL: " << a1[-1000] << endl;
  assert(true == a1[1]);
  assert(false == a1[2]);
  assert(true == a1[-3]);
  assert(true == a1[100]);
  assert(true != a1[11]);
  assert(true != a1[0]);

  cout << "\nTesting the Array::operator[ ] getter\n";
  const StaticArray<bool, 100> b1 = a1;
  for (int i = 0; i < 10; i++)
    assert(a1[i] == b1[i]);

  cout << "\nConst object test\n";
  const StaticArray<bool, 100> c1;
  assert(c1.capacity());
  assert(c1[0] == c1[0]);
}
