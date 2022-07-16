#include<iostream>
#include<utility>
#include<vector>
#include<ctime>
#include"Field.cpp"
#include"Sheep.cpp"
#include"Wolf.cpp"
#include"Grass.cpp"
#include"supportFunction.h"
using namespace std;
int main(){
    srand(time(NULL));
    int functionSelection;//选择功能
    cout<<"Welcome to the ecosystem simulation programme!"<<endl;
    while(1){
        cout<<"Please input 1 to start or else to exit:";
        cin>>functionSelection;
        if(functionSelection==1){
            int n,s,w,epoch;
            cout<<"Caution:The sum of sheep and wolves cannot be greater than the square of the size of the ecosystem!"<<endl;
            cout<<"In the Map of Console, g is grass_alive, * is grass_dead, s is sheep and w is wolf!"<<endl;
            cout<<"In the Map of GUI, 'green' is grass_alive, 'brown' is grass_dead, 'white' is sheep and 'black' is wolf!"<<endl;
            cout<<"Please input the size of ecosystem:";//按提示输出
            cin>>n;
            cout<<"Please input the number of sheep:";
            cin>>s;
            cout<<"Please input the number of wolf:";
            cin>>w;
            cout<<"Please input the number of epoch:";
            cin>>epoch;
            if((s+w)>=n*n){
                cout<<"ERROR!The sum of sheep and wolves is out of size!"<<endl;//输入错误
                system("pause");
                exit(1);
            }
            else{
                Field f(n,s,w,epoch);//初始化世界以及展示
                cout<<"The ecosystem has already initalized!"<<endl;
                f.displayMap();
                cout<<"The initial number of Sheep is:"<<s<<endl;
                cout<<"The initial number of Wolf is:"<<w<<endl;
                f.epochRun();//开始循环
                cout<<"The epoch is over!"<<endl<<endl;
            }
        }
        else{
            cout<<"Thanks for using the ecosystem simulation programme!"<<endl;//退出程序
            system("pause");
            exit(1);
        }
    }
    system("pause");
    return 0;
}
//Programmed by JeasunLok,July 15th 2022,SUN YAT SEN UNIVERSITY