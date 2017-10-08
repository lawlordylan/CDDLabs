#include "Semaphore.h"
#include <iostream>
#include <thread>
/** mutex.cpp 
 *  Simple program to demonstrate the principles of semaphores and show them in action. This program will demonstrate the princples of mutual exclusion. A shared variable count can only be accessed by one thread at a time. This will be achieved using semaphores.
 */
void threadOne(std::shared_ptr<Semaphore> theSemaphore, int& count)
{
  theSemaphore->Wait();
  /**critical region */
  std::cout << "Thread 1 enters critical section. Count is "<< count << std::endl;
  count ++;
  std::cout << "Thread 1 increments count" << std::endl;
  std::cout << "Count: "<< count << std::endl;
  /**end critical region */
  std::cout << "Thread 1 exits critical section" << std::endl;
  theSemaphore->Signal();
}
void threadTwo(std::shared_ptr<Semaphore> theSemaphore, int& count)
{
  theSemaphore->Wait();
  /**critical region */
  std::cout << "Thread 2 enters critical section. Count is "<< count << std::endl;
  count ++;
  std::cout << "Thread 2 increments count" << std::endl;
  std::cout << "Count: "<< count << std::endl;
  /**end critical region*/
  std::cout << "Thread 2 exits critical section" << std::endl;
  theSemaphore->Signal();
}

int main(void)
{
  int count = 0;
  std::thread t1, t2;
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  /**< Launch the threads  */
  t1=std::thread(threadOne,sem, std::ref(count));
  t2=std::thread(threadTwo,sem, std::ref(count));
  std::cout << "Launched from the main\n";
  t1.join();
  t2.join();
  return 0;
}
