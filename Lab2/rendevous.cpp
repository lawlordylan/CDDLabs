/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ brief A Semaphore Implementation to show the rendevous problem, where task A and task B must "rendevous" before either can continue
  \									\
  \\ Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"
#include <iostream>
#include <vector>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> task1, std::shared_ptr<Semaphore> task2){
  std::cout <<"Task 1 started " <<std::endl;
  std::cout << "Task 1 waiting for Task 2 " <<std::endl;
  task2-> Signal();
  task1-> Wait();
  std::cout << "Task 1 recieved signal from Task 2" <<std::endl;
  std::cout << "Task 1 finished and sending signal to Task 2" <<std::endl;
  task2 -> Signal();
}
void taskTwo(std::shared_ptr<Semaphore> task1,std::shared_ptr<Semaphore> task2){
  task2 -> Wait();
  std::cout <<"Task 2 started" <<std::endl;
  std::cout << "Task 2 will release Task 1 and wait for it to finish" <<std::endl;
  task1->Signal();
  task2->Wait();
  std::cout << "Task 2 has recieved signal that Task 1 finished" <<std::endl;
  std::cout << "Task 2 finished"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1(new Semaphore);
  std::shared_ptr<Semaphore> sem2(new Semaphore);
  /**< Launch the threads - Note thread 1 runs task2 which must finish last  */
  std::cout << "Launched from the main" << std::endl;
  threadOne=std::thread(taskTwo,sem1,sem2);
  threadTwo=std::thread(taskOne,sem1,sem2);
  threadOne.join();
  threadTwo.join();
  return 0;
}
