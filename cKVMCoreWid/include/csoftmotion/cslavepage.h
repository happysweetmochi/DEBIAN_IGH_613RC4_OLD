#ifndef CSLAVEPAGE_H
#define CSLAVEPAGE_H
#include <QWidget>
#include "include/cwidget/cbasepage.h"

#ifdef __linux
    #include "../ethercatmasterConsole/etcHeader/etcheader.h"
    #include "../ethercatmasterConsole/etcHeader/jmc_axis_cmd.h"
#elif
#endif

namespace Ui {
class cSlavePage;
}

class cSlavePage : public cBasePage
{
    Q_OBJECT

public:
    explicit cSlavePage(QWidget *parent = nullptr);
    ~cSlavePage();
    virtual int conf(QString name,QJsonObject confObj);

    virtual int init(QString name,void *arg);

    virtual int beforDB();
    virtual int afterDB();

    virtual int beforDelete();

    pod_config  *slavemem = nullptr;
    static cBasePage *getNewPage();

private:
    Ui::cSlavePage *ui;
};

#endif // CSLAVEPAGE_H
