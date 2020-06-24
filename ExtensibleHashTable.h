/*
 * ExtensibleHashTable.cpp
 * Author: Sarajuddin Kazimi
 * Date June 12, 2020
*/

#include <iostream>
#include "Bucket.h"
using namespace std;
class ExtensibleHashTable {
  private:

    Bucket** directory;
    int global_depth;
    int bucket_size;

    /**helper functions**/
    // returns hash value of key
    int h(int key);


    /*Desc: Double the size of directory and distribute pointers
            Delete the previous directory*/
    void double_directory();


    /*Desc: Split bukets and creates two new buckets; distributes keys accordingly
             and remove old bucket.
     Post:   Local depth is incremented*/
    void split_bucket(int key);

  public:

    /* Default constructor
       Desc:  This constructor creates an empty hash table; bucket should store 4 keys
              set global depth to 1 and directory size is 2^global depth. */
    ExtensibleHashTable();


    /* Parametric constructor.
       Desc:  creates an empty hash table; bucket_size is set to bucket_size;
       set global depth to 1 and directory size is 2^global depth.*/
    ExtensibleHashTable(int bucket_size);



    /* Desc: Copy Constructor.*/
    ExtensibleHashTable(const ExtensibleHashTable& rhs);


    //Desc: Inserts the key into the hash table in the appropriate bucket
    void insert(int key);


    //Desc: Search the hash table for the key; if found returns true, otherwise returns false
    bool find(int key);


    /*Desc: Search the hash table for the key; if found, remove all matching values;
            return true if the key was found and removed, false otherwise*/
    bool remove(int key);


    //Desc: prints the contents of the directory and buckets
    void print();
    // // Description: Prints the content of "this".
    // friend ostream & operator<<(ostream & os, const Bucket & aExtensibleHashTable);


    // Desc:  Destructor
    ~ExtensibleHashTable();
};
