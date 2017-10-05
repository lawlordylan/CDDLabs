#include "Semaphore.h"
/** \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

/** Wait Method
 *  decrement the semaphore and locks the thread if
 *  value is <0
 */
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}
/** Signal Method
 *  Inncrement the semaphore and unlocks one thread if
 *  value is >0
 */
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
