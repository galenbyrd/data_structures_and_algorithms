//
// Created by galen byrd on 10/26/17.
//

#ifndef PROJECT4_SORTINGALGORITHMS_H
#define PROJECT4_SORTINGALGORITHMS_H
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "MLBHomeruns.h"
using namespace std;

void bubble_sort(vector<Homerun> &v, int &reads, int &writes) {
    // i represents the beginning index
    // of the sorted elements in the vector
    for (int i = v.size(); i > 0; --i) {
        int num_swaps = 0;
        // n represents the index of the
        // current iteration through the vector
        for (int n = 0; n < i-1; ++n) {
            ++reads;
            ++reads;
            if (v[n] > v[n+1]) {
                // swap elements
                ++reads;
                Homerun temp = v[n];
                ++reads;
                ++writes;
                v[n] = v[n+1];
                ++writes;
                v[n+1] = temp;
                ++num_swaps;
            }
        }
        if (num_swaps == 0) {
            // we didn't swap in the last iteration
            // of the vector. Vector is sorted.
            return;
        }
    }
}

void selection_sort(vector<Homerun> &v, int &reads, int &writes) {
    // i represents the index where the minimum
    // will be swapped
    for (int i = 0; i < v.size()-1; ++i) {
        int min_index = i;
        // n represents the current index in the
        // iteration through the vector
        for (int n = i+1; n < v.size(); ++n) {
            ++reads;
            ++reads;
            if (v[n] < v[min_index]) {
                min_index = n;
            }
        }
        if (min_index != i) {
            // swap elements at min_index and i
            ++reads;
            Homerun temp = v[min_index];
            ++reads;
            ++writes;
            v[min_index] = v[i];
            ++writes;
            v[i] = temp;
        }
    }
}

void quick_sort( vector<Homerun> & items, int &reads, int &writes) {
    if (items.size() > 1) {
        vector<Homerun> smaller;
        vector<Homerun> same;
        vector<Homerun> larger;

        auto chosenItem = items[items.size() / 2];

        for (auto &i : items) {
            ++reads;
            if (i < chosenItem) {
                ++writes;
                smaller.push_back(move(i));
            } else if (chosenItem < i) {
                ++reads;
                ++writes;
                larger.push_back(move(i));
            } else {
                ++writes;
                same.push_back(move(i));
            }
        }

        quick_sort(smaller, reads, writes);     // Recursive call!
        quick_sort(larger, reads, writes);      // Recursive call!

        move(begin(smaller), end(smaller), begin(items));
        move(begin(same), end(same), begin(items) + smaller.size());
        move(begin(larger), end(larger), end(items) - larger.size());
    }
}

#endif //PROJECT4_SORTINGALGORITHMS_H
