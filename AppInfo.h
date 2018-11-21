//
// Created by jonb on 11/20/18.
//
#pragma once
#include <string>
using namespace std;
//class AppInfo {
//public:
//    AppInfo(char **argv)        {appName = argv[0];};
//    static string getAppName()  { return appName;};
//    static uint getAppInstance(){ return 1; };
//private:
//    static string appName;
//};


// Source: Design Patterns (GoF)
// Page:   129
class Singleton
{
public:
    static Singleton* Instance();
protected:
    Singleton();
    ~Singleton() {
        if (0 != m_pInstance) {
            // Add all of your other destruction
            // responsibilities at this point.

            // Hold a copy of the singleton pointer,
            // and zero out the static member-data
            // before calling delete on the object.
            Singleton* pTemp = m_pInstance;
            m_pInstance = 0;
            delete pTemp;
        }
    }
private:
    static Singleton* m_pInstance;
};