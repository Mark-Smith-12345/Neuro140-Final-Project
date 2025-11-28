#include "LevelManager.h"

#include <QFileInfo>
#include <QRegularExpression>
#include <algorithm>

LevelManager::LevelManager(const QDir &levelDirectory, QObject *parent)
    : QObject(parent), m_directory(levelDirectory)
{
}

QStringList LevelManager::availableLevels() const
{
    const QStringList filters{QStringLiteral("lvl-*.txt"), QStringLiteral("*.txt")};
    QStringList candidates;
    for (const QString &filter : filters) {
        const QFileInfoList files = m_directory.entryInfoList(QStringList{filter}, QDir::Files, QDir::Name);
        for (const QFileInfo &info : files) {
            candidates.append(info.fileName());
        }
    }
    candidates.removeDuplicates();

    std::sort(candidates.begin(), candidates.end(), [](const QString &a, const QString &b) {
        return a.localeAwareCompare(b) < 0;
    });
    return candidates;
}

LevelData LevelManager::loadLevel(const QString &levelName) const
{
    QFileInfo info(levelName);
    QString targetName = info.fileName();
    if (!info.completeSuffix().contains(QStringLiteral("txt"))) {
        targetName.append(QStringLiteral(".txt"));
    }

    const QString absolutePath = m_directory.filePath(targetName);
    return m_loader.loadLevelFile(absolutePath);
}

QString LevelManager::describeTile(QChar symbol) const
{
    return tileNameForSymbol(symbol);
}
