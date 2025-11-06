
#include "ethercatmaster.h"
//#include "ui_ethercatmaster.h"
#include <sys/inotify.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <fstream>



#include <QVector>


slave_pdo conf_pdo(uint index,uint sub_index,uint size,QString info)
{
    slave_pdo tempPdo;
    tempPdo.index = index;
    tempPdo.sub_index = sub_index;
    tempPdo.size = size;
    tempPdo.info = info;
    return tempPdo;
}



slave_config slave_change_to_axisslave()
{
    slave_config slave;

    slave.MbxOut.index.clear();
    slave.MbxIn.index.clear();
    slave.output.index.clear();
    slave.output.WD = 1;
    slave.input.index.clear();
    slave.input.WD = 1;

    slave_index out_1600;
    out_1600.index = 0x1600;
    out_1600.info = "servo_1600";
    out_1600.pdo.append(conf_pdo(0x6040,0x00,16,"ctrl_word"));
    out_1600.pdo.append(conf_pdo(0x6060,0x00,8,"operation_mode"));
    out_1600.pdo.append(conf_pdo(0x607A,0x00,32,"target_position"));
    out_1600.pdo.append(conf_pdo(0x6071,0x00,16,"target_torque"));
    out_1600.pdo.append(conf_pdo(0x60FE,0x01,32,"digital_outputs"));
    slave.output.index.append(out_1600);

    slave_index in_1A00;
    in_1A00.index = 0x1A00;
    in_1A00.info = "servo_1A00";
    in_1A00.pdo.append(conf_pdo(0x603F,0x00,16,"error_code"));
    in_1A00.pdo.append(conf_pdo(0x6041,0x00,16,"status_word"));
    in_1A00.pdo.append(conf_pdo(0x6061,0x00,8,"modes_of_operation_display"));
    in_1A00.pdo.append(conf_pdo(0x6064,0x00,32,"position_actual_value"));
    in_1A00.pdo.append(conf_pdo(0x6077,0x00,16,"torque_actual_velue"));
    in_1A00.pdo.append(conf_pdo(0x60F4,0x00,32,"following_error_actual_value"));
    in_1A00.pdo.append(conf_pdo(0x60FD,0x00,32,"digital_inputs"));
    slave.input.index.append(in_1A00);
    return slave;
    //QMessageBox::information(this,"通知","切换为伺服成功",QMessageBox::Yes | QMessageBox::No);
}

 slave_config slave_change_to_sscio()
 {
     slave_config slave;


     slave.MbxOut.index.clear();
     slave.MbxIn.index.clear();
     slave.output.index.clear();
     slave.output.WD = 1;
     slave.input.index.clear();
     slave.input.WD = 1;


     slave_index out_1601;
     out_1601.index = 0x1601;
     out_1601.info = "servo_1601";
     out_1601.pdo.append(conf_pdo(0x7010,0x01,1,"LED1"));
     out_1601.pdo.append(conf_pdo(0x7010,0x02,1,"LED2"));
     out_1601.pdo.append(conf_pdo(0x7010,0x03,1,"LED3"));
     out_1601.pdo.append(conf_pdo(0x7010,0x04,1,"LED4"));
     out_1601.pdo.append(conf_pdo(0x7010,0x05,1,"LED5"));
     out_1601.pdo.append(conf_pdo(0x7010,0x06,1,"LED6"));
     out_1601.pdo.append(conf_pdo(0x7010,0x07,1,"LED7"));
     out_1601.pdo.append(conf_pdo(0x7010,0x08,1,"LED8"));
     out_1601.pdo.append(conf_pdo(0x7010,0x00,8,"Gap"));
     slave.output.index.append(out_1601);

     slave_index in_1A00;
     in_1A00.index = 0x1A00;
     in_1A00.info = "servo_1A00";
     in_1A00.pdo.append(conf_pdo(0x6000,0x01,1,"SW1"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x02,1,"SW2"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x03,1,"SW3"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x04,1,"SW4"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x05,1,"SW5"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x06,1,"SW6"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x07,1,"SW7"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x08,1,"SW8"));
     in_1A00.pdo.append(conf_pdo(0x6000,0x00,8,"Gap"));
     slave.input.index.append(in_1A00);

     slave_index in_1A02;
     in_1A02.index = 0x1A02;
     in_1A02.info = "servo_1A00";
     in_1A02.pdo.append(conf_pdo(0x6020,0x01,1,"UnderRage"));
     in_1A02.pdo.append(conf_pdo(0x6020,0x02,1,"OverRage"));
     in_1A02.pdo.append(conf_pdo(0x6020,0x03,2,"Limit1"));
     in_1A02.pdo.append(conf_pdo(0x6020,0x05,2,"Limit2"));
     in_1A02.pdo.append(conf_pdo(0x6020,0x00,8,"Gap"));
     in_1A02.pdo.append(conf_pdo(0x1802,0x07,1,"TxPdoState"));
     in_1A02.pdo.append(conf_pdo(0x1802,0x09,1,"TxPdoToggle"));
     in_1A02.pdo.append(conf_pdo(0x6020,0x11,16,"ADIn"));

     slave.input.index.append(in_1A02);

     return slave;
     //cBaseVar::insertLog(1,slave->name,"切换为成功");
     //QMessageBox::information(this,"通知","切换为SSCIO成功",QMessageBox::Yes | QMessageBox::No);
 }



 int JSON_Save(QString path , QVector<slave_config> slave_vec , QVector<axis_config> axes_vec)
 {
     QFile file(path);
     bool ret = file.open(QIODevice::WriteOnly);

     QJsonObject vec_obj;
     ret = etc_vector2json("",&slave_vec,&vec_obj);
     if (ret != 0){
         return -1;
     }

     ret = axis_vector2json("",&axes_vec,&vec_obj);
     if (ret != 0){

         return -1;
     }
     QJsonDocument jsonDoc;
     jsonDoc.setObject(vec_obj);
     //jsonDoc.
     file.write(jsonDoc.toJson(QJsonDocument::Compact));
     file.flush();
     file.close();

     return 0;
 }




void EtherCatMaster::autoCOnfig()
{
    QVector<slave_config> slaves;
    QVector<axis_config> axes;
    ec_master *master0 = ecrt_open_master(0);
    for(int i = 0; i < MAX_SLAVE;i++){
        ec_slave_info_t info;
        slave_config slave;
        axis_config axis;
        int ret = ecrt_master_get_slave(master0,i,&info);
        if(ret != 0){
            break;
        }
        slave.name = "slave-" + QString::number(i);
        slave.position = i;
        if(info.vendor_id == 0x9 && info.product_code == 0x26483052){
            slave = slave_change_to_sscio();
            qDebug() << "no." << i << "slaves : " << "SSCIO";
        }else{
            slave = slave_change_to_axisslave();
            axis.name = "slave-" + QString::number(i) + "-axis";
            axis.pdoNo = i + 1 ;
            axis.enc_ratio = 1048576;
            axis.circle_diff = 1;
            axes.append(axis);
            qDebug() << "no." << i << "slaves : " << "axis";
        }
        slave.name = "slave-" + QString::number(i);
        slave.position = i;
        slave.pid = info.product_code;
        slave.vid = info.vendor_id;
        slave.alias = info.alias;
        slaves.append(slave);
    }

    JSON_Save("/home/etcConfig/config.json" , slaves,axes);
    qDebug() << "save " << "/home/etcConfig/config.json : " ;

}











//void ethercatwid::on_auto_config_clicked()
//{
//    QMessageBox::StandardButton result = QMessageBox::warning(this,"警告","将会覆盖所有PID,VID,ALIAS参数",QMessageBox::Yes | QMessageBox::No);
//    if(result == QMessageBox::No){
//        return;
//    }
//    ec_master *master = ecrt_open_master(0);
//    if(master == nullptr){
//        cBaseVar::insertLog(-1,"","打开主站失败");
//        return;
//    }

//    for(int i = 0; i < ui->slaveTable->rowCount();i++){
//        ec_slave_info_t info;
//        int ret = ecrt_master_get_slave(master,i,&info);
//        if(ret != 0){
//            cBaseVar::insertLog(-1,"","PDO配置于实际链接个数不符");
//            return;
//        }
//        ui->slaveTable->setCurrentItem(ui->slaveTable->item(i,0));
//        slave_config *config = get_Slave();
//        if(config == nullptr){
//            cBaseVar::insertLog(-1,"","找不到从站 - " + ui->slaveTable->item(i,0)->text());
//            return;
//        }
//        config->alias = info.alias;
//        config->pid = info.product_code;
//        config->vid = info.vendor_id;
//        cBaseVar::insertLog(1,ui->slaveTable->item(i,0)->text(),"配置完成 ");


//    }
//}
