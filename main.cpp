#include <QCoreApplication>

#include <memory>

#include "view.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto view = std::make_shared<View>;

    return a.exec();
}
