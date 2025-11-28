#include "LevelTypes.h"

QString tileNameForSymbol(QChar symbol)
{
    switch (symbol.unicode()) {
    case 'M':
        return QStringLiteral("Mario Start");
    case 'F':
        return QStringLiteral("Finish");
    case '-':
        return QStringLiteral("Empty");
    case 'X':
        return QStringLiteral("Ground Block");
    case '#':
        return QStringLiteral("Pyramid Block");
    case 'S':
        return QStringLiteral("Brick (Normal)");
    case 'C':
        return QStringLiteral("Brick (Coin)");
    case 'L':
        return QStringLiteral("Brick (1-Up)");
    case 'U':
        return QStringLiteral("Special Brick");
    case '@':
        return QStringLiteral("Question Block (Special)");
    case '!':
        return QStringLiteral("Question Block (Coin)");
    case '2':
        return QStringLiteral("Hidden Block (Coin)");
    case '1':
        return QStringLiteral("Hidden Block (1-Up)");
    case 'D':
        return QStringLiteral("Used Block");
    case 'o':
        return QStringLiteral("Coin");
    case 't':
        return QStringLiteral("Pipe");
    case 'T':
        return QStringLiteral("Pipe with Piranha");
    case '*':
        return QStringLiteral("Bullet Bill");
    case '|':
        return QStringLiteral("Platform Background");
    case '%':
        return QStringLiteral("Platform");
    case 'g':
        return QStringLiteral("Goomba");
    case 'G':
        return QStringLiteral("Goomba (Winged)");
    case 'r':
        return QStringLiteral("Red Koopa");
    case 'R':
        return QStringLiteral("Red Koopa (Winged)");
    case 'k':
        return QStringLiteral("Green Koopa");
    case 'K':
        return QStringLiteral("Green Koopa (Winged)");
    case 'y':
        return QStringLiteral("Spiky");
    case 'Y':
        return QStringLiteral("Spiky (Winged)");
    default:
        return QStringLiteral("Unknown");
    }
}
