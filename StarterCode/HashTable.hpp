#pragma once
#include "Record.hpp"
#include <iostream>
#define MAXHASH 1000
template <class T> class HashTable

{
private:
  Record<T> *hashMap;
  //holding record of T
    int currentSize;
    // how many records you have
    // no duplicate records


public:
	HashTable();
	bool find(int key, T& value);
	bool insert(int key, T value);
	float alpha();
	bool remove(int key);
  int hashFunction(int);
  int probeFunction(int, int);

//extra functions
  int SecondProbeFunction(int, int);
  int SecondHashFunction(int);

	~HashTable();
    //Add code here

    friend ostream& operator<<(ostream& os, const HashTable<T>& me){
      for(int i = 0; i < MAXHASH; i++){
        os << me.hashMap[i] << std::endl;
      }
      return os;
    }
};
