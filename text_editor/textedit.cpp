#include "textedit.h"
#include "mainwindow.h"
#include<QWidget>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
#include<QApplication>
#include<QStatusBar>

textedit::textedit(QWidget* parent):QTextEdit(parent) {
	TextEdit = new QTextEdit;
	TextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); //设置滚动条
	TextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); //垂直滚动
}
