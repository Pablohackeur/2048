using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

const int GAUCHE = 4, DROITE = 6, HAUT = 8, BAS = 2;
typedef vector<vector<int> > Plateau;



/** choisi un nombre aléatoire compris entre 0 et a
 * @param un entier a
 * @return un entier compris entre 0 et a
**/
int alea(int a){
    srand(time(NULL));
    return rand()%a;
}




/** Initialise le tableau d'entiers du jeu à zéro
 * @return le tableau d'entiers g rempli de valeurs nulles
**/
Plateau plateauVide (){
    Plateau g;
    g = vector<vector<int> > (4);
    g[0] = vector<int> (4);
    g[1] = vector<int> (4);
    g[2] = vector<int> (4);
    g[3] = vector<int> (4);
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            g[i][j]=0;
            }
    }
    return g;
}




/** Initialise le tableau d'entiers g en donnant à deux cases aléatoires la valeur 2, les autres restant nulles
 * @return le tableau d'entiers g avec ses nouvelles valeurs
**/
Plateau plateauInitial(){
    Plateau g = plateauVide();
    int i = alea(4);
    int j = alea(4);
    g[i][j]=2;
    int o = alea (4);
    int p = alea (4);
    while (i==o and j==p){
        int o = alea (4);
        int p = alea (4);
    }
    g[o][p]=2;
    return g;
}


/** Affiche le plateau de jeu
 * @param le tableau d'entiers à deux dimensions g
 * @return un affichage avec les valeurs du tableau présentées dans les cases du plateau de jeu
**/
string dessine(Plateau g){
    for (int k=0; k<25; k++){
        cout << "*";
    }
    cout << endl;
    for (int i=0; i<4; i++){
        cout << "*";
        for (int j=0; j<4; j++){
             if (g[i][j]==0){
                cout << "     *";
            }
            else if (g[i][j]<10 and g[i][j]!=0){
                cout << "  " << g[i][j] << "  *";
            }
            else if (g[i][j]>=10 and g[i][j]<100){
                cout << " " << g[i][j] << "  *";
            }
            else if (g[i][j]>=100 and g[i][j]<1000){
                cout << " " << g[i][j] << " *";
            }
            else if (g[i][j]>=1000){
                cout << " " << g[i][j] << "*";
            }

        }
        cout << endl;
        for (int a=0; a<25; a++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

int main (){
    Plateau g;
    plateauVide();
    dessine(g);
    return 0;
}
