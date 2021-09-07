#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	ui.setupUi(this);
	initUi();
}

MainWindow::~MainWindow()
{
	SqlConnectionPool::closeConnection(m_db);
}

void MainWindow::initUi()
{
	m_db = SqlConnectionPool::openConnection();
	setSexComboBox();
	setCardTypeComboBox();
}

void MainWindow::setSexComboBox()
{
	QList<Sex> sexList;
	SqlController::getInstance().selectFromSex(sexList, m_db);
	if (!sexList.isEmpty())
	{
		for (const auto sex : sexList)
		{
			ui.comboBoxSex->addItem(sex.sexDescription, sex.sexId);
		}
	}
}

void MainWindow::setCardTypeComboBox()
{
	QList<CardType> cardTypeList;
	SqlController::getInstance().selectFromCardType(cardTypeList, m_db);
	if (!cardTypeList.isEmpty())
	{
		for (const auto cardType : cardTypeList)
		{
			ui.comboBoxCardType->addItem(cardType.cardTypeDesc, cardType.cardTypeCode);
		}
	}
}
