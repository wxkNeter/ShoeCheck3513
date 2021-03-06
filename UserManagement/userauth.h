﻿#ifndef USERAUTH_H
#define USERAUTH_H

#include <QObject>
#include "user.h"

class UserAuth : public QObject
{
    Q_OBJECT

public:
    /* 用户认证部分功能 */
    User getCurrentUser() const;
    void setCurrentUser(const User &value);

public:
    static UserAuth *getUserInstance();
private:
    explicit UserAuth(QObject *parent = 0);
    static UserAuth *userAuth;
    User currentUser;
};
#define USER_AUTH UserAuth::getUserInstance()

#endif // USERAUTH_H
