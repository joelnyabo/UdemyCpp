#include<iostream>
#include<cstdint>
#include<fstream>
#include<filesystem>
#include<vector>
#include<string>
#include<algorithm>


struct User {
    std::string name;
    int age;
};


void ausgabe_tab(const std::vector<User> &user)
{
    for(auto &it : user)
    {
      std::cout<<it.name<<"   "<<it.age<<"\n";
    }

}

bool max(int a, int b)
{
    return a<b ? true:false;
}

int main()
{
    auto user_tab = std::vector<User>(4, User{});
    auto my_pfad = std::filesystem::current_path();
    for(auto it = std::filesystem::directory_iterator(my_pfad); it!=std::filesystem::directory_iterator{}; ++it)
    {
      if(std::filesystem::is_regular_file(*it))
      {
        std::cout<<std::filesystem::absolute(*it)<<"  \n->Die Größe = "<<std::filesystem::file_size(*it)<<"\n"<<"Extension = "<<static_cast<std::filesystem::path>(*it).extension()<<"\n";

      }
    }

    std::size_t i = 0;
    auto str = std::string{};
    auto user = std::string{"users.txt"};
    auto output_user = std::ifstream{};
    output_user.open(user, std::ios::in);
    if(output_user.is_open())
    {
        while(getline(output_user, str))
        {
            auto idx = str.find(";");
           user_tab[i].name = str.substr(0, idx);
           user_tab[i].age = std::stoi(str.substr(idx+1, str.size()));
           i++;
        }
    }
    output_user.close();
    ausgabe_tab(user_tab);
     str = "";
    //Übung 3.

    auto error = std::string{"error.txt"};
    auto error_datei = std::ofstream(error);

    auto log = std::string{"log.txt"};
    auto log_datei = std::ifstream{};
    log_datei.open(log, std::ios::in);
    if(log_datei.is_open())
    {
        while(getline(log_datei, str))
        {
            if(str.find("ERROR") != std::string::npos)
            {
                error_datei<<str;
                std::cout<<str;
            }
        }
    }
    else
    {
        std::cout<<"logdatei kann nicht geöffnet werden!\n";
    }
    error_datei.close();
    log_datei.close();

    //aufgabe 4
    auto number_vector = std::vector<int>{};
    double summe = 0;

    int at = 0;
    str = "";
    auto number = std::string{"numbers.txt"};
    auto number_datei = std::ifstream{};
    number_datei.open(number, std::ios::in);
    if(number_datei.is_open())
    {
        while(getline(number_datei, str))
        {
          summe += std::stoi(str);
          std::cout<<str;
          number_vector.push_back(std::stoi(str));
          at++;
        }
    }
    else
    {
       std::cout<<"\n numbers.txt konnte nicht geöffnet werden \n";
    }
    number_datei.close();
    auto durch = (summe/(static_cast<double>(at)+1));
   number_datei.close();
    std::sort(number_vector.begin(), number_vector.end(), max);
    std::cout<<"\nSumme = "<<summe<<" ,durchschnitt = "<<durch<<" ,Min = "<<number_vector[0]<<" ,Max = "<<number_vector[number_vector.size()-1];

    //Aufgabe 5

    auto backup_path = std::filesystem::current_path();
    backup_path  /= "backup";
    if(!std::filesystem::exists(backup_path))
    {
        std::filesystem::create_directories(backup_path);
    }
    for(auto it = std::filesystem::directory_iterator(std::filesystem::current_path());it!= std::filesystem::directory_iterator{}; ++it)
    {
        if(std::filesystem::is_regular_file(*it) && it->path().extension() == ".txt")
        {
           backup_path /= static_cast<std::filesystem::path>(*it).filename();
          std::filesystem::copy_file(static_cast<std::filesystem::path>(*it), backup_path);
          backup_path= backup_path.parent_path();
        }
    }

}
