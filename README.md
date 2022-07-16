# English Version
##Welcome to this Ecosystem Simulator
####Programmed by JeasunLok,July 15th 2022,SUN YAT SEN UNIVERSITY
#### Video：[Introdution of the program by Chinese](https://www.bilibili.com/video/BV1oS4y1J7sm?spm_id_from=333.999.0.0&vd_source=37637236b9378fa05cf47dbdc81be5df)
******
###Wolf Sheep Predation
In this system, there are three kinds of creatures: wolf, sheep and grass. The three live in the same square grid. They follow a certain way of life: they will die, eat, reproduce, etc. As operators, we can Set the initial number of wolves and sheep and the size of the grid, and set the number of iterations. This program will display the running result map of each iteration and the number of wolves, sheep and grass on the console and graphical interface to observe the ecosystem stability.
******
###Highlights of this program compared to the basic requirements
##### ·The STL control in the C++ library is used for the main coding of this program
##### ·Mainly use the vector container class to declare class objects, and make good use of tuple, utlity, algorithm, random.ctime libraries for coding
##### ·Add grass into the ecosystem, more simulation
##### ·For wolves that have only been bred for 8 days, give priority to the ability to move to sheep in the four neighborhoods
##### ·The movement for each iteration is not simply traversing the object array in order, but shuffling the order in the object array through the shuffer function to make it show random movement
##### ·In addition to completing the console program output, a simple GUI interface is also added for visual output results
##### ·The GUI uses the EGE library for simple rasterization
##### &ensp;[EGE library download link](https://xege.org/)
******
### Libraries required by this program
1. C++ built-in library
    * iostream
    * utility
    * vector
    * tuple
    * ctime
    * algorithm
    * random
2. other librarise need to download
    * [EGE](https://xege.org/)：**graphics.h**
******
### How to run the program
##### This program has been basically completed (some bugs are not excluded)
##### Running method 1: run directly using the generated client.exe file
##### Running method 2: Use the g++ compiler in the compiler to compile client.cpp and run it to generate the client.exe file to run
>Notice! ! ! This program is compiled with VS Code. It may not be compiled under the VS compiler, resulting in an error in operation! ! !
>
>At the same time, the EGE library requires that the compilation environment has installed the header files contained in the library
This program uses MinGW 64bit to develop EGE graphical interface
>
##### After successfully running the file, input according to the prompts of the console program, and output <u>1, grid size, number of sheep, number of wolves, number of iterations</u> in order to view the output results.
##### The output results of this program can be changed in the source code. If no changes are made, the program will output in sequence during iteration:
1. console program
    * Ecosystem Map<b>（g is live grass,* is dead grass,o is sheep,x is wolf）</b>
    * the number of live grass
    * the number of sheep
    * the number of wolf
    * Ecosystem Base Map<b>（only live grass and dead grass）</b>
2. GUI interface
    * Ecosystem Map<b>（green is live grass,brown is dead grass,white is sheep,black is wolf）</b>
******
###File Description
1. client.cpp
    <b>Program main file, directly compile the file to run the program
     Enter the console according to the prompt to get the output result</b>
2. Organism
    * Organism.h
    Abstract class, Organism class header file, containing basic data and method definitions
    * Organism.cpp
    Organism class cpp file, only defines the constructor copy constructor and destructor
3. Wolf
    * Wolf.h
    A derived class of the Organism class, the Wolf class header file, contains definitions of data and methods belonging to the Wolf  class
    * Wolf.cpp
    Wolf class cpp file, concrete implementation of Wolf class method
4. Sheep
    * Sheep.h
    The derived class of the Organism class, the Sheep header file, contains the definitions of the data and methods belonging to the Sheep
    * Sheep.cpp
    Sheep cpp file, specific implementation of sheep method
5. Grass
    * Grass.h
    A class derived from the Organism class, the Grass class header file, containing the definitions of the data and methods belonging to the Grass class
    * Grass.cpp
    Grass cpp file, specific implementation of grass methods
6. Field
    * Field.h
    World/map class, all creatures live on this class, combine other creature classes into this class, and display unified actions
    This file is the header file of the world/map class, which contains the definitions of the data and methods belonging to the world/map. The most important thing is to define four container class arrays: <b>Grass, Wolf, Sheep, Map, combine them</b>
    * Field.cpp
    World/map class cpp file, concrete implementation of world/map class methods
7. supportFunction.h
    <b>The more important header files in this project, including the important functions</b>
    1. In the initialization map, the functions isRepeatS and isRepeat that prevent any animal objects from being generated in the same place repeatedly
    2. The most important <b>sheep moving function sheepMove and wolf moving function wolfMove</b> in the whole iteration process
    3. <b>Graphical interface initialization function start_up and graphic interface iterative display function show based on EGE library</b>
    4. Auxiliary delay function Delay
******
### Additional Notes For This Program
* Some parameters can be modified by entering the source code, such as the starvation energy (starvation speed) of sheep and wolves, and the reproduction speed of grass, sheep and wolves. The starvation energy (starvation speed) defaults to 3, and the default reproduction speed of the three is 3, 3, and 8 respectively (recommended by the teacher)
* This program adopts the main program loop coding, that is, after the end of the process, you can enter the parameters again to run again, without exiting and restarting
* <b>The basic initial logic of this program is: the grass moves first, then the sheep moves, and finally the wolf moves again, that is, the grass first judges rebirth; the sheep then judges to eat grass, move, reproduce, and starve to death; the wolf finally judges to eat sheep, move, reproduce, starve</b>
******
# 中文版
##欢迎使用本生态系统模拟程序
####Programmed by JeasunLok,July 15th 2022,SUN YAT SEN UNIVERSITY
#### 视频：[程序主体逻辑和代码介绍](https://www.bilibili.com/video/BV1oS4y1J7sm?spm_id_from=333.999.0.0&vd_source=37637236b9378fa05cf47dbdc81be5df)
******
###狼羊草生态系统模拟
在本系统中，存在狼、羊、草三种生物，三者在同一个方形网格中生存，他们遵从一定的生活方式：会死亡、会进食、会繁殖等等，作为操作者，我们可以设定初始的狼、羊数量以及网格的大小，并设置迭代次数，本程序将在控制台以及图形界面展示每一次迭代的运行结果地图以及狼、羊、草的数量，以观察该生态系统的稳定性。
******
###本程序相较于基本要求的亮点
##### ·使用了C++库中STL控件进行本程序主要的编码
##### ·主要利用vector容器类进行类对象的声明，编码善用tuple,utlity,algorithm,random.ctime各个库
##### ·添加草类进入该生态系统，更加仿真化
##### ·对于8天才繁殖的狼给予四邻域内优先向羊移动的本领
##### ·对于每次迭代的移动并非简单的顺序遍历对象数组而是通过shuffer函数打乱对象数组内的顺序，使其呈现随机化运动
##### ·除了完成控制台程序输出外，还增添了简单的GUI界面进行可视化输出结果
##### ·GUI采用的是EGE库进行简单的栅格化处理
##### &ensp;[EGE库下载链接](https://xege.org/)
******
### 本程序要求包含的库
1. C++自带库
    * iostream
    * utility
    * vector
    * tuple
    * ctime
    * algorithm
    * random
2. 第三方库
    * [EGE](https://xege.org/)：**graphics.h**
******
### 本程序运行方法
##### 本程序已经基本完成（不排除有部分bug）
##### 运行方法一：直接使用生成的client.exe文件运行
##### 运行方法二：在编译器中使用g++编译器对client.cpp进行编译后运行生成client.exe文件运行
>注意！！！本程序采用VS Code进行编译，在VS编译器下可能编译不过，导致运行出错！！！
>
>同时EGE库要求编译环境已安装该库所包含的头文件
本程序采用MinGW 64bit进行EGE图形界面的开发
>
##### 成功运行文件后，按照控制台程序的提示进行输入，分别按顺序输出<u>1，网格大小，羊的数量，狼的数量，迭代次数</u>即可查看输出结果
##### 本程序输出结果可以在源代码中进行更改，若不进行更改，本程序在迭代时会按顺序输出：
1. 控制台程序
    * 生态系统地图<b>（g为活草,*为死草,o为羊,x为狼）</b>
    * 活草的数量
    * 羊的数量
    * 狼的数量
    * 生态系统底图<b>（只含死草和活草）</b>
2. GUI界面
    * 生态系统地图<b>（绿色为活草，棕色为死草，白色为羊，黑色为狼）</b>
******
###文件说明
1. client.cpp
    <b>程序主文件，直接编译该文件运行本程序
    根据提示在控制台进行输入即可得到输出结果</b>
2. Organism
    * Organism.h
    抽象类，生物类头文件，包含基础数据和方法定义
    * Organism.cpp
    生物类cpp文件，仅定义了构造函数复制构造函数和析构函数
3. Wolf
    * Wolf.h
    生物类的派生类，狼类头文件，包含属于狼的数据和方法的定义
    * Wolf.cpp
    狼类cpp文件，狼类方法的具体实现
4. Sheep
    * Sheep.h
    生物类的派生类，羊类头文件，包含属于羊的数据和方法的定义
    * Sheep.cpp
    羊类cpp文件，羊类方法的具体实现
5. Grass
    * Grass.h
    草类的派生类，草类头文件，包含属于草的数据和方法的定义
    * Grass.cpp
    草类cpp文件，草类方法的具体实现
6. Field
    * Field.h
    世界/地图类，所有生物都在该类上生存，对其他生物类进行组合到该类中，统一行动展示
    该文件是世界/地图类的头文件，包含属于世界/地图的数据和方法的定义，最重要定义了四个容器类数组：<b>草、狼、羊、地图，对其进行组合</b>
    * Field.cpp
    世界/地图类cpp文件，世界/地图类方法的具体实现
7. supportFunction.h
    <b>本大作业中较为重要的头文件，包含主要的函数</b>
    1. 初始化地图中，防止重复在同一地点生成任意动物对象的函数isRepeatS以及isRepeat
    2. 在整个迭代过程中最重要的<b>羊移动函数sheepMove以及狼移动函数wolfMove</b>
    3. <b>基于EGE库的图形界面初始化函数start_up以及图形界面迭代展示函数show</b>
    4. 辅助延时函数Delay
******
### 本程序附加注意事项
* 有些参数可以进入源代码进行修改，如羊和狼的饥饿能量（饿死速度），草、羊和狼的繁殖速度。饥饿能量（饿死速度）都默认为3，三者的默认繁殖速度则分别为3，3，8（老师推荐）
* 本程序采用主程序循环编码，即一次过程结束后可再次输入参数重新运行，无需退出重开
* <b>本程序的基本初动逻辑是：草先动作，羊再移动，最后狼再移动 即草先判断重生；羊再判断吃草，移动，生殖，饿死；狼最后判断吃羊，移动，生殖，饿死</b>