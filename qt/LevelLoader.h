#pragma once

#include "LevelTypes.h"

#include <QFile>
#include <QString>

class LevelLoader
{
public:
    LevelData loadLevelFile(const QString &filePath) const;

private:
    LevelData parseLevel(QFile &file) const;
    void validateMetadata(LevelData &level) const;
};
