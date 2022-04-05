#include "Activity.hpp"
Activity::Activity() {
  this->head = nullptr;
  this->manager = "";
  this->description = "";
}
Activity::~Activity() {}
void Activity::set_head(Activity* head) {
  this->head = head;
  // std::cout << head->get_manager()+ " hola" << std::endl;
}
Activity* Activity::get_head() { return this->head; }
void Activity::set_manager(std::string manager) { this->manager = manager; }
std::string Activity::get_manager() {
  if (this->manager == "") {
    if (head) {
      return this->head->get_manager();
    } else {
      std::cerr << " NOTE: No manager and head specified!" << std::endl;
    }
  }
  return this->manager;
}
void Activity::set_description(std::string description) {
  this->description = description;
}
std::string Activity::get_description() { return this->description; }

std::vector<int> Activity::get_init_date() { return this->init_date; }
std::vector<int> Activity::get_end_date() { return this->end_date; }
std::vector<int> Activity::get_planned_init_date() {
  return this->planned_init_date;
}
std::vector<int> Activity::get_planned_end_date() {
  return this->planned_end_date;
}

void Activity::set_init_date(int day, int month, int year) {
  this->init_date.push_back(day);
  this->init_date.push_back(month);
  this->init_date.push_back(year);
}
void Activity::set_end_date(int day, int month, int year) {
  this->end_date.push_back(day);
  this->end_date.push_back(month);
  this->end_date.push_back(year);
}
void Activity::set_planned_init_date(int day, int month, int year) {
  this->planned_init_date.push_back(day);
  this->planned_init_date.push_back(month);
  this->planned_init_date.push_back(year);
}
void Activity::set_planned_end_date(int day, int month, int year) {
  this->planned_end_date.push_back(day);
  this->planned_end_date.push_back(month);
  this->planned_end_date.push_back(year);
}
void Activity::set_activity_name(std::string name){
  this->name_of_activity = name;
}
std::string Activity::get_activity_name(){
  return name_of_activity;
}
void Activity::set_values(std::vector<std::string> * vector_of_values){
  vector_of_values->push_back(name_of_activity);
  vector_of_values->push_back(get_manager());
  vector_of_values->push_back(description);
  vector_of_values->push_back(vec_to_string(init_date));
  vector_of_values->push_back(vec_to_string(end_date));
}
std::string Activity::vec_to_string(std::vector<int> date) {
  std::string to_print;
  for (int i = 0; i < 3; i++) {
    to_print += std::to_string(date[i]) + "/";
  }

  to_print.pop_back();
  return to_print;
}