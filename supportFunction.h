#pragma once
#ifndef SUPPORTFUNCTION_H
#define SUPPORTFUNCTION_H
#include<iostream>
#include<utility>
#include<vector>
#include<tuple>
#include<ctime>
#include"Sheep.cpp"
#include"Wolf.cpp"
#include"Field.cpp"
#include<graphics.h>
bool isRepeatS(int x,int y,vector<Sheep> S){//遍历判断是否重复再插入：羊
    int sNum=S.size();
    int mark1=0;
    for(int i=0;i<sNum;i++){
        if((S[i].getPosition().first==x)&&(S[i].getPosition().second==y)){
            mark1=1;
            break;
        }
        else{
            mark1=0;
        }
    }
    return mark1;
}
bool isRepeat(int x,int y,vector<Sheep> S,vector<Wolf> W){//遍历判断是否重复再插入：狼
    int sNum=S.size();
    int wNum=W.size();
    int mark1=0;
    int mark2=0;
    for(int i=0;i<sNum;i++){
        if((S[i].getPosition().first==x)&&(S[i].getPosition().second==y)){
            mark1=1;
            break;
        }
        else{
            mark1=0;
        }
    }
    for(int i=0;i<wNum;i++){
        if((W[i].getPosition().first==x)&&(W[i].getPosition().second==y)){
            mark2=1;
            break;
        }
        else{
            mark2=0;
        }
    }
    if(mark1==0&&mark2==0){
        return false;
    }
    else{
        return true;
    }
}
tuple<vector<Grass>,vector<Sheep>,vector<Wolf>,vector<vector<char>>,int> sheepMove(int n,int length,vector<Grass> G,vector<Sheep> S,vector<Wolf> W,vector<vector<char>> M){//核心函数，羊移动
    int Die=-1;
    int sNum=S.size();
    int wNum=W.size();
    int orginalX=S[n].getPosition().first;
    int orginalY=S[n].getPosition().second;//记住原来的位置，移动之后可能要回调


    for(int i=0;i<G.size();i++){//羊吃草
        if(orginalX==G[i].getPosition().first&&orginalY==G[i].getPosition().second){
            if(G[i].getEnergy()==1){
                S[n].recover();
                G[i].starve();
            }
        }
 
    }

    S[n].move();//羊移动
    if((S[n].getPosition().first<0)||(S[n].getPosition().first>length-1)//移动到地图外，回调
     ||(S[n].getPosition().second<0)||(S[n].getPosition().second>length-1)){
        S[n].setPosition(orginalX,orginalY);
    }
    // cout<<S[n].getPosition().first<<S[n].getPosition().second<<endl;
    for(int i=0;i<sNum;i++){
        if(i==n){
            continue;
        }
        if((S[n].getPosition().first==S[i].getPosition().first)&&//移动到的地方有羊，回调
           (S[n].getPosition().second==S[i].getPosition().second)){
            S[n].setPosition(orginalX,orginalY);
        }
    }
    // cout<<S[n].getPosition().first<<S[n].getPosition().second<<endl;
    for(int i=0;i<wNum;i++){
        if((S[n].getPosition().first==W[i].getPosition().first)&&//移动到的地方有狼，回调
           (S[n].getPosition().second==W[i].getPosition().second)){
            S[n].setPosition(orginalX,orginalY);
        }
    }
    // cout<<S[n].getPosition().first<<S[n].getPosition().second<<endl;
    M[orginalX][orginalY]='*';
    M[S[n].getPosition().first][S[n].getPosition().second]='o';//修改底图
    
    if(S[n].breed()){//羊繁殖
        if((S.size()+W.size())<(length*length)){
            int sx=S[n].getPosition().first+((rand()%(3))-1);
            int sy=S[n].getPosition().second+((rand()%(3))-1);//四邻域随机繁殖
            if(!isRepeat(sx,sy,S,W)&&(sx>=0)&&(sy>=0)&&(sx<length)&&(sy<length)){//没重复没出边界就生
                S.push_back(Sheep(sx,sy,3,0));
                M[sx][sy]='o';
            }
        }
        else{
            W[n].setBreedTime(0);//否则不生
        }
    }

    if(S[n].starve()){//羊是否饿死
        // cout<<"starve"<<endl;
        Die=n;//饿死就记住标号，之后删除
        // cout<<"n:"<<n<<endl;
        M[orginalX][orginalY]='*';
        M[S[n].getPosition().first][S[n].getPosition().second]='*';
    }
    // cout<<S.size()<<endl;
    // cout<<W[n].getPosition().first<<W[n].getPosition().second<<endl;
    else{
        M[orginalX][orginalY]='*';
        M[S[n].getPosition().first][S[n].getPosition().second]='o';
    }
    return make_tuple(G,S,W,M,Die);
}
tuple<vector<Sheep>,vector<Wolf>,vector<vector<char>>,int,int> wolfMove(int n,int length,vector<Sheep> S,vector<Wolf> W,vector<vector<char>> M){//核心函数 狼移动
    int sDie=-1;
    int wDie=-1;
    int sNum=S.size();
    int wNum=W.size();
    int orginalX=W[n].getPosition().first;
    int orginalY=W[n].getPosition().second;//记住原来的位置，移动之后可能要回调

    int sheepX=-1;//优先吃四邻域里的羊
    int sheepY=-1;
    int wolfSelection=0;
    for(int i=0;i<sNum;i++){
        sheepX=S[i].getPosition().first;
        sheepY=S[i].getPosition().second;
        if( ((sheepX==orginalX)&&(sheepY==orginalY+1))||
            ((sheepX==orginalX+1)&&(sheepY==orginalY))||
            ((sheepX==orginalX)&&(sheepY==orginalY-1))||
            ((sheepX==orginalX-1)&&(sheepY==orginalY)) ){//四邻域里有羊就吃了
                wolfSelection=1;
                sDie=i;
                break;
            }
    }

    if(wolfSelection==1){//四邻域里有羊就吃了
        W[n].setPosition(sheepX,sheepY);
        W[n].setBreedTime(W[n].getBreedTime()+1);
        W[n].setEnergy(W[n].getEnergy()-1);
        W[n].recover();
    }
    else{//否则再随即移动
        W[n].move();//狼随机移动
        if((W[n].getPosition().first<0)||(W[n].getPosition().first>length-1)//移动到边界之外，回调
        ||(W[n].getPosition().second<0)||(W[n].getPosition().second>length-1)){
            W[n].setPosition(orginalX,orginalY);
        }
        // cout<<W[n].getPosition().first<<W[n].getPosition().second<<endl;
        for(int i=0;i<wNum;i++){
            if(i==n){
                continue;
            }
            if((W[n].getPosition().first==W[i].getPosition().first)&&//移动到有狼的地方，回调
            (W[n].getPosition().second==W[i].getPosition().second)){
                W[n].setPosition(orginalX,orginalY);
            }
        }
        // cout<<S.size()<<endl;
        // cout<<W[n].getPosition().first<<W[n].getPosition().second<<endl;
        for(int i=0;i<sNum;i++){
            if((S[i].getPosition().first==W[n].getPosition().first)&&//移动到有羊的地方，把羊吃了
            (S[i].getPosition().second==W[n].getPosition().second)){
                sDie=i;
                W[n].recover();
                // cout<<"recover"<<endl;
            }
        }
    }

    if(W[n].breed()){//狼生殖
        // cout<<"breed"<<endl;
        if((S.size()+W.size())<(length*length)){
            int wx=W[n].getPosition().first+((rand()%(3))-1);
            int wy=W[n].getPosition().second+((rand()%(3))-1);//四邻域随机繁殖
            if(!isRepeat(wx,wy,S,W)&&(wx>=0)&&(wy>=0)&&(wx<length)&&(wy<length)){//没重复没出边界就生殖
                W.push_back(Wolf(wx,wy,3,0));
                M[wx][wy]='x';
            }
        }
        else{
            W[n].setBreedTime(0);//否则不生殖
        }
    }

    // cout<<"e:"<<W[n].getEnergy()<<endl;
    if(W[n].starve()){//狼是否饿死
        // cout<<"starve"<<endl;
        wDie=n;//记住位置，出去删除
        // cout<<"n:"<<n<<endl;
        M[orginalX][orginalY]='*';
        M[W[n].getPosition().first][W[n].getPosition().second]='*';//改地图
    }
    // cout<<S.size()<<endl;
    // cout<<W[n].getPosition().first<<W[n].getPosition().second<<endl;
    else{
        M[orginalX][orginalY]='*';
        M[W[n].getPosition().first][W[n].getPosition().second]='x';//改地图
    }

    return make_tuple(S,W,M,sDie,wDie);
}
void Delay(int time) { //time*1000为秒数
    clock_t now=clock(); //延迟
    while(clock()-now<time); 
} 

void start_up(int HEIGHT,int WIDTH) {// 程序初始化函数 
    int BLOCK_SIZE=800/HEIGHT;
	// 初始化画布大小
	initgraph(WIDTH*BLOCK_SIZE, HEIGHT*BLOCK_SIZE);
	setcolor(EGERGB(200, 200, 200));// 设置默认背景颜色
	setrendermode(RENDER_MANUAL); //设置为非自动刷新 (只有delay/delay_fps/getch 才刷新屏幕） 
}

void show(vector<vector<char>> Map,int HEIGHT,int WIDTH) { //绘制函数 
	color_t color;
	cleardevice();// 清屏
    int BLOCK_SIZE=800/HEIGHT;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Map[i][j]=='g') {
				// 草的颜色
				color = EGERGB(34, 139, 34);
			}
			else if(Map[i][j]=='o') {
				// 羊的颜色 
				color = EGERGB(255, 255, 255);
			}
            else if(Map[i][j]=='*') {
				// 死草的颜色 
				color = EGERGB(156, 102, 31);
			}
            else if(Map[i][j]=='x') {
				// 狼的颜色 
				color = EGERGB(0, 0, 0);
			}
			setfillcolor(color);
			//i是行(y)，j是列(x) 
			bar(j*BLOCK_SIZE, i*BLOCK_SIZE, (j + 1)*BLOCK_SIZE, (i + 1)*BLOCK_SIZE);//展示
		}
	}
}
#endif