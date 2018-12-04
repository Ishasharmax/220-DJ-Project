//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "Song.h"
#include "MasterList.h"
#include "../NewFinalProject/DJTestLib.h"

void runCarTests(){
    Car myCar =  Car(1995, "Chevy", "Blazer", 500, 85);
    std::cout << myCar.toString() << std::endl;
    printAssertEquals(415, myCar.calcPotentialProfit(), 0.00001);

    myCar.addRepairCost(15);
    myCar.addRepairCost(100);
    printAssertEquals(300, myCar.calcPotentialProfit(), 0.00001);
}

void runPriorityQueueTest(PriorityQueue *qToTest){
    std::cout << "---------- testAddAndDequeue ----------"<< std::endl;
    qToTest->addItem("1. broken bone", 2.5);
    qToTest->addItem("2. head trauma", 3.4);
    qToTest->addItem("3. cut on foot", 1.05);
    qToTest->addItem("4. sore throat", 0.8);
    qToTest->addItem("5. animal bite", 2.5);
    qToTest->addItem("6. cut on back", 1.1);

    while (!qToTest->isEmpty()) {
        std::cout << qToTest->dequeueHighestPriorityItem() << std::endl;
    }
    std::cout << "---- done ----"<< std::endl;;
}

void runFastDequeueTest(){
    PriorityQueue* p1 = new LinkedPriorityQueueFastDequeue();
    runPriorityQueueTest(p1);
    delete p1;
}