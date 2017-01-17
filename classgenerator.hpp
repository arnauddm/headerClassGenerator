#ifndef CLASSGENERATOR_HPP
#define CLASSGENERATOR_HPP

#include "code.hpp"

#include <QMainWindow>

namespace Ui {
class classGenerator;
}

class classGenerator : public QMainWindow
{
    Q_OBJECT

public:
    explicit classGenerator(QWidget *parent = 0);
    ~classGenerator();

private:
    Ui::classGenerator *ui;

private slots:
    void generate();
};

#endif // CLASSGENERATOR_HPP
