#pragma once
#ifndef FIELD_H
#define FIELD_H
#include<utility>
#include<vector>
#include"Sheep.cpp"
#include"Wolf.cpp"
#include"Grass.cpp"
using namespace std;
class Field{//世界/地图类，顾名思义
private:
    int length;
    int grassNumber;
    int sheepNumber;
    int wolfNumber;
    int epoch;
    vector<Wolf> W;//狼容器类对象数组
    vector<Sheep> S;//羊容器类对象数组
    vector<Grass> G;//草容器类对象数组
    vector<vector<char>> Map;//展示地图
public:
    Field(int l=100,int sN=50,int wN=20,int e=20);//构造函数
    void displayMap();//展示地图
    void displayMap_Base();//展示底图
    void epochRun();//迭代
};
#endif