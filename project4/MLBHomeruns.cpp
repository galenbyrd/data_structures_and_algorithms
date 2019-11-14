//
// Created by galen byrd on 10/26/17.
//

#include <iostream>
#include "MLBHomeruns.h"
#include "SortingAlgorithms.h"

Homerun::Homerun() {
    date = hitter = hteam = pitcher = pteam = park = "";
    inning = distance = apex = 0;
    speed = elevangle = horizangle = 0;
}
Homerun::Homerun(string dateIn, string hitterIn, string hteamIn, string pitcherIn, string pteamIn, int inningIn,
                 string parkIn, int distanceIn, float speedIn, float elevangleIn, float horizangleIn, int apexIn){
    date = dateIn;
    hitter = hitterIn;
    hteam = hteamIn;
    pitcher = pitcherIn;
    pteam = pteamIn;
    inning = inningIn;
    park = parkIn;
    distance = distanceIn;
    speed = speedIn;
    elevangle = elevangleIn;
    horizangle = horizangleIn;
    apex = apexIn;
}


string Homerun::getDate() const{
    return date;
}
string Homerun::getHitter() const{
    return hitter;
}
string Homerun::getHteam() const{
    return hteam;
}
string Homerun::getPitcher() const{
    return pitcher;
}
string Homerun::getPteam() const{
    return pteam;
}
int Homerun::getInning() const{
    return inning;
}
string Homerun::getPark() const{
    return park;
}
int Homerun::getDistance() const{
    return distance;
}
float Homerun::getSpeed() const{
    return speed;
}
float Homerun::getElevangle() const{
    return elevangle;
}
float Homerun::getHorizangle() const{
    return horizangle;
}
int Homerun::getApex() const{
    return apex;
}


void Homerun::setDate(string dateIn) {
    date = dateIn;
}
void Homerun::setHitter(string hitterIn) {
    hitter = hitterIn;
}
void Homerun::setHteam(string hteamIn) {
    hteam = hteamIn;
}
void Homerun::setPitcher(string pitcherIn) {
    pitcher = pitcherIn;
}
void Homerun::setPteam(string pteamIn) {
    pteam = pteamIn;
}
void Homerun::setInning(int inningIn) {
    if (1<=inningIn){
        inning = inningIn;
    }
}
void Homerun::setPark(string parkIn) {
    park = parkIn;
}
void Homerun::setDistance(int distanceIn) {
    distance = distanceIn;
}
void Homerun::setSpeed(float speedIn) {
    speed = speedIn;
}
void Homerun::setElevangle(float elevangleIn) {
    elevangle = elevangleIn;
}
void Homerun::setHorizangle(float horizangleIn) {
    if (45<=horizangleIn){
        horizangle = horizangleIn;
    }
}
void Homerun::setApex(int apexIn) {
    apex = apexIn;
}

bool operator < (const Homerun &p1, const Homerun &p2) {
    return p1.getPitcher() < p2.getPitcher();
}
bool operator > (const Homerun &p1, const Homerun &p2) {
    return p1.getPitcher() > p2.getPitcher();
}
ostream& operator << (ostream& outs, const Homerun &p) {
    outs << p.getPitcher() << endl;
    return outs;
}

void Homerun::copyVector(vector<Homerun> all, vector<Homerun> &v, int i) {
    v.resize(i);
    for (int j=0; j<i; ++j) {
        v[j] = all[j];
    }
}

void Homerun::bubble(vector<Homerun> &v, int size, int &reads, int &writes){
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bubble_sort(v, reads, writes);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    cout << "Vector size " << size  << " gives " << reads << " reads, " << writes << " writes and takes " << time_span.count() << " milliseconds" << endl;
    reads=0;
    writes=0;
}
void Homerun::select(vector<Homerun> &v, int size, int &reads, int &writes){
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    selection_sort(v, reads, writes);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    cout << "Vector size " << size  << " gives " << reads << " reads, " << writes << " writes and takes " << time_span.count() << " milliseconds" << endl;
    reads=0;
    writes=0;
}
void Homerun::quick(vector<Homerun> &v, int size, int &reads, int &writes){
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    quick_sort(v, reads, writes);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    cout << "Vector size " << size  << " gives " << reads << " reads, " << writes << " writes and takes " << time_span.count() << " milliseconds" << endl;
    reads=0;
    writes=0;
}