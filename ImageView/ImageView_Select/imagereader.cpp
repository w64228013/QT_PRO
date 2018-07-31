#include "imagereader.h"

ImageReader::ImageReader(QWidget *parent)
    : QWidget(parent)
{

}

void ImageReader::initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();

    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);

    /*all file*/
    mimeTypeFilters.append("application/octet-stream");

    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");

    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

QString ImageReader::getFilePath()
{
    QFileDialog dialog(this, tr("Open File"));

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = QImageReader::supportedMimeTypes();

    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);

    /*all file*/
    mimeTypeFilters.append("application/octet-stream");

    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");

    dialog.setDirectory(basicPath);

//    connect(&dialog,&QDialog::rejected,[=](){
//        qDebug()<<"111111";
//    });

    dialog.exec();

    if(dialog.selectedFiles().isEmpty()){
        return NULL;
    }

    QString tempPath = dialog.selectedFiles().first();
    basicPath = tempPath;
    return  tempPath;
}

QString ImageReader::getFolderPath()
{
    QString tempPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                basicPath,
                                QFileDialog::ShowDirsOnly
                                | QFileDialog::DontResolveSymlinks);
    return  tempPath;
}
