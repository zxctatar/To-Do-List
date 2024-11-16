#include "filemanager.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

FileManager::FileManager(QObject* parent) : QObject(parent)
{

}

bool FileManager::checkFile(QString& fileDir) const // проверка файла на существование
{
    return QFile::exists(fileDir);
}

bool FileManager::fileIsEmpty(QString& fileDir) const // проверка пуст ли файл
{
    QFile file(fileDir);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug() << "Error open file FileManager->fileIsEmpty" << file.errorString();
    }

    if(file.size() == 0)
    {
        file.close();
        return true;
    }

    file.close();
    return false;
}

QJsonArray FileManager::readTaskFromFile(QString& fileDir) const // получение списка задач из файла
{
    QFile file(fileDir);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error open file FileManager->readTaskFromFile" << file.errorString();
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    return doc.array();
}

void FileManager::createJsonFile(QString& fileDir) const
{
    QFile file(fileDir);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error open file FileManager->createJsonFile" << file.errorString();
        return;
    }
    file.write("[]");
    file.close();
}

void FileManager::createNewTask(QString& fileDir, quint64 id, QString& name, QString& dateTime, QString& description, bool done) // добавление новой задачи
{
    QFile file(fileDir);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Ошибка открытия файла чтения createTask" << file.errorString();
        return;
    }

    QJsonDocument docRead = QJsonDocument::fromJson(file.readAll());
    QJsonArray tasks = docRead.array();
    file.close();

    QJsonObject recordObject;

    recordObject.insert("id", QJsonValue::fromVariant(id));
    recordObject.insert("name", QJsonValue::fromVariant(name));
    recordObject.insert("dateTime", QJsonValue::fromVariant(dateTime));
    recordObject.insert("description", QJsonValue::fromVariant(description));
    recordObject.insert("done", QJsonValue::fromVariant(done));

    tasks.append(recordObject);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        qDebug() << "Ошибка открытия файла записи createTask" << file.errorString();
        return;
    }

    QJsonDocument docWrite(tasks);

    file.write(docWrite.toJson());
    file.close();
}

void FileManager::deleteTaskInFile(quint64 id, QString& fileDir)
{
    QJsonArray array = readTaskFromFile(fileDir);

    for(int i = 0; i < array.size(); ++i)
    {
        QJsonObject obj = array[i].toObject();
        if(obj["id"].toInt() == id)
        {
            array.removeAt(i);
            updateFile(fileDir, array);
            break;
        }
    }
}

void FileManager::updateFile(QString& fileDir, QJsonArray& array)
{
    QFile file(fileDir);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        qDebug() << "Ошибка открытия файла записи updateFile" << file.errorString();
        return;
    }

    QJsonDocument docWrite(array);

    file.write(docWrite.toJson());
    file.close();
}

void FileManager::completeTaskInFile(quint64 id, QString& fileDir)
{
    QJsonArray array = readTaskFromFile(fileDir);

    for(int i = 0; i < array.size(); ++i)
    {
        QJsonObject obj = array[i].toObject();
        if(obj["id"].toInt() == id)
        {
            obj["done"] = true;
            array[i] = obj;
            updateFile(fileDir, array);
            break;
        }
    }
}

FileManager::~FileManager()
{}



