/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[24];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainwindow"
QT_MOC_LITERAL(1, 11, 7), // "fileNew"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "fileOpen"
QT_MOC_LITERAL(4, 29, 8), // "fileSave"
QT_MOC_LITERAL(5, 38, 10), // "fileSaveAs"
QT_MOC_LITERAL(6, 49, 9), // "filePrint"
QT_MOC_LITERAL(7, 59, 16), // "filePrintPreview"
QT_MOC_LITERAL(8, 76, 8), // "fileExit"
QT_MOC_LITERAL(9, 85, 8), // "fileUndo"
QT_MOC_LITERAL(10, 94, 8), // "fileRedo"
QT_MOC_LITERAL(11, 103, 7), // "fileCut"
QT_MOC_LITERAL(12, 111, 8), // "fileCopy"
QT_MOC_LITERAL(13, 120, 9), // "filePaste"
QT_MOC_LITERAL(14, 130, 9), // "fileAbout"
QT_MOC_LITERAL(15, 140, 9), // "fileColor"
QT_MOC_LITERAL(16, 150, 10), // "fileItalic"
QT_MOC_LITERAL(17, 161, 13), // "fileUnderline"
QT_MOC_LITERAL(18, 175, 8), // "fileBold"
QT_MOC_LITERAL(19, 184, 12), // "textModified"
QT_MOC_LITERAL(20, 197, 14), // "ShowTextRowCol"
QT_MOC_LITERAL(21, 212, 7), // "Preview"
QT_MOC_LITERAL(22, 220, 9), // "QPrinter*"
QT_MOC_LITERAL(23, 230, 7) // "printer"

    },
    "mainwindow\0fileNew\0\0fileOpen\0fileSave\0"
    "fileSaveAs\0filePrint\0filePrintPreview\0"
    "fileExit\0fileUndo\0fileRedo\0fileCut\0"
    "fileCopy\0filePaste\0fileAbout\0fileColor\0"
    "fileItalic\0fileUnderline\0fileBold\0"
    "textModified\0ShowTextRowCol\0Preview\0"
    "QPrinter*\0printer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    0,  126,    2, 0x08 /* Private */,
      15,    0,  127,    2, 0x08 /* Private */,
      16,    0,  128,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    0,  131,    2, 0x08 /* Private */,
      20,    0,  132,    2, 0x08 /* Private */,
      21,    1,  133,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainwindow *_t = static_cast<mainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileNew(); break;
        case 1: _t->fileOpen(); break;
        case 2: { bool _r = _t->fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->filePrint(); break;
        case 5: _t->filePrintPreview(); break;
        case 6: _t->fileExit(); break;
        case 7: _t->fileUndo(); break;
        case 8: _t->fileRedo(); break;
        case 9: _t->fileCut(); break;
        case 10: _t->fileCopy(); break;
        case 11: _t->filePaste(); break;
        case 12: _t->fileAbout(); break;
        case 13: _t->fileColor(); break;
        case 14: _t->fileItalic(); break;
        case 15: _t->fileUnderline(); break;
        case 16: _t->fileBold(); break;
        case 17: _t->textModified(); break;
        case 18: _t->ShowTextRowCol(); break;
        case 19: _t->Preview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainwindow.data,
      qt_meta_data_mainwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
