/*! 
  \\ Author: Dylan Lawlor
  \\ Date: 11/05/2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief: Demonstration of the use of the SafeBuffer class
  \									
  \\ 
*/

#include "SafeBuffer.h"
#include <iostream>
#include <chrono>
#include <thread>

/**
   Main Buffer for counting characters consumed
 */
int characterCountBuffer[26] = {0};

/**
   ConsumerMethod removes a character from the safe buffer, at random time intevals. It also keeps track of the count of each letter removed.
 */

void ConsumerMethod(std::shared_ptr<SafeBuffer> sBuff) {
  char c;
  while ( c != 'X')
    {
       c = sBuff->Pop();
       std::cout << "Consuming " << c << std::endl;
       std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
       characterCountBuffer[c]++;
    }
}

/**
   ProducerMethod adds a random character to a safe buffer, at random timer intervals.
   When it has produced numCharacters amount of items it pushs 'X' to the buffer to signal the end.
 */

void ProducerMethod(std::shared_ptr<SafeBuffer> sBuff, int numCharacters) {
  char c;
  int i = 0;
  while ( i <= numCharacters)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
      c =  std::rand() % 26 + 97;
      sBuff->Push(c);
      i++;
      std::cout << "Producing " << c << std::endl;
    }
  sBuff->Push('X');  
}

/**
   PrintCharCount the count buffer.
 */

void PrintCharCount() {
  for ( char i = 97; i < 123; ++i ) {
    std::cout << i << ":" << characterCountBuffer[i] << std::endl;
  }
}

int main(void) {
  int numCharacters;
  std::shared_ptr<SafeBuffer> sBuff(new SafeBuffer);
  std::thread producerThread[5];
  std::thread consumerThread[5];

  std::cout << "How many characters will each thread use?" << std::endl;
  std::cin >> numCharacters;

  for ( int i = 0; i < 5; i++ ) {
    producerThread[i] = std::thread(ProducerMethod, sBuff, numCharacters);
    consumerThread[i] = std::thread(ConsumerMethod, sBuff);
  }

  for ( int i = 0; i < 5; i++ ) {
    producerThread[i].join();
    consumerThread[i].join();
  }

  PrintCharCount();
  std::cout << "Fin"<< std::endl;
  return 0;
}
