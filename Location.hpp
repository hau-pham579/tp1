#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__

#include <iostream>
#include <string>

#include "Couts.hpp"


class Location: public Couts {  
 public:
  Location (double le_cout, string le_nom) : Couts(le_cout,  le_nom) {}
   
    Location() {}
      
    ~Location() {}
   
};
#endif