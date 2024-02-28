//
// Created by Kaden Jessee on 8/20/2022.
//
#include "Url.h"
#include "DynamicString.h"
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
Url::Url(const char *str) : DynamicString(str) {
    // scheme == https
    // authority == www.google.com
    // path == /search
    cout << "string: " << str << endl;
    int colon = find(':',0);
    if(colon <= 0){
        throw invalid_argument("Invalid format");
    }
    char * c_scheme = new char[colon + 1];
    for(int i = 0; i < colon; i++){
        c_scheme[i] = cstr[i];
    }
    c_scheme[colon] = '\0';
    scheme = c_scheme;
    delete[] c_scheme;
    cout << "scheme: " << scheme << endl;
    //define authority and path
    int w = find('/', colon+3);
    cout << "w " << w << endl;
    if(w < 0){
        //make it go to the next slash
        int auLen = len() - scheme.len() - 3;
        char * c_auth = new char[auLen + 1];
        for (int i = 0; i < auLen; i++) {
            c_auth[i] = cstr[i + scheme.len() + 3];
        }
        c_auth[auLen] = '\0';
        authority = c_auth;
        delete[] c_auth;
        cout << "Authority: " << authority << endl;
        return;
    }else if (w > scheme.len() + 3){    // go ahead and find the authority
        //make it go to the next slash
        int auLen = w - scheme.len() - 3;
        char *c_auth = new char[auLen + 1];
        for (int i = 0; i < auLen; i++) {
            c_auth[i] = cstr[i + scheme.len() + 3];
        }
        c_auth[auLen] = '\0';
        authority = c_auth;
        delete[] c_auth;
    }else{
        authority = "";
    }
    cout << "Authority: " << authority << endl;
    //path
    //schemeSize + 3, authoritysize + slash, go to end of string
    int pathSize = len() - scheme.len() - 3 - authority.len() - 1; //get size of path
    char * c_path = new char[pathSize + 1];
    for(int i = 0; i < pathSize; i++){
        c_path[i] = cstr[i + w + 1];
    }
    c_path[pathSize] = '\0';
    path = c_path;
    delete[] c_path;
    cout << "path: " << path << endl;
}

int Url::compare(const Url &other) {
    //if negative, return negative, same for positive, else check authority
    //path is case-sensitive, just use compare
    //scheme
    if(scheme.iCompare(other.scheme) < 0){
        return -1;
    }
    if(scheme.iCompare(other.scheme) > 0){
        return 1;
    }
    //authority
    if(authority.iCompare(other.authority) < 0){
        return -1;
    }
    if(authority.iCompare(other.authority) > 0){
        return 1;
    }
    //path
    if(path.compare(other.path) < 0){
        return -1;
    }
    if(path.compare(other.path) > 0){
        return 1;
    }
    return 0;
}