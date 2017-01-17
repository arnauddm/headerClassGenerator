#include "classgenerator.hpp"
#include "ui_classgenerator.h"

classGenerator::classGenerator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::classGenerator)
{
    ui->setupUi(this);

    connect(this->ui->generate, SIGNAL(clicked(bool)), this, SLOT(generate()));
    connect(this->ui->quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

classGenerator::~classGenerator()
{
    delete ui;
}

void classGenerator::generate() {
    QString code;

    if(this->ui->addCommentary->isChecked()) {
        code += "/*\n";
        code += "Auteur : " + this->ui->editor->text() + "\n";
        code += "Date de création : " + this->ui->date->date().toString() + "\n";
        code += "\n";
        code += "Description : \n" + this->ui->explanation->toPlainText() + "\n";
        code += "*/\n\n\n";
    }

    if(this->ui->antiMultiInclude->isChecked()) {
        code += "#ifndef " + this->ui->className->text().toUpper() + "_HPP\n";
    }

    code += "#define " + this->ui->className->text().toUpper() + "_HPP\n\n\n";

    code += "class " + this->ui->className->text();

    if(!this->ui->heritedClass->text().isEmpty()) {
        code += " : public " + this->ui->heritedClass->text() + " ";
    }

    code += "{\n";
    code += "   public:\n";

    if(this->ui->constructor->isChecked()) {
        code += "       " + this->ui->className->text() + "();\n";
    }

    if(this->ui->destructor->isChecked()) {
        code += "       ~" + this->ui->className->text() + "();\n";
    }

    code += "\n\n\n";
    code += "   Protected:\n";
    code += "\n\n\n";
    code += "   Private:\n";
    code += "\n\n\n";
    code += "}";
    code += "\n\n";

    if(this->ui->antiMultiInclude->isChecked()) {
        code += "#endif //" + this->ui->className->text().toUpper() + "_HPP";
    }

    Code *codeEditor = new Code(code);
    codeEditor->show();

}
