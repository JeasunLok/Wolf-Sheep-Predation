#pragma once
#ifndef SHEEP_H
#define SHEEP_H
#include<utility>
#include"Organism.cpp"
using namespace std;
class Sheep:public Organism{
private:
    pair<int,int> position;
    int breedTime;
    int energy;
public:
    // Sheep();
    Sheep(int x=0,int y=0,int e=3,int bT=0);
    // Sheep(const Sheep& S);
    ~Sheep();
    bool starve();
    void move();
    bool breed();
    void recover();//恢复
    pair<int,int> getPosition();
    int getEnergy();
    int getBreedTime();
    void setEnergy(int e);
    void setBreedTime(int bT);
    void setPosition(int x,int y);//设置位置
    Sheep operator =(Sheep S);//重载=号
};
#endif