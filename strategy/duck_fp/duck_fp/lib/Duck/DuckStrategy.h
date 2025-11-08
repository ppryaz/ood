#ifndef DUCKSTRATEGY_H
#define DUCKSTRATEGY_H

#include <functional>
#include <iostream>


static int commonFly;
// Fly Behavior
auto FlyWithWings = []() {
    int flyCount = 0;
    return [flyCount]() mutable {
        ++flyCount;
        std::cout << "I'm flying! Flight #" << flyCount << std::endl;
        commonFly = flyCount;
    };
};

auto FlyNoWay = [](){
    int flyCount = 0;
    return [flyCount]() mutable {
        flyCount = 0;
        commonFly = flyCount;
    }; };

// Quack Behavior
auto QuackNone = [](){ return []() {}; };
auto QuackNorm = [](){
     return [](){
         std::cout << "I'm Quack!!" << std::endl;
     };
};
auto Squeak = [](){
     return [](){
        std::cout << "I'm Squeak!!" << std::endl;
     };
};

// Dance Behavior
auto DanceWaltz = [](){
     return []() {
         std::cout << "I'm dance Waltz!!" << std::endl;
     };
};
auto DanceMenuete = [](){
     return []() {
             std::cout << "I'm dance Menuete!!" << std::endl;
     };
};
auto NoDance = [](){ return []() {}; };


#endif // DUCKSTRATEGY_H
