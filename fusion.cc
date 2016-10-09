#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void remplir (int tab[], int taille) {

  int var;
  cin >> var;
  tab[0]=var;

  for (int n=1; n<taille; n++) {
    
    do{
      
      cin >> var; 
    if (tab[n-1]<var)
      tab[n]=var;
    else
      cout << "Veuillez rentrez une valeur plus grande" << endl;
   
    }while(tab[n-1]>var);
     
      }
}

void showArray(int tab[], int taille ){
  
  for (int n=0; n<taille; n++) 
    cout << tab[n] << " ";
 
  cout << endl;
  } 

int main () {
  const  int taille=5;
  int tab1[taille];
  int tab2[taille];
  int tab12[taille*2];

  cout << "Remplir tableau 1" << endl;
  remplir ( tab1, taille);
  cout << "Remplir tableau 2" << endl;
  remplir ( tab2, taille);
  showArray( tab1, taille);
  showArray( tab2, taille);
  cout << endl;

  int n=0;
  int m=0; 
  int p=0;

  for(int n=0; n<taille*2; n++){
    tab12[n]=0;
  }


  do{
  if (tab1[n]<tab2[m]) {
    tab12[p]=tab1[n];
    n++;
    p++;
      }else{
    tab12[p]=tab2[m]; 
    m++;
    p++;
  }
  
  if(n>=taille) {
    tab12[p]=tab2[m];
    m++;
    p++;
  }
  
  if(m>=taille ){
    tab1[p]=tab1[n];
    n++;
    p++;
  }
  
  /*
  cout << "Pour la valeur n: " << n << endl;
  showArray( tab1, taille);
  cout << "Pour la valeur m: " << m << endl;
  showArray( tab2, taille);
  cout << "Pour la valeur p: " << p << endl;
  showArray(tab12, taille*2-1);
  cout << endl;
  */

  }while(p<taille*2);
  
  showArray(tab12, taille*2);
}
