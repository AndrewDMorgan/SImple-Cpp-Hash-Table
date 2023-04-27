#include <iostream>

// a class for a hash table (doesn't deal with collisions)
template <typename T>
class HashTable
{
    private:
        // the values being stored in the table
        T* table;
    
    public:
        HashTable()
        {
            // allocating the memory for the array
            table = (T*) malloc(sizeof(int) * 268435456);
        }
    
    private:
        // getting the hash index (probably not perfect)
        int Hash(std::string string)
        {
            // getting the first two and last two chars
            unsigned int length = string.length() - 1;
            char first = string[0];
            char second = string[1];
            char secondLast = string[length - 1];
            char last = string[length];
            
            // adding the values together
            int hashIndex = (int(first)) + (int(second) << 7) + (int(secondLast) << 14) + (int(last) << 21);
            
            // returning the value
            return hashIndex;
        }
    
    public:
        // allowing the values to be accsessed
        T & operator [](std::string string)
        {
            int hashIndex = Hash(string);
            return table[hashIndex];
        }
        
        // freeing the memory
        ~HashTable() {  free(table);  }
};

