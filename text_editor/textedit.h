#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

class textedit :public QTextEdit{
	Q_OBJECT
public:
	textedit(QWidget * parent = nullptr);
	QTextEdit *TextEdit;
};

#endif
