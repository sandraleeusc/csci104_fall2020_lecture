#include <iostream>
#include <cstring>
#include <stdexcept>
#include <memory>
#include "str.h"

Str::Str()
{ // This empty constructor should store the empty string

}

Str::Str(const char* s)
{ // This constructor should store the string passed as argument


}

// This is a copy constructor. It is necessary to pass Str objects too and from functions
// We will discuss more next class meeting

Str::Str(const Str& other){
   buffer = std::make_unique<char[]>(other.size()+1);
   len = other.size();
    strcpy(this->buffer.get(), other.buffer.get());

}

Str::~Str()
{

}

size_t Str::size() const
{
  
}


