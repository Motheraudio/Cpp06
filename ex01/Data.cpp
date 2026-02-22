#include "Data.hpp"

Data::Data(){
	this->x = 67;
	this->j = 'a';
}

Data::Data(const Data& other){
	*this = other;
}

Data::~Data(){

}

Data& Data::operator=(const Data& obj){
	this->j = obj.j;
	this->x = obj.x;
	return (*this);
}

