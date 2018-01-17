#include "uav.h"
#include<fstream>
#include<istream>

UAV::UAV()
{

}

void UAV::redconfig()
{
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
              signal.push_back(tmp0);
           }
           continue;
       }
    }

}

void UAV::readuavfile()
{
    std::vector<int> tmp;
    std::string uavname;
    std::string filename("F:\\code\\thought_work\\uav.txt");
    std::ifstream ifile(filename);
    std::string  line;
    std::string upath;
    while(std::getline(ifile,line))
    {
            int div_pose = line.find(" ");
            uavname =line.substr(0,div_pose); //  uavname  的判断
            upath = line.substr(div_pose+1,line.size());
            tmp.clear();
            tmp.push_back(10); // 判断此项是否为故障 10 真  非 10 故障
            for(int i= 0;i<upath.size();i++)
            {
                if(upath[i] == ' ')
                {
                    continue;
                }
                if(upath[i] == '-')
                {
                   int a= upath[++i]-'0';
                   tmp.push_back(0-a);
                   continue;
                }
                tmp.push_back(upath[i]-'0');
            }
            uavpath.push_back(tmp);
    }

}

