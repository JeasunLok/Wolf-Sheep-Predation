#pragma once
#ifndef GRASS_H
#define GRASS_H
#include<utility>
#include"Organism.cpp"
using namespace std;
class Grass:public Organism{
private:
    pair<int,int> position;
    int breedTime;
    int energy;
public:
    // Grass();
    Grass(int x=0,int y=0,int e=1,int bT=0);
    // Grass(const Grass& G);
    ~Grass();
    bool breed();
    bool starve();
    void recover();//恢复
    void move();
    pair<int,int> getPosition();
    int getEnergy();
    int getBreedTime();
    void setEnergy(int e);
    void setBreedTime(int bT);
    void setPosition(int x,int y);//设置位置
    Grass operator =(Grass G);//重载=号
};
#endif