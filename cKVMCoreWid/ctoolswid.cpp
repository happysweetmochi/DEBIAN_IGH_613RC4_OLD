#include "ctoolswid.h"
#include "ui_ctoolswid.h"
#include "include/cwidget/cresdock.h"

#include <QMessageBox>


#include "include/csoftmotion/cethercatpage.h"

#include "include/csoftmotion/caxispage.h"
#include "include/csoftmotion/cslavepage.h"


#include "include/cwidget/chardwareconf.h"
cToolsWid::cToolsWid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cToolsWid)
{
    ui->setupUi(this);
    //rootVar.fullName = "运动控制后台2.0";

    cVarZeroMQ mq0;
    mq0.listenPort(14514);

    QAction *act0 = new QAction();
    newCVar(act0,"0网络测试.触发",C_INPUT,0,"网络测试.触发");

    QObject::connect(act0, &QAction::triggered, [=]() {
        qDebug() << "act0";
        cBaseVar::connectRemoteServer("tcp://localhost:14515");
    });
    for(int i = 0 ; i < 100000;i++){
        //newCVar(&testDouble[i],"网络测试.double-" + QString::number(i),C_INPUT,0,"网络测试.double-" + QString::number(i));
    }
    cResDock *resDoc = new cResDock();

    pageCreater creater;
    creater.func = cEtherCATPage::getNewPage;
    creater.resName = "EtherCAT";
    resDoc->regPageCreater(creater);


    creater.func = cAxisPage::getNewPage;
    creater.resName = "Axis";
    resDoc->regPageCreater(creater);


    creater.func = cSlavePage::getNewPage;
    creater.resName = "Slave";
    resDoc->regPageCreater(creater);


    creater.func = cHardWareConf::getNewPage;
    creater.resName = "hardwareconf";
    resDoc->regPageCreater(creater);

//    QJsonObject obj =  resDoc->getBaseObj();
//    resDoc->addNode(obj, nullptr);
//    if(resDoc->resHash.find("EtherCAT")  != resDoc->resHash.end()){
//        resDoc->resHash["EtherCAT"].page->init("EtherCAT" , nullptr);
//    }


    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea , resDoc);

    resDoc->defaultStart();


    ui->mainTab->setTabsClosable(true);

    // 启用滚动功能
    ui->mainTab->tabBar()->setUsesScrollButtons(true); // 启用滚动按钮

    //resDoc->

    // 处理关闭按钮点击事件
    QObject::connect(ui->mainTab, &QTabWidget::tabCloseRequested, [&](int index) {
        ui->mainTab->removeTab(index);
        return;
        int ret = QMessageBox::question(
            this,
            "关闭标签页",
            QString("确定要关闭标签页 '%1' 吗？").arg(ui->mainTab->tabText(index)),
            QMessageBox::Yes | QMessageBox::No);

        if (ret == QMessageBox::Yes) {
            ui->mainTab->removeTab(index); // 移除对应索引的标签页
        }
    });

    connect(resDoc,&cResDock::showNewPage,this,&cToolsWid::showPage);


    connect(ui->showVarList,&QAction::triggered,&varList,&cVarList::show);
}
void cToolsWid::showPage(cBasePage *page)
{
    if(page == nullptr){
        return;
    }
    QStringList nameList = page->name.split(".");
    ui->mainTab->addTab((QWidget *)page,nameList.last());
    ui->mainTab->setCurrentWidget((QWidget *)page);
}

void cToolsWid::closeEvent(QCloseEvent *e)
{
    QMessageBox::StandardButtons ret = QMessageBox::information(this,"警告","是否关闭控制程序",QMessageBox::Yes,QMessageBox::No);
    if(ret == QMessageBox::No){
        e->ignore();
        return;
    }

    sleep(2);
    close();

}

cToolsWid::~cToolsWid()
{
    delete ui;
}

