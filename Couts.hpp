#ifndef __COUTS_HPP__
#define __COUTS_HPP__

#include <iostream>
#include <string>
using namespace std;

class Couts {
 public:
    double souscout;
    string nom;    
    
    Couts(double le_cout, string le_nom) {
      this->souscout = le_cout;
      this->nom = le_nom;      
    }
    
    Couts() {}
      
    virtual ~Couts() {}
      

    void afficher() {
      std::cout <<this->nom<<" : "<<this->souscout<<" sous/jour"<<std::endl;
    }
    double calculercout (int a, int b) {
      double coutloc1 = (double) a * (b / 30.0); 
      return coutloc1;
    }

    double calculercout (int a, int b, int c) {
      double coutelec1 = (double) (a * b * 24.0 * c) /1000.0;   
      return coutelec1;
    }
    double calculercout (double a, double b) {
      double couteau1 = (double) (a*b*24*60*60.0);
      return couteau1;
    }
    
};

#endif