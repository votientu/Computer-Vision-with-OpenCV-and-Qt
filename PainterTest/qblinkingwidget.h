#ifndef QBLINKINGWIDGET_H
#define QBLINKINGWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

namespace Ui {
class QBlinkingWidget;
}

class QBlinkingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QBlinkingWidget(QWidget *parent = 0);
    ~QBlinkingWidget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void onBlink();

private:
    Ui::QBlinkingWidget *ui;
    QTimer blinkTimer;
    bool blink;
};

#endif // QBLINKINGWIDGET_H
