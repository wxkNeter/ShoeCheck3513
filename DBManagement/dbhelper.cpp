﻿#include "dbhelper.h"
#include <QApplication>

DBHelper* DBHelper::dbHelper=NULL;

DBHelper::DBHelper()
{

}

bool DBHelper::isOpen()
{
    return m_db.isOpen();
}

bool DBHelper::connectToConfigedDB()
{
    //从配置文件中读取
    //这里应该读取一个xml文件吧
    //xml文件的位置绝对是写死的
    DBConnectPara para;
    para.driver = "QSQLITE";
    para.databaseName = QApplication::applicationDirPath() + "shoecheck.db";
    return connectToDataBase(para);
}

bool DBHelper::connectToDataBase(DBConnectPara para)
{
    if(m_db.isOpen())
        m_db.close();

    QString driver = para.driver;

    if(driver == "QSQLITE")
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(para.databaseName);
    }
    else if(driver == "QMYSQL")
    {
        m_db = QSqlDatabase::addDatabase("QMYSQL");

        m_db.setHostName(para.hostName);
        m_db.setPort(para.port);
        m_db.setDatabaseName(para.databaseName);
        m_db.setUserName(para.userName);
        m_db.setPassword(para.userPasswd);
    }
    else
    {
        return false;
    }

    return m_db.open();
}

bool DBHelper::validateUser(QString name, QString passwd, User &user)
{
    //写下的第一条sql语句
    if(name != "wxk")
        return false;

    user.setName(name);
    user.setPasswd(passwd);

    user.setRole(UserRole::Admin);

    return true;


}

DBHelper *DBHelper::getDBHelperInstance()
{
    if(dbHelper == NULL)
        dbHelper = new DBHelper;
    return dbHelper;
}
