#include "LevelManager.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const QString directoryPath = argc > 1 ? QString::fromLocal8Bit(argv[1])
                                            : QStringLiteral("../Mario-AI-Framework/levels/original");
    const QString levelName = argc > 2 ? QString::fromLocal8Bit(argv[2]) : QStringLiteral("lvl-1.txt");

    LevelManager manager(QDir(directoryPath));
    try {
        const LevelData data = manager.loadLevel(levelName);
        qInfo() << "Loaded level" << levelName
                << "(" << data.metadata.width << "x" << data.metadata.height << ")";
        qInfo() << "Start tile:" << data.metadata.start << "Finish tile:" << data.metadata.finish;
        qInfo() << "Available tiles: " << manager.availableLevels();

        if (!data.tiles.isEmpty()) {
            const QChar firstSymbol = data.tiles.constFirst().constFirst();
            qInfo() << "Top-left tile" << firstSymbol << "->" << manager.describeTile(firstSymbol);
        }
    } catch (const std::exception &ex) {
        qCritical() << "Failed to load level:" << ex.what();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
