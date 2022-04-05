// Lab #1 of Design
/*
Developed by:
* Luis Bolanos Valverde B91145
* Jarod Venegas Alpizar B98410
* Jorim G. Wilson Ellis B98615
*/

#include <istream>

#include "Compound_activity.hpp"
#include "JSON_Serialization_Constructor.hpp"
#include "XML_Serialization_Constructor.hpp"
#include "Simple_Activity.hpp"
#include "Type.hpp"

#define MENU                                                     \
  "Que tipo de proyecto desea crear?\n[1] Proyecto Simple\n[2] " \
  "Proyecto Compuesto\n "
/**
 * @brief
 *   main setup to execute concept testing on the design
 */

string director(Abstract_Serialization_Constructor* cs, Activity* activity,
                int number_of_activities) {
  std::vector<std::string> vec_to_serializate;
  activity->to_serializate(&vec_to_serializate);
  for (int i = 0; i < number_of_activities; i++) {
    cs->initialize_object(vec_to_serializate.front());
    vec_to_serializate.erase(vec_to_serializate.begin());
    cs->serialize_activity(&vec_to_serializate);
    cs->end_object();
  }
  std::string buffer = cs->get_serialization();

  return buffer;
}
int main() {
  //------Testing types of projects--------

  /*
     NOTA
     Esta implementacion permite la creacion y modificacion de tipos de
     proyectos mediante la interaccion con el usuario. Aqui estan las funciones
     comentadas pero no se utilizan ya que estamos creando un tipo de proyecto
     ya predefinido.
  */
  Type* project_type = new Type();
  std::cout << "\nTipos de Proyectos....\n" << std::endl;
  project_type->add_predefined_types();
  project_type->to_string_of_types();
  // project_type->add_a_new_type();
  // project_type->modify_a_type("Proyecto predefindo 2");
  // project_type->remove_a_type("Proyecto predefindo 2");
  Activity* new_activity;
  int number_of_total_activities;

  std::string input = "";
  std::cout << MENU << std::endl;
  getline(std::cin, input);
  if (input == "1") {
    new_activity = project_type->constructor_of_type("Proyecto Simple");
    number_of_total_activities =
        project_type->get_total_of_activities("Proyecto Simple");
  } else {
    new_activity = project_type->constructor_of_type("Proyecto Compuesto");
    number_of_total_activities =
        project_type->get_total_of_activities("Proyecto Compuesto");
  }

  std::cout << "\nAhora usando el serializador XML: " << std::endl;
  JSON_Serialization_Constructor* cs_xml =
      new JSON_Serialization_Constructor();  // se crea el serializador
  std::cout << director(cs_xml, new_activity, number_of_total_activities)
            << endl;

  std::cout << "" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "" << std::endl;

  std::cout << "\nAhora usando el serializador JSON: " << std::endl;
  JSON_Serialization_Constructor* cs_json =
      new JSON_Serialization_Constructor();  // se crea el serializador
  std::cout << director(cs_json, new_activity, number_of_total_activities)
            << std::endl;

  return 0;
}