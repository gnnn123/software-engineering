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
	bool loadFile(const QString& fileName); //��ȡ�ļ�
private:
	QString curFile; //��ǰ�ļ���
	QTextCharFormat fmt; //��ʽ

	void createActions();  //��������
	void createmenus();   //�����˵���
	void createContextMenu();  //�����Ҽ��˵�
 	void createToolBars();    //����������
	void createStatusBar();   //�����ײ�״̬��
	bool okToContinue();    //�ж��ļ��Ƿ񱣴�
	void setCurrentFile(const QString& fileName);  //���õ�ǰ�ļ���
	bool save(const QString& fileName);  //�����ļ�
	void UpdateMenus();   //���²˵���

	//�˵���
	QMenuBar *menuBar = nullptr;
	QMenu *menuFile = nullptr;
	QMenu *menuEdit = nullptr;
	QMenu *formatEdit = nullptr;
	QMenu *helpEdit = nullptr;
	//�˵�����Ŀ
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
	//������
	QToolBar* mainToolBar = nullptr;
	//���༭����
	textedit* TextEdit = nullptr;
	//״̬��
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
