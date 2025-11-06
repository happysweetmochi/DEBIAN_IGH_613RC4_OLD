#include "include/csoftmotion/cslavepage.h"
#include "ui_cslavepage.h"

cSlavePage::cSlavePage(QWidget *parent) :
    cBasePage(parent),
    ui(new Ui::cSlavePage)
{
    ui->setupUi(this);
}
int cSlavePage::conf(QString name,QJsonObject confObj)
{

}


int cSlavePage::init(QString name,void *arg)
{
    slavemem = (pod_config *)arg;
    if(slavemem == nullptr){
        return -1;
    }
    pod_config *pdo = slavemem;

    cBaseVar *var = nullptr;
    int pos = 0;
    int bit_Size = 0;
    for(uint i = 0; i < slavemem->inNum + slavemem->outNum ; i++){
        int size0 = pdo->info[i].bit_length / 8;


        int curOffset = bit_Size / 8;
        pos = curOffset;
        if(pdo->info[i].index == 0 && pdo->info[i].subindex == 0){

        }else{
            bit_Size = bit_Size + pdo->info[i].bit_length;
        }

        int curBitPos = bit_Size  % 8;

        qDebug() << (char *)&pdo->pdoname[i * 64] << " : " << pos;
        switch(size0){
            case 0:
                if (pdo->pdo_dir[i] == PDO_OUTPUT){
                    char *tempValue = &pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_INPUT,0,&pdo->pdoname[i * 64]);

                }else{
                    char *tempValue = &pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_OUTPUT,0,&pdo->pdoname[i * 64]);
                }
            break;
            case 1:
                if (pdo->pdo_dir[i] == PDO_OUTPUT){
                    char *tempValue = &pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_INPUT,0,&pdo->pdoname[i * 64]);
                }else{
                    char *tempValue = &pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_OUTPUT,0,&pdo->pdoname[i * 64]);
                }
            break;
            case 2:
                if (pdo->pdo_dir[i] == PDO_OUTPUT){
                    ushort *tempValue = (ushort *)&pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_INPUT,0,&pdo->pdoname[i * 64]);
                }else{
                    ushort *tempValue = (ushort *)&pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_OUTPUT,0,&pdo->pdoname[i * 64]);
                }
            break;
            case 4:
                if (pdo->pdo_dir[i] == PDO_OUTPUT){
                    uint *tempValue = (uint *)&pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_INPUT,0,&pdo->pdoname[i * 64]);
                }else{
                    uint *tempValue = (uint *)&pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_OUTPUT,0,&pdo->pdoname[i * 64]);
                }
            break;
            case 8:
                if (pdo->pdo_dir[i] == PDO_OUTPUT){
                    ulong *tempValue = (ulong *)&pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_INPUT,0,&pdo->pdoname[i * 64]);
                }else{
                    ulong *tempValue = (ulong *)&pdo->pdo_data[pos];
                    var = newCVar(tempValue ,name + "." + (char *)&pdo->pdoname[i * 64],C_OUTPUT,0,&pdo->pdoname[i * 64]);
                }
            break;
            default:
            break;
        }
        //pos = pos + size0;
    }

    ui->varList->updateListBy(name);
    return 0;
}

int cSlavePage::beforDB()
{

}
int cSlavePage::afterDB()
{

}

int cSlavePage::beforDelete()
{

}

cBasePage *cSlavePage::getNewPage()
{
    cSlavePage *page = new cSlavePage();
    return page;
}

cSlavePage::~cSlavePage()
{
    delete ui;
}
