/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      49,   44,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     158,  152,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     200,  152,   11,   11, 0x08,
     226,  220,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     270,   11,   11,   11, 0x08,
     298,   11,   11,   11, 0x08,
     314,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0search_product()\0"
    "sort_results()\0text\0select_user_combo(QString)\0"
    "select_user_button()\0add_product_to_cart()\0"
    "view_user_cart()\0buy_user_cart()\0index\0"
    "cart_index_select(int)\0remove_from_cart()\0"
    "display_review(int)\0state\0sort_reviews(int)\0"
    "add_product_review_main()\0"
    "add_product_review_window()\0save_database()\0"
    "quit_program()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->search_product(); break;
        case 1: _t->sort_results(); break;
        case 2: _t->select_user_combo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->select_user_button(); break;
        case 4: _t->add_product_to_cart(); break;
        case 5: _t->view_user_cart(); break;
        case 6: _t->buy_user_cart(); break;
        case 7: _t->cart_index_select((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->remove_from_cart(); break;
        case 9: _t->display_review((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->sort_reviews((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->add_product_review_main(); break;
        case 12: _t->add_product_review_window(); break;
        case 13: _t->save_database(); break;
        case 14: _t->quit_program(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
