#pragma once

#include <QObject>
#include <memory>

class QElapsedTimer;
class QEventLoop;

class AdditionalThread : public QObject
{
    Q_OBJECT

public:
    explicit AdditionalThread(QObject *parent = nullptr);
    ~AdditionalThread();

public slots:
    void start();
    void stop();

private:
    std::unique_ptr<QElapsedTimer> et_;
    std::unique_ptr<QEventLoop> eventLoop_;

    bool run_ = false;
};

