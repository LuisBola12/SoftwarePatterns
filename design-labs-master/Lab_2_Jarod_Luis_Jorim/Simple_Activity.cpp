#include "Simple_Activity.hpp"

Simple_Activity::Simple_Activity() {}

Simple_Activity::~Simple_Activity() {}

void Simple_Activity::configurate_dates() {}

void Simple_Activity::set_activities(std::vector<Activity *> activities) {
  this->activities = activities;
  for (int index = 0; index < (int)this->activities.size(); index++) {
    this->activities[index]->set_head(this);
  }
}

void Simple_Activity::to_serializate(
    std::vector<std::string> *vec_to_serializate) {
  set_values(vec_to_serializate);
}

void Simple_Activity::set_valores_1() {
  this->set_manager("Pablo");
  this->set_description("Prueba 1 con manager");
  this->set_init_date(1, 12, 2020);
  this->set_end_date(15, 11, 2020);
  this->set_planned_init_date(1, 10, 2020);
  this->set_planned_end_date(15, 11, 2020);
}

void Simple_Activity::set_valores_2() {
  // this->set_manager("");
  this->set_description("Prueba 2 sin manager");
  this->set_init_date(18, 10, 2020);
  this->set_end_date(1, 11, 2020);
  this->set_planned_init_date(15, 9, 2020);
  this->set_planned_end_date(15, 10, 2020);
}