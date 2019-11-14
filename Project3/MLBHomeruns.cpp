//
// Created by galen byrd on 10/4/17.
//

#include <iostream>
#include <fstream>
#include "MLBHomeruns.h"

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

float avgDistance(const vector <Homerun> &p){
    int total = 0;
    int count = 0;
    for (int i = 0; i < p.size(); ++i){
        total += p[i].getDistance();
        ++count;
    }
    float avgDistance = total/count;
    return avgDistance;
}

float avgHorizangle(const vector<Homerun> &p) {
    float total = 0;
    int count = 0;
    for (int i = 0; i < p.size(); ++i){
        total += p[i].getHorizangle();
        ++count;
    }
    float avgHorizangle = total/count;
    return avgHorizangle;
}

//calculate average depth from file of recorded depths
float avgdepth(string filename){
    int deep=0;
    int total=0;
    float num=0;

    ifstream in(filename);
    while(in){
        in >> deep;
        total+=deep;
        ++num;
    }
    float avg=total/num;
    return avg;
}

bool operator < (const Homerun &p1, const Homerun &p2) {
    return p1.getPitcher() < p2.getPitcher();
}
ostream& operator << (ostream& outs, const Homerun &p) {
    outs << p.getPitcher() << endl;
    return outs;
}
bool operator == (const Homerun &p1, const Homerun &p2) {
    return p1.getPitcher() == p2.getPitcher();
}