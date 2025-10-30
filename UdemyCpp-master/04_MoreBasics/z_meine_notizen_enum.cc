//enum : enumeration auf deutsch aufzählen
//video 112

#include<iostream>
#include<string>
//#define MODE

#ifdef MODE
enum Permissionlevel //mit enum wenn man STUDENT und PROF deklariert, wird es als Global Variable für das ganze Programm.
{
    STUDENT,
    PROF,
};

enum Server //deswegen wird es hier STUDENT und PROF als Compilerfehler erkannt.
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


int main()
{
    auto permission_dan = Permissionlevel::STUDENT;
    auto Permission_Jöel = Permissionlevel::PROF;
    Userdata dan = {"Dannick", 14, Permissionlevel::STUDENT};
    Userdata joel = {"joel", 07, Permission_Jöel };

    switch ( permission_dan)
    {
        case( Permissionlevel::STUDENT ):
        {
            std::cout<<"Student\n";
            break;
        }
        case( Permissionlevel::PROF ):
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
#else
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


int main()
{
    auto permission_dan = Permissionlevel::STUDENT;
    auto Permission_Jöel = Permissionlevel::PROF;
    Userdata dan = {"Dannick", 14, Permissionlevel::STUDENT};
    Userdata joel = {"joel", 07, Permission_Jöel };

    switch ( permission_dan)
    {
        case( Permissionlevel::STUDENT ):
        {
            std::cout<<"Student\n";
            break;
        }
        case( Permissionlevel::PROF ):
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
#endif
