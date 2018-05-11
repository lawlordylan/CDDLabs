/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief: implementation of the SafeBuffer class
  \									
  \\ 

*/

#include "SafeBuffer.h"
#include <iostream>

/**
   Constructor, spaces provides a fininte buffer size
 */

SafeBuffer::SafeBuffer() {
  items = std::make_shared<Semaphore>(0);
  mutex = std::make_shared<Semaphore>(1);
  spaces = std::make_shared<Semaphore>(100);
}

/**
  Push checks wether there is space on the buffer (spaces semaphore)
  When there is space Push locks access to the buffer (using mutex)
  Character is pushed to the buffer and the lock released, as well as items signaled.
 */

void SafeBuffer::Push(char c) {
  spaces->Wait();
  mutex->Wait();
  safeBuffer.push(c);
  mutex->Signal();
  items->Signal();
}

/**
   Pop checks if there is an item in the buffer (items semaphore)
   If there is Pop locks access to the buffer (mutex semaphore)
   The front character is popped, and the lock released, with spaces signalled to indicate there is more space on the buffer.
 */

char SafeBuffer::Pop() {
  char c;
  items->Wait();
  mutex->Wait();
  c = safeBuffer.front();
  safeBuffer.pop();
  mutex->Signal();
  spaces->Signal();
  return c;
}
