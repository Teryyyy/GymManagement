#pragma once
#include <iostream>
using namespace std;

class User {
private:
    string username;
    string password;
    int type;
public:
    User() :username("Unknown"), password("Unknown"), type(0) {}
    User(string username, string password, int type) :username(username), password(password), type(type) {}
    ~User() {

    }
    void setUsername(string username) {
        this->username = username;
    }
    string getUsername() {
        return username;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getPassword() {
        return password;
    }
    void setType(int type) {
        this->type = type;
    }
    int getType() {
        return type;
    }
    void inputUser() {
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        cout << "Press 1. ADMIN 2.NORMAL " << endl;
        cin >> type;
    }
    void outputUser() {
        cout << "Username : " << username << " ";
        //cout << "\nType : " << type << endl;
    }
};