#ifndef FPCSC_PERFUTIL_SLEEP_H
#define FPCSC_PERFUTIL_SLEEP_H

#include <chrono>
#include <iostream>
#include <thread>

namespace fpcsc {

inline void sleep_for_secs(unsigned Secs) {
  std::cout << "Sleeping for " << Secs << " seconds" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(Secs));
}

inline void sleep_for_millisecs(unsigned Millisecs) {
  std::cout << "Sleeping for " << Millisecs << " milliseconds" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(Millisecs));
}

inline void sleep_for_nanosecs(unsigned millisecs) {
  std::this_thread::sleep_for(std::chrono::nanoseconds(millisecs));
}

} // namespace fpcsc

#endif // FPCSC_PERFUTIL_SLEEP_H
