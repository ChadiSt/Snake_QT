#include "gameover.h"
#include <QFont>
#include <QString>


GameOver::GameOver()
{
    setPlainText(QString("GAME OVER"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",32));
}
