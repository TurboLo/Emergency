#pragma execution_character_set("utf-8")
#include <QApplication>
#include <iostream>
#include "MainWindow.h"
#include "ImportDataFromExcel.h"
#include <qDebug>
#include <QtCore/qglobal.h>

int main(int argc, char* argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
    MainWindow mm;
	mm.show();


    // ��ӡ����
    /*QString text =
        "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do\n"
        "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut\n"
        "enim ad minim veniam, quis nostrud exercitation ullamco laboris\n"
        "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor\n"
        "in reprehenderit in voluptate velit esse cillum dolore eu fugiat\n"
        "nulla pariatur. Excepteur sint occaecat cupidatat non proident,\n"
        "sunt in culpa qui officia deserunt mollit anim id est laborum.\n"
        "�������һ���ǳ���Ҫ���ˣ���ô�����һ���ǳ���Ҫ���ˣ�������һ���ǳ���Ҫ���ˡ�";

    QPrinter printer;

    QPrintDialog* dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if (dialog->exec() != QDialog::Accepted)
        return -1;

    QPainter painter;
    painter.begin(&printer);

    painter.drawText(100, 100, 500, 500, Qt::AlignLeft | Qt::AlignTop, text);

    painter.end();*/

	return a.exec();
}