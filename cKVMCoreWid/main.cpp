#include "ctoolswid.h"

#include <QApplication>




int main(int argc, char *argv[])
{
    qputenv("QT_LOGGING_RULES", "qt.widgets.stylesheet=false"); // 关闭样式表警告
    QApplication a(argc, argv);
    cToolsWid w;
    w.show();


    return a.exec();
}
