#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include <graphics.h>
#include <conio.h>

void main()
{
    //闲着没事熟悉一下许久不用的cpp的独特的输入输出语句
    cout << "    --------------------------------------------------" << endl;
    cout << "    |                                                |" << endl;
    cout << "    |                                                |" << endl;
    cout << "    |                                                |" << endl;
    cout << "    --------------------------------------------------" << endl;

    cout << "这个小程序就是为了让已经长期不写cpp程序的我重新熟悉一下 \n";

    //获取文件地址
    string path;
    char xy_line_data[40];//假设是16位精度，载加上几位整数位，估计40位是没问题了
    int xy_size = 0;
    int x_location[100]{};
    int y_location[100]{};
    for (int j = 0; j < 100; j++)
    {
        x_location[j] = 0;
        y_location[j] = 0;
    }

    cout << "请输入坐标文件（.xy）的路径，理论上支持绝对路径和相对路径：";
    cin >> path;// c:/users/hx893/desktop/xy.xy

    //读取文件信息，并存储入数组中，顺便在控制台中展示
    ifstream xy_file(path, ios::in);
    int x, y;

    while (xy_file.getline(xy_line_data, sizeof(xy_line_data)))
    {
        stringstream xy_word(xy_line_data);
        xy_word >> x;
        xy_word >> y;
        cout << x << " " << y << endl;
        x_location[xy_size] = x;
        y_location[xy_size] = y;
        xy_size += 1;
    }
    cout << "    ----------------------------------------------------------------------------------------------------" << endl;

    cout << "坐标数量为：" << xy_size << endl;
    if (xy_size > 100)
    {
        cout << "读取信息数超出缓存空间数，请适当修改源码" << endl;
    }
    else
    {
        cout << "读取信息数未超出缓存空间数，无需修改源码" << endl;
    }

    cout << "输出以下信息用以确认坐标数据导入成功" << endl;
    for (int j = 0; j < xy_size; j++)
    {
        cout << x_location[j] << " " << y_location[j]<< endl;
    }
    cout << "数据导入成功" << endl;
    cout << "    ----------------------------------------------------------------------------------------------------" << endl;

    //引入EasyX第三方库进行图像绘制
    x_location[xy_size] = x_location[0];
    y_location[xy_size] = y_location[0];
    initgraph(30, 20);
    for (int j = 0; j < xy_size; j++)
    {
        line(x_location[j], y_location[j], x_location[j + 1], y_location[j + 1]);
    }
    _getch();
    closegraph();
    cout << "绘图完毕" << endl;
    cout << "    ----------------------------------------------------------------------------------------------------" << endl;

    system("pause");

}