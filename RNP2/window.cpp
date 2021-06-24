#include "window.h"


Window::Window()
{
    gridLayout = new QGridLayout();
    mainText = new QLabel("Ez egy Random Name Picker Koch-Gömöri Richárd reszere");
    gridLayout->addWidget(mainText,0,0);

    //label = new QLabel("Enter Name:");
    //lineedit = new QLineEdit();
    //gridLayout->addWidget(label,0,0);
    //gridLayout->addWidget(lineedit,0,1);

    button = new QPushButton("Random Name");
    gridLayout->addWidget(button,1,0);

    welcome = new QLabel("Push the button first bruh");
    gridLayout->addWidget(welcome,2,0);
    this->setLayout(gridLayout);

    QObject::connect(button, &QPushButton::clicked, this, &Window::handleButtonClicked);
}

Window::~Window()
{
    delete label;
    delete lineedit;
    delete gridLayout;
    delete welcome;
}

void Window::handleButtonClicked()
{

    QFile inputFile(QString("names.txt"));
    inputFile.open(QIODevice::ReadOnly);

    if (!inputFile.isOpen())
    {
        welcome->setText("File not found!");
        return;
    }
    QVector<QString> stringVector;
    QAtomicInteger i=0;
    QTextStream stream(&inputFile);
    for (QString line = stream.readLine();!line.isNull();line = stream.readLine())
    {
        stringVector.push_back(line);
        i++;
    };
    welcome->setText("Your turn !" + stringVector[QRandomGenerator::global()->bounded(i)]);
    inputFile.close();
}
