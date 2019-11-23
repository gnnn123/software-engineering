#include <QApplication>
#include "mainwindow.h"
#include "textedit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainwindow m;
	m.show();
	return a.exec();
}
