#include "Semaphore.h"
#include <iostream>
#include <thread>
/** signal.cpp 
 *  Simple program to demonstrate the principles of semaphores and show them in action. The function taskOne has to complete before taskTwo, no matter the timing of their actual executions
 */
void taskOne(std::shared_ptr<Semaphore> theSemaphore)
{
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
{
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
