//Khang Nguyen 300007277

#include <iostream>

using namespace std;

struct Stat
{
    float min;
    float moy;
    float max;
};

Stat statMonth(Stat** tableTemp, int mois, int years){
    Stat* ptr_stat = new Stat[12];  
    for(int i = 0; i < 12; i++){
        float tmpMin = tableTemp[0][i].min;
        float tmpMax = tableTemp[0][i].max;
        float tmpMoy = tableTemp[0][i].moy;
        for(int j = 1; j < years; j++){
            if (tableTemp[j][i].min < tmpMin){
                tmpMin = tableTemp[j][i].min;
            }
            tmpMoy += tableTemp[j][i].moy;
            if (tableTemp[j][i].max > tmpMax){
                tmpMax = tableTemp[j][i].max;
            }
        }
        ptr_stat[i].min = tmpMin;
        ptr_stat[i].max = tmpMax;
        ptr_stat[i].moy = tmpMoy/years;
    }
    return ptr_stat[mois];
}


void printMonth(Stat &stat, int mois){
    const char *months[12] = { "Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre" }; 
    std::cout << "Pour le mois de " << months[mois] << "\n";
    std::cout << "LaTempérature minimum a été de = " << stat.min << "\n";
    std::cout << "LaTempérature moyenne a été de = " << stat.moy << "\n";
    std::cout << "LaTempérature max a été de = " << stat.max << "\n";
    
}

int main()
{    
    float an19[12][3] = { {-15,-12,-9},{-12,-9,-6},{-8,-4,-1},{1,5,9},{7,11,15},{12,17,22},{17,22,27},{14,19,24},{10,15,20},{5,9,13},{-5,-2,2},{-7,-4,-1} };
    float an18[12][3] = { {-13,-9,-5},{-9,-5,0},{-4,-1,2},{-1,3,7},{8,15,21},{12,17,23},{17,22,28},{17,21,26},{12,17,21},{3,7,11},{-4,-1,2},{-8,-5,-2} };
    float an17[12][3] = { {-11,-7,-3},{-11,-6,-2},{-9,-6,-2},{3,7,11},{7,11,16},{12,17,22},{15,20,25},{13,19,24},{13,18,23},{9,13,17},{-3,1,5},{-11,-9,-6} };
    float an16[12][3] = { {-11,-7,-4},{-13,-9,-4},{-6,-2,1},{-1,3,8},{8,13,18},{12,17,22},{15,20,25},{16,21,26},{11,17,22},{6,9,13},{0,4,7},{-9,-6,-2} };
    float an15[12][3] = { {-18,-13,-8},{-22,-17,-12},{-10,-6,-2},{1,5,10},{9,15,22},{11,17,22},{14,20,26},{15,20,25},{12,17,22},{4,8,12},{2,5,8},{-1,1,4} };
    float an14[12][3] = { {-17,-12,-8},{-16,-11,-7},{-12,-8,-3},{0,4,8},{7,13,18},{12,17,23},{13,18,24},{13,18,24},{10,15,20},{6,10,14},{-2,1,4},{-6,-4,-1} };
    float an13[12][3] = { {-15,-10,-5},{-14,-10,-5},{-6,-3,0},{0,4,9},{8,13,19},{11,16,21},{15,20,26},{13,19,25},{8,14,19},{6,9,13},{-5,-1,3},{-13,-9,-6} };
    float an12[12][3] = { {-14,-9,-5},{-12,-7,-2},{-1,3,7},{1,6,10},{9,14,20},{12,18,23},{14,20,25},{15,19,24},{9,14,19},{6,10,14},{-2,1,4},{-8,-5,-1} };
    float an11[12][3] = { {-14,-11,-7},{-13,-9,-4},{-7,-4,0},{1,5,10},{7,12,17},{12,17,22},{15,21,26},{14,19,23},{11,16,20},{6,10,13},{1,5,9},{-6,-3,0} };
    float an10[12][3] = { {-10,-7,-4},{-7,-5,-3},{-1,3,6},{4,9,14},{8,14,20},{12,17,22},{16,21,26},{14,19,24},{10,15,19},{4,8,11},{-2,2,5},{-8,-6,-3} };
    
    int mois;
    //Créer tableau dynamique 10x12 avec struct stat
    Stat **tableTemp = new Stat*[10];
    float (*cur) = &an19[0][0];
    for(int i = 0; i < 10; i++){
        tableTemp[i] = new Stat[12];
        for(int j = 0; j < 12; j++){
            tableTemp[i][j].min = *cur;
            cur++;
            tableTemp[i][j].moy = *cur;
            cur++;
            tableTemp[i][j].max = *cur;
            cur++;
        }
    }
    
    std::cout << "Entrer le nombre du mois (entre 1 et 12): ";
    std::cin >> mois;
    mois--;
    
    Stat stat = statMonth(tableTemp, mois, 10);
    printMonth(stat, mois);
    
    delete tableTemp;
    tableTemp = nullptr;
    return 0; 
}




