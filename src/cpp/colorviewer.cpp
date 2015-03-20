
#include "colorviewer.h"
#include "paintarea.h"
#include <QColorDialog>

#include <QSettings>
#include <QScrollArea>
#include <QTextCodec>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QTimer>
#include <QToolBar>
#include <QInputDialog>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QStatusBar>
#include <QPluginLoader>

ColorViewer::ColorViewer(QWidget *parent)
    : QWidget(parent),
        paintArea(new PaintArea)
{

    setMinimumSize(100, 100);

}

ColorViewer::~ColorViewer()
{
}

void ColorViewer::paintEvent(QPaintEvent *event)
{

    QPainter p(this);
    p.setPen(actualPen);
    p.setBrush(QBrush(actualColor));
    p.drawRect( QRect( 2, 2, width()-4, height()-4 ) );
      event->accept();
}

void ColorViewer::setPen(const QPen &pen)
{
    actualPen = pen;
}

QPen ColorViewer::pen() const
{
    return actualPen;
}

void ColorViewer::setColor(const QColor &color)
{
    actualColor = color;



}
QColor ColorViewer::color() const
{
    return actualColor;
}


void ColorViewer::changeColor(const QColor &color)
{
    actualColor = color;

    update();
}



