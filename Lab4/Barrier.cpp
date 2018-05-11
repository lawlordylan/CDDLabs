/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief: Barrier Class - a semaphore implementation of the barrier class where N threads need to rendevous before continuing
  \									
  \\ 

*/
#include "Barrier.h"
#include <iostream>
#include <mutex>
/*!
  Ready is called to indicate that a thread has reached the rendevous
 */
void Barrier::Ready(){
  	mutex->Wait();
	count++;
	if(count == n){
	  barrierB->Wait();
	  barrierA->Signal();
	}
	mutex->Signal();
	barrierA->Wait();
	barrierA->Signal();
}
/*!
  Done is called to indicate all threads have finished and the count can be reset
 */
void Barrier::Done(){	
	mutex->Wait();
	count--;
	if(count == 0){
	  barrierA->Wait();
	  barrierB->Signal();
	}
	mutex->Signal();
	barrierB->Wait();
	barrierB->Signal();
}

Barrier::Barrier(int c){
	  n = c;
	  count = 0;
	  mutex=std::make_shared<Semaphore>(1);
	  barrierA=std::make_shared<Semaphore>(0);
	  barrierB=std::make_shared<Semaphore>(1);
	  
}

	


