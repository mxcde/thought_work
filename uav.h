#ifndef UAV_H
#define UAV_H
#include<strings.h>
#include<string.h>
#include<iostream>
#include<string>
#include<vector>
///  配置文件  存储文件路径  和  信号配置
/// 读取文本文件  按行读取
///  读取信号


//逻辑部分

// 规则 1
/*
 * 无人机id 判断  字母和数字组成
 * 位置坐标  x y  z为整数  可负
 */

// 规则二：
/*
无人机发送过数据后
无人机ID  x y z[offset x][offset y][offset z]
offset  代表移动量
*/
//规则三:
/*
如果判断无人机 故障
无论接受到什么后继消息
都处于故障状态
*/

class UAV
{
public:
    UAV();



 private:
    void redconfig();
    void readuavfile();

private:
    std::string filename;
    std::string uavname;
   std::vector<std::vector<int>>  uavpath;
   std::vector<int>  signal;
};

#endif // UAV_H
