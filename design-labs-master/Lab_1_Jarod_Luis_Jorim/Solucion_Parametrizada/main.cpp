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
    NOTA:
    Intentamos seguir la misma idea de hacer los casteos del profe,
    sin embargo, requería de otras cosas como convertir una clase a otra
    por lo que tuvimos que utilizar dynamic_cast y si bien si se logra
    hacer el casteo y se guardan en el vector de actividades, estas 
    pierden sus valores, por lo tanto, al intentar hacer el metodo de 
    configurate_dates este se cae ya que no hay informacion dentro de 
    las actividades.
  */
  Type* project_type = new Type();
  std::cout << "\nCreating a proyect type..." << std::endl;
  project_type->add_predefined_types();
  project_type->to_string_of_types();

  Compound_Activity project;
  Compound_Activity fase_1;
  Compound_Activity fase_2;

  Simple_Activity tarea_1;
  Simple_Activity tarea_2;
  Simple_Activity tarea_3;
  Simple_Activity tarea_4;

  tarea_1.set_valores_1();
  tarea_2.set_valores_2();
  tarea_3.set_valores_1();
  tarea_4.set_valores_2();

  fase_1.push_activities<Simple_Activity>(&tarea_1);
  fase_1.push_activities<Simple_Activity>(&tarea_2);
  fase_1.configurate_dates();

  fase_2.push_activities<Simple_Activity>(&tarea_3);
  fase_2.push_activities<Simple_Activity>(&tarea_4);
  fase_2.configurate_dates();

  project.push_activities<Compound_Activity>(&fase_1);
  project.push_activities<Compound_Activity>(&fase_2);
  project.configurate_dates();

  project.to_string();
}