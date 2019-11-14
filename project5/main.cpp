#include "MLBHomeruns.h"
#include "SeparateChaining.h"
#include "Probing.h"
#include <fstream>
using namespace std;

unsigned int hornerHash(const string &key, int tableSize);
string get_key(const Homerun &input);

int main() {
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
    int reads = 0;

    ifstream f_in("MLBhomeruns.csv");
    while (f_in and !f_in.eof()) {
        getline(f_in, date, ',');
        while (isspace(date[0])) {
            date = date.substr(1, date.length() - 1);
        }
        f_in >> comma;
        getline(f_in, lastname, ',');
        getline(f_in, firstname, '"');
        f_in >> comma;
        hitter = firstname + ' ' + lastname;
        getline(f_in, hteam, ',');
        f_in >> comma;
        getline(f_in, lastname, ',');
        getline(f_in, firstname, '"');
        f_in >> comma;
        pitcher = firstname + ' ' + lastname;
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
    f_in.close();


    Separate_Chaining<Homerun> sc(61, get_key);
    ofstream numReads("SeparateChainingReads.txt");
    cout << "SEPERATE CHAINING:" << endl;
    for (Homerun hr:allHomeruns){
        reads=0;
        sc.insert(hr,reads);
        if (numReads){
            numReads << reads << endl;
        }
    }
    numReads.close();
    // Run a search followed by a removal to show that they return the same reads
    for (int i = 0; i < 15; ++i){
        reads=0;
        // set up timer for searching
        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        sc.search(allHomeruns[i],reads);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;
        cout << "Search reads: " << reads << " and takes " << time_span.count() << " Milliseconds" << endl;
        reads=0;
        sc.remove(allHomeruns[i],reads);
        cout << "Remove reads: " << reads << endl;
    }
    cout << "Avg reads (size 61): " << Homerun::avgReads("SeparateChainingReads.txt") << endl;
    cout << "Max reads (size 61): " << Homerun::maxReads("SeparateChainingReads.txt") << endl;

    // New larger prime number for separate chaining
    Separate_Chaining<Homerun> sc2(503, get_key);
    ofstream numReads2("SeparateChainingReads.txt");
    for (Homerun hr:allHomeruns){
        reads=0;
        sc2.insert(hr,reads);
        if (numReads2){
            numReads2 << reads << endl;
        }
    }
    numReads2.close();
    cout << "Avg reads (size 503): " << Homerun::avgReads("SeparateChainingReads.txt") << endl;
    cout << "Max reads (size 503): " << Homerun::maxReads("SeparateChainingReads.txt") << endl;

    // New larger prime number for separate chaining
    Separate_Chaining<Homerun> sc3(997, get_key);
    ofstream numReads3("SeparateChainingReads.txt");
    for (Homerun hr:allHomeruns){
        reads=0;
        sc3.insert(hr,reads);
        if (numReads3){
            numReads3 << reads << endl;
        }
    }
    numReads3.close();
    cout << "Avg reads (size 997): " << Homerun::avgReads("SeparateChainingReads.txt") << endl;
    cout << "Max reads (size 997): " << Homerun::maxReads("SeparateChainingReads.txt") << endl;

    // New larger prime number for separate chaining
    Separate_Chaining<Homerun> sc4(2003, get_key);
    ofstream numReads4("SeparateChainingReads.txt");
    for (Homerun hr:allHomeruns){
        reads=0;
        sc4.insert(hr,reads);
        if (numReads4){
            numReads4 << reads << endl;
        }
    }
    numReads4.close();
    cout << "Avg reads (size 2003): " << Homerun::avgReads("SeparateChainingReads.txt") << endl;
    cout << "Max reads (size 2003): " << Homerun::maxReads("SeparateChainingReads.txt") << endl;

    // New larger prime number for separate chaining
    Separate_Chaining<Homerun> sc5(8009, get_key);
    ofstream numReads5("SeparateChainingReads.txt");
    for (Homerun hr:allHomeruns){
        reads=0;
        sc5.insert(hr,reads);
        if (numReads5){
            numReads5 << reads << endl;
        }
    }
    numReads5.close();
    cout << "Avg reads (size 8009): " << Homerun::avgReads("SeparateChainingReads.txt") << endl;
    cout << "Max reads (size 8009): " << Homerun::maxReads("SeparateChainingReads.txt") << endl;



    Probing<Homerun> probing(2027,get_key);
    ofstream probeReads("ProbingReads.txt");
    for (Homerun hr:allHomeruns){
        reads=0;
        probing.insert(hr,reads);
        if (probeReads){
            probeReads << reads << endl;
        }
    }
    probeReads.close();
    cout << "PROBING:" << endl;
    cout << "Avg reads: " << Homerun::avgReads("ProbingReads.txt") << endl;
    cout << "Max reads: " << Homerun::maxReads("ProbingReads.txt") << endl;
    for (int i = 0; i < 15; ++i){
        reads=0;
        // set up timer for search and show search/remove return same number of reads
        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        probing.search(allHomeruns[i],reads);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;
        cout << "Search reads: " << reads << " and takes " << time_span.count() << " Milliseconds" << endl;
        reads=0;
        probing.remove(allHomeruns[i],reads);
        cout << "Remove reads: " << reads << endl;
    }
}



string get_key(const Homerun &input) {
    return input.getPitcher();
}
unsigned int hornerHash(const string &key, int tableSize) {
    unsigned int hashVal = 0;
    for (char ch : key) {
        hashVal = 37*hashVal + ch;
    }
    return hashVal % tableSize;
}