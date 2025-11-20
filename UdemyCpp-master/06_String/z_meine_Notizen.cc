#include<iostream>
#include<string>
#include<cstdint>
#include<fstream>
//#define MODE

struct Player
{
    std::size_t idx;
    double x;
    double y;
};

#ifdef MODE
int main()
{
    std::string str{};
    std::string text{};
    auto search_str = std::string{"zwei"};
    auto to_replace = std::string{"one"};
    auto input_file = std::ifstream{};
    input_file.open("TextInput.txt");
    if( input_file.is_open() )
    {
        while(getline(input_file, str))
        {
            text +=str + " ";
        }
    }
    else
    {
        std::cout<<"File can noct be open!\n";
        return(1);
    }
    input_file.close();
    auto idx = text.find(search_str);
    if(idx != std::string::npos)
    {
        text.replace(idx, search_str.length(), to_replace);
    }
    else
    {
        std::cout<<"Not found!\n";
    }

    auto output_file = std::ofstream{};
    output_file.open("TextOutput.txt");
    if(output_file.is_open())
    {
       output_file<<text;
    }
    output_file.close();


}
//#else
void add_in_datei(const std::string &datei_name, int n)
{
    std::string add{};
  auto output = std::ofstream{};
  output.open(datei_name, std::ios::out | std::ios::app);
  if( !output.is_open() || output.fail())
  {
    std::cout<<" Faul Datei!\n";
  }
  else
  {
    do{
        std::getline(std::cin, add);
        output<<add<<" \n";
        n--;
    }while(n!=0);
  }

}

void zustand_player(const std::string &datei_name, const Player &player)
{
    std::string add{};
    auto o_player_datei = std::ofstream{};
    o_player_datei.open(datei_name, std::ios::out | std::ios::app);
    if(!o_player_datei.is_open() || o_player_datei.fail())
    {
        std::cout<<"Fail!\n";
    }
    else
    {
        o_player_datei<<"Player = "<<std::to_string(player.idx)<<" ,"<<std::to_string(player.x)<<" "<<std::to_string(player.y)<<"\n";
    }
}

int main()
{
    const auto datei_name = std::string{"text.txt"};
    Player p{.idx = 1, .x = 2.3, .y= 8.9};
    zustand_player(datei_name, p);
 //add_in_datei(datei_name, 3);
}


#include<iostream>
#include<filesystem>
#include<string>
#include<array>
#include<vector>

int main()
{
    std::size_t i =0;
    auto file_sammler = std::vector<std::filesystem::path>(30, std::filesystem::path{});
   auto current_pfad = std::filesystem::current_path();
   for(auto it = std::filesystem::directory_iterator(current_pfad); it!=std::filesystem::directory_iterator{}; it++)
   {
      if(std::filesystem::is_regular_file(*it) && (static_cast<std::filesystem::path>(*it).extension() == ".cc"))
     {
       file_sammler[i++] = *it;
     }
   }
for(auto at : file_sammler)
{
    if(at != "")
    {
      std::cout<<at<<"\n";
    }
}

}
#else
#include<iostream>
#include<filesystem>
#include<string>
#include<array>
#include<vector>
int main()
{
  auto new_directory_path = std::filesystem::current_path();
  new_directory_path /= "test";
  if(!std::filesystem::exists(new_directory_path))
  {
    std::filesystem::create_directories(new_directory_path);
  }
  auto file_to_copy = std::filesystem::current_path();
  file_to_copy /= "FileSystem2.cc";
  new_directory_path /= "FileSystem2.cc";
 if(!std::filesystem::exists(new_directory_path))
 {
    std::filesystem::copy_file(file_to_copy, new_directory_path);
 }

}



#endif
