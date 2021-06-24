#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QString>
#include <QAtomicInteger>
#include <QRandomGenerator>
#include <QIODevice>

class Window : public QWidget
{
    Q_OBJECT
public:
    Window();
    ~Window();

private:
    QLabel* label;
    QLabel* mainText;
    QLabel* welcome;
    QLineEdit* lineedit;
    QPushButton* button;
    QGridLayout* gridLayout;
private slots:
    void handleButtonClicked();

};
#endif // WINDOW_H
