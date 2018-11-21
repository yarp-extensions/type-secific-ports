//
// Created by jonb on 11/21/18.
//
#include "AppInfo.h"

Singleton::Singleton() {

}

Singleton* Singleton::m_pInstance = 0;
Singleton* Singleton::Instance()
{
  if (0 == m_pInstance) {
	m_pInstance = new Singleton;
  }
  return m_pInstance;
}