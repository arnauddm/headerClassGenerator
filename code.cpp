#include "code.hpp"
#include "ui_code.h"

Code::Code(QString code, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Code)
{
    ui->setupUi(this);

    connect(this->ui->close, SIGNAL(clicked(bool)), this, SLOT(close()));

    this->ui->codeEditor->setPlainText(code);
}

Code::~Code()
{
    delete ui;
}
