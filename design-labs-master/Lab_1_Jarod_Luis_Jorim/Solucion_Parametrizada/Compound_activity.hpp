#ifndef COMPOUND_ACTIVITY
#define COMPOUND_ACTIVITY
#include <string>
#include <vector>

#include "Activity.hpp"

/**
 * @brief
 *   Concrete class simulating a group of activities and it's respective setters
 * and getters Inherits from Activity class
 */
class Compound_Activity : public Activity<Compound_Activity> {
  // private:
  // std::vector<Activity*> activities;
 public:
  Compound_Activity();
  ~Compound_Activity();
  // This method compares two given dates and returs a 1 if first date is lesser
  // than the second date. Returns 0 on the flipside
  int compare_two_dates(std::vector<int> date1, std::vector<int> date2);
  void remove_activity(Activity* activity);
  // This method returns all the activities that make up this compound activity
  void configurate_dates() override;
  void conf_init_date();
  void conf_end_date();
  void conf_planned_init_date();
  void conf_planned_end_date();
  // abstract method to print results
  void to_string() override;
};
#endif