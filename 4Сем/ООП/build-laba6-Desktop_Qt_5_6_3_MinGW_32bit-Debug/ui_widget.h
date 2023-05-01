/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *ageLabel;
    QLabel *estateTypeLabel;
    QLabel *residetnsLabel;
    QLabel *areaLabel;
    QLabel *periodLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QComboBox *estateTypeBox;
    QLineEdit *residentsEdit;
    QLineEdit *areaEdit;
    QComboBox *periodBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *costLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *calcButton;
    QPushButton *undoButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(901, 522);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Widget->setFont(font);
        Widget->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameLabel = new QLabel(Widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        nameLabel->setFont(font1);

        verticalLayout->addWidget(nameLabel);

        ageLabel = new QLabel(Widget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));
        ageLabel->setFont(font1);

        verticalLayout->addWidget(ageLabel);

        estateTypeLabel = new QLabel(Widget);
        estateTypeLabel->setObjectName(QStringLiteral("estateTypeLabel"));
        estateTypeLabel->setFont(font1);

        verticalLayout->addWidget(estateTypeLabel);

        residetnsLabel = new QLabel(Widget);
        residetnsLabel->setObjectName(QStringLiteral("residetnsLabel"));
        residetnsLabel->setFont(font1);

        verticalLayout->addWidget(residetnsLabel);

        areaLabel = new QLabel(Widget);
        areaLabel->setObjectName(QStringLiteral("areaLabel"));
        areaLabel->setFont(font1);

        verticalLayout->addWidget(areaLabel);

        periodLabel = new QLabel(Widget);
        periodLabel->setObjectName(QStringLiteral("periodLabel"));
        periodLabel->setFont(font1);

        verticalLayout->addWidget(periodLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameEdit = new QLineEdit(Widget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setFont(font1);

        verticalLayout_2->addWidget(nameEdit);

        ageEdit = new QLineEdit(Widget);
        ageEdit->setObjectName(QStringLiteral("ageEdit"));
        ageEdit->setFont(font1);

        verticalLayout_2->addWidget(ageEdit);

        estateTypeBox = new QComboBox(Widget);
        estateTypeBox->setObjectName(QStringLiteral("estateTypeBox"));
        estateTypeBox->setFont(font1);

        verticalLayout_2->addWidget(estateTypeBox);

        residentsEdit = new QLineEdit(Widget);
        residentsEdit->setObjectName(QStringLiteral("residentsEdit"));
        residentsEdit->setFont(font1);

        verticalLayout_2->addWidget(residentsEdit);

        areaEdit = new QLineEdit(Widget);
        areaEdit->setObjectName(QStringLiteral("areaEdit"));
        areaEdit->setFont(font1);

        verticalLayout_2->addWidget(areaEdit);

        periodBox = new QComboBox(Widget);
        periodBox->setObjectName(QStringLiteral("periodBox"));
        periodBox->setFont(font1);

        verticalLayout_2->addWidget(periodBox);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        costLabel = new QLabel(Widget);
        costLabel->setObjectName(QStringLiteral("costLabel"));
        costLabel->setFont(font1);

        horizontalLayout_3->addWidget(costLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        calcButton = new QPushButton(Widget);
        calcButton->setObjectName(QStringLiteral("calcButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calcButton->sizePolicy().hasHeightForWidth());
        calcButton->setSizePolicy(sizePolicy);
        calcButton->setFont(font1);

        horizontalLayout_2->addWidget(calcButton);

        undoButton = new QPushButton(Widget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setFont(font1);

        horizontalLayout_2->addWidget(undoButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "4134\320\272 \320\232\320\276\321\201\321\202\321\217\320\272\320\276\320\262 \320\235\320\270\320\272\320\270\321\202\320\260", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("Widget", "\320\230\320\274\321\217:", Q_NULLPTR));
        ageLabel->setText(QApplication::translate("Widget", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202:", Q_NULLPTR));
        estateTypeLabel->setText(QApplication::translate("Widget", "\320\232\320\273\320\260\321\201\321\201 \320\266\320\270\320\273\321\214\321\217:", Q_NULLPTR));
        residetnsLabel->setText(QApplication::translate("Widget", "\320\247\320\270\321\201\320\273\320\276 \320\277\321\200\320\276\320\266\320\270\320\262\320\260\321\216\321\211\320\270\321\205:", Q_NULLPTR));
        areaLabel->setText(QApplication::translate("Widget", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214:", Q_NULLPTR));
        periodLabel->setText(QApplication::translate("Widget", "\320\241\321\200\320\276\320\272 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\321\217: ", Q_NULLPTR));
        nameEdit->setText(QString());
        nameEdit->setPlaceholderText(QString());
        ageEdit->setText(QString());
        ageEdit->setPlaceholderText(QString());
        estateTypeBox->clear();
        estateTypeBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\320\232\320\262\320\260\321\200\321\202\320\270\321\200\320\260 \321\215\320\272\320\276\320\275\320\276\320\274-\320\272\320\273\320\260\321\201\321\201\320\260", Q_NULLPTR)
         << QApplication::translate("Widget", "\320\255\320\273\320\270\321\202\320\275\320\260\321\217 \320\272\320\262\320\260\321\200\321\202\320\270\321\200\320\260", Q_NULLPTR)
         << QApplication::translate("Widget", "\320\242\320\260\321\203\320\275-\321\205\320\260\321\203\321\201", Q_NULLPTR)
         << QApplication::translate("Widget", "\320\232\320\276\321\202\321\202\320\265\320\264\320\266", Q_NULLPTR)
        );
        residentsEdit->setText(QString());
        residentsEdit->setPlaceholderText(QString());
        areaEdit->setText(QString());
        areaEdit->setPlaceholderText(QString());
        periodBox->clear();
        periodBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "6 \320\274\320\265\321\201\321\217\321\206\320\265\320\262 ", Q_NULLPTR)
         << QApplication::translate("Widget", "12 \320\274\320\265\321\201\321\217\321\206\320\265\320\262", Q_NULLPTR)
         << QApplication::translate("Widget", "18 \320\274\320\265\321\201\321\217\321\206\320\265\320\262", Q_NULLPTR)
        );
        costLabel->setText(QApplication::translate("Widget", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\276\320\263\320\276 \320\262\320\267\320\275\320\276\321\201\320\260:   0", Q_NULLPTR));
        calcButton->setText(QApplication::translate("Widget", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        undoButton->setText(QApplication::translate("Widget", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\271 \320\267\320\260\320\277\321\200\320\276\321\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
