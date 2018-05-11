/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief: Barrier.h 
  \									
  \\ 

*/
#include <mutex>
#include "Semaphore.h"
/*!
  Class used to implement a rendezvous with more than two threads, meaning N threads will have to reach a certain point (rendezvous) before continuing
 */
class Barrier{
public:
 	int count;
	int n;
	std::shared_ptr<Semaphore>  mutex;
	std::shared_ptr<Semaphore>  barrierA;
	std::shared_ptr<Semaphore>  barrierB;
	void Ready();
	void Done();
	Barrier(int c);
	
};
