#include <iostream>
#include <fstream>
#include <iomanip>


double mappa_punto(double x, int a, int b, int c, int d) {
    double y = c + (x-a)*(d-c)/(b-a);
    return y;
}

double calcolo_media(double somma, int i){
    double media = somma/i;
    return media;
}

int main(){

    //inizio definendo gli intervalli di partenza e di arrivo
    int a = 1; int b=5;
    int c = -1; int d=2;

    std::string filenameIN="data.csv";
    std::string filenameOU = "result.csv";
    std::ifstream ifs(filenameIN);
    std::ofstream ofs(filenameOU);
    double somma=0; //mi creo una varibile in cui andrò a salvarmi man mano la somma dei valori che leggo da file
    int cont = 0; //mi creo una variabile che mi indicherà quanti valori ho sommato

    if (ifs.is_open()){
        while (!ifs.eof()){
            //leggo il valore da file
            double val;
            ifs >> val;
            //mappo il valore sul nuovo intervallo
            double val_mappato;
            val_mappato = mappa_punto(val,a,b,c,d);
            //incremento la somma e il contatore
            somma +=val_mappato;
            cont +=1;
            //stampo la media su output
            double media;
            media = calcolo_media(somma, cont);
            ofs << std::setiosflags(std::ios::scientific) << std::setprecision(16) << media << std::endl;
        }

    }

    return 0;
}
