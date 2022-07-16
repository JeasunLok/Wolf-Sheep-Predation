#pragma once
#include<iostream>
#include<utility>
#include<ctime>
#include"Grass.h"
using namespace std;
Grass::Grass(int x,int y,int e,int bT):Organism(x,y,e),breedTime(bT){
    position.first=x;
    position.second=y;
    energy=e;
}
Grass::~Grass(){}
bool Grass::breed(){
    if(breedTime==3){
        breedTime=0;
        return true;
    }
    else{
        return false;
    }
}
void Grass::move(){
    breedTime++;
}
bool Grass::starve(){
    energy=0;
    return true;
}
void Grass::recover(){
    energy=1;
}
pair<int,int> Grass::getPosition(){
    return position;
}
int Grass::getEnergy(){
    return energy;
}
int Grass::getBreedTime(){
    return breedTime;
}
void Grass::setEnergy(int e){
    energy=e;
}
void Grass::setBreedTime(int bT){
    breedTime=bT;
}
void Grass::setPosition(int x,int y){
    position.first=x;
    position.second=y;
}
Grass Grass::operator =(Grass G){
    position.first=G.getPosition().first;
    position.second=G.getPosition().second;
    breedTime=G.getBreedTime();
    energy=G.getEnergy();
    return *this;
}