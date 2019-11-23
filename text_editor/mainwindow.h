#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QtPrintSupport/QPrinter> 
#include "textedit.h"

class mainwindow:public QMainWindow {
	Q_OBJECT
public:
	mainwindow(QWidget *parent = nullptr);
	~mainwindow();
	bool loadFile(const QString& fileName); //读取文件
private:
	QString curFile; //当前文件名
	QTextCharFormat fmt; //格式

	void createActions();  //创建操作
	void createmenus();   //创建菜单栏
	void createContextMenu();  //创建右键菜单
 	void createToolBars();    //创建工具栏
	void createStatusBar();   //创建底部状态栏
	bool okToContinue();    //判断文件是否保存
	void setCurrentFile(const QString& fileName);  //设置当前文件名
	bool save(const QString& fileName);  //保存文件
	void UpdateMenus();   //更新菜单栏

	//菜单栏
	QMenuBar *menuBar = nullptr;
	QMenu *menuFile = nullptr;
	QMenu *menuEdit = nullptr;
	QMenu *formatEdit = nullptr;
	QMenu *helpEdit = nullptr;
	//菜单下项目
	QAction *newAct = nullptr;
	QAction *openAct = nullptr;
	QAction *saveAct = nullptr;
	QAction *save_asAct = nullptr;
	QAction *printAct = nullptr;
	QAction *printPreviewAct = nullptr;
	QAction *exitAct = nullptr;
	QAction *undoAct = nullptr;
	QAction *redoAct = nullptr;
	QAction *cutAct = nullptr;
	QAction *copyAct = nullptr;
	QAction *pasteAct = nullptr;
	QAction *aboutAct = nullptr;
	QAction *aboutQTAct = nullptr;
	QAction *colorAct = nullptr;
	QAction *boldAct = nullptr;
	QAction *italicAct = nullptr;
	QAction *ulAct = nullptr;
	//工具栏
	QToolBar* mainToolBar = nullptr;
	//主编辑界面
	textedit* TextEdit = nullptr;
	//状态栏
	QLabel* rowColumnLabel = nullptr;

protected:
	void closeEvent(QCloseEvent *event);
private slots:
	void fileNew();
	void fileOpen();
	bool fileSave();
	bool fileSaveAs();
	void filePrint();
	void filePrintPreview();
	void fileExit();
	void fileUndo();
	void fileRedo();
	void fileCut();
	void fileCopy();
	void filePaste();
	void fileAbout();
	void fileColor();
	void fileItalic();
	void fileUnderline();
	void fileBold();
	void textModified();
	void ShowTextRowCol();
	void Preview(QPrinter *printer);
};

#endif
