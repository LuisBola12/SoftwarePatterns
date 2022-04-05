#pragma once
#include "Abstract_Serialization_Constructor.hpp"

class XML_Serialization_Constructor : public Abstract_Serialization_Constructor
{
public:
	XML_Serialization_Constructor();
	~XML_Serialization_Constructor();

	/* SERIALIZADORES */
	virtual void initialize_object(std::string nombreObjeto) override;
	virtual void end_object() override;
	virtual void serialize_activity(std::vector<std::string> * vec_to_serializate) override;
	virtual std::string get_serialization() override;
	

private:
	std::string serialization; // el producto del Constructor
};

XML_Serialization_Constructor::XML_Serialization_Constructor() : serialization("")
{
}

XML_Serialization_Constructor::~XML_Serialization_Constructor()
{
}

void XML_Serialization_Constructor::initialize_object(std::string nombreObjeto)
{
	serialization = serialization + "< " + nombreObjeto + ' ';
}

void XML_Serialization_Constructor::end_object()
{
	serialization = serialization + ">\n";
}

void XML_Serialization_Constructor::serialize_activity(std::vector<std::string> * vec_to_serializate)
{
	serialization = serialization + "Manager" + '=' + '"' + vec_to_serializate->front() + '"' + " ";
	vec_to_serializate->erase(vec_to_serializate->begin());
    serialization = serialization + "Description"+ '=' + '"' + vec_to_serializate->front()+ '"' + " ";
	vec_to_serializate->erase(vec_to_serializate->begin());
    serialization = serialization + "Init Date"+ '=' + '"' + vec_to_serializate->front()+ '"' + " ";
	vec_to_serializate->erase(vec_to_serializate->begin());
    serialization = serialization + "End Date"+ '=' + '"' + vec_to_serializate->front() + '"' + " ";
	vec_to_serializate->erase(vec_to_serializate->begin());
}

std::string XML_Serialization_Constructor::get_serialization()
{
	return serialization;
}