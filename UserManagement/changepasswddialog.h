﻿#ifndef CHANGEPASSWDDIALOG_H
#define CHANGEPASSWDDIALOG_H

#include <QDialog>
#include <QShowEvent>
class QPushButton;
class QLineEdit;
class QLabel;

namespace Ui {
class ChangePasswdDialog;
}

class ChangePasswdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswdDialog(QWidget *parent = 0);
    void setTitle(QString title);
    QString getNewPasswd();
    ~ChangePasswdDialog();
signals:
    void aimedNewPasswd(QString newPasswd);
protected:
    void showEvent(QShowEvent*);

private slots:
    void pushButton_ok_clicked();
    void pushButton_cancel_clicked();

    void userInputChanged();

private:
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    QLabel *label_newPasswd;
    QLabel *label_ackNewPasswd;
    QLabel *label_prompt;

    QLineEdit *lineEdit_newPasswd;
    QLineEdit *lineEdit_ackNewPasswd;
};

#endif // CHANGEPASSWDDIALOG_H
