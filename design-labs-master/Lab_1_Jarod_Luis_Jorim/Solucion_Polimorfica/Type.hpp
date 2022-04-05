#ifndef TYPE
#define TYPE
#include "Compound_activity.hpp"
#include "Simple_Activity.hpp"

/**
 * @brief
 *   Concrete class used to keep track on the types of projects
 */

// Struct to add/modify activities to a project
typedef struct {
  std::string name_of_activity;
  int number_of_times;
} Configurate_project;

// Struct used to build and keep tabs on a project type or configuration
typedef struct {
  std::string name_of_type;
  std::vector<Configurate_project> type_activites;
} type_of_project;

class Type {
 private:
  std::vector<type_of_project> types_of_projects;

 public:
  Type();
  ~Type();
  void add_a_new_type();
  void remove_a_type(std::string name_of_type);
  void modify_a_type(std::string name_of_type);
  void add_predefined_types();
  Activity* create_a_type_of_activity(std::string name_of_type);
  // This method prints the project's type
  void to_string_of_types();
  // This method returns the activities configured in a given project type
  std::string in_type(int position);
};

#endif