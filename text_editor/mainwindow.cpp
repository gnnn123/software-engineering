#include "mainwindow.h"
#include<QLabel>
#include<QMenu>
#include<QtGui>
#include<QMenuBar>
#include<QAction>
#include<QToolBar>
#include<QStatusBar>
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>
#include<QMessageBox>
#include<QTextStream>
#include<QTabWidget>
#include<QApplication>
#include<QCloseEvent>
#include<QColorDialog>
#include<QTextCharFormat>
#include<QTextDocumentWriter>
#include<QtPrintSupport/QPrinter>  
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrintPreviewDialog>

mainwindow::mainwindow(QWidget *parent) :QMainWindow(parent) {
	this->resize(QSize(800, 600));
	TextEdit = new textedit(this);
	setCentralWidget(TextEdit);

	createActions(); //��������
	createmenus();  //�����˵���
	createToolBars(); //����
	createStatusBar();
	createContextMenu();

	boldAct->setCheckable(true);
	italicAct->setCheckable(true);
	ulAct->setCheckable(true);

	UpdateMenus();

	connect(TextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(ShowTextRowCol()));
	connect(TextEdit, SIGNAL(textChanged()), this, SLOT(textModified()));
}
mainwindow::~mainwindow(){ }

void mainwindow::textModified() {
	saveAct->setEnabled(true);
	setWindowTitle(curFile + "[*]"); //setWindowModified(true)����[*]��λ�ü���*
	setWindowModified(true); //�����ı����޸�
}
bool mainwindow::okToContinue() {  //�ж��Ƿ��Ѿ�����
	if (isWindowModified()) {
		QMessageBox box(QMessageBox::Question, tr("save"), tr("Do you want to save the file?"));
		box.setStandardButtons(QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel);
		box.setButtonText(QMessageBox::Ok, tr("Yes"));
		box.setButtonText(QMessageBox::No, tr("No"));
		box.setButtonText(QMessageBox::Cancel, tr("Cancel"));
		int res = box.exec();
		if (res == QMessageBox::Ok)
		{
			return fileSave();
		}
		else if (res == QMessageBox::Cancel)
		{
			return false;
		}
	}
	return true;
}
void mainwindow::setCurrentFile(const QString& fileName) {
	curFile = fileName;
	TextEdit->setWindowModified(false);
	setWindowModified(false);
	if (!fileName.isEmpty()) {
		curFile.replace('/', '\\');
	}
	setWindowTitle(tr("[*]%1").arg(curFile));
}
bool mainwindow::loadFile(const QString& fileName) {
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, tr("Read File"), tr("Cannot open the file."));
		return false;
	}
	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor); //�����״Ϊ�ȴ�
	TextEdit->setText(in.readAll());
	QApplication::restoreOverrideCursor();//�ָ����״̬
	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File loaded"), 2000);
	saveAct->setEnabled(false);
	return true;
}
void mainwindow::fileNew() {
	if (okToContinue()) {
		TextEdit->clear();
		setCurrentFile("new");
		setWindowTitle(curFile + "[*]");
		UpdateMenus();
	}
}
void mainwindow::UpdateMenus() { //���²˵���
	//��ɫ
	fmt.setForeground(Qt::black);
	//�Ӵ�
	boldAct->setChecked(false);
	fmt.setFontWeight(30);
	//б��
	italicAct->setChecked(false);
	fmt.setFontItalic(false);
	//�»���
	ulAct->setChecked(false);
	fmt.setFontUnderline(false);
	TextEdit->mergeCurrentCharFormat(fmt);
}
void mainwindow::fileOpen() {
	if (okToContinue()) {
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open"),
			QString(), tr("Normal text file (*.txt);;"
			"C++ source file (*.cpp);;HTML document (*.htm *.html);;all files(*.*)"));
		if (!fileName.isEmpty()) {
			loadFile(fileName);
		}
		else {
			QMessageBox::warning(this, tr("Path"), tr("you didn't select anything"));
		}
		UpdateMenus();
	}
}
bool mainwindow::save(const QString& fileName) {  //�����ļ�
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Save File"),
			tr("Cannot write file."));
		return false;
	}
	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out << TextEdit->document()->toHtml();
	QApplication::restoreOverrideCursor();

	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File saved"), 2000);
	saveAct->setEnabled(false);
	return true;
}
bool mainwindow::fileSave() {
	if ((!curFile.isEmpty() && curFile == "new") || curFile.isEmpty())
		return fileSaveAs();
	else
		return save(curFile);
}
bool mainwindow::fileSaveAs() {
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "./new.txt",tr("Normal text file (*.txt);;"
			"C++ source file (*.cpp);;HTML document (*.htm *.html);;all files(*.*)"));
	if (!fileName.isEmpty()) {
		return save(fileName);
	}
	else  return false;
}
void mainwindow::filePrint() {
	QPrinter printer;
	QString printerName = printer.printerName();
	if(printerName.size() == 0)	return;
	QPrintDialog printDialog(&printer,this);
	if (printDialog.exec())
	{
		QTextDocument *doc = TextEdit->document();
		doc->print(&printer);
	}
}
void mainwindow::filePrintPreview() {
	QPrinter printer;
	QPrintPreviewDialog previewDialog(&printer, this);
	connect(&previewDialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(Preview(QPrinter*)));
	previewDialog.exec();
}
void mainwindow::Preview(QPrinter *printer)
{
	TextEdit->print(printer);
}
void mainwindow::closeEvent(QCloseEvent *event) {
	if (okToContinue()) {
		event->accept();
	}
	else
	{
		event->ignore();
	}
}
void mainwindow::fileExit() {
	close();
}
void mainwindow::fileCopy() {
	TextEdit->copy();
}
void mainwindow::fileCut() {
	TextEdit->cut();
}
void mainwindow::fileUndo() {
	TextEdit->undo();
}
void mainwindow::fileRedo() {
	TextEdit->redo();
}
void mainwindow::filePaste() {
	TextEdit->paste();
}
void mainwindow::fileAbout() {
	QMessageBox::about(this, tr("About"), 
		tr("<h1>Text Editor</h1>"
			"<p>This is a simple text editor."
			"<p>"
			"<p>Gu Nan"
			"<p>2018229034"
		));
}
void mainwindow::fileColor() {
	QColor color = QColorDialog::getColor(Qt::black);
	fmt.setForeground(color);
	TextEdit->mergeCurrentCharFormat(fmt);
}
void mainwindow::fileItalic() {
	if (!italicAct->isChecked()) {
		fmt.setFontItalic(false);
	}
	else {
		fmt.setFontItalic(true);
	}
	TextEdit->mergeCurrentCharFormat(fmt);
}
void mainwindow::fileUnderline() {
	if (!ulAct->isChecked()) {
		fmt.setFontUnderline(false);
	}
	else
	{
		fmt.setFontUnderline(true);
	}
	TextEdit->mergeCurrentCharFormat(fmt);
}
void mainwindow::fileBold() {
	if (!boldAct->isChecked()) {
		fmt.setFontWeight(30);
	}
	else {
		fmt.setFontWeight(70);
	}
	TextEdit->mergeCurrentCharFormat(fmt);
}
void mainwindow::ShowTextRowCol() //״̬������ʾ�����кź��к�
{
	rowColumnLabel->setText(tr("row: %1  col: %2").arg(TextEdit->textCursor().blockNumber() + 1).
		arg(TextEdit->textCursor().columnNumber() + 1));

}
void mainwindow::createActions() { //ÿ������
	//�½��ļ�
	newAct = new QAction(tr("New"), this);
	newAct->setIcon(QIcon(":/images/new.png"));
	newAct->setShortcut(QKeySequence::New);
	newAct->setToolTip("New");
	newAct->setStatusTip("Create a new file");
	connect(newAct, SIGNAL(triggered()), this, SLOT(fileNew()));
	//���ļ�
	openAct = new QAction(QIcon(":/images/open.png"), tr("Open"), this);
	openAct->setShortcut(QKeySequence::Open);
	openAct->setToolTip("Open");
	openAct->setStatusTip("Open a file");
	connect(openAct, SIGNAL(triggered()), this, SLOT(fileOpen()));
	//����
	saveAct = new QAction(QIcon(":/images/save.png"), tr("Save"), this);
	saveAct->setShortcut(QKeySequence::Save);
	saveAct->setToolTip("Save");
	saveAct->setStatusTip("Save the file");
	connect(saveAct, SIGNAL(triggered()), this, SLOT(fileSave()));
	//���Ϊ
	save_asAct = new QAction(tr("Save As..."), this);
	save_asAct->setShortcut(QKeySequence("Ctrl+Shift+S"));
	save_asAct->setToolTip("Save As");
	save_asAct->setStatusTip("Save AS the file");
	connect(save_asAct, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
	//��ӡ
	printAct = new QAction(QIcon(":/images/print.png"), tr("Print"), this);
	printAct->setShortcut(QKeySequence::Print);
	printAct->setToolTip("Print");
	printAct->setStatusTip("Print the file");
	connect(printAct, SIGNAL(triggered()), this, SLOT(filePrint()));
	//��ӡԤ��
	printPreviewAct = new QAction(QIcon(":/images/printPreview.png"), tr("Print Preview"), this);
	printPreviewAct->setToolTip("PrintPreview");
	printPreviewAct->setStatusTip("Preview the file before print");
	connect(printPreviewAct, SIGNAL(triggered()), this, SLOT(filePrintPreview()));
	//�˳�
	exitAct = new QAction(QIcon(":/images/exit.png"), tr("Exit"), this);
	exitAct->setShortcut(tr("Esc"));
	exitAct->setToolTip("Exit");
	exitAct->setStatusTip("Exit");
	connect(exitAct, SIGNAL(triggered()), this, SLOT(fileExit()));
	//����
	undoAct = new QAction(QIcon(":/images/undo.png"), tr("Undo"), this);
	undoAct->setShortcut(QKeySequence::Undo);
	undoAct->setToolTip("Undo");
	undoAct->setStatusTip("Undo");
	connect(undoAct, SIGNAL(triggered()), this, SLOT(fileUndo()));
	//�ָ�
	redoAct = new QAction(QIcon(":/images/redo.png"), tr("Redo"), this);
	redoAct->setShortcut(QKeySequence::Redo);
	redoAct->setToolTip("Redo");
	redoAct->setStatusTip("Redo");
	connect(redoAct, SIGNAL(triggered()), this, SLOT(fileRedo()));
	//����
	cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cut"), this);
	cutAct->setShortcut(QKeySequence::Cut);
	cutAct->setToolTip("Cut");
	cutAct->setStatusTip("Cut");
	connect(cutAct, SIGNAL(triggered()), this, SLOT(fileCut()));
	//����
	copyAct = new QAction(QIcon(":/images/copy.png"), tr("Copy"), this);
	copyAct->setShortcut(QKeySequence::Copy);
	copyAct->setToolTip("Copy");
	copyAct->setStatusTip("Copy");
	connect(copyAct, SIGNAL(triggered()), this, SLOT(fileCopy()));
	//ճ��
	pasteAct = new QAction(QIcon(":/images/paste.png"), tr("Paste"), this);
	pasteAct->setShortcut(QKeySequence::Paste);
	pasteAct->setToolTip("Paste");
	pasteAct->setStatusTip("Paste");
	connect(pasteAct, SIGNAL(triggered()), this, SLOT(filePaste()));
	//�Ӵ�
	boldAct = new QAction(QIcon(":/images/bold.png"), tr("Bold"), this);
	boldAct->setShortcut(QKeySequence::Bold);
	boldAct->setToolTip("Bold");
	boldAct->setStatusTip("Bold");
	connect(boldAct, SIGNAL(triggered()), this, SLOT(fileBold()));
	//б��
	italicAct = new QAction(QIcon(":/images/italic.png"), tr("Italic"), this);
	italicAct->setShortcut(QKeySequence::Italic);
	italicAct->setToolTip("Italic");
	italicAct->setStatusTip("Italic");
	connect(italicAct, SIGNAL(triggered()), this, SLOT(fileItalic()));
	//�»���
	ulAct = new QAction(QIcon(":/images/underline.png"), tr("Underline"), this);
	ulAct->setShortcut(QKeySequence::Underline);
	ulAct->setToolTip("Underline");
	ulAct->setStatusTip("Underline");
	connect(ulAct, SIGNAL(triggered()), this, SLOT(fileUnderline()));
	//��ɫ
	colorAct = new QAction(QIcon(":/images/color.png"), tr("Color"), this);
	colorAct->setToolTip("color");
	colorAct->setStatusTip("Set color of the text");
	connect(colorAct, SIGNAL(triggered()), this, SLOT(fileColor()));
	//About
	aboutAct = new QAction(tr("About"), this);
	aboutAct->setToolTip("Aboutme");
	aboutAct->setStatusTip("About the programme");
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(fileAbout()));
	//About QT
	aboutQTAct = new QAction(QIcon(":/images/aboutQt.png"), tr("About QT"), this);
	aboutQTAct->setToolTip("AboutQT");
	aboutQTAct->setStatusTip("About QT");
	connect(aboutQTAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void mainwindow::createmenus() { //�����˵���
	menuBar = new QMenuBar;
	//�ļ��˵�
	menuFile = menuBar->addMenu(tr("&File"));
	menuFile->addAction(newAct);
	menuFile->addAction(openAct);
	menuFile-> addSeparator();
	menuFile->addAction(saveAct);
	menuFile->addAction(save_asAct);
	menuFile->addSeparator();
	menuFile->addAction(printAct);
	menuFile->addAction(printPreviewAct);
	menuFile->addSeparator();
	menuFile->addAction(exitAct);
	//�༭�˵�
	menuEdit = menuBar->addMenu(tr("&Edit"));
	menuEdit->addAction(undoAct);
	menuEdit->addAction(redoAct);
	menuEdit->addAction(cutAct);
	menuEdit->addAction(copyAct);
	menuEdit->addAction(pasteAct);
	//��ʽ�˵�
	formatEdit = menuBar->addMenu(tr("&Format"));
	QMenu *font = formatEdit->addMenu(tr("Font"));
	font->addAction(boldAct);
	font->addAction(italicAct);
	font->addAction(ulAct);
	formatEdit->addAction(colorAct);
	
	//����
	helpEdit = menuBar->addMenu(tr("&Help"));
	helpEdit->addAction(aboutAct);
	helpEdit->addAction(aboutQTAct);
	setMenuBar(menuBar);
}
void mainwindow::createToolBars() {
	mainToolBar = addToolBar(tr("main"));
	mainToolBar->addAction(newAct);
	mainToolBar->addAction(openAct);
	mainToolBar->addAction(saveAct);
	mainToolBar->addAction(printAct);
	mainToolBar->addSeparator();
	mainToolBar->addAction(undoAct);
	mainToolBar->addAction(redoAct);
	mainToolBar->addAction(cutAct);
	mainToolBar->addAction(copyAct);
	mainToolBar->addAction(pasteAct);
	mainToolBar->addSeparator();
	mainToolBar->addAction(boldAct);
	mainToolBar->addAction(italicAct);
	mainToolBar->addAction(ulAct);
	mainToolBar->addAction(colorAct);
}
void mainwindow::createContextMenu() { //����Ҽ��˵�
	TextEdit->addAction(copyAct);
	TextEdit->addAction(cutAct);
	TextEdit->addAction(pasteAct);
}
void mainwindow::createStatusBar() {
	rowColumnLabel = new QLabel(tr("row: 1   col: 1"));
	rowColumnLabel->setAlignment(Qt::AlignRight);
	rowColumnLabel->setMinimumSize(rowColumnLabel->sizeHint());
	statusBar()->addPermanentWidget(rowColumnLabel);
}

