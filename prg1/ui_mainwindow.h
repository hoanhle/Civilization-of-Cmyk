/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphics_view;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *beacons_checkbox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *beaconnames_checkbox;
    QCheckBox *lightbeams_checkbox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *beamcolor_checkbox;
    QCheckBox *beamroutes_checkbox;
    QCheckBox *roads_checkbox;
    QSpacerItem *verticalSpacer;
    QRadioButton *pick_beacon;
    QRadioButton *pick_coord;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *zoom_plus;
    QToolButton *zoom_minus;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *zoom_1;
    QToolButton *zoom_fit;
    QLabel *label_3;
    QDoubleSpinBox *fontscale;
    QPlainTextEdit *output;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *cmd_info_text;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cmd_select;
    QLabel *label_2;
    QComboBox *number_select;
    QPushButton *file_button;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *stop_button;
    QPushButton *execute_button;
    QPushButton *clear_input_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(749, 661);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphics_view = new QGraphicsView(layoutWidget);
        graphics_view->setObjectName(QString::fromUtf8("graphics_view"));
        graphics_view->setInteractive(true);
        graphics_view->setDragMode(QGraphicsView::NoDrag);

        horizontalLayout_2->addWidget(graphics_view);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        beacons_checkbox = new QCheckBox(layoutWidget);
        beacons_checkbox->setObjectName(QString::fromUtf8("beacons_checkbox"));
        beacons_checkbox->setChecked(true);

        verticalLayout_2->addWidget(beacons_checkbox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        beaconnames_checkbox = new QCheckBox(layoutWidget);
        beaconnames_checkbox->setObjectName(QString::fromUtf8("beaconnames_checkbox"));
        beaconnames_checkbox->setChecked(true);

        horizontalLayout_7->addWidget(beaconnames_checkbox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        lightbeams_checkbox = new QCheckBox(layoutWidget);
        lightbeams_checkbox->setObjectName(QString::fromUtf8("lightbeams_checkbox"));
        lightbeams_checkbox->setChecked(true);

        verticalLayout_2->addWidget(lightbeams_checkbox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        beamcolor_checkbox = new QCheckBox(layoutWidget);
        beamcolor_checkbox->setObjectName(QString::fromUtf8("beamcolor_checkbox"));

        verticalLayout_5->addWidget(beamcolor_checkbox);

        beamroutes_checkbox = new QCheckBox(layoutWidget);
        beamroutes_checkbox->setObjectName(QString::fromUtf8("beamroutes_checkbox"));
        beamroutes_checkbox->setEnabled(false);

        verticalLayout_5->addWidget(beamroutes_checkbox);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        roads_checkbox = new QCheckBox(layoutWidget);
        roads_checkbox->setObjectName(QString::fromUtf8("roads_checkbox"));
        roads_checkbox->setEnabled(false);
        roads_checkbox->setChecked(true);

        verticalLayout_2->addWidget(roads_checkbox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pick_beacon = new QRadioButton(layoutWidget);
        pick_beacon->setObjectName(QString::fromUtf8("pick_beacon"));
        pick_beacon->setChecked(true);

        verticalLayout_2->addWidget(pick_beacon);

        pick_coord = new QRadioButton(layoutWidget);
        pick_coord->setObjectName(QString::fromUtf8("pick_coord"));
        pick_coord->setEnabled(false);

        verticalLayout_2->addWidget(pick_coord);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        zoom_plus = new QToolButton(layoutWidget);
        zoom_plus->setObjectName(QString::fromUtf8("zoom_plus"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(zoom_plus->sizePolicy().hasHeightForWidth());
        zoom_plus->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(zoom_plus);

        zoom_minus = new QToolButton(layoutWidget);
        zoom_minus->setObjectName(QString::fromUtf8("zoom_minus"));
        sizePolicy.setHeightForWidth(zoom_minus->sizePolicy().hasHeightForWidth());
        zoom_minus->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(zoom_minus);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        zoom_1 = new QToolButton(layoutWidget);
        zoom_1->setObjectName(QString::fromUtf8("zoom_1"));
        sizePolicy.setHeightForWidth(zoom_1->sizePolicy().hasHeightForWidth());
        zoom_1->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(zoom_1);

        zoom_fit = new QToolButton(layoutWidget);
        zoom_fit->setObjectName(QString::fromUtf8("zoom_fit"));
        sizePolicy.setHeightForWidth(zoom_fit->sizePolicy().hasHeightForWidth());
        zoom_fit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(zoom_fit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        fontscale = new QDoubleSpinBox(layoutWidget);
        fontscale->setObjectName(QString::fromUtf8("fontscale"));
        fontscale->setMinimum(0.010000000000000);
        fontscale->setSingleStep(0.100000000000000);
        fontscale->setValue(1.000000000000000);

        verticalLayout_2->addWidget(fontscale);


        horizontalLayout_2->addLayout(verticalLayout_2);

        splitter->addWidget(layoutWidget);
        output = new QPlainTextEdit(splitter);
        output->setObjectName(QString::fromUtf8("output"));
        output->setUndoRedoEnabled(false);
        output->setLineWrapMode(QPlainTextEdit::NoWrap);
        splitter->addWidget(output);

        verticalLayout->addWidget(splitter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        cmd_info_text = new QLabel(centralWidget);
        cmd_info_text->setObjectName(QString::fromUtf8("cmd_info_text"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmd_info_text->sizePolicy().hasHeightForWidth());
        cmd_info_text->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(cmd_info_text);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        cmd_select = new QComboBox(centralWidget);
        cmd_select->setObjectName(QString::fromUtf8("cmd_select"));

        horizontalLayout->addWidget(cmd_select);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        number_select = new QComboBox(centralWidget);
        number_select->setObjectName(QString::fromUtf8("number_select"));

        horizontalLayout->addWidget(number_select);

        file_button = new QPushButton(centralWidget);
        file_button->setObjectName(QString::fromUtf8("file_button"));

        horizontalLayout->addWidget(file_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        stop_button = new QPushButton(centralWidget);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setEnabled(false);

        verticalLayout_3->addWidget(stop_button);

        execute_button = new QPushButton(centralWidget);
        execute_button->setObjectName(QString::fromUtf8("execute_button"));

        verticalLayout_3->addWidget(execute_button);

        clear_input_button = new QPushButton(centralWidget);
        clear_input_button->setObjectName(QString::fromUtf8("clear_input_button"));

        verticalLayout_3->addWidget(clear_input_button);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        beacons_checkbox->setText(QApplication::translate("MainWindow", "Beacons", nullptr));
        beaconnames_checkbox->setText(QApplication::translate("MainWindow", "Beacon names", nullptr));
        lightbeams_checkbox->setText(QApplication::translate("MainWindow", "Beams", nullptr));
        beamcolor_checkbox->setText(QApplication::translate("MainWindow", "Beam color", nullptr));
        beamroutes_checkbox->setText(QApplication::translate("MainWindow", "Beam routes", nullptr));
        roads_checkbox->setText(QApplication::translate("MainWindow", "Fibres", nullptr));
        pick_beacon->setText(QApplication::translate("MainWindow", "Pic&k Beacon", nullptr));
        pick_coord->setText(QApplication::translate("MainWindow", "Pick &Xroad", nullptr));
        zoom_plus->setText(QApplication::translate("MainWindow", "+", nullptr));
        zoom_minus->setText(QApplication::translate("MainWindow", "-", nullptr));
        zoom_1->setText(QApplication::translate("MainWindow", "1:1", nullptr));
        zoom_fit->setText(QApplication::translate("MainWindow", "Fit", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Fontscale", nullptr));
        cmd_info_text->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Command:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Number:", nullptr));
        file_button->setText(QApplication::translate("MainWindow", "File...", nullptr));
        stop_button->setText(QApplication::translate("MainWindow", "Stop test", nullptr));
        execute_button->setText(QApplication::translate("MainWindow", "Execute", nullptr));
        clear_input_button->setText(QApplication::translate("MainWindow", "Clear input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
