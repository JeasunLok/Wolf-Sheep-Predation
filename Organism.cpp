#pragma once
#include"Organism.h"
#include<utility>
using namespace std;
Organism::Organism(int x,int y,int e){
    position.first=x;
    position.second=y;
    energy=e;
}
Organism::Organism(const Organism& O){
    position.first=O.position.first;
    position.second=O.position.second;
    energy=O.energy;
}
Organism::~Organism(){}