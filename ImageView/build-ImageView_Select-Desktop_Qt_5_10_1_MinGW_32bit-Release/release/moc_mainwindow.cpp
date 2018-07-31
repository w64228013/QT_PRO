/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImageView_Select/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[482];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 31), // "on_ROIwidthlineEdit_textChanged"
QT_MOC_LITERAL(4, 68, 4), // "arg1"
QT_MOC_LITERAL(5, 73, 32), // "on_ROIheightlineEdit_textChanged"
QT_MOC_LITERAL(6, 106, 23), // "on_SetROIButton_clicked"
QT_MOC_LITERAL(7, 130, 24), // "on_SaveROIButton_clicked"
QT_MOC_LITERAL(8, 155, 29), // "on_actionOpenFolder_triggered"
QT_MOC_LITERAL(9, 185, 30), // "on_actionSetSavePath_triggered"
QT_MOC_LITERAL(10, 216, 28), // "on_ROIPrefixEdit_textChanged"
QT_MOC_LITERAL(11, 245, 41), // "on_infoBrowser_customContextM..."
QT_MOC_LITERAL(12, 287, 3), // "pos"
QT_MOC_LITERAL(13, 291, 39), // "on_ImageView_customContextMen..."
QT_MOC_LITERAL(14, 331, 23), // "on_actionDrag_triggered"
QT_MOC_LITERAL(15, 355, 21), // "on_NextButton_clicked"
QT_MOC_LITERAL(16, 377, 21), // "on_PrevButton_clicked"
QT_MOC_LITERAL(17, 399, 30), // "on_TypeBox_currentIndexChanged"
QT_MOC_LITERAL(18, 430, 24), // "on_SetROIButton_released"
QT_MOC_LITERAL(19, 455, 26) // "on_actionZoomOut_triggered"

    },
    "MainWindow\0on_actionOpen_triggered\0\0"
    "on_ROIwidthlineEdit_textChanged\0arg1\0"
    "on_ROIheightlineEdit_textChanged\0"
    "on_SetROIButton_clicked\0"
    "on_SaveROIButton_clicked\0"
    "on_actionOpenFolder_triggered\0"
    "on_actionSetSavePath_triggered\0"
    "on_ROIPrefixEdit_textChanged\0"
    "on_infoBrowser_customContextMenuRequested\0"
    "pos\0on_ImageView_customContextMenuRequested\0"
    "on_actionDrag_triggered\0on_NextButton_clicked\0"
    "on_PrevButton_clicked\0"
    "on_TypeBox_currentIndexChanged\0"
    "on_SetROIButton_released\0"
    "on_actionZoomOut_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    1,   98,    2, 0x08 /* Private */,
       6,    0,  101,    2, 0x08 /* Private */,
       7,    0,  102,    2, 0x08 /* Private */,
       8,    0,  103,    2, 0x08 /* Private */,
       9,    0,  104,    2, 0x08 /* Private */,
      10,    1,  105,    2, 0x08 /* Private */,
      11,    1,  108,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    1,  117,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_ROIwidthlineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_ROIheightlineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_SetROIButton_clicked(); break;
        case 4: _t->on_SaveROIButton_clicked(); break;
        case 5: _t->on_actionOpenFolder_triggered(); break;
        case 6: _t->on_actionSetSavePath_triggered(); break;
        case 7: _t->on_ROIPrefixEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_infoBrowser_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->on_ImageView_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->on_actionDrag_triggered(); break;
        case 11: _t->on_NextButton_clicked(); break;
        case 12: _t->on_PrevButton_clicked(); break;
        case 13: _t->on_TypeBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_SetROIButton_released(); break;
        case 15: _t->on_actionZoomOut_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "rectangle"))
        return static_cast< rectangle*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
