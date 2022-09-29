//Project 9-1 | A set class for chars

#include <iostream>

const int MAX_SIZE = 100;

class Set 
{
    int len; //number of members;
    char members[MAX_SIZE]; //array that holds the set

    int find(char ch); //Return index of the element

public:
    Set() { len = 0; } //Build null Set

    int getLength() { return len; } //Return num of elements

    void showSet();
    bool isMember(char ch);

    Set operator +(char ch); //add an element
    Set operator -(char ch); //remove element
    
    Set operator +(Set obj2); //set union
    Set operator -(Set obj2); //set difference

    bool operator <(Set obj2); //Check subset
    bool operator >(Set obj2); //Check superset

    Set operator &(Set obj2); //Get intersection
    Set operator |(Set obj2); //Symmetric difference

};

int Set::find(char ch)
{
    for(int i = 0; i < len; i++)
        if(members[i] == ch) return i;
    
    return -1;
}

void Set::showSet()
{
    std::cout << "{ ";
    for(int i = 0; i < len; i++)
        std::cout << members[i] << " ";
    
    std::cout << "}\n";
}

bool Set::isMember(char ch)
{
    if(find(ch) != -1)
        return true;
    else 
        return false;
}

Set Set::operator +(char ch)
{
    Set newSet;

    if(len == MAX_SIZE)
    {
        std::cout << "Set is full.\n";
        return *this; // return existing set
    }

    newSet = *this;
    if(find(ch) == -1) //check if element already exist
    {
        newSet.members[newSet.len] = ch;
        newSet.len++;
    }

    return newSet;
}

Set Set::operator -(char ch)
{
    Set newSet;
    int position = find(ch);

    for(int i = 0; i < len; i++) //copy and compress
        if(i != position) newSet = newSet + members[i];

    return newSet;
}

Set Set::operator +(Set obj2)
{
    Set newSet = *this;

    for(int i = 0; i < obj2.len; i++) //Add unique elements
        newSet = newSet + obj2.members[i];
    
    return newSet;
}

Set Set::operator -(Set obj2)
{
    Set newSet = *this;

    for(int i = 0; i < obj2.len; i++) //Remove matching elements
        newSet = newSet - obj2.members[i];
    
    return newSet;
}

bool Set::operator <(Set obj2)
{
    if(len > obj2.len) return false;

    for(int i = 0; i < len; i++)
        if(obj2.find(members[i]) == -1) return false;
    
    return true;

/* my ugly solution
    Set thisSet = *this;

    if(thisSet.len < obj2.len)
    {
        for(int i = 0; i < thisSet.len; i++)
        {
            if(!obj2.isMember(thisSet.members[i]))
            {
                std::cout << "Not subset because a not member found";
                return false;
            }
        }
        std::cout << "Left subset of right";
        return true;
    }
    else  
    {
        std::cout << "Left NOT subset of right";
        return false;
    } 
*/
}

bool Set::operator >(Set obj2)
{
    if(len < obj2.len) return false;

    for(int i = 0; i < obj2.len; i++)
        if(find(obj2.members[i]) == -1) return false;

    return true;
}

Set Set::operator &(Set obj2)
{
    Set newSet;

    for(int i = 0; i < len; i++)
        if(obj2.find(members[i]) != -1) 
            newSet = newSet + members[i];

    return newSet;
}

Set Set::operator |(Set obj2)
{
    Set newSet;

    for(int i = 0; i < len; i++)
        if(obj2.find(members[i]) == -1) 
            newSet = newSet + members[i];
    
    for(int i = 0; i < obj2.len; i++)
        if(find(obj2.members[i]) == -1) 
            newSet = newSet + obj2.members[i];
    
    return newSet;
}


int main()
{
    Set s1, s2, s3;

    s1 = s1 + 'A';
    s1 = s1 + 'B';
    s1 = s1 + 'C';
    std::cout << "s1 after adding A B C: ";
    s1.showSet();

    std::cout << "\n";

    std::cout << "Testing for membership using isMember().\n";
    if(s1.isMember('B'))
        std::cout << "B is a member of s1.\n";
    else   
        std::cout << "B is not a member of s1.\n";

    if(s1.isMember('T'))
        std::cout << "T is a member of s1.\n";
    else   
        std::cout << "T is not a member of s1.\n";

    std::cout << "\n";

    s1 = s1 - 'B';
    std::cout << "s1 after s1 = s1 - 'B': ";
    s1.showSet();

    s1 = s1 - 'A';
    std::cout << "s1 after s1 = s1 - 'A': ";
    s1.showSet();

    s1 = s1 - 'C';
    std::cout << "s1 after s1 = s1 - 'C': ";
    s1.showSet();

    std::cout << "\n";

    s1 = s1 + 'A';
    s1 = s1 + 'B';
    s1 = s1 + 'C';
    std::cout << "s1 after adding A B C: ";
    s1.showSet();

    s2 = s2 + 'A';
    s2 = s2 + 'X';
    s2 = s2 + 'W';
    std::cout << "s2 after adding A X W: ";
    s2.showSet();

    s3 = s1 + s2;
    std::cout << "s3 after s3 = s1 + s2: ";
    s3.showSet();

    s3 = s3 - s1;
    std::cout << "s3 after s3 - s1: ";
    s3.showSet();

    std::cout << "\n";

    s2 = s2 - s2; //clear s2
    std::cout << "s2 after s2 = s2 - s2: ";
    s2.showSet();

    std::cout << "\n";

    s2 = s2 + 'C';
    s2 = s2 + 'B';
    s2 = s2 + 'A';

    std::cout << "s2 after adding C B A";
    s2.showSet();

    std::cout << "Check S1 subset S2:\n";
    s1 = s1 - 'C';
    s1.showSet();
    s2.showSet();
    if(s1 < s2) std::cout << "Y\n"; else std::cout << "N\n";

    std::cout << "Check S1 superset S2:\n";
    s1 = s1 + 'C' + 'D' + 'E';
    s1.showSet();
    s2.showSet();
    if(s1 > s2) std::cout << "Y\n"; else std::cout << "N\n";

    Set intersection = s1 & s2;
    std::cout << "Intersection:\n";
    intersection.showSet();

    Set symmetricDifference = s1 | s2;
    std::cout << "Symmetric difference:\n"; 
    symmetricDifference.showSet();

    return 0;
}