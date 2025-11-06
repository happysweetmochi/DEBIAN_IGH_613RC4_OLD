#ifndef SLAVE_STARTUP_WID_H
#define SLAVE_STARTUP_WID_H

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
class slave_startup_wid;
}

class slave_startup_wid : public QWidget
{
    Q_OBJECT

public:
    explicit slave_startup_wid(QWidget *parent = 0);
    ~slave_startup_wid();
    void from(slave_startup *startup);
    void settype(int type);
public slots:
    void typechanged();
    void setIndex();
    void setSubIndex();
    void setValue();
private slots:
    void on_info_clicked();

    void on_write_clicked();

private:
    slave_startup *curstartup;
    Ui::slave_startup_wid *ui;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // SLAVE_STARTUP_WID_H
