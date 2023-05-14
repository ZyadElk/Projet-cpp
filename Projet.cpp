#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Depense 
{
public:
        int mois ;
        double prix;
        int nbr_fois;
        string categorie;
        Depense(int mois ,double prix,int nbr_fois,string categorie) 
        {
                    this->mois = mois;
                    this->prix = prix;
                    this->nbr_fois = nbr_fois;
                    this->categorie = categorie;
                  
        }
}; 

// Boucle pour stocker les prix , nombre de fois et les categories pour chaque mois
int main()
{
    vector<Depense> depenses ;
    int mois ;
    double prix;
    int nbr_fois;
    string categorie;
    cout<<"saisir 0 si vous avez termine "<< endl ;
     while (true) {        
          cout<< "saisir : " <<endl ;
          cout<< "le mois (ou 0 pour terminer): " ;
          cin >> mois ;
          while(mois<0 || mois>12){
                cout<<"saisir un nombre entre 1 et 12 ou 0 pour terminer ";
                cin >> mois; }
        if (mois == 0) break;
          cout << "prix : ";
          cin >> prix ;
          while(prix < 0){
                cout<<"saisir un nombre positif ";
                cin >> prix ; }
          do {      
          cout<<"nbr_fois : " ;
          cin>> nbr_fois ;
          } while(nbr_fois <= 0);
          cout<<"categorie : " ;
          cin>> categorie ;

        depenses.push_back(Depense(mois,prix,nbr_fois,categorie)); }
        
    // Calcul de dépenses total pour chaque mois
    
    vector<double> depense_Mois(12, 0);
    for (int i = 0; i < depenses.size(); i++) {
    const Depense& s = depenses[i];
    depense_Mois[s.mois - 1] += s.prix * s.nbr_fois ;
    }

    
    // Affichage de dépenses totales pour chaque mois
    
    for (int i = 0; i < 12; i++) {
        if (depense_Mois[i]!=0)
        cout << "depenses totales pour le mois " << i+1 << " : " << depense_Mois[i] << endl;
    }   
    
    // Calcul du minimum et maximum de dépenses totales pour chaque mois
    double max(depense_Mois[0]) , min(depense_Mois[0]) ;
     for(int i = 1 ; i < 12 ; i++)
     { if (depense_Mois[i]!=0)
          { if (max < depense_Mois[i])
               max =  depense_Mois[i] ; 
            else if (min > depense_Mois[i])
               min = depense_Mois[i] ; }
               }
    // Affichage du minimum et maximum de dépenses
    cout<<"le maximum de depenses : " << max <<endl ;
    cout<<"le minimum de depenses : " << min <<endl ;
    
    // Calcul de dépenses totales et dépenses moyenne pour tous les mois
    double depenseTotale = 0 , depenseMoyenne ;
    int count = 0 ;
    for (int i = 0 ;i < 12 ; i++) {
       if (depense_Mois[i]!=0)    
          { depenseTotale += depense_Mois[i] ;
            count++ ; }
    }
    depenseMoyenne = depenseTotale / count ;

    // Affichage de dépenses totales pour tous les mois
    cout<< "depenses totales pour tous les mois : " << depenseTotale << endl;
    cout<< "depenses moyennes pour tous les mois : " << depenseMoyenne << endl ;
                                                                        
    return 0;
}
