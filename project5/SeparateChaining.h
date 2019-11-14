//
// Created by galen byrd on 11/28/17.
//

#ifndef PROJECT5_SEPARATECHAINING_H
#define PROJECT5_SEPARATECHAINING_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Object>
class Separate_Chaining {
private:
    vector<vector<Object>> hash_table;
    function<string(const Object &item)> get_key;
    unsigned int hash(const Object &item) const {
        string key = get_key(item);
        // Horner's Hash
        unsigned int hash_val = 0;
        for (char ch : key) {
            hash_val = 37*hash_val + ch;
        }
        return hash_val % hash_table.size();
    }
public:
    // Requires: size is >= 0 (preferably prime)
    // parameter: function that takes an Object by const reference and returns a string key
    Separate_Chaining(int size, function<string(const Object &item)> func_name) {
        // create empty vectors at each index
        hash_table.resize(size);
        get_key = func_name;
    }

    // if the element isn't already in the hash table,
    // push it back onto the vector at the hash index
    void insert(const Object &item, int &reads) {
        if (!search(item, reads)) {
            // the item is not in the hash table. Insert it.
            int index = hash(item);
            hash_table[index].push_back(item);
        }
    }

    void remove(const Object &item, int &reads) {
        int index = hash(item);
        for (int i = 0; i < hash_table[index].size(); ++i) {
            ++reads;
            if (hash_table[index][i] == item) {
                // we found the item. Remove it.
                hash_table[index].erase(hash_table[index].begin() + i);
                break;
            }
        }
    }

    bool search(const Object &item, int &reads) const {
        int index = hash(item);
        // loop through the elements stored at that hash index
        for (Object element : hash_table[index]) {
            ++reads;
            if (element == item) {
                return true;
            }
        }
        return false;
    }

    void print_table(ostream& outs) const {
        for (int i = 0; i < hash_table.size(); ++i) {
            outs << i << ": ";
            for (int j = 0; j < hash_table[i].size(); ++j) {
                outs << hash_table[i][j] << ", ";
            }
            outs << endl;
        }
    }

    // TODO: resize to bigger table, rehash
};


#endif //PROJECT5_SEPARATECHAINING_H
