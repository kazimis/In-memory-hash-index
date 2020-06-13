/*
 * Bucket.h
 * Class Description: This class is used to implement buckets in exstensible hash index.
 * Author: Sarajuddin Kazimi
 * Date June 12, 2020
*/

#include <iostream>
using namespace std;
class Bucket {

  private:
    int* arr_keys =NULL;    //array of keys
    int capacity;     //capacity of bucket
    int num_el;       //number of keys in this bucket
    int local_depth;  //local depth

    /**helper functions**/
    // returns hash value of key
    int h(int key, int local_d);
  public:

    /* Desc:  Default Constructor. Allocate arr_keys of size 4.
              set local_depth to 1, set capacity to 4 and set num_el to 0. */
    Bucket();


    /* Parametric constructor.
       Desc:  Allocate arr_keys of size of "num_keys"
              set local_depth to local_depth, set capacity to num_keys
              and set num_el to 0*/
    Bucket(int num_keys, int local_depth);


    //Copy Constructor
    Bucket(const Bucket & rhs );


    // Assignment operator Overload
    Bucket& operator =(const Bucket &rhs);


    // Desc: Increment local_depth
    void incr_local_depth();


    // Desc: get local_depth
    int get_local_depth()const;


    /* Desc:  Search this bucket for the key; if found return true, otherwise return false
    */
    bool is_found(int key)const;


    /*Desc: search this bucket for the key; if found, removes all matching values
            return true if the key was found and removed, false otherwise
      post: key is removed, keys are shifted in arr_keys, and num_el is deremented accordingly*/
    bool remove(int key);


    /* Desc: return true if bucket is full, false otherwise */
    bool is_full() const;


    /* Desc:  Insert key to this Bucket.
       Pre:   Bucket has free space.
       Post:  free_space is decremented */
    void insert_key(int key);


    /* Desc:  Split current bucket and into two buckets and distribute keys.
              and return position of the new bucket in directory.
    */
    int split(Bucket* bucket1, Bucket* bucket2);


    // Description: Prints the content of "this".
    friend ostream & operator<<(ostream & os, const Bucket & aBucket);



    //Desc: Destructor
    ~Bucket();


      // // Desc: Copy Constructor. (O(N))
      // ExtensibleHashTable(const PriorityQueue& rhs);


      // // Desc: Destructor. (O(N))
      // //Post: All allocated memory by the class is released.
      // ~PriorityQueue();
      //
      //
      // // Desc: Returns true if Priority Queue empty. (O(1))
      // bool isEmpty() const;
      //
      //
      // // Desc: Returns length of the Priority Queue. (O(1))
      // int getLength() const;
      //
      //
      // // Desc: Inserts x in sorted order. (O(N))
      // //  Pre: Priority Queue is sorted.
      // // Post: Priority Queue remains sorted. len is increased by one.
      // void enqueue(const T& x);
      //
      //
      // // Desc: Removes the element with "highest" priority. (O(1))
      // //  Pre: Priority Queue not empty.
      // //       Throws EmptyDataCollectionException if Priority Queue empty.
      // //Post:  length is decreased by one. PriorityQueue remains sorted
      // void dequeue() throw(EmptyDataCollectionException);
      //
      //
      // // Desc: Returns the element with the "highest" priority. (O(1))
      // //  Pre: Priority Queue not empty.
      // //       Throws EmptyDataCollectionException if Priority Queue empty.
      // // Post: Priority Queue is unchanged.
      // T& peek() const throw(EmptyDataCollectionException);
      //
      //
      //
      // //Description: 'Inline function. Prints the content of PriorityQueue P
      // friend ostream & operator<< (ostream & os, const PriorityQueue & P){
      //     //freind function to class. We can get data directly.
      //     Node<T>* current= P.head;
      //     while(current){
      //       os<<current->data<<endl;
      //       current = current->next;
      //     }
      //     return os;
      // }

}; // PriorityQueue
