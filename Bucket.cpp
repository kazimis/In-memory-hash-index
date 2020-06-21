/*
 * Bucket.cpp
 * Class Description: This class is used to implement buckets in exstensible hash index.
 * Author: Sarajuddin Kazimi
 * Date June 18, 2020
*/

#include "Bucket.h"
#include <exception>
/**helper functions**/
// returns hash value of key
int Bucket :: h(int key, int local_d){
  return (key & ((1<<local_d)-1));
}



/* Desc:  Default Constructor. Allocate arr_keys of size 4.
          set local_depth to 1, set capacity to 4 and set num_el to 0. */
Bucket::Bucket(){
  arr_keys = new int[4];
  num_el = 0;
  capacity = 4;
  local_depth = 1;
}


/* Parametric constructor.
   Desc:  Allocate arr_keys of size of "num_keys"
          set local_depth to local_depth, set capacity to num_keys and set num_el to 0*/
Bucket::Bucket(int num_keys, int local_d){
  arr_keys = new int[num_keys];
  num_el = 0;
  capacity = num_keys;
  local_depth = local_d;
}


//Copy Constructor
Bucket::Bucket(const Bucket & rhs ){
  num_el = rhs.num_el;
  capacity = rhs. capacity;
  local_depth = rhs.local_depth;
  arr_keys = new int[capacity];
  //copy elements
  if (rhs.arr_keys){
    for(int i = 0; i < capacity; i++){
      arr_keys[i] = rhs.arr_keys[i];
    }
  }else{
    arr_keys = NULL;
  }
}


// Assignment operator Overload
Bucket& Bucket :: operator =(const Bucket &rhs){
  if (this != &rhs){
    if(arr_keys!= NULL){
      delete [] arr_keys;
      arr_keys = NULL;
    }
    num_el = rhs.num_el;
    capacity = rhs. capacity;
    local_depth = rhs.local_depth;
    arr_keys = new int[capacity];

    if(rhs.arr_keys){
      for(int i = 0; i < capacity; i++){
        arr_keys[i] = rhs.arr_keys[i];
      }
    }else{
      arr_keys = NULL;
    }
  }
  return *this;
}

// Desc:  Increment local_depth
void Bucket::incr_local_depth(){
  local_depth ++;
}


// Desc:  get local_depth
int Bucket::get_local_depth()const{
  return local_depth;
}


/* Desc:  Search this bucket for the key; if found return true, otherwise return false
*/
bool Bucket:: is_found(int key)const{
  for(int i = 0; i < num_el; i++){
    if(arr_keys[i]== key){
      return true;
    }
  }
  return false;
}


/*Desc: search this bucket for the key; if found, removes all matching values
        return true if the key was found and removed, false otherwise
  post: key is removed, keys are shifted in arr_keys, and num_el is deremented accordingly*/
bool Bucket::remove(int key){
  int* tmp = new int[capacity];
  int j = 0;
  for(int i = 0; i < num_el; i++){
    int this_key = arr_keys[i];
    if(this_key!= key){
      tmp[j++] = this_key;
    }
  }
  delete [] arr_keys;
  arr_keys = tmp;
  bool is_removed = j != num_el;
  num_el = j;
  return is_removed;
}


/* Desc: return true if bucket is full, false otherwise */
bool Bucket::is_full() const{
  return num_el ==capacity;
}


/* Desc:  Insert key to this Bucket.
   Pre:   Bucket has free space.
   Post:  free_space is decremented*/
void Bucket::insert_key(int key){
  int count = 0;
  for(int i = 0; i < num_el;i++){
    if (arr_keys[i] == key){
      count++;
    }
    if(count >= 2){
      throw std::runtime_error("An attempt to insert identical search key values in bucket "
                                "which is already filled with identical search key values");
    }
  }
  arr_keys[num_el] = key;
  num_el++;
}


/* Desc:  Split current bucket and into two buckets and distribute keys.
          and return position of the new bucket in directory.
*/
int Bucket::split(Bucket* bucket1, Bucket* bucket2){
  int prev_index = h(arr_keys[0], local_depth-1);
  for(int i = 0; i < num_el; i++){
    int key = arr_keys[i];
    if(h(key,local_depth) == prev_index){
      bucket1->insert_key(key);
    }else{
      bucket2->insert_key(key);
    }
  }
  return h(bucket2->arr_keys[0], local_depth);
}



/* Desc:  Overloader operator << to print bucket.
   Pre:   Bucket is not empty
*/
ostream & operator<<(ostream & os, const Bucket & aBucket) {
  os<<"[";
  if(aBucket.num_el ==0){
    for(int i = 0; i <aBucket.capacity-1; i++){
      os<<"-,";
    }
    os<<"-";
  }else{
    int i;
    for(i = 0; i < aBucket.num_el-1; i++){
      os << aBucket.arr_keys[i]<<",";
    }
    os<<aBucket.arr_keys[i++];
    while(i < aBucket.capacity){
      if(i != aBucket.capacity){
        os<< ",-";
      }
      i++;
    }
  }
  os<<"] ("<< aBucket.local_depth <<")";
  return os;
}


//Desc: Destructor
Bucket::~Bucket(){
  cout<<"bucket destructor\n";
  delete [] arr_keys;
}
