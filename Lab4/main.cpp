/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief A Semaphore Implementation to demonstrate a reusable barrier 
  \									
  \\ 

*/


#include "Barrier.h"
#include <iostream>
#include <thread>
#include <mutex>

/*
  //Function that demonstrates reusable barrier.
*/

void work(std::shared_ptr<Barrier> rb){
  	std::cout << "Thread working away...*BANG* Ouch a barrier! We all gotta smash this together to get thru!" << std::endl;
  	rb->Ready();
	std::cout << "*BOOM* We broke through together! Now we can continue!" << std::endl;
	rb->Done();
	std::cout << "Thread finished" << std::endl;
}
/*
  Main Method
 */

int main(void){
  int numThreads = 5;
  std::thread threadArr[numThreads] ;
  std::shared_ptr<Barrier> rb(new Barrier(numThreads));
  
  /**< Launch the threads  */
  for(int i = 0; i < numThreads; i++ ){
    threadArr[i] = std::thread(work, rb);
  }
  for(int i =0; i <numThreads; i++){
    threadArr[i].join(); 
  }
  std::cout << "All Threads Finished, back in main"<< std::endl ;
  return 0;
}
