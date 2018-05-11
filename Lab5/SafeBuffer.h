#ifndef SAFEBUFFER_H
#define SAFEBUFFER_H

/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief: SafeBuffer header file
  \									
  \\ 

*/

#include <mutex>
#include "Semaphore.h"
#include <queue>

/*!  SafeBuffer class*/
class SafeBuffer {
 public:
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> items;
  std::shared_ptr<Semaphore> spaces;
  std::queue<char> safeBuffer;
  SafeBuffer();
  void Push(char);
  char Pop();
};

#endif //  SAFEBUFFER_H_
