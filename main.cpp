#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<iomanip>
using namespace std;
const char* str = "中文";
int total = 0;
long long h = 0;
map< long long, string >mp1;//名字
map< long long, string >mp;//学号
map< string, long long >mp2;
map< string, long long >mp3;
struct st
{

    string na;//姓名
    string num;//学号
    long long point[1000];
    float  cl[1000];
    float ma[1000];
    float en[1000];
    float com[1000];
    float av[1000];
}hao;

void list()
{
    cout << "--------- 计科专业学生成绩管理系统 ----------" << endl;
    cout << "请输入代号以进行操作" << endl;
    cout << "1 添加学生的记录" << endl;
    cout << "2 查询学生" << endl;
    cout << "3 对学生数据排序" << endl;
    cout << "4 删除学生的记录" << endl;
    cout << "5 修改学生的记录" << endl;
    cout << "6 班级成绩分析" << endl;
    cout << "7 输出学生信息表" << endl;
    cout << "0 结束操作" << endl;
}
void test1()
{

    int m;
    cout << "请输入要添加的学生数量" << endl;
    cin >> m;
    h = total;
    total = m + total;

    cout << "请输入学生的信息" << endl;

    cout << "学号" << "\t" << "姓名" << "\t" << "班级" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机 " << endl;
    while (m--)
    {
        h++;
        cin >> hao.num >> hao.na >> hao.cl[h] >> hao.ma[h] >> hao.en[h] >> hao.com[h];
        {
            hao.point[h] = h;
            mp[h] = hao.num;
            mp1[h] = hao.na;
            mp2[hao.na] = h;
            mp3[hao.num] = h;
            hao.av[h] = (hao.ma[h] + hao.en[h] + hao.com[h]) / 3;
        }
    }

}

void test2()
{
    string xin;
    string  xuehao;
    int q;
    cout << "如想按名字查询请按 1" << endl;
    cout << "如想按学号查询请按 2" << endl;
    cin >> q;
    cout << "请输入" << endl;
    if (q == 1)
    {
        cin >> xin;
        long long  trans = mp2[xin];

        if (trans == -1)
        {
            cout << "没有该生的信息" << endl;
        }
        else {
            cout << "学号" << "\t" << "姓名" << "\t" << "班级" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机 " << "\t" << "平均成绩" << endl;
            cout << setprecision(2) << mp[trans] << " \t" << mp1[trans] << " \t" << hao.cl[trans] << " \t" << hao.ma[trans] << " \t" << hao.en[trans] << " \t" << hao.com[trans] << " \t" << hao.av[trans] << endl;
        }
    }
    else if (q == 2)
    {
        cin >> xuehao;
        long long xh = mp3[xuehao];
        if (xh == -1)
        {
            cout << "没有该生的信息" << endl;
        }
        else {
            //  cout << "学号 姓名 班级 数学 英语 计算机 平均分" << endl;
            cout << "学号" << "\t" << "姓名" << "\t" << "班级" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机 " << "\t" << "平均成绩" << endl;
            cout << setprecision(2) << mp[xh] << " \t" << mp1[xh] << " \t" << hao.cl[xh] << " \t" << hao.ma[xh] << " \t" << hao.en[xh] << " \t" << hao.com[xh] << " \t" << hao.av[xh] << endl;
        }
    }

}
void test4()
{
    long long t = 0;

    for (long long i = 1; i <= total; i++)
    {
        for (long long j = 1; j <= total - i; j++)
        {
            if (hao.av[hao.point[j]] < hao.av[hao.point[j + 1]])
            {

                t = hao.point[j];
                hao.point[j] = hao.point[j + 1];
                hao.point[j + 1] = t;
            }
        }
    }
}
void test4ex()
{
    long long t = 0;
    for (long long i = 1; i <= total; i++)
    {
        for (long long j = 1; j <= total - i; j++)
        {
            if (hao.com[hao.point[j]] < hao.com[hao.point[j + 1]])
            {
                t = hao.point[j];
                hao.point[j] = hao.point[j + 1];
                hao.point[j + 1] = t;
            }
        }
    }
}
void test5()
{
    cout << "请输入要删除学生的学号" << endl;
    string xuehao;
    cin >> xuehao;
    long long item = 0;
    for (long long i = 1; i <= total; i++)
    {
        if (mp[hao.point[i]] == xuehao)
            item = i;
    }
    mp2[mp1[hao.point[item]]] = -1;
    mp3[xuehao] = -1;
    total = total - 1;
    for (long long i = item; i <= total; i++)
    {
        swap(hao.point[i], hao.point[i + 1]);
    }
}
void test6()
{
    string xuehao;
    string xin;
    cout << "请输入想要修改的学生的学号" << endl;
    cin >> xuehao;
    cout << "请重新输入此学生的信息" << endl;
    // cout << "学号       姓名      班级 数学 英语 计算机" << endl;
    cout << "学号" << "\t" << "姓名" << "\t" << "班级" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机 " << endl;
    long long trans = mp3[xuehao];
    if (trans == 0)
    {
        cout << "对不起，没有该生信息" << endl;
    }
    else {
        cin >> hao.num >> hao.na >> hao.cl[trans] >> hao.ma[trans] >> hao.en[trans] >> hao.com[trans];
        hao.av[trans] = (hao.ma[trans] + hao.en[trans] + hao.com[trans]) / 3;
        xin = mp1[trans];
        mp3[xuehao] = -1;
        mp2[xin] = -1;
        mp[trans] = hao.num;
        mp1[trans] = hao.na;
        mp3[hao.num] = trans;
        mp2[hao.na] = trans;
    }

}
void test7()
{
    float maav = 0, enav = 0, comav = 0, mahigh = -1;
    float malow = 110, enhigh = -1, enlow = 110, comhigh = -1, comlow = 110;
    float maline = 0, enline = 0, comline = 0;
    float macout = 0, encout = 0, comcout = 0;
    for (long long i = 1; i <= total; i++)
    {
        maav = maav + hao.ma[hao.point[i]];
        enav = enav + hao.en[hao.point[i]];
        comav = comav + hao.com[hao.point[i]];
        if (hao.ma[hao.point[i]] > mahigh)
        {
            mahigh = hao.ma[hao.point[i]];
        }
        if (hao.en[hao.point[i]] > enhigh)
        {
            enhigh = hao.en[hao.point[i]];
        }
        if (hao.com[hao.point[i]] > comhigh)
        {
            comhigh = hao.com[hao.point[i]];
        }
        if (hao.ma[hao.point[i]] < malow)
        {
            malow = hao.ma[hao.point[i]];
        }
        if (hao.en[hao.point[i]] < enlow)
        {
            enlow = hao.en[hao.point[i]];
        }
        if (hao.com[hao.point[i]] < comlow)
        {
            comlow = hao.com[hao.point[i]];
        }
        if (hao.ma[hao.point[i]] >= 60)
        {
            macout++;
        }
        if (hao.en[hao.point[i]] >= 60)
        {
            encout++;
        }
        if (hao.com[hao.point[i]] >= 60)
        {
            comcout++;
        }
    }
    maline = macout / total;
    enline = encout / total;
    comline = comcout / total;

    cout << "数学平均成绩：" << maav / total << "   数学最高成绩" << mahigh << "   数学最低成绩" << malow << "    数学及格率" << maline << endl;
    cout << "英语平均成绩：" << enav / total << "   英语最高成绩" << enhigh << "   英语最低成绩" << enlow << "    英语及格率" << enline << endl;
    cout << "计算机平均成绩：" << comav / total << "   计算机最高成绩" << comhigh << "   计算机最低成绩" << comlow << "    计算机及格率" << comline << endl;


}


void test8()
{
    cout << "<<---------学生信息表----------->>" << endl;
    cout << "-------------------------------" << endl;
    cout << "学号" << "\t" << "姓名" << "\t" << "班级" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机 " << "\t" << "平均成绩" << endl;
    for (long long i = 1; i <= total; i++)
    {
        cout <<fixed<< setprecision(2)<<" "<< mp[hao.point[i]] << "\t" << mp1[hao.point[i]] << "\t" << (int)hao.cl[hao.point[i]]<<"\t" <<  hao.ma[hao.point[i]] << "\t" << hao.en[hao.point[i]] << "\t" << hao.com[hao.point[i]] << "\t" << hao.av[hao.point[i]] <<"\t"<< endl;
    }
    cout << "--------------------------------" << endl;

}


int main()
{
    int n;
    list();


    while (cin >> n, n)
    {

        if (n == 1)
        {
            test1();
            list();
        }
        else if (n == 2)
        {
            test2();
            system("pause");
            list();
        }
        else if (n == 3)
        {
            cout << "按平均成绩排序" << endl;
            test4();
            test8();
            cout << "按计算机成绩排序" << endl;
            test4ex();
            test8();


            system("pause");
            list();
        }
        else if (n == 4)
        {
            test5();
            system("pause");
            list();
        }
        else if (n == 5)
        {
            test6();
            system("pause");
            list();
        }
        else if (n == 6)
        {
            test7();
            system("pause");
            list();
        }
        else if (n == 7)
        {
            test8();
            system("pause");
            list();
        }


    }

}

