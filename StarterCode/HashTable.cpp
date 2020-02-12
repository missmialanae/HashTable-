#include "HashTable.hpp"
#include "Record.hpp"
#include <string>
using namespace std;

/*Generic constructor*/
template <class T> HashTable<T>::HashTable(){
  //sets current size to zero
  currentSize = 0;

  // set hashMap
  hashMap = new Record <T> [MAXHASH];
  for (int i = 0; i < MAXHASH; i++){
    Record <T> r; // call to default constructor; sets record to emptyRecord
    hashMap[i] = r;
    //break;
  }
  //break;

}

/*Finds an element with a certain key and stores it in the value passed*/
template <class T> bool HashTable<T>::find(int key, T& value) {
//std::cout << "In find" << std::endl;
  int homeIndex = hashFunction(key);
  int index = homeIndex;
  int collisions = 0;

  while (true){
    // if its normal and its the first value
    if(hashMap[index].isNormal() && hashMap[index].getKey() == key){
      value = hashMap[index].getValue();
      return true;
      //break;

    }else if (hashMap[index].isEmpty()){
      return false;
      //break;

    }else{
      // if it is a tombstone or the key value doesnt matter
      collisions++;
      int offset =  probeFunction(key, collisions);
      index = (offset + homeIndex) % MAXHASH;
      //break;

      //throw(1);

    }// end else statement

    //break;

  }// end while statement
//std::cout << "Leave find" << std::endl;
}// end find function

// do we need a collison counter??

/*Inserts the key/value into the hashtable*/
template <class T> bool HashTable<T>::insert(int key, T value) {
//std::cout << "In insert" << std::endl;
  int numCollisions = 0;
  if(currentSize == MAXHASH || find(key, value)){
    return false;

  }
  // if there is an open spot
//std::cout << "Back to Insert" << std::endl;
  int homeIndex =  hashFunction(key);
  Record<T> rec(key, value);
  if(hashMap[homeIndex].isTombstone() || hashMap[homeIndex].isEmpty()){
    hashMap[homeIndex] = rec;

  }else{
    numCollisions++;
    bool inserted = false;

    while (!inserted){

      int offsets = probeFunction(key, numCollisions);
      int newSpot = (offsets + homeIndex) % MAXHASH;
      //  std::cout << "In while -- " << numCollisions << " -- " << newSpot << std::endl;

      //break;

      if(hashMap[newSpot].isTombstone() || hashMap[newSpot].isEmpty()){
        inserted = true;
        hashMap[newSpot] = rec;

        //break;

      }else{
        numCollisions++;

        //break; the program only runs like once at this point

      }// end else

      //break;

      // may want this later

      cout << alpha() ;
      cout << "\t"<< numCollisions<< endl;


    }// end while loop

  }
  currentSize++;
  return true;

  //break;
  //throw (1);
}


/*Returns the load factor for the hash*/

template <class T> float HashTable<T>::alpha() {
  float alpha = (float) currentSize / MAXHASH;
  return alpha;
}

/*Kills a table key*/
template <class T> bool HashTable<T>::remove(int key){
  int homeIndex = hashFunction(key);
  int index = homeIndex;
  int collisions = 0;

  while (true){
    // if its normal and its the first value
    if(hashMap[index].isNormal() && hashMap[index].getKey() == key){
      hashMap[index].kill();
      return true;
      //break;
    }else if (hashMap[index].isEmpty()){
      return false;
      //break;
    }else{
      int offset =  probeFunction(key, collisions);
      index = (offset + homeIndex) % MAXHASH;
      //break;
    }// end else statement
    //break;
  }// end while

} // end

/*Hash function for finding the home position*/
template <class T> int HashTable<T>::hashFunction(int key) {
  int index = key % MAXHASH;
  return index;

  //going to tell us where to insert it (home index)

  //return 0;

}

template <class T> int HashTable <T>::SecondHashFunction (int key){
  int index = (key * key) % MAXHASH;
  return index;
}// end second has function

/*The result of probing is returned with the new slot's position*/
template <class T> int HashTable<T>::probeFunction(int key, int numCollisions) {
  return numCollisions;
  // return numCollisions
}

template <class T> int HashTable<T>::SecondProbeFunction (int key, int numCollisions){
  return (numCollisions * numCollisions);
  // return numCollisions squared

}// end of second probe function

/*Deallocater*/
template <class T> HashTable<T>::~HashTable()
{
  delete[] hashMap;

  // just a infinite loop check
  std::cout << "the end"<< endl;
}

//Sets what types T can be
template class HashTable<int>;
template class HashTable<float>;
template class HashTable<string>;
