#ifndef ACTIVITY
#define ACTIVITY
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief
 *   Abstract class simulating what an activity should be and it's respective
 * setters and getters
 */
class Activity {
 public:
  Activity* head;
  std::string manager;
  std::string description;
  std::vector<int> init_date;
  std::vector<int> end_date;
  std::vector<int> planned_init_date;
  std::vector<int> planned_end_date;
  std::vector<Activity*> activities;
  Activity();
  ~Activity();
  void set_head(Activity* head);
  void set_manager(std::string manager);
  void set_description(std::string description);
  void set_init_date(int day, int month, int year);
  void set_end_date(int day, int month, int year);
  void set_planned_init_date(int day, int month, int year);
  void set_planned_end_date(int day, int month, int year);
  Activity* get_head();
  std::string get_manager();
  std::string get_description();
  std::vector<int> get_init_date();
  std::vector<int> get_end_date();
  std::vector<int> get_planned_init_date();
  std::vector<int> get_planned_end_date();

  // Virtual method to print results. Changes according to class implementation
  virtual void to_string() = 0;
  virtual void configurate_dates() = 0;
  virtual void set_activities(std::vector<Activity*> activities) = 0;
};
#endif