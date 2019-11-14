#include "MLBHomeruns.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream f_in("MLBhomeruns.csv");

    vector<Homerun> allHomeruns;
    string date = "";
    string firstname = "";
    string lastname = "";
    string hitter = "";
    string hteam = "";
    string pitcher = "";
    string pteam = "";
    int inning = 0;
    string park = "";
    int distance = 0;
    float speed = 0;
    float elevangle = 0;
    float horizangle = 0;
    int apex = 0;
    char comma = ' ';
    int find = 0;
    int depth = 0;

    //cout << "Date              Hitter      Hitting Team     Pitcher    Pitching Team   Inning       Ballpark    Distance   Speed off Bat   Elevation Angle Horizontal Angle    Apex" << endl;
    //cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (f_in and !f_in.eof()){
        getline(f_in, date, ',');
        while (isspace(date[0])) {
            date = date.substr(1, date.length() - 1);
        }
        f_in >> comma;
        getline(f_in, lastname, ',');
        getline(f_in, firstname, '"');
        f_in >> comma;
        hitter=firstname+' '+lastname;
        getline(f_in, hteam, ',');
        f_in >> comma;
        getline(f_in, lastname, ',');
        getline(f_in, firstname, '"');
        f_in >> comma;
        pitcher=firstname+' '+lastname;
        getline(f_in, pteam, ',');
        f_in >> inning >> comma;
        getline(f_in, park, ',');
        f_in >> distance >> comma;
        f_in >> speed >> comma;
        f_in >> elevangle >> comma;
        f_in >> horizangle >> comma;
        f_in >> apex;

        // read in data from file and push objects to back of vector
        allHomeruns.push_back(Homerun(date, hitter, hteam, pitcher, pteam, inning, park, distance, speed, elevangle, horizangle, apex));
    }
    // 3 dummy values in the vector
    allHomeruns.push_back(Homerun());
    allHomeruns.push_back(Homerun());
    allHomeruns.push_back(Homerun());

    f_in.close();

    // initialize trees
    BinarySearchTree<Homerun> BST;
    AvlTree<Homerun> AVL;
    SplayTree<Homerun> Splay;

    // fill trees with objects in vector minus dummy values
    for (int j=0; j< allHomeruns.size()-3; ++j) {
        BST.insert(allHomeruns[j]);
        AVL.insert(allHomeruns[j]);
        Splay.insert(allHomeruns[j]);
    }

    ifstream random_bst("RandomInts.txt");
    ifstream sorted_bst("SortedInts.txt");
    ifstream five_bst("FiveInts.txt");

    // read in from integer file what index to search for, search for it and record depth of each search to a file
    while (sorted_bst and !sorted_bst.eof()){
        sorted_bst >> find;
        BST.contains(allHomeruns[find], depth);

        ofstream sortedBST("sortedIntsBSTDepth.txt");
        if (sortedBST){
            sortedBST << depth << endl;
        }
        sortedBST.close();
        depth=0;
    }
    while (random_bst and !random_bst.eof()) {
        random_bst >> find;
        BST.contains(allHomeruns[find], depth);

        ofstream randomBST("randomIntsBSTDepth.txt");
        if (randomBST){
            randomBST << depth << endl;
        }
        randomBST.close();
        depth = 0;
    }
    while (five_bst and !five_bst.eof()){
        five_bst >> find;
        BST.contains(allHomeruns[find], depth);

        ofstream fiveBST("fiveIntsBSTDepth.txt");
        if (fiveBST){
            fiveBST << depth << endl;
        }
        fiveBST.close();
        depth=0;
    }

    five_bst.close();
    random_bst.close();
    sorted_bst.close();


    ifstream random_avl("RandomInts.txt");
    ifstream sorted_avl("SortedInts.txt");
    ifstream five_avl("FiveInts.txt");

    while (sorted_avl and !sorted_avl.eof()){
        sorted_avl >> find;
        AVL.contains(allHomeruns[find], depth);

        ofstream sortedAVL("sortedIntsAVLDepth.txt");
        if (sortedAVL){
            sortedAVL << depth << endl;
        }
        sortedAVL.close();
        depth=0;
    }
    while (random_avl and !random_avl.eof()){
        random_avl >> find;
        AVL.contains(allHomeruns[find], depth);

        ofstream randomAVL("randomIntsAVLDepth.txt");
        if (randomAVL){
            randomAVL << depth << endl;
        }
        randomAVL.close();
        depth=0;
    }
    while (five_avl and !five_avl.eof()){
        five_avl >> find;
        AVL.contains(allHomeruns[find], depth);

        ofstream fiveAVL("fiveIntsAVLDepth.txt");
        if (fiveAVL){
            fiveAVL << depth << endl;
        }
        fiveAVL.close();
        depth=0;
    }
    five_avl.close();
    random_avl.close();
    sorted_avl.close();



    ifstream random_splay("RandomInts.txt");
    ifstream sorted_splay("SortedInts.txt");
    ifstream five_splay("FiveInts.txt");

    while (sorted_splay and !sorted_splay.eof()){
        sorted_splay >> find;
        Splay.contains(allHomeruns[find], depth);

        ofstream sortedSplay("sortedIntsSplayDepth.txt");
        if (sortedSplay){
            sortedSplay << depth << endl;
        }
        sortedSplay.close();
        depth=0;
    }
    while (random_splay and !random_splay.eof()){
        random_splay >> find;
        Splay.contains(allHomeruns[find], depth);

        ofstream randomSplay("randomIntsSplayDepth.txt");
        if (randomSplay){
            randomSplay << depth << endl;
        }
        randomSplay.close();
        depth=0;
    }
    while (five_splay and !five_splay.eof()){
        five_splay >> find;
        Splay.contains(allHomeruns[find], depth);

        ofstream fiveSplay("fiveIntsSplayDepth.txt");
        if (fiveSplay){
            fiveSplay << depth << endl;
        }
        fiveSplay.close();
        depth=0;
    }
    five_splay.close();
    random_splay.close();
    sorted_splay.close();


    cout << "The average depth for sorted integers in a BST tree is: " << setprecision(4) << avgdepth("sortedIntsBSTDepth.txt") << endl;
    cout << "The average depth for sorted integers in an AVL tree is: " << avgdepth("sortedIntsAVLDepth.txt") << endl;
    cout << "The average depth for sorted integers in a SPLAY tree is: " << avgdepth("sortedIntsSplayDepth.txt") << endl;

    cout << "The average depth for random integers in a BST tree is: " << avgdepth("randomIntsBSTDepth.txt") << endl;
    cout << "The average depth for random integers in an AVL tree is: " << avgdepth("randomIntsAVLDepth.txt") << endl;
    cout << "The average depth for random integers in a SPLAY tree is: " << avgdepth("randomIntsSplayDepth.txt") << endl;

    cout << "The average depth for 5 repeated integers in a BST tree is: " << avgdepth("fiveIntsBSTDepth.txt") << endl;
    cout << "The average depth for 5 repeated integers in an AVL tree is: " << avgdepth("fiveIntsAVLDepth.txt") << endl;
    cout << "The average depth for 5 repeated integers in a SPLAY tree is: " << avgdepth("fiveIntsSplayDepth.txt") << endl;

    return 0;
}