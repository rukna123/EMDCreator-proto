/*  exmplayer, GUI front-end for mplayer.
    Copyright (C) 2010-2015 Rupesh Sreeraman

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef RPHSLIDER_H
#define RPHSLIDER_H

#include <QSlider>

class rphSlider : public QSlider
{
Q_OBJECT
public:
    rphSlider( QWidget  *parent = 0);
int pressedControl;
signals:
void sliderPressed(QString val, QPoint *pt);
void hoverValue(QString val,QPoint *pt);
void hidetooltip();
void  showtooltip(QPoint *pt);
protected:

void enterEvent ( QEvent * event );
void leaveEvent ( QEvent * event );
void mousePressEvent ( QMouseEvent * event );
void mouseMoveEvent(QMouseEvent *event);
void mouseReleaseEvent(QMouseEvent *ev);
inline int pick(const QPoint &pt) const;
int pixelPosToRangeValue(int pos) const;
void  wheelEvent ( QWheelEvent * event );

private:
QPoint *pt;
};

#endif // RPHSLIDER_H
