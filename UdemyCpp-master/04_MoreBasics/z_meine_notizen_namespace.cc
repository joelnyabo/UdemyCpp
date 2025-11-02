#include<iostream>
#include<string>

namespace AD
{
    enum class Permissionlevel //aber mit enum class nicht, STUDENT und PROF werden nur für jede enum Class deklariert
    {
       STUDENT,
       PROF,
    };

    enum class Server //deswegen wird es hier STUDENT und PROF als Compilerfehler erkannt.Immer enum class verwenden
    {
        STUDENT,
        PROF,
    };

    struct Userdata
    {
       std::string name;
       std::uint32_t id;
       Permissionlevel permission;
    };
}


int main()
{
    auto permission_dan = AD::Permissionlevel::STUDENT;
    auto Permission_Jöel = AD::Permissionlevel::PROF;
    AD::Userdata dan = {.name ="Dannick", .id=14, .permission = AD::Permissionlevel::STUDENT};//Designated Struct Initializer
    auto joel =  AD::Userdata{.name = "joel", .id = 07, .permission = Permission_Jöel };

    switch ( permission_dan )
    {
        case( AD::Permissionlevel::STUDENT ):
        {
            std::cout<<"Student\n";
            break;
        }
        case( AD:: Permissionlevel::PROF ):
        {
            std::cout<<"Student\n";
            break;
        }
        default:
        {
            std::cout<<"None of both\n";
            break;
        }

    }
}

