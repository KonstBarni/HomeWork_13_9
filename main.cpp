#include <iostream>
#include <string>
#include "GraphFriends.h"

int main()
{
    Friends group;
    
    group.addPerson("Олег");
    group.addPerson("Юра");
    group.addPerson("Никита");
    group.addPerson("Ксюша");
    group.addPerson("Настя");
    group.addPerson("Ваня");
    group.addPerson("Маша");
    group.addPerson("Женя");
    
    group.addFrienship("Олег", "Юра");
    group.addFrienship("Юра", "Никита");
    group.addFrienship("Никита", "Ксюша");
    group.addFrienship("Олег", "Настя");
    group.addFrienship("Ваня", "Настя");
    group.addFrienship("Женя", "Ваяня");
    group.addFrienship("Маша", "Женя");
    

    //group.threeHandMeetings("Олег");
    group.threeHandMeetings("Женя");
    group.threeHandMeetings("Настя");
    group.threeHandMeetings("Виктор");
    
    
    return 0;
}