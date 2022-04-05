#ifndef SIMPLE_ACTIVITY
#define SIMPLE_ACTIVITY
#include <string>
#include <vector>

#include "Activity.hpp"

/**
 * @brief
 *   Concrete class simulating a single activity and it's respective setters and
 * getters Inherits from Activity class
 */
class Simple_Activity : public Activity<Simple_Activity> {
 public:
  Simple_Activity();
  ~Simple_Activity();
  void set_valores_1();
  void set_valores_2();
  // This method prints the vector passed as a string with dd/mm/yy format
  std::string print_date(std::vector<int> planned_date_data);
  // abstract method to print results
  void configurate_dates() override;
  void to_string() override;
};
#endif