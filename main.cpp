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
    
    Couts() {
      std::cout <<"Constructeur de Couts "<<std::endl; 
    }
    virtual ~Couts() {
      std::cout <<"Destructeur de Couts "<<std::endl; 
    }

    void afficher() {
      std::cout <<this->nom<<" : "<<this->souscout<<" sous/jour"<<std::endl;
    }
    
    
};

class Location: public Couts {  
 public:
  Location (double le_cout, string le_nom) : Couts(le_cout,  le_nom) {}
   
    Location() {
      std::cout <<"Constructeur de Location "<<std::endl; 
    }
    ~Location() {
      std::cout <<"Destructeur de Location "<<std::endl; 
    } 
};

class Electricite: public Couts {
  
 public:
   
    Electricite ( double le_cout, string le_nom): Couts(le_cout,  le_nom) {}

    Electricite() {
      std::cout <<"Constructeur d'electricite "<<std::endl; 
    }
    ~Electricite() {
      std::cout <<"Destructeur d'electricite "<<std::endl; 
    } 
};

class Eau : public Couts {
  
 public:
   Eau ( double le_cout, string le_nom) : Couts(le_cout,  le_nom) {}
   
      Eau() {
      std::cout <<"Constructeur d'eau "<<std::endl; 
    }
   ~Eau() {
      std::cout <<"Destructeur d'eau"<<std::endl; 
    } 
};

double calculercout (int a, int b);
double calculercout (int a, int b, int c);
double calculercout (double a, double b);

int main() {
  
  Couts* arr[250];
  
  int k=-1;
  int choix;
  bool fin = false;
  
  do {
  
  std::cout << "==========================================" << std::endl;
  std::cout << "1. Ajouter un cout de location" << std::endl;
  std::cout << "2. Ajouter un cout en electricite" << std::endl;
  std::cout << "3. Ajouter un cout pour la consommation d'eau" << std::endl;
  std::cout << "4. Afficher un compte-rendu de la machine pour une periode " << std::endl;  
  std::cout << "5. Quitter le logiciel" << std::endl;

  std::cout << "Votre choix : " ;
  std::cin >> choix;
  
  switch(choix) {
    case 1: { 
    bool fin_case1 = false;
    int repcase1=0;
    int m2=0;
    int prixloc=0; 
    double coutloc = 0;   
    std::string nomloc;
    
    std::string module;
    std::string espace = "Espace";
    do{    
      
      std::cout <<"Entrez un module de la machine pour l'espace : ";
      std::cin >> module;  
      std::cout << "Entrez l'espace de la module en metres-carres : ";
      std::cin >> m2;   
      std::cout << "Entrez le cout en sous pour la location en metres-carres/jour : ";
      std::cin >> prixloc;      
      nomloc = espace+module;
      coutloc = calculercout(m2, prixloc); 
      
      Location* loc = new Location();  
      k++;  
      arr[k] = new Location(coutloc, nomloc);    
       delete loc;    
      arr[k]->afficher();
     
         
      std::cout << "Voulez-vous ajouter un autre module pour l'espace (1=oui, 2=non) : ";
      std::cin >> repcase1;
      if (repcase1  == 2)
         fin_case1 = true;
    }while (fin_case1 == false);
    
    break;
    }
    case 2: {
      bool fin_case2 = false;
      int repcase2=0;
      double coutelec = 0;
      std::string nomelec;
      std::string module2;
      Electricite elec(coutelec, nomelec); 
      std::string electricite = "Electricite";
      int volts;
      int amperes;
      int prixelec; 
    do{    
      std::cout <<"Entrez un module de la machine pour l'electricite : ";
      std::cin >> module2;        
      std::cout << "Entrez le voltage de la machine : ";
      std::cin >> volts;  
      std::cout << "Entrez l'amperage de la machine : ";
      std::cin >> amperes;  
      std::cout << "Entrez le cout en sous pour l'electricite par KWH/jour : ";
      std::cin >> prixelec; 
      nomelec = electricite+module2;
      coutelec = calculercout(volts, amperes, prixelec); 

      Electricite* elec = new Electricite();
      k++;  
      arr[k] = new Electricite(coutelec, nomelec);  
      delete elec;    
      arr[k]->afficher();
      
      

      std::cout << "Voulez-vous ajouter un autre module pour l'electricite (1=oui, 2=non) : ";
      std::cin >> repcase2;
      if (repcase2  == 2)
         fin_case2 = true;
    }while (fin_case2 == false); 
      break;
    }
    case 3: {
    bool fin_case3 = false;
    int repcase3=0;
    double couteau = 0;
    std::string nomeau;
    std::string module3;
    Eau ea(couteau, nomeau); 
    std::string eau = "Eau";
    double debit;
    double prixeau;
    do{    
      
      std::cout <<"Entrez un module de la machine pour l'eau: ";
      std::cin >> module3;         
      std::cout << "Entrez le debit en L/s : ";
      std::cin >> debit;  
      std::cout << "Entrez le cout en sous de l'eau par litre/jpur : ";
      std::cin >> prixeau;  
      nomeau = eau+module3;
      couteau = calculercout(debit,prixeau);

      Eau* eau = new Eau();
      k++;  
      arr[k] = new Eau(couteau, nomeau);    
      delete eau;  
      arr[k]->afficher();
      

      std::cout << "Voulez-vous ajouter un autre module pour l'eau (1=oui, 2=non) : ";
      std::cin >> repcase3;
      if (repcase3  == 2)
         fin_case3 = true;
    }while (fin_case3 == false); 
      break;  
    }
    case 4: {
    bool fin_case4 = false;
    int nbjrs=0;
    double coutitem=0.0;
    double couttotal = 0.0;
    double coutmod =0.0;
    string nommod;
    
    std::cout <<"Entrez le nombre de jours a utiliser : ";
    std::cin >> nbjrs;   
  
        std::cout << "================================" << std::endl;
    
      for (int i=0; i<k+1 ; i++) {
    
        coutmod = arr[i]->souscout;
        nommod = arr[i]->nom;
        coutitem = (coutmod * nbjrs) / 100.0;      
        couttotal = couttotal + coutitem; 
        std::cout<<nommod<<" : "<<coutitem<<"$ "<<std::endl;
        
      }
      std::cout<<"------------------"<<std::endl;
      std::cout<<"cout total = "<<couttotal<<" $ pour "<<nbjrs<< "  jours "<<std::endl;    

       for (int i=0; i<k+1 ; i++) {        
           delete arr[i];
       }    
      break;  
    }
    case 5: { return(0); }
  }; 

} while (fin == false);
return 0;
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