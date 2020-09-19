#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpSocket>
#include <QWidget>
#include <QTcpServer>
#include <QTextEdit>
class MyServer : public QWidget
{
    Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit*  m_ptxt;
    quint16     m_nNextBlockSize; 
    
    void sendToClient(QTcpSocket* pSocket, const QString& str);
public:
    MyServer(quint16 nPort, QWidget* pwgt = 0);
public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
};

#endif // MYSERVER_H
