#pragma once

#include <QPoint>
#include <QVector>
#include <QChar>
#include <QString>

struct LevelMetadata {
    int width = 0;
    int height = 0;
    QPoint start{-1, -1};
    QPoint finish{-1, -1};
};

struct LevelData {
    LevelMetadata metadata;
    QVector<QVector<QChar>> tiles;
};

QString tileNameForSymbol(QChar symbol);
