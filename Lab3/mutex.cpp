/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ brief A Semaphore Implementation to show mutual exclusion where only one thread at a time can access a shared variable, in this case a counter.
  \  
  \\ Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

void threadOne(std::shared_ptr<Semaphore> theSemaphore, int& count)
{
  std::cout << "Thread 1 started" << std::endl;
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
  std::cout << "Thread 2 started" << std::endl;
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
