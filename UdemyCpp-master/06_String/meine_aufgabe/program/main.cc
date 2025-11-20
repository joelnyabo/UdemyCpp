#include<iostream>
#include<cstdint>
#include<fstream>
#include<filesystem>
#include<vector>


struct User {
    std::string name;
    int age;
};


int main()
{
    std::vector<User> users(4, User{});
    std::size_t i = 0;
   const auto path = std::filesystem::current_path().parent_path() /"data";
    for(auto it = std::filesystem::directory_iterator(path); it!=std::filesystem::directory_iterator{}; ++it)
    {
        std::cout<<*it<<"\n";
    }
    auto filename = "user.txt";

 if(std::filesystem::exists(filename))
 {
    auto str = std::string{};
    auto input_file = std::ifstream{};
    input_file.open(filename, std::ios::in);
    if(input_file.is_open())
    {
        while(getline(std::cin, str))
        {
           auto idx = str.find(";");
           users[i++].name = str.substr(0, idx);
           users[i++].age =std::stoi(str.substr(idx, str.length()));
        }
        std::cout<<users[0].name<<" "<<users[0].age;
    }
}
    else
    {
        std::cout<<"Datei konnte icht geöffnet werden!\n";
    }



}
