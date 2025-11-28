#include "LevelLoader.h"

#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <stdexcept>

LevelData LevelLoader::loadLevelFile(const QString &filePath) const
{
    QFile file(filePath);
    if (!file.exists()) {
        throw std::runtime_error(QStringLiteral("Missing level file: %1").arg(filePath).toStdString());
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(QStringLiteral("Cannot open level file: %1").arg(filePath).toStdString());
    }

    LevelData level = parseLevel(file);
    validateMetadata(level);
    return level;
}

LevelData LevelLoader::parseLevel(QFile &file) const
{
    LevelData level;
    QTextStream stream(&file);
    int y = 0;
    while (!stream.atEnd()) {
        const QString rawLine = stream.readLine();
        if (rawLine.trimmed().isEmpty()) {
            continue;
        }

        QVector<QChar> row;
        row.reserve(rawLine.size());
        for (int x = 0; x < rawLine.size(); ++x) {
            const QChar symbol = rawLine.at(x);
            row.append(symbol);
            if (symbol == QLatin1Char('M')) {
                level.metadata.start = QPoint(x, y);
            } else if (symbol == QLatin1Char('F')) {
                level.metadata.finish = QPoint(x, y);
            }
        }
        level.tiles.append(row);
        ++y;
    }

    if (!level.tiles.isEmpty()) {
        level.metadata.height = level.tiles.size();
        level.metadata.width = level.tiles.constFirst().size();
    }

    return level;
}

void LevelLoader::validateMetadata(LevelData &level) const
{
    if (level.metadata.width == 0 || level.metadata.height == 0) {
        throw std::runtime_error("Level data is empty after parsing");
    }

    for (const auto &row : level.tiles) {
        if (row.size() != level.metadata.width) {
            throw std::runtime_error("Inconsistent row widths detected in level definition");
        }
    }

    if (level.metadata.start == QPoint(-1, -1)) {
        level.metadata.start = QPoint(0, level.metadata.height - 1);
    }
    if (level.metadata.finish == QPoint(-1, -1)) {
        level.metadata.finish = QPoint(level.metadata.width - 1, level.metadata.height - 1);
    }
}
