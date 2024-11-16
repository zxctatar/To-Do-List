#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QString>
#include <QJsonArray>

class FileManager : public QObject
{
    Q_OBJECT

public:
    explicit FileManager(QObject* parent = nullptr);

    bool checkFile(QString& fileDir) const; // проверка файла на существование
    bool fileIsEmpty(QString& fileDir) const; // проверка пуст ли файл
    void createJsonFile(QString& fileDir) const; // создание Json файла
    void createNewTask(QString& fileDir, quint64 id, QString& name, QString& dateTime, QString& description, bool done); // добавление новой задачи
    void updateFile(QString& fileDir, QJsonArray& array);

    QJsonArray readTaskFromFile(QString& fileDir) const; // получение списка задач из файла

    ~FileManager();

public slots:
    void deleteTaskInFile(quint64 id, QString& fileDir);
    void completeTaskInFile(quint64 id, QString& fileDir);
};



#endif // FILEMANAGER_H
