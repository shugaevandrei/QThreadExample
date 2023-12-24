#pragma once
#include <QObject>
#include <memory>


class QThread;
class AdditionalThread;

class MainThread : public QObject
{
    Q_OBJECT
public:
    explicit MainThread(QObject *parent = nullptr);
    ~MainThread();

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void startWork();
    void stopWork();

private:
    std::unique_ptr<QThread> thr_;
    std::unique_ptr<AdditionalThread> worker_;
};

