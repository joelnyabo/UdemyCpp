//Video 62 (Preprocessor Defines)
#include<iostream>// ist einfach eine Kopie Paste der Bibliothek.
#define GUESS 7// muss immer großgeschrieben werden, damit man weiß dass es ein konstanter fix Wert der nicht verändert wwerden kann.
//so eine define wird in moderne C++ nicht mehr so genutzt sondern um bestimmte Teile des Code zu aktivieren wie unten .

#define MODE_1//zb: MODE 1 wäre eine mode in einem Spiel wo der Spieler eine Zahl raten soll.


int main()
{
    int chance = 3;
    int guess = 0;
    #ifdef MODE_1

        std::cout<<"Please guess a number you have anly one chance: "<<std::endl;
        std::cin>>guess;
        if( guess == GUESS )
           std::cout<<"you win"<<std::endl;
        else
           std::cout<<"you lost"<<std::endl;

    #else
        do{
            std::cout<<"Please guess a number you have"<< chance<<"chances"<<std::endl;
            std::cin>>guess;
            if( guess == GUESS )
            {
                std::cout<<"you win"<<std::endl;
                break;
            }
           else
           {
                std::cout<<"you lost"<<std::endl;
                --chance;
           }
         }while( chance > 0);
    #endif
}
