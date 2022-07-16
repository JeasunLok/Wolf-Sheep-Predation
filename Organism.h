#pragma once
#ifndef ORGANISM_H
#define ORGANISM_H
#include<utility>
using namespace std;
class Organism{
private:
    pair<int,int> position;
    int energy;
    int breedTime;
public:
    Organism(int x=0,int y=0,int e=3);
    Organism(const Organism& O);
    ~Organism();
    virtual bool starve() =0;//饿死
    virtual void move() =0;//移动
    virtual bool breed() =0;//繁殖
    virtual pair<int,int> getPosition() =0;//获得位置
    virtual int getEnergy() =0;//获得能量
    virtual int getBreedTime() =0;//获得繁殖时间
    virtual void setEnergy(int e) =0;//设置能量
    virtual void setBreedTime(int bT) =0;//设置繁殖时间
};
#endif