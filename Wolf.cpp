#pragma once
#include<iostream>
#include<utility>
#include<ctime>
#include"Wolf.h"
using namespace std;
// Wolf::Wolf():Organism(-1,-1,-1),breedTime(-1){}
Wolf::Wolf(int x,int y,int e,int bT):Organism(x,y,e),breedTime(bT){
    position.first=x;
    position.second=y;
    energy=e;
}
// Wolf::Wolf(const Wolf& W):Organism(W.getPosition().first,W.getPosition().second,W.getEnergy()),breedTime(W.getBreedtime()){}
Wolf::~Wolf(){}
bool Wolf::starve(){
    if(energy<0){
        return true;
    }
    else{
        return false;
    }
}
void Wolf::move(){//四邻域随机移动，能量减一，繁殖时间加一
    // srand(time(NULL));
    int direction=(rand()%4)+1;
    switch(direction){
        case 1:position.second=position.second+1;break;
        case 2:position.first=position.first+1;break;
        case 3:position.second=position.second-1;break;
        case 4:position.first=position.first-1;break;
    }
    energy=energy-1;
    breedTime=breedTime+1;
}
bool Wolf::breed(){
    if(breedTime==8){
    // if(breedTime==8){
        breedTime=0;
        return true;
    }
    else{
        return false;
    }
}
void Wolf::recover(){
    energy=3;
}
pair<int,int> Wolf::getPosition(){
    return position;
}
int Wolf::getEnergy(){
    return energy;
}
int Wolf::getBreedTime(){
    return breedTime;
}
void Wolf::setEnergy(int e){
    energy=e;
}
void Wolf::setBreedTime(int bT){
    breedTime=bT;
}
void Wolf::setPosition(int x,int y){
    position.first=x;
    position.second=y;
}
Wolf Wolf::operator =(Wolf W){
    position.first=W.getPosition().first;
    position.second=W.getPosition().second;
    breedTime=W.getBreedTime();
    energy=W.getEnergy();
    return *this;
}