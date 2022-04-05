#pragma once

#include <string>
#include <utility>
using namespace std;

#include "Type.hpp"

class Abstract_Serialization_Constructor{
public:
	Abstract_Serialization_Constructor() {};
	~Abstract_Serialization_Constructor() {};

	/* SERIALIZADORES */
	virtual void initialize_object(string nombreObjeto) = 0;
	virtual void end_object() = 0;
	virtual void serialize_activity(std::vector<std::string> * vec_to_serializate) = 0;
	virtual string get_serialization() = 0;
};
