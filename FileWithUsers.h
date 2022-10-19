#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XmlFile
{

public:
    FileWithUsers(string fileName) : XmlFile(fileName){};
    void addUserToFile(User user);
    void addAllUsersToFile(vector <User> &users);
    vector <User> loadUsersFromFile();

};

#endif
