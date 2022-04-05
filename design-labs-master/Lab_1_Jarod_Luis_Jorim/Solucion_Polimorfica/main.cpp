// Lab #1 of Design
/*
Developed by:
* Luis Bolanos Valverde B91145
* Jarod Venegas Alpizar B98410
* Jorim G. Wilson Ellis B98615
*/

#include "Compound_activity.hpp"
#include "Simple_Activity.hpp"
#include "Type.hpp"

/**
 * @brief
 *   main setup to execute concept testing on the design
 */
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
  std::cout << "\nCreating a proyect type..." << std::endl;
  project_type->add_predefined_types();
  project_type->to_string_of_types();
  // project_type->add_a_new_type();
  // project_type->modify_a_type("Proyecto predefindo 2");
  // project_type->remove_a_type("Proyecto predefindo 2");
  Activity* new_activity =
      project_type->create_a_type_of_activity("Proyecto predefindo 2");
  new_activity->to_string();
}