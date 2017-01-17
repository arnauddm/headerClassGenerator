#ifndef CODE_HPP
#define CODE_HPP

#include <QDialog>

namespace Ui {
class Code;
}

class Code : public QDialog
{
    Q_OBJECT

public:
    explicit Code(QString code, QWidget *parent = 0);
    ~Code();

private:
    Ui::Code *ui;
};

#endif // CODE_HPP
