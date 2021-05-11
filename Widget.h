#ifndef WIDGET_H
#define WIDGET_H

#include "Downloader.h"

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void onDownloadButtonClicked();


    void onSelectTargetFolderButtonClicked();


    void onCancelButtonClicked();


    void onUpdateProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    Ui::Widget *ui;
    Downloader m_downloader;
};
#endif // WIDGET_H
