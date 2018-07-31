#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <QObject>
#include <QFileDialog>
#include <QStandardPaths>
#include <QStandardPaths>
#include <QMessageBox>
#include <QImageReader>
#include <QImageWriter>
#include <QGuiApplication>
#include <QDebug>


class ImageReader : public QWidget
{
    Q_OBJECT
public:
    explicit ImageReader(QWidget *parent = nullptr);

    void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode);

    QString getBasicPath()const{return basicPath;}
    template<typename Pfiletype>
    bool loadFile(const QString &fileName,Pfiletype *storage){
        QImageReader reader(fileName);
        reader.setAutoTransform(true);
        *storage = reader.read();
        if (storage->isNull()) {
            QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                     tr("Cannot load %1: %2")
                                     .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
            return false;
        }
        return true;
    }

    QString getFilePath();
    QString getFolderPath();

signals:

public slots:

private:
    QString basicPath = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0);
};

#endif // IMAGEREADER_H
