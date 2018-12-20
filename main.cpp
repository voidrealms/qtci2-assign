#include <QCoreApplication>
#include <QMap>
#include <QList>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> map;
    QTextStream cin(stdin);
    QString name;
    int age;

    while (true) {
        qInfo() << "Enter a name or type quit";
        name = cin.readLine();
        if(name.toUpper() == "QUIT") break;

        qInfo() << "Enter an age:";
        age = cin.readLine().toInt();

        map[name] = age;
        qInfo() << name << " is " << age << " years old";

    }

    QList<QString> keys = map.keys();
    keys.sort();

    foreach(QString key, keys) {
        qInfo() << key << " is " << map[key] << " years old";
    }

    return a.exec();
}
