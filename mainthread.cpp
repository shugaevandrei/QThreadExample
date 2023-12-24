#include "mainthread.h"
#include "additionalthread.h"
#include <QThread>
#include <QDebug>

MainThread::MainThread(QObject *parent)
    : QObject{parent}, thr_(std::make_unique<QThread>()), worker_(std::make_unique<AdditionalThread>())
{
    connect(this, &MainThread::startWork, worker_.get(), &AdditionalThread::start);
    connect(this, &MainThread::stopWork, worker_.get(), &AdditionalThread::stop);

    worker_->moveToThread(thr_.get());
    thr_->start();
}

void MainThread::start()
{
    emit startWork();
}

void MainThread::stop()
{
    emit stopWork();
}

MainThread::~MainThread() = default;
