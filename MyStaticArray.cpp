// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include<cstdlib>

#include "StaticArray.h"

vector<string> parseString(string);

const bool PLACED = true;

int main(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  StaticArray<double, 100> valStore;
  StaticArray<bool, 100> storeStatus;
  int storeTotal = 0;
  string index;
  string value;
  vector<string> tokens;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
      break;
    }
    cin >> value;
    cin.ignore(1000,10);
    valStore[atof(index.c_str())] = atof(value.c_str());
    storeStatus[atof(index.c_str())] = PLACED;
  }while(index != "Q" || index != "q");
  cout << endl;

  for(int i = 0; i < 100; i++){
    if(storeStatus[i] == PLACED){
      storeTotal++;
    }
  }
  cout << "You stored this many values: " << storeTotal << endl;

  cout << "The index-value pairs are:" << endl;
  for(int i = 0; i < 100; i++){
    if(storeStatus[i] != 0){
      cout << i << " => " << valStore[i] << endl;
    }
  }
  cout << endl;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
      break;
    }
    if(storeStatus[atof(index.c_str())] == PLACED && atof(index.c_str()) >=0 && atof(index.c_str()) < 100){
      double valFind = valStore[atoi(index.c_str())];
      cout << "Found it -- the value stored at " << index << " is " << valFind << "\n";
    }
    else{
      cout << "I didn't find it\n";
    }
  }while(index != "Q" || index != "q");
}

vector<string> parseString(string str){
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}
