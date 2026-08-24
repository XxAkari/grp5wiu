#pragma once
#include "Boss.h"
#include <iostream>

//Constuctor

//Destructor

//Getter


//Setter
void Boss::setHP(int newHP)
{

}
void Boss::setATK(int newATK)
{

}

void Boss::ObobjibName() {
	std::cout << R"(
.||||. ||||. .||||. ||||.    ||| ||||| ||||. 
|    | |   | |    | |   |     |    |   |   |
|    | |   | |    | |   |     |    |   |   |
|    | ||||. |    | ||||.     |    |   ||||.
|    | |   | |    | |   | \   |    |   |   |
|    | |   | |    | |   |  \  |    |   |   |
.||||. ||||. .||||. ||||.   \\/  ||||| ||||.)" << std::endl;
};

void Boss::BobmijName() {
	std::cout << R"(
||||. .||||. ||||. |\    /| |||||    |||
|   | |    | |   | | \  / |   |       |
|   | |    | |   | |  \/  |   |       |
||||. |    | ||||. |      |   |       |
|   | |    | |   | |      |   |   \   |
|   | |    | |   | |      |   |    \  |
||||. .||||. ||||. |      | |||||   \\/)" << std::endl;
};

void Boss::JimbobName() {
	std::cout << R"(
   ||| ||||| |\    /| ||||. .||||. ||||. 
    |    |   | \  / | |   | |    | |   |
    |    |   |  \/  | |   | |    | |   |
    |    |   |      | ||||. |    | ||||.
\   |    |   |      | |   | |    | |   |
 \  |    |   |      | |   | |    | |   |
  \\/  ||||| |      | ||||. .||||. ||||.)" << std::endl;
};
