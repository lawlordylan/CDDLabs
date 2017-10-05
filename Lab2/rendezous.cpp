#include "Semaphore.h"
#include <iostream>
#include <thread>
/** rendezous.cpp 
 *  Thread A has to wait for thread B
Thread B has to wait for thread A
Both have to arrive at a certain point before aither proceeds
Thread A
A1;
A2;
Thread B
B1;
B2;
A1 must finish before B2 starts
B1 must finish before A2 starts
 */
void taskA(std::shared_ptr<Semaphore> theSemaphore)
{
  std::cout <<"Thread A process 1"<<std::endl;
  /** <Need B1 to finish first */
  theSemaphore->Signal();
  theSemaphore->Wait();
  theSemaphore->Signal();
  std::cout <<"Thread A process 2"<<std::endl;
  
}
void taskB(std::shared_ptr<Semaphore> theSemaphore)
{
  std::cout <<"Thread B process 1"<<std::endl;
  /** <Need A1 to finish first */
  theSemaphore->Signal();
  theSemaphore->Wait();
  theSemaphore->Signal(); 
  std::cout <<"Thread B process 2"<<std::endl;
}

int main(void)
{
  std::thread threadA, threadB;
  std::shared_ptr<Semaphore> sem( new Semaphore(-1));
  /**< Launch the threads  */
  threadA=std::thread(taskA,sem);
  threadB=std::thread(taskB,sem);
  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  return 0;
}
