#include <QtNetwork>
#include "sms.h"


QString twilio_phone_number = "+13344012030";   // t7ott num elli me twilio


sms::sms(){

}
void sms::sendSMS(const QString &to, const QString &message) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC43ebf291f3dd4ca994586b7d46ea5826/Messages.json"); // hne fi 3outh l we7dt7ott SID te3 compte twilio
    QNetworkRequest request(url);

//  /// ////////////////////////////////////////////////////////////////////// fi 3oth 1 t7ot SID w 2 t7ot Token
    QString credentials = "AC43ebf291f3dd4ca994586b7d46ea5826:7a9502cfd6fbadc357663b2d04a7a260";
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);


    QByteArray postData;
    postData.append("From="+twilio_phone_number);
    postData.append("&To=" + to);
    postData.append("&Body=" + message);


    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Make the request
    QNetworkReply *reply = manager->post(request, postData);


    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS sent successfully";
        } else {
            qDebug() << "Failed to send SMS:" << reply->errorString();
        }


        reply->deleteLater();
        manager->deleteLater();
    });
}
