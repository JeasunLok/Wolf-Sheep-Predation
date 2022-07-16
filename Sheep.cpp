#pragma once
#include<iostream>
#include<utility>
#include<ctime>
#include"Sheep.h"
using namespace std;
// Sheep::Sheep():Organism(-1,-1,-1),breedTime(-1){}
Sheep::Sheep(int x,int y,int e,int bT):Organism(x,y,e),breedTime(bT){
    position.first=x;
    position.second=y;
    energy=e;
}
// Sheep::Sheep(const Sheep& S):Organism(S.getPosition().first,S.getPosition().second,S.getEnergy()),breedTime(S.getBreedtime()){}
Sheep::~Sheep(){}
bool Sheep::starve(){
    if(energy<0){
        return true;
    }
    else{
        return false;
    }
}
void Sheep::recover(){
    energy=3;
}
void Sheep::move(){//四邻域随机移动，能量减一，繁殖时间加一
    // srand(time(NULL));
    int direction=(rand()%4)+1;
    // cout<<position.first<<position.second<<endl;
    switch(direction){
        case 1:position.second=position.second+1;break;
        case 2:position.first=position.first+1;break;
        case 3:position.second=position.second-1;break;
        case 4:position.first=position.first-1;break;
    }
    // cout<<position.first<<position.second<<endl;
    energy=energy-1;
    breedTime=breedTime+1;
}
bool Sheep::breed(){
    if(breedTime==3){
        breedTime=0;
        return true;
    }
    else{
        return false;
    }
}
pair<int,int> Sheep::getPosition(){
    return position;
}
int Sheep::getEnergy(){
    return energy;
}
int Sheep::getBreedTime(){
    return breedTime;
}
void Sheep::setEnergy(int e){
    energy=e;
}
void Sheep::setBreedTime(int bT){
    breedTime=bT;
}
void Sheep::setPosition(int x,int y){
    position.first=x;
    position.second=y;
}
Sheep Sheep::operator =(Sheep S){
    position.first=S.getPosition().first;
    position.second=S.getPosition().second;
    breedTime=S.getBreedTime();
    energy=S.getEnergy();
    return *this;
}
