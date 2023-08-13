#pragma once
#include <string>
#include <vector>

#define SIZE 15

using namespace std;


class Friends
{
private:
    int gr_size{SIZE};       //Определение максимального размера графа
    string persons[SIZE];           //Массив имен
    //std::vector<string> hum; 
    bool matrix [SIZE][SIZE];       //Матрица смежности знакомств
    int nameCount;                       //Счетчик добавленных имен

public:

    Friends();
    
    void addPerson(string name);         //добавление персон
    void delPerson(const string& name);         //удалить персону
    void addFrienship(const string& name1, const string& name2);    //добавление дружбы между персонами
    void delFriendship(const string& name1, const string& name2);   //удаление дружбы
    void threeHandMeetings(const string& name);     //показать знакомства через три рукопожатия
    void depthInner(int current, bool visited[], int start, int stop);     //рекурсивная функция обхода графа
    ~Friends();
};
