#include "MLBHomeruns.h"
#include "SortingAlgorithms.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    vector<Homerun> allHomeruns;
    vector<Homerun> Homeruns25;
    vector<Homerun> Homeruns50;
    vector<Homerun> Homeruns100;
    vector<Homerun> Homeruns200;
    vector<Homerun> Homeruns300;
    vector<Homerun> Homeruns400;
    vector<Homerun> Homeruns500;
    vector<Homerun> Homeruns600;
    vector<Homerun> Homeruns700;
    vector<Homerun> Homeruns800;
    vector<Homerun> Homeruns900;
    vector<Homerun> Homeruns1000;
    vector<Homerun> Homeruns1600;
    vector<Homerun> Homeruns3200;
    vector<Homerun> Homeruns5600;
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
    int writes=0;

    ifstream f_in("MLBhomeruns.csv");
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
    f_in.close();

    Homerun::copyVector(allHomeruns, Homeruns100, 100);
    Homerun::copyVector(allHomeruns, Homeruns200, 200);
    Homerun::copyVector(allHomeruns, Homeruns300, 300);
    Homerun::copyVector(allHomeruns, Homeruns400, 400);
    Homerun::copyVector(allHomeruns, Homeruns500, 500);
    Homerun::copyVector(allHomeruns, Homeruns600, 600);
    Homerun::copyVector(allHomeruns, Homeruns700, 700);
    Homerun::copyVector(allHomeruns, Homeruns800, 800);
    Homerun::copyVector(allHomeruns, Homeruns900, 900);
    Homerun::copyVector(allHomeruns, Homeruns1000, 1000);

    cout << "Bubble sort:" << endl;
    Homerun::bubble(Homeruns100, 100, reads, writes);
    Homerun::bubble(Homeruns200, 200, reads, writes);
    Homerun::bubble(Homeruns300, 300, reads, writes);
    Homerun::bubble(Homeruns400, 400, reads, writes);
    Homerun::bubble(Homeruns500, 500, reads, writes);
    Homerun::bubble(Homeruns600, 600, reads, writes);
    Homerun::bubble(Homeruns700, 700, reads, writes);
    Homerun::bubble(Homeruns800, 800, reads, writes);
    Homerun::bubble(Homeruns900, 900, reads, writes);
    Homerun::bubble(Homeruns1000, 1000, reads, writes);

    Homerun::copyVector(allHomeruns, Homeruns100, 100);
    Homerun::copyVector(allHomeruns, Homeruns200, 200);
    Homerun::copyVector(allHomeruns, Homeruns300, 300);
    Homerun::copyVector(allHomeruns, Homeruns400, 400);
    Homerun::copyVector(allHomeruns, Homeruns500, 500);
    Homerun::copyVector(allHomeruns, Homeruns600, 600);
    Homerun::copyVector(allHomeruns, Homeruns700, 700);
    Homerun::copyVector(allHomeruns, Homeruns800, 800);
    Homerun::copyVector(allHomeruns, Homeruns900, 900);
    Homerun::copyVector(allHomeruns, Homeruns1000, 1000);

    cout << "Selection sort:" << endl;
    Homerun::select(Homeruns100, 100, reads, writes);
    Homerun::select(Homeruns200, 200, reads, writes);
    Homerun::select(Homeruns300, 300, reads, writes);
    Homerun::select(Homeruns400, 400, reads, writes);
    Homerun::select(Homeruns500, 500, reads, writes);
    Homerun::select(Homeruns600, 600, reads, writes);
    Homerun::select(Homeruns700, 700, reads, writes);
    Homerun::select(Homeruns800, 800, reads, writes);
    Homerun::select(Homeruns900, 900, reads, writes);
    Homerun::select(Homeruns1000, 1000, reads, writes);

    Homerun::copyVector(allHomeruns, Homeruns100, 100);
    Homerun::copyVector(allHomeruns, Homeruns200, 200);
    Homerun::copyVector(allHomeruns, Homeruns300, 300);
    Homerun::copyVector(allHomeruns, Homeruns400, 400);
    Homerun::copyVector(allHomeruns, Homeruns500, 500);
    Homerun::copyVector(allHomeruns, Homeruns600, 600);
    Homerun::copyVector(allHomeruns, Homeruns700, 700);
    Homerun::copyVector(allHomeruns, Homeruns800, 800);
    Homerun::copyVector(allHomeruns, Homeruns900, 900);
    Homerun::copyVector(allHomeruns, Homeruns1000, 1000);

    cout << "Quick sort:" << endl;
    Homerun::quick(Homeruns100, 100, reads, writes);
    Homerun::quick(Homeruns200, 200, reads, writes);
    Homerun::quick(Homeruns300, 300, reads, writes);
    Homerun::quick(Homeruns400, 400, reads, writes);
    Homerun::quick(Homeruns500, 500, reads, writes);
    Homerun::quick(Homeruns600, 600, reads, writes);
    Homerun::quick(Homeruns700, 700, reads, writes);
    Homerun::quick(Homeruns800, 800, reads, writes);
    Homerun::quick(Homeruns900, 900, reads, writes);
    Homerun::quick(Homeruns1000, 1000, reads, writes);

    Homerun::copyVector(allHomeruns, Homeruns25, 25);
    Homerun::copyVector(allHomeruns, Homeruns50, 50);
    Homerun::copyVector(allHomeruns, Homeruns100, 100);
    Homerun::copyVector(allHomeruns, Homeruns200, 200);
    Homerun::copyVector(allHomeruns, Homeruns400, 400);
    Homerun::copyVector(allHomeruns, Homeruns800, 800);
    Homerun::copyVector(allHomeruns, Homeruns1600, 1600);
    Homerun::copyVector(allHomeruns, Homeruns3200, 3200);
    Homerun::copyVector(allHomeruns, Homeruns5600, 5600);

    cout << "NOW DOUBLING SIZE OF DATASET" << endl;
    cout << "Bubble sort:" << endl;
    Homerun::bubble(Homeruns25, 25, reads, writes);
    Homerun::bubble(Homeruns50, 50, reads, writes);
    Homerun::bubble(Homeruns100, 100, reads, writes);
    Homerun::bubble(Homeruns200, 200, reads, writes);
    Homerun::bubble(Homeruns400, 400, reads, writes);
    Homerun::bubble(Homeruns800, 800, reads, writes);
    Homerun::bubble(Homeruns1600, 1600, reads, writes);
    Homerun::bubble(Homeruns3200, 3200, reads, writes);
    Homerun::bubble(Homeruns5600, 5600, reads, writes);

    Homerun::copyVector(allHomeruns, Homeruns25, 25);
    Homerun::copyVector(allHomeruns, Homeruns50, 50);
    Homerun::copyVector(allHomeruns, Homeruns100, 100);
    Homerun::copyVector(allHomeruns, Homeruns200, 200);
    Homerun::copyVector(allHomeruns, Homeruns400, 400);
    Homerun::copyVector(allHomeruns, Homeruns800, 800);
    Homerun::copyVector(allHomeruns, Homeruns1600, 1600);
    Homerun::copyVector(allHomeruns, Homeruns3200, 3200);
    Homerun::copyVector(allHomeruns, Homeruns5600, 5600);

    cout << "Selection sort:" << endl;
    Homerun::select(Homeruns25, 25, reads, writes);
    Homerun::select(Homeruns50, 50, reads, writes);
    Homerun::select(Homeruns100, 100, reads, writes);
    Homerun::select(Homeruns200, 200, reads, writes);
    Homerun::select(Homeruns400, 400, reads, writes);
    Homerun::select(Homeruns800, 800, reads, writes);
    Homerun::select(Homeruns1600, 1600, reads, writes);
    Homerun::select(Homeruns3200, 3200, reads, writes);
    Homerun::select(Homeruns5600, 5600, reads, writes);

    Homerun::copyVector(allHomeruns, Homeruns25, 25);
    Homerun::copyVector(allHomeruns, Homeruns50, 50);
    Homerun::copyVector(allHomeruns, Homeruns100, 100);
    Homerun::copyVector(allHomeruns, Homeruns200, 200);
    Homerun::copyVector(allHomeruns, Homeruns400, 400);
    Homerun::copyVector(allHomeruns, Homeruns800, 800);
    Homerun::copyVector(allHomeruns, Homeruns1600, 1600);
    Homerun::copyVector(allHomeruns, Homeruns3200, 3200);
    Homerun::copyVector(allHomeruns, Homeruns5600, 5600);

    cout << "Quick sort:" << endl;
    Homerun::quick(Homeruns25, 25, reads, writes);
    Homerun::quick(Homeruns50, 50, reads, writes);
    Homerun::quick(Homeruns100, 100, reads, writes);
    Homerun::quick(Homeruns200, 200, reads, writes);
    Homerun::quick(Homeruns400, 400, reads, writes);
    Homerun::quick(Homeruns800, 800, reads, writes);
    Homerun::quick(Homeruns1600, 1600, reads, writes);
    Homerun::quick(Homeruns3200, 3200, reads, writes);
    Homerun::quick(Homeruns5600, 5600, reads, writes);


    return 0;
}