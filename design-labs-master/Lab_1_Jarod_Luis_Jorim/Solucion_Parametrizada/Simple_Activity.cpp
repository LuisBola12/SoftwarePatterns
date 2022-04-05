#include "Simple_Activity.hpp"
Simple_Activity::Simple_Activity() {}
Simple_Activity::~Simple_Activity() {}
void Simple_Activity::configurate_dates() {}

std::string Simple_Activity::print_date(std::vector<int> planned_init_data) {
  std::string to_print;
  for (int i = 0; i < 3; i++) {
    to_print += std::to_string(planned_init_data[i]) + "/";
  }

  to_print.pop_back();
  return to_print;
}

void Simple_Activity::to_string() {
  std::string to_print = "\n\t\t----||Simple Activity||----";
  to_print += "\n*Manager: " + this->get_manager();
  to_print += "\n*Description: " + this->get_description();
  to_print +=
      "\n*Planned Initial Date: " + print_date(this->get_planned_init_date());
  to_print += " - Planned Finalization Date: " +
              print_date(this->get_planned_end_date());
  to_print += "\n*Initial Date: " + print_date(this->get_init_date());
  to_print += " - Finalization Date: " + print_date(this->get_end_date());

  std::cout << to_print << std::endl;
}
void Simple_Activity::set_valores_1() {
  this->set_manager("Pablo");
  this->set_description("Ensayo 1 con manager");
  this->set_init_date(1, 12, 2020);
  this->set_end_date(15, 11, 2020);
  this->set_planned_init_date(1, 10, 2020);
  this->set_planned_end_date(15, 11, 2020);
}
/**
 * @brief
 *
 */
void Simple_Activity::set_valores_2() {
  // this->set_manager("");
  this->set_description("Ensayo 2 sin manager");
  this->set_init_date(18, 10, 2020);
  this->set_end_date(1, 11, 2020);
  this->set_planned_init_date(15, 9, 2020);
  this->set_planned_end_date(15, 10, 2020);
}