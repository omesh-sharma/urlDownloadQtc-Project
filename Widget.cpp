#include "Widget.h"
#include "ui_Widget.h"

#include <QFileDialog>
#include <QStandardPaths>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->downloadPushButton, &QPushButton::clicked, this, &Widget::onDownloadButtonClicked);
    connect(ui->selectTargetFolderPushButton, &QPushButton::clicked, this, &Widget::onSelectTargetFolderButtonClicked);
    connect(ui->cancelPushButton, &QPushButton::clicked, this, &Widget::onCancelButtonClicked);
    connect(&m_downloader, &Downloader::updateDownloadProgress, this, &Widget::onUpdateProgress);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onDownloadButtonClicked()
{
    m_downloader.get(ui->targetFolderLineEdit->text(), ui->urlLineEdit->text());
}

void Widget::onSelectTargetFolderButtonClicked()
{

    QString targetFolder = QFileDialog::getExistingDirectory(this,
                                                             tr("Select folder"),
                                                             QStandardPaths::writableLocation(QStandardPaths::DownloadLocation),
                                                             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->targetFolderLineEdit->setText(targetFolder);
}

void Widget::onCancelButtonClicked()
{

    m_downloader.cancelDownload();
    ui->downloadProgressBar->setMaximum(100);
    ui->downloadProgressBar->setValue(0);
}

void Widget::onUpdateProgress(qint64 bytesReceived, qint64 bytesTotal)
{

    ui->downloadProgressBar->setMaximum(bytesTotal);
    ui->downloadProgressBar->setValue(bytesReceived);
}
