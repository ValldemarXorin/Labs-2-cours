/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLineEdit *email;
    QLineEdit *password;
    QLabel *title;
    QToolButton *support;
    QPushButton *SingIn;
    QLabel *ErrorMessage;
    QToolButton *CheckPassword;
    QPushButton *SingUp;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(615, 445);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(false);
        LoginWindow->setFont(font);
        LoginWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"                background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, \n"
"                                    stop: 0 #1E1E1E, /* \320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\321\213\320\271) */\n"
"                                    stop: 1 #001f3f); /* \320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\320\276-\321\201\320\270\320\275\320\270\320\271) */\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"    }"));
        email = new QLineEdit(LoginWindow);
        email->setObjectName("email");
        email->setGeometry(QRect(360, 140, 211, 41));
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QLineEdit:hover {\n"
"		background-color: #1E1E1E\n"
"}\n"
"\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #0056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"        background-color: #3E3E3E; /* \320\246\320\262\320\265\321"
                        "\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"    }"));
        password = new QLineEdit(LoginWindow);
        password->setObjectName("password");
        password->setGeometry(QRect(360, 220, 211, 41));
        password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px 40px 5px 0; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QLineEdit:hover {\n"
"		background-color: #1E1E1E\n"
"}\n"
"\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #0056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"        background-color: #3E3E3E; /* \320\246\320\262\320"
                        "\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"    }"));
        title = new QLabel(LoginWindow);
        title->setObjectName("title");
        title->setGeometry(QRect(70, 40, 111, 71));
        title->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 16pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        support = new QToolButton(LoginWindow);
        support->setObjectName("support");
        support->setGeometry(QRect(70, 340, 41, 41));
        support->setToolTipDuration(-1);
        support->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"        background-color: #2E2E2E; /* \320\246\320\262\320\265\321\202 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        border: none; /* \320\221\320\265\320\267 \320\263\321\200\320\260\320\275\320\270\321\206 */\n"
"        border-radius: 20px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px;\n"
"    }\n"
"    QToolButton:hover {\n"
"        background-color: #0056a1; /* \320\246\320\262\320\265\321\202 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"    }"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("help-browser")));
        support->setIcon(icon);
        support->setCheckable(false);
        support->setChecked(false);
        support->setAutoRepeat(false);
        support->setAutoExclusive(false);
        support->setAutoRaise(false);
        SingIn = new QPushButton(LoginWindow);
        SingIn->setObjectName("SingIn");
        SingIn->setGeometry(QRect(470, 340, 101, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        SingIn->setFont(font1);
        SingIn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"		background-color: #1E1E1E\n"
"}"));
        ErrorMessage = new QLabel(LoginWindow);
        ErrorMessage->setObjectName("ErrorMessage");
        ErrorMessage->setGeometry(QRect(360, 280, 211, 16));
        ErrorMessage->setCursor(QCursor(Qt::CursorShape::SizeBDiagCursor));
        ErrorMessage->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: none;\n"
"	color: #e50b0b;\n"
"}"));
        CheckPassword = new QToolButton(LoginWindow);
        CheckPassword->setObjectName("CheckPassword");
        CheckPassword->setGeometry(QRect(540, 230, 22, 22));
        CheckPassword->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: #2E2E2E;\n"
"	border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 11px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"		background-color: #3E3E3E\n"
"}"));
        SingUp = new QPushButton(LoginWindow);
        SingUp->setObjectName("SingUp");
        SingUp->setGeometry(QRect(360, 340, 101, 41));
        SingUp->setFont(font1);
        SingUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"		background-color: #1E1E1E\n"
"}"));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        email->setText(QString());
        email->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Email", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "password", nullptr));
        title->setText(QCoreApplication::translate("LoginWindow", "MDB&MS", nullptr));
#if QT_CONFIG(tooltip)
        support->setToolTip(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Hello, bro</span></p><p align=\"center\">This window can help</p><p align=\"center\"> you with sport</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        support->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        SingIn->setText(QCoreApplication::translate("LoginWindow", "Sing In", nullptr));
        ErrorMessage->setText(QString());
        CheckPassword->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        SingUp->setText(QCoreApplication::translate("LoginWindow", "Sing Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
