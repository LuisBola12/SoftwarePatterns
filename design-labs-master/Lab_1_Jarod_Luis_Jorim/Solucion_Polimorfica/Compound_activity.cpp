#include "Compound_activity.hpp"

#include <algorithm>
Compound_Activity::Compound_Activity() {}
Compound_Activity::~Compound_Activity() {}
void Compound_Activity::set_activities(std::vector<Activity *> activities) {
  this->activities = activities;
  for (int index = 0; index < (int)this->activities.size(); index++) {
    this->activities[index]->set_head(this);
  }
}
void Compound_Activity::push_activities(Activity *activity) {
  activity->set_head(this);
  this->activities.push_back(activity);
}
void Compound_Activity::remove_activity(Activity *activity) {
  this->activities.erase(
      std::remove(this->activities.begin(), this->activities.end(), activity),
      this->activities.end());
}

int Compound_Activity::compare_two_dates(std::vector<int> date1,
                                         std::vector<int> date2) {
  if (date1[2] == date2[2]) {
    if (date1[1] == date2[1]) {
      if (date1[0] == date2[0]) {
        return 1;
      } else {
        if (date1[0] < date2[0]) {
          return 1;
        } else {
          return 0;
        }
      }
    } else {
      if (date1[1] < date2[1]) {
        return 1;
      } else {
        return 0;
      }
    }
  } else {
    if (date1[2] < date2[2]) {
      return 1;
    } else {
      return 0;
    }
  }
}

std::string print_date(std::vector<int> planned_init_data) {
  std::string to_print;
  for (int i = 0; i < 3; i++) {
    to_print += std::to_string(planned_init_data[i]) + "/";
  }

  to_print.pop_back();
  return to_print;
}

void Compound_Activity::conf_init_date() {
  std::vector<int> oldest_date = this->activities[0]->init_date;
  for (int index = 1; index < (int)this->activities.size(); index++) {
    if (compare_two_dates(oldest_date, this->activities[index]->init_date) ==
        0) {
      oldest_date = this->activities[index]->init_date;
    }
  }
  this->init_date = oldest_date;
}
void Compound_Activity::conf_end_date() {
  std::vector<int> furthest_date = this->activities[0]->end_date;
  for (int index = 1; index < (int)this->activities.size(); index++) {
    if (compare_two_dates(furthest_date, this->activities[index]->end_date) ==
        1) {
      furthest_date = this->activities[index]->end_date;
    }
  }
  this->end_date = furthest_date;
}
void Compound_Activity::conf_planned_init_date() {
  std::vector<int> oldest_date = this->activities[0]->planned_init_date;
  for (int index = 1; index < (int)this->activities.size(); index++) {
    if (compare_two_dates(oldest_date,
                          this->activities[index]->planned_init_date) == 0) {
      oldest_date = this->activities[index]->planned_init_date;
    }
  }
  this->planned_init_date = oldest_date;
}
void Compound_Activity::conf_planned_end_date() {
  std::vector<int> furthest_date = this->activities[0]->planned_end_date;
  for (int index = 1; index < (int)this->activities.size(); index++) {
    if (compare_two_dates(furthest_date,
                          this->activities[index]->planned_end_date) == 1) {
      furthest_date = this->activities[index]->planned_end_date;
    }
  }
  this->planned_end_date = furthest_date;
}

std::vector<Activity *> Compound_Activity::get_compound_activity() {
  return this->activities;
}

void Compound_Activity::configurate_dates() {
  conf_init_date();
  conf_end_date();
  conf_planned_init_date();
  conf_planned_end_date();
}

void Compound_Activity::to_string() {
  std::string to_print = "\n\t\t----||Compound Activity||----";
  to_print += "\n*Project Manager: " + get_manager();
  to_print += "\n*Description: " + get_description();
  // std::cout << to_print << std::endl;
  to_print += "\n*Planned Initial Date: " + print_date(get_planned_init_date());
  to_print +=
      " - Planned Finalization Date: " + print_date(get_planned_end_date());
  to_print += "\n*Initial Date: " + print_date(get_init_date());
  to_print += " - Finalization Date: " + print_date(get_end_date());
  // std::cout << to_print << std::endl;

  std::cout << to_print << std::endl;
  for (int index = 0; index < (int)activities.size(); index++) {
    activities[index]->to_string();
  }
}

/*
 si mis actividades estan vacias -> retorna las fechas


*/