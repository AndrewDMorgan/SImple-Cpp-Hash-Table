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
            int length = string.length() - 1;
            short first = string[0];
            short second = string[1];
            short secondLast = string[length - 1];
            short last = string[length];
            
            // adding the values together
            int hashIndex = first | second<<7 | secondLast<<14 | last<<21;
            // returning the value
            return hashIndex;
        }
    
    public:
        // allowing the values to be accsessed
        T & operator [](std::string string) {  return table[Hash(string)];  }
        
        // freeing the memory
        ~HashTable() {  free(table);  }
};

