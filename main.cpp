#include <iostream>
#include<fstream>
using namespace std;
#include<vector>
int main()
{

    std::string  filename;
    std::vector<int> ar;
    std::ifstream ifile("F:\\code\\thought_work\\config.ini");
    std::string  line;
    std::string tmp;
    int tmp0;
    while(std::getline(ifile,line))
    {
       if(line== "[uav_fie_path]")
        {
            std::getline(ifile,line);
            int div_pose = line.find("=");
            filename =line.substr(div_pose+1,line.size()-1);
        }
       if(line =="[uav_signal]")
       {
           while(std::getline(ifile,line))
           {
               int div_pose = line.find("=");
              tmp =line.substr(div_pose+1,line.size()-1) ;
              tmp0 =atoi(tmp.c_str());
              ar.push_back(tmp0);
           }
           continue;
       }
    }



  return 0;
}

