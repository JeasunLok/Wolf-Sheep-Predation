#pragma once
#include<iostream>
#include<utility>
#include<vector>
#include<tuple>
#include<ctime>
#include<algorithm>
#include<random>
#include"Sheep.cpp"
#include"Wolf.cpp"
#include"Field.h"
#include"supportFunction.h"
// using namespace std;
Field::Field(int l,int sN,int wN,int e){
    // srand(time(NULL));
    S.clear();W.clear();G.clear();
    length=l;
    grassNumber=l*l;
    sheepNumber=sN;
    wolfNumber=wN;
    epoch=e;
    Map.resize(l);
    for(int i=0;i<Map.size();i++){//初始化地图
        Map[i].resize(l);
    }
    // cout<<"0"<<endl;//输出提示
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            G.push_back((Grass(i,j,1,0)));//地图上每个点生成草对象
            Map[i][j]='g';
        }
    }
    // cout<<"1"<<endl;//输出提示
    for(int i=0;i<sN;i++){
        int sx=(rand()%(l));
        int sy=(rand()%(l));
        if(!isRepeatS(sx,sy,S)){//不能重复
            S.push_back(Sheep(sx,sy,3,0));//随机在地图里插入指定数量的羊
        }
        else{
            i--;
        }
    }
    // S.resize(sN);
    // cout<<"2"<<S.size()<<endl;//输出提示
    for(int i=0;i<wN;i++){
        int wx=(rand()%(l));
        int wy=(rand()%(l));
        if(!isRepeat(wx,wy,S,W)){//不能重复
            W.push_back(Wolf(wx,wy,3,0));//随机再地图里插入指定数量的狼
        }
        else{
            i--;
        }
    }
    // W.resize(wN);
    // cout<<"3"<<W.size()<<endl;//输出提示
    for(int i=0;i<sN;i++){
        Map[S[i].getPosition().first][S[i].getPosition().second]='o';//根据羊对象改地图
    }
    for(int i=0;i<wN;i++){
        Map[W[i].getPosition().first][W[i].getPosition().second]='x';//根据狼对象该地图
    }
    // cout<<"4"<<endl;//输出提示
}
void Field::displayMap(){//地图展示 遍历Map
    for(int i=0;i<length;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            cout<<Map[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<length;i++){
        cout<<"-";
    }
    cout<<endl;
}

void Field::displayMap_Base(){//底图展示 遍历草对象
    vector<vector<char>> Map_Base;
    Map_Base.resize(length);
    for(int i=0;i<Map_Base.size();i++){
        Map_Base[i].resize(length);
    }
     for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            for(int g=0;g<G.size();g++){
                    if((G[g].getPosition().first==i)&&(G[g].getPosition().second==j)
                        &&(G[g].getEnergy()==0)){
                        Map_Base[i][j]='*';
                    }
                    else if((G[g].getPosition().first==i)&&(G[g].getPosition().second==j)
                        &&(G[g].getEnergy()==1)){
                        Map_Base[i][j]='g';
                    }

                }
            // Map_Base[i][j]='g';
        }
    }
    // for(int i=0;i<G.size();i++){
    //     if(G[i].getEnergy()==0){
    //         Map_Base[G[i].getPosition().first][G[i].getPosition().second]='*';
    //     }
    // }
    for(int i=0;i<length;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            cout<<Map_Base[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<length;i++){
        cout<<"-";
    }
    cout<<endl;
}

void Field::epochRun(){//主要函数 核心逻辑
    shuffle(begin(S),end(S),default_random_engine(random_device()()));//打乱羊容器，使其随机
    shuffle(begin(W),end(W),default_random_engine(random_device()()));//打乱狼容器，使其随机
    start_up(length,length);
    for(int e=0;e<epoch;e++){//迭代开始

        for(int i=0;i<G.size();i++){
        if(G[i].getEnergy()==0){//草先动
            G[i].move();
        }
        if(G[i].breed()){
            G[i].recover();//判断要不要重生
        }
    }
        for(int i=0;i<sheepNumber;i++){//羊再动 每只羊都要动
            int Die=-1;
            tuple<vector<Grass>,vector<Sheep>,vector<Wolf>,vector<vector<char>>,int> sheepMoveResult;
            sheepMoveResult=sheepMove(i,length,G,S,W,Map);//返回元组 核心函数 羊移动
            tie(G,S,W,Map,Die)=sheepMoveResult;
            if(Die!=-1){//如果羊移动之后发现它死了，删除这个羊容器里的对象
                S.erase(S.begin()+Die);
                sheepNumber=S.size();
                i--;
                // S.resize(sheepNumber);
            }
        }
        // cout<<S.size()<<endl;//输出提示
        for(int i=0;i<wolfNumber;i++){//狼最后动 每只狼都要动
            int sDie=-1;
            int wDie=-1;
            tuple<vector<Sheep>,vector<Wolf>,vector<vector<char>>,int,int> wolfMoveResult;
            wolfMoveResult=wolfMove(i,length,S,W,Map);//返回元组 核心函数 狼移动
            tie(S,W,Map,sDie,wDie)=wolfMoveResult;
            if(sDie!=-1){//如果狼移动之后吃到了羊，删除这个羊容器里的对象
                S.erase(S.begin()+sDie);
                sheepNumber=S.size();
                // S.resize(sheepNumber);
            }
            // cout<<S.size()<<endl;//输出提示
            if(wDie!=-1){//如果狼移动之后发现它死了，删除这个狼容器里的对象
                W.erase(W.begin()+wDie);
                wolfNumber=W.size();
                i--;
                // W.resize(wolfNumber);
            }
            // cout<<W.size()<<endl;//输出提示
            // for(int j=0;j<wolfNumber;j++){//输出提示
            //     cout<<j<<":"<<W[j].getEnergy()<<endl;
            // }
        }
        // for(int j=0;j<wolfNumber;j++){//输出提示
        //     cout<<j<<":"<<W[j].getEnergy()<<endl;
        // }

        for(int i=0;i<length;i++){//修正草羊狼移动之后的地图
            for(int j=0;j<length;j++){
                int mark=1;
                for(int s=0;s<S.size();s++){
                    if((S[s].getPosition().first==i)&&(S[s].getPosition().second==j)){
                        mark=0;
                    }
                }
                for(int w=0;w<W.size();w++){
                    if((W[w].getPosition().first==i)&&(W[w].getPosition().second==j)){
                        mark=0;
                    }
                }
                for(int g=0;g<G.size();g++){
                    if((G[g].getPosition().first==i)&&(G[g].getPosition().second==j)
                        &&(G[g].getEnergy()==0)){
                        mark=0;
                    }
                }
                if(mark==0){
                    continue;
                }
                else{
                    Map[i][j]='g';
                }
            }
        }

        int grassNum_alive=0;//遍历草容器，计算活着的草
        for(int g=0;g<G.size();g++){
            if(G[g].getEnergy()==1){
                grassNum_alive++;
            }
        }

        cout<<endl;
        displayMap();//展示地图
        cout<<"The number of Grass_alive is:"<<grassNum_alive<<endl;//数据展示
        cout<<"The number of Sheep is:"<<S.size()<<endl;
        cout<<"The number of Wolf is:"<<W.size()<<endl;
        cout<<"The base Map about Grass is following:"<<endl;
        displayMap_Base();//展示底图
        show(Map,length,length);//GUI窗口展示
        delay_fps(60);//帧率延迟
        Delay(2000);//延迟
    }
}
