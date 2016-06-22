# Labirynth
Simple game in C++ with GLUT (OpenGL Utility Toolkit). The main purpose of making this game was to learn something
about object-oriented programming, OpenGL and I/O operations in txt files. Project was created in 2012.

#### How to install?
1. Executable file (Release version) of *Labirynth* is called **Gra.exe** and can be found in [Release\ ](https://github.com/PawelTypiak/Labirynth/tree/master/Release)
folder in the main directory.
2. If you just want to launch the game, you have to add **glut32.dll** file to **C:\Windows\System** directory.
3. If you want to modify this project and compile it, you have to configure GLUT. All needed files are located in [GLUT files\ ](https://github.com/PawelTypiak/Labirynth/tree/master/GLUT%20files).
  - add **glut.h** file to **C:\Program Files\Microsoft Visual Studio 10.0\VC\include\GL** (it is an example for Visual studio 10, you have to create GL folder)
  - add **glut32.lib** file to **C:\Program Files\Microsoft Visual Studio 10.0\VC\lib**
  - add all the libs in Visual Studio - **Project->"YourApplicationName"->Properties**.
  In opened window click **Configuration Properties->Linker->Input** and edit **Additional Dependencies**.
  You have to add following libraries here: **opengl32.lib, glu32.lib** and **glut32.lib**
  <p align="center">
  <img src="http://margalski.boo.pl/blog/wp-content/uploads/2010/12/trelemorele.png" width="600" />
  </p>
  - add `#include <GL/glut.h>` in your .cpp file.

#### Project description
- The main character is Mr. Ballman. You have to help him to get out of the labirynth before the doors will be closed and he will       stuck there forever!
  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/ballman.jpg" width="500" />
  </p>
- After launching the game, you can see the initial window. You can click **Start** to start the game, or **Cancel** to exit.
  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/first_screen.jpg" width="500" />
  </p>
- When you click **Start** you will see the main menu. You can start new game (click **n**), load saved game (click **w**) or you can   exit (click **esc**).
- If your choice is a new game, you will start from level 1. There are 4 levels available in this game:
  
  Level 1            |  Level 2
  :-------------------------:|:-------------------------:
  ![](https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/level1.jpg)  |  ![](https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/level2.jpg)
  
  Level 3            |  Level 4
  :-------------------------:|:-------------------------:
  ![](https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/level3.jpg)  |  ![](https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/level4.jpg)
- At the beginning of every level the whole labirynth is shown - you can try to memorize ale the paths to the exit doors. You can       click **Enter** to start or **esc** to exit. 
  Every level has to be completed in 20s + additional time from the previous level.

  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/level_information.jpg" width="500" />
  </p>
  
- There are some bonus objects located in every level. 
- <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/bonus.jpg" width="500" />
  </p>
  
  If Mr. Ballman walks into one of them, there is several random actions that might happen:
  - Camera height might be set to higher or lower than the defeault height:
  
  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/normal_view.jpg" width="500" />
  </p>

  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/low_view.jpg" width="500" />
  </p>
  
  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/high_view.jpg" width="500" />
  </p>
  
  - Mr. Ballman might be moved to the start or to the end position.
  - Speed of walking might be decreased.
- If you won't be able to complete level in time, don't worry! After every completed level game is saved, so you don't have to
  start from the beginning. All you have to do is to click **w** instead of **n** at the beginning of the game, and you can start from your last level.
  Information about your last level with times of completing every previous level is saved in **ostPoziom.txt** located in [Release\ ](https://github.com/PawelTypiak/Labirynth/tree/master/Release) folder if you want to change it in executable.
  If you're modifying project you might probably want to change it in [Gra\ ](https://github.com/PawelTypiak/Labirynth/tree/master/Gra).
- After you finish level 4 you can see he statistics which show how fast every level has been completed. 
  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/after_finish.jpg" width="500" />
  </p>
  You can exit now, or see the best scores for each level (click **r**). 
  <p align="center">
  <img src="https://github.com/PawelTypiak/Labirynth/blob/master/screenshots/records.jpg" width="500" />
  </p>
  You can clear it or modify
  it in **rekord1p1, rekord1p2, rekord1p3** and **rekord1p4** in [Release\ ](https://github.com/PawelTypiak/Labirynth/tree/master/Release) or in [Gra\ ](https://github.com/PawelTypiak/Labirynth/tree/master/Gra).
  
  
