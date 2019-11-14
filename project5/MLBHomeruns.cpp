//
// Created by galen byrd on 11/28/17.
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

//calculate average reads from file of recorded reads
float Homerun::avgReads(string filename){
    int reads=0;
    int total=0;
    float num=0;

    ifstream in(filename);
    while(in){
        in >> reads;
        total+=reads;
        ++num;
    }
    in.close();
    float avg=total/num;
    return avg;
}
//calculate max reads from file of recorded reads
int Homerun::maxReads(string filename){
    int max=0;
    int reads=0;

    ifstream in(filename);
    while(in){
        in >> reads;
        if (reads>max){
            max=reads;
        }
    }
    in.close();
    return max;
}

bool operator == (const Homerun &p1, const Homerun &p2) {
    return p1.getPitcher() == p2.getPitcher();
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