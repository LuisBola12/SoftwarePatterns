#pragma once
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief
 *   Abstract class simulating what an activity should be and it's respective
 * setters and getters
 */
class Act;
template <typename Self>
class Activity {
 public:
  Activity<Self>* head;
  std::string manager;
  std::string description;
  std::vector<int> init_date;
  std::vector<int> end_date;
  std::vector<int> planned_init_date;
  std::vector<int> planned_end_date;
  std::vector<Activity<Self>*> activities;
  // Virtual method to print results. Changes according to class implementation
  virtual void to_string() = 0;
  virtual void configurate_dates() = 0;

  Activity() {
    static_cast<Self*>(this)->head = nullptr;
    static_cast<Self*>(this)->manager = "";
    static_cast<Self*>(this)->description = "";
  }

  ~Activity() {}
  template <typename T>
  void set_head(T* head) {
    static_cast<Self*>(this)->head = dynamic_cast<Self*>(head);
  }

  template <typename T>
  void push_activities(T* activity) {
    activity->set_head(static_cast<Self*>(this));
    static_cast<Self*>(this)->activities.push_back(
        dynamic_cast<Self*>(activity));
  }

  void set_manager(std::string manager) {
    static_cast<Self*>(this)->manager = manager;
  }

  std::string get_manager() {
    if (static_cast<Self*>(this)->manager == "") {
      if (head) {
        return static_cast<Self*>(this)->head->get_manager();
      } else {
        std::cerr << " NOTE: No manager and head specified!" << std::endl;
      }
    }
    return static_cast<Self*>(this)->manager;
  }

  void set_description(std::string description) {
    static_cast<Self*>(this)->description = description;
  }

  std::string get_description() {
    return static_cast<Self*>(this)->description;
  }

  std::vector<int> get_init_date() {
    return static_cast<Self*>(this)->init_date;
  }
  std::vector<int> get_end_date() { return static_cast<Self*>(this)->end_date; }
  std::vector<int> get_planned_init_date() {
    return static_cast<Self*>(this)->planned_init_date;
  }
  std::vector<int> get_planned_end_date() {
    return static_cast<Self*>(this)->planned_end_date;
  }

  void set_init_date(int day, int month, int year) {
    static_cast<Self*>(this)->init_date.push_back(day);
    static_cast<Self*>(this)->init_date.push_back(month);
    static_cast<Self*>(this)->init_date.push_back(year);
  }
  void set_end_date(int day, int month, int year) {
    static_cast<Self*>(this)->end_date.push_back(day);
    static_cast<Self*>(this)->end_date.push_back(month);
    static_cast<Self*>(this)->end_date.push_back(year);
  }
  void set_planned_init_date(int day, int month, int year) {
    static_cast<Self*>(this)->planned_init_date.push_back(day);
    static_cast<Self*>(this)->planned_init_date.push_back(month);
    static_cast<Self*>(this)->planned_init_date.push_back(year);
  }
  void set_planned_end_date(int day, int month, int year) {
    static_cast<Self*>(this)->planned_end_date.push_back(day);
    static_cast<Self*>(this)->planned_end_date.push_back(month);
    static_cast<Self*>(this)->planned_end_date.push_back(year);
  }
  template <typename T>
  void set_activities(std::vector<T*> activities) {
    static_cast<Self*>(this)->activities = activities;
    for (int index = 0;
         index < (int)static_cast<Self*>(this)->activities.size(); index++) {
      static_cast<Self*>(this)->activities[index]->set_head(this);
    }
  }
};