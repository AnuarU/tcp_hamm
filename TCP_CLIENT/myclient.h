#ifndef MYCLIENT_H
#define MYCLIENT_H
#include <QTcpSocket>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>

class MyClient : public QWidget
{
    Q_OBJECT
public:
    QTcpSocket* m_pTcpSocket;
    QTextEdit*  m_ptxtInfo;
    QLineEdit*  m_ptxtInput;
    quint16     m_nNextBlockSize;
    MyClient(const QString& strHost, quint16 nPort, QWidget* pwgt = nullptr);
private slots:
    void slotReadyRead   ();
    void slotError       (QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected   ();
};

#endif // MYCLIENT_H
