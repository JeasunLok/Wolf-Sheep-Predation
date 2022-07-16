#pragma once
#ifndef WOLF_H
#define WOLF_H
#include<utility>
#include"Organism.cpp"
using namespace std;
class Wolf:public Organism{
private:
    pair<int,int> position;
    int breedTime;
    int energy;
public:
    // Wolf();    
    Wolf(int x=0,int y=0,int e=3,int bT=0);
    // Wolf(const Wolf& W);
    ~Wolf();
    bool starve();
    void move();
    bool breed();
    void recover();
    pair<int,int> getPosition();
    int getEnergy();
    int getBreedTime();
    void setEnergy(int e);
    void setBreedTime(int bT);
    void setPosition(int x,int y);
    Wolf operator =(Wolf W);
};
#endif