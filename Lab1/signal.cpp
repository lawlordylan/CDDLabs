/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018 
  \\ brief A Semaphore Implementation to show serialization, where task A must happen before task B
  \									
  \\ Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>


void taskA(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
void taskB(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads - Note we launch taskB first, despite wanting taskA to happen before taskB */
  std::cout << "Launched from the main" << std::endl;
  threadOne=std::thread(taskB,sem);
  threadTwo=std::thread(taskA,sem);
  threadOne.join();
  threadTwo.join();
  return 0;
}
