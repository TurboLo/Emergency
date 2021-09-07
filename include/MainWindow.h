/****************************************************************************
*						 系统主界面（收费界面）
*****************************************************************************
*
*					 File Name : EMERGENCYSYSTEM_MAINWINDOW_H
*
*				  Project Name : MainWindow
*
*					Programmer : Turbo
*
*				   Create Date : 2021-08-09
*
*				   Update Date :
*
*******************************************************************************/
#ifndef EMERGENCYSYSTEM_MAINWINDOW_H
#define EMERGENCYSYSTEM_MAINWINDOW_H
#include <QMainWindow>
#include "ui_MainWindow.h"
#include <QSqlDatabase>
#include "SqlConnectionPool.h"
#include "Structure.h"
#include "SqlController.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow :public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow() override;
protected:
	void initUi();
private:
	void setSexComboBox();
	void setCardTypeComboBox();
private:
	Ui::MainWindow ui;
	QSqlDatabase m_db;
};

#endif // !EMERGENCYSYSTEM_MAINWINDOW_H
