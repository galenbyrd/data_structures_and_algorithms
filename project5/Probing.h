//
// Created by galen byrd on 11/28/17.
//

#ifndef PROJECT5_PROBING_H
#define PROJECT5_PROBING_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Object>
class Probing {
private:
    int num_hash_elements;
    enum hash_status {ACTIVE, EMPTY, REMOVED};
    struct hash_element {
        Object item;
        hash_status status;
    };
    vector<hash_element> hash_table;
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

    void rehash(int &reads) {
        vector<hash_element> old_table = hash_table;
        hash_table.resize(next_prime(2*old_table.size()));
        for (hash_element &element : hash_table) {
            element.status = EMPTY;
            element.item = Object();
        }
        num_hash_elements = 0;
        for (hash_element &element : old_table) {
            if (element.status == ACTIVE) {
                insert(element.item, reads);
            }
        }
    }

    int next_prime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

public:
    // Requires: size is >= 0 (preferably prime)
    // parameter: function that takes an Object by const reference and returns a string key
    Probing(int size, function<string(const Object &item)> func_name) {
        // create EMPTY hash_elements at each index
        hash_table.resize(size);
        for (hash_element &element : hash_table) {
            element.status = EMPTY;
        }
        get_key = func_name;
        num_hash_elements = 0;
    }

    // if the element isn't already in the hash table,
    // add it to the hash table (and probe if necessary)
    // This assumes there is at least one hash_element that is not ACTIVE
    void insert(const Object &item, int &reads) {
        if (!search(item, reads)) {
            // the item is not in the hash table. Insert it.
            int index = hash(item);
            while (hash_table[index].status == ACTIVE) {
                // we can't insert the item here. Keep probing.
                ++index;
                index %= hash_table.size();
            }
            // now index is at the spot where we can insert.
            hash_table[index].item = item;
            if (hash_table[index].status == EMPTY) {
                ++num_hash_elements;
            }
            hash_table[index].status = ACTIVE;
            if (num_hash_elements > hash_table.size() / 2) {
                rehash(reads);
            }
        }
    }

    void remove(const Object &item, int &reads) {
        // check that the item is in the hash_table
        if (search(item, reads)) {
            int index = hash(item);
            // loop through the cluster linearly to find the element
            while (hash_table[index].status != EMPTY){
                if (hash_table[index].item == item &&
                    hash_table[index].status == ACTIVE) {
                    // we found the element. Remove it.
                    hash_table[index].status = REMOVED;
                    return;
                }
                ++index;
                index %= hash_table.size();
            }
            // code should never reach this
        }
    }

    // Assuming there is at least one EMPTY hash_element in the hash_table
    bool search(const Object &item, int &reads) const {
        int index = hash(item);
        // loop through the cluster linearly to find the element
        while (hash_table[index].status != EMPTY){
            if (hash_table[index].item == item &&
                hash_table[index].status == ACTIVE) {
                ++reads;
                // we found the element. Return true.
                return true;
            }
            ++reads;
            ++index;
            index %= hash_table.size();
            /*
             * Alternate:
             * if (index == hash_table.size() {
             *    index = 0;
             * }
             */
        }
        return false;
    }

    void print_table(ostream& outs) const {
        for (int i = 0; i < hash_table.size(); ++i) {
            outs << i << ": " << hash_table[i].item << endl;
        }
    }
};

#endif //PROJECT5_PROBING_H
