#ifndef __EAU_HPP__
#define __EAU_HPP__

#include <iostream>
#include <string>

#include "Couts.hpp"

class Eau : public Couts {  
 public:
   Eau ( double le_cout, string le_nom) : Couts(le_cout,  le_nom) {}
   
   Eau() {}
      
   ~Eau() {}

};

#endif