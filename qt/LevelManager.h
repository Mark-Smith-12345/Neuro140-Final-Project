#pragma once

#include "LevelLoader.h"

#include <QDir>
#include <QObject>
#include <QStringList>

class LevelManager : public QObject
{
    Q_OBJECT
public:
    explicit LevelManager(const QDir &levelDirectory, QObject *parent = nullptr);

    QStringList availableLevels() const;
    LevelData loadLevel(const QString &levelName) const;
    QString describeTile(QChar symbol) const;

    const QDir &directory() const { return m_directory; }

private:
    QDir m_directory;
    LevelLoader m_loader;
};
