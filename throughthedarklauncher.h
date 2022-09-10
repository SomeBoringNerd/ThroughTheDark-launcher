#ifndef THROUGHTHEDARKLAUNCHER_H
#define THROUGHTHEDARKLAUNCHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ThroughTheDarkLauncher; }
QT_END_NAMESPACE

class ThroughTheDarkLauncher : public QMainWindow
{
    Q_OBJECT

public:
    ThroughTheDarkLauncher(QWidget *parent = nullptr);
    ~ThroughTheDarkLauncher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::ThroughTheDarkLauncher *ui;
};
#endif // THROUGHTHEDARKLAUNCHER_H
