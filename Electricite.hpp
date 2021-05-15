#ifndef __ELECTRICITE_HPP__
#define __ELECTRICITE_HPP__

#include <iostream>
#include <string>

#include "Couts.hpp"


class Electricite: public Couts {  
 public:   
    Electricite ( double le_cout, string le_nom): Couts(le_cout,  le_nom) {}

    Electricite() {}
      
    ~Electricite() {}
   
};

#endif