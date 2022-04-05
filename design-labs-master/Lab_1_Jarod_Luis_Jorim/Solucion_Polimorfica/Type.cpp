#include "Type.hpp"

#include <istream>

Type::Type() {}
Type::~Type() {}
void Type::add_a_new_type() {
  std::string input;
  int number_of_inputs = 0;
  type_of_project new_project_type;
  Configurate_project new_activity;
  std::cout
      << "Enter the name of the type of Activity you want to configurate: "
      << std::endl;
  std::getline(std::cin, input);
  new_project_type.name_of_type = input;

  while (true) {
    std::cout << "If you want to exit this enter (exit)" << std::endl;
    std::getline(std::cin, input);
    if (input == "exit") {
      break;
    } else {
      if (number_of_inputs == 0) {
        std::cout << "Enter the name of the head Activity: " << std::endl;
        std::getline(std::cin, input);
        new_activity.name_of_activity = input;
        new_activity.number_of_times = 1;
        new_project_type.type_activites.push_back(new_activity);
        number_of_inputs++;
      } else {
        std::cout << "Enter the name of this sub-activity" << std::endl;
        std::getline(std::cin, input);
        new_activity.name_of_activity = input;
        std::cout << "Enter the number of activities for this type of Activity"
                  << std::endl;
        std::getline(std::cin, input);
        new_activity.number_of_times = stoi(input);
        new_project_type.type_activites.push_back(new_activity);
        number_of_inputs++;
      }
    }
  }

  this->types_of_projects.push_back(new_project_type);
}

void Type::remove_a_type(std::string name_of_type) {
  bool find = true;
  int index = 0;
  while (find != false) {
    if (this->types_of_projects[index].name_of_type == name_of_type) {
      find = false;
    }
    index++;
  }
  std::vector<type_of_project>::iterator iter =
      types_of_projects.begin() + index;
  this->types_of_projects.erase(iter);
}
void Type::modify_a_type(std::string name_of_type) {
  type_of_project project_to_modify;
  int position;
  for (int i = 0; i < (int)types_of_projects.size(); i++) {
    if (types_of_projects[i].name_of_type == name_of_type) {
      project_to_modify = types_of_projects[i];
      position = i;
    }
  }
  std::cout << "Type to modify" << std::endl;
  std::cout << in_type(position) << std::endl;

  std::string input;
  bool condition = true;
  while (condition) {
    std::cout << "What do you want to do? \n[1] Add \n[2] Remove \n[3] Exit"
              << std::endl;
    std::getline(std::cin, input);
    std::vector<Configurate_project> modify_type =
        project_to_modify.type_activites;
    Configurate_project new_activity;
    std::vector<Configurate_project>::iterator iter;
    switch (stoi(input)) {
      case 1:
        std::cout << "Based on the order of the type" << std::endl;
        std::cout << "¿Where do you want to add the activity?" << std::endl;
        std::getline(std::cin, input);
        iter = modify_type.begin() + stoi(input);
        std::cout << "Enter the name of the new activity" << std::endl;
        std::getline(std::cin, input);
        new_activity.name_of_activity = input;
        std::cout << "Enter the number of activities for this type of Activity"
                  << std::endl;
        std::getline(std::cin, input);
        new_activity.number_of_times = stoi(input);
        modify_type.insert(iter, new_activity);
        break;
      case 2:
        std::cout << "Based on the order of the type" << std::endl;
        std::getline(std::cin, input);
        iter = modify_type.begin() + stoi(input);
        modify_type.erase(iter);
        break;
      case 3:
        break;
    }
  }
  std::cout << "Enter the name of the head Activity: " << std::endl;
  std::getline(std::cin, input);
}

void Type::add_predefined_types() {
  type_of_project predefined_type_1;
  type_of_project predefined_type_2;

  Configurate_project first_activity;
  Configurate_project second_activity;
  Configurate_project third_activity;

  // Configurate the first type of ptoject
  predefined_type_1.name_of_type = "Proyecto predefindo 1";
  // First activity
  first_activity.name_of_activity = "Proyecto";
  first_activity.number_of_times = 1;
  // Second activity
  second_activity.name_of_activity = "Tarea";
  second_activity.number_of_times = 4;
  // Add the activities in the project
  predefined_type_1.type_activites.push_back(first_activity);
  predefined_type_1.type_activites.push_back(second_activity);

  // Configurate the second type of ptoject
  predefined_type_2.name_of_type = "Proyecto predefindo 2";
  // First activity
  first_activity.name_of_activity = "Proyecto";
  first_activity.number_of_times = 1;
  // Second activity
  second_activity.name_of_activity = "Fase";
  second_activity.number_of_times = 2;
  // Third activity
  third_activity.name_of_activity = "Tarea";
  third_activity.number_of_times = 2;
  // Add the activities in the project
  predefined_type_2.type_activites.push_back(first_activity);
  predefined_type_2.type_activites.push_back(second_activity);
  predefined_type_2.type_activites.push_back(third_activity);

  // Add the types of projects in the vector
  this->types_of_projects.push_back(predefined_type_1);
  this->types_of_projects.push_back(predefined_type_2);
}

Activity* Type::create_a_type_of_activity(std::string name_of_type) {
  type_of_project project_to_create;
  for (int i = 0; i < (int)types_of_projects.size(); i++) {
    if (types_of_projects[i].name_of_type == name_of_type) {
      project_to_create = types_of_projects[i];
    }
  }

  std::vector<std::vector<Activity*>> project_template;
  project_template.resize(project_to_create.type_activites.size());
  for (int i = 1; i < (int)project_to_create.type_activites.size(); i++) {
    if (i == (int)project_to_create.type_activites.size() - 1) {
      for (int j = 0;
           j < (int)project_to_create.type_activites[i].number_of_times; j++) {
        Simple_Activity* activity = new Simple_Activity();
        if (j == 0) {
          activity->set_valores_2();
        } else {
          activity->set_valores_1();
        }
        activity->set_description(
            project_to_create.type_activites[i].name_of_activity);
        project_template[i].push_back(activity);
      }
    } else {
      for (int j = 0;
           j < (int)project_to_create.type_activites[i].number_of_times; j++) {
        Compound_Activity* compound_activity = new Compound_Activity();
        compound_activity->set_manager("Jeisson");
        compound_activity->set_description(
            project_to_create.type_activites[i].name_of_activity);
        project_template[i].push_back(compound_activity);
      }
    }
  }

  for (int i = (int)project_template.size() - 1; i > 1; i--) {
    for (int j = 0; j < (int)project_template[i].size(); j++) {
      project_template[i - 1][j]->set_activities(project_template[i]);
      project_template[i - 1][j]->configurate_dates();
      // project_template[i-1][j]->set_head(project_template[i][j]);
    }
  }

  Compound_Activity* complete_project = new Compound_Activity();
  complete_project->set_manager("JEISSON 2.0");
  complete_project->set_description(
      project_to_create.type_activites[0].name_of_activity);
  complete_project->set_activities(project_template[1]);
  complete_project->configurate_dates();
  /*
     P
   F   F
  T T T T
  */
  // complete_project->to_string();
  return complete_project;
}

void Type::to_string_of_types() {
  std::cout << "Available Preconfigured Types:" << std::endl;
  std::string output = "";
  for (int index = 0; index < (int)this->types_of_projects.size(); index++) {
    output += "Configuration " + std::to_string(index + 1) + ": " +
              this->types_of_projects[index].name_of_type;
    output += " [" + in_type(index) + "]";
    output += "\n";
  }
  std::cout << output << std::endl;
}
std::string Type::in_type(int position) {
  std::string output = "";
  int size_of_vec =
      (int)this->types_of_projects[position].type_activites.size();
  for (int index = 0; index < size_of_vec; index++) {
    output += " " + std::to_string(index) + ".";
    output += this->types_of_projects[position]
                  .type_activites[index]
                  .name_of_activity;
    output += "->";
  }
  output.pop_back();
  output.pop_back();
  return output;
}