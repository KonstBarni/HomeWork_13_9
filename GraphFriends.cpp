#include <string>
#include <iostream>
#include "GraphFriends.h"

using namespace std;

Friends::Friends()
{
    for(int i = 0; i < gr_size; ++i )
    {
        for(int j = 0; j < gr_size; ++j)
        {
            matrix[i][j] = false;
        }
    }
    nameCount = 0;
}

void Friends::addPerson(string name)     //добавление персоны
{

    if(nameCount == gr_size)
    {
        cout << "Ошибка. Память имен переполнена.";
        return;
    }
    persons[nameCount++] = name;

}

void Friends::addFrienship(const string& name1, const string& name2)    //добавить дружбу
{
    int m {-1};
    int n {-1};

    for(int i = 0; i < gr_size; ++i)
    {
        if(name1 == persons[i])
            m = i;

        if(name2 == persons[i])
            n = i;
    }

    matrix[n][m] = true;
    matrix[m][n] = true;
}

void Friends::delFriendship(const string& name1, const string& name2) //удаление дружбы
{
    int m {-1};
    int n {-1};

    for(int i = 0; i < gr_size; ++i)
    {
        if(name1 == persons[i])
            m = i;

        if(name2 == persons[i])
            n = i;
    }

    matrix[n][m] = false;
    matrix[m][n] = false;
}
    
void Friends::delPerson(const string& name)     //удаление персоны
{
    int match {-1};
    for(int i = 0; i < gr_size; ++i)
    {
        if(name == persons[i])
            match = i;

        if(match < 0)
            cout<<"Ошибка имени!"<<endl;
            return;
    }

    for(int i = match; i < gr_size - 1; ++i)
    {
        matrix[i][match] = matrix[i + 1][match];
        matrix[match][i] = matrix[match][i + 1];
        persons[i] = persons[i + 1];
        matrix[i][gr_size - 1] = false;
        matrix[gr_size - 1][i] = false;
    }

    persons[gr_size - 1].clear();
    --nameCount;
}
    
void Friends::threeHandMeetings(const string& name)
{
    int match {-1};

    for(int i = 0; i < gr_size; i++)
    {
        if(name == persons[i])
        {
            match = i;
            break;    
        }
        
    }

    if(match < 0)
    {
        cout<<"Имя "<< name << " -не найдено!"<<endl;
        return;
    }

    cout << persons[match] << " знаком: " << std::endl;

    bool visited[gr_size];
    for(int i = 0; i < nameCount; i++)
        visited[i] = false;

    int start{0};
    int stop{3};

    depthInner(match, visited, start, stop);
    cout << endl;
}

void Friends::depthInner(int current, bool visited[], int start, int stop)
{

    if(start > stop)
        return;

    visited[current] = true;

    for(int i = 0; i < gr_size; i++)
    {
        if(!visited[i] && matrix[i][current])
        {
            cout << persons[i]<<endl;
            depthInner(i, visited, start++, stop);
        }
    }
    
}

Friends::~Friends(){}
    