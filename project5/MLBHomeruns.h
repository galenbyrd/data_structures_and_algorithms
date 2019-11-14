//
// Created by galen byrd on 11/28/17.
//

#ifndef PROJECT5_MLBHOMERUNS_H
#define PROJECT5_MLBHOMERUNS_H

#include <string>
#include <vector>
using namespace std;

class Homerun {
private:
    string date;
    string hitter;
    string hteam;
    string pitcher;
    string pteam;
    int inning;
    string park;
    int distance;
    float speed;
    float elevangle;
    float horizangle;
    int apex;
public:
    //Constructors
    Homerun();
    Homerun(string dateIn, string hitterIn, string hteamIn, string pitcherIn, string pteamIn, int inningIn,
            string parkIn, int distanceIn, float speedIn, float elevangleIn, float horizangleIn, int apexIn);

    //Getters
    string getDate() const;
    string getHitter() const;
    string getHteam() const;
    string getPitcher() const;
    string getPteam() const;
    int getInning() const;
    string getPark() const;
    int getDistance() const;
    float getSpeed() const;
    float getElevangle() const;
    float getHorizangle() const;
    int getApex() const;

    //Setters
    void setDate(string dateIn);
    void setHitter(string hitterIn);
    void setHteam(string hteamIn);
    void setPitcher(string pitcherIn);
    void setPteam(string pteamIn);
    void setInning(int inningIn);
    void setPark(string parkIn);
    void setDistance(int distanceIn);
    void setSpeed(float speedIn);
    void setElevangle(float elevangleIn);
    void setHorizangle(float horizangleIn);
    void setApex(int apexIn);

    static float avgReads(string filename);
    static int maxReads(string filename);

    friend bool operator == (const Homerun &p1, const Homerun &p2);
    friend bool operator < (const Homerun &p1, const Homerun &p2);
    friend bool operator > (const Homerun &p1, const Homerun &p2);
    friend ostream& operator << (ostream& outs, const Homerun &p);
};

#endif //PROJECT5_MLBHOMERUNS_H