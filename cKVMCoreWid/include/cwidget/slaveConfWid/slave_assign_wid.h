#ifndef SLAVE_ASSIGN_WID_H
#define SLAVE_ASSIGN_WID_H

#include <QWidget>
#include <QInputDialog>
#include "include/cwidget/cVarList.h"
#ifdef __linux
    #include "../ethercatmasterConsole/etcHeader/etcheader.h"
    #include "../ethercatmasterConsole/etcHeader/jmc_axis_cmd.h"
#elif
#endif
#include "qt59to514.h"
namespace Ui {
class slave_assign_wid;
}

class slave_assign_wid : public QWidget
{
    Q_OBJECT

public:
    explicit slave_assign_wid(QWidget *parent = 0);
    ~slave_assign_wid();
    int setSize(int size);
    int setType(QString type);
    int setWD(int WD);
    int from(slave_assign *assign);
private slots:
    void on_watchDog_currentIndexChanged(int index);

private:
    Ui::slave_assign_wid *ui;
    slave_assign *curassign = nullptr;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // SLAVE_ASSIGN_WID_H
