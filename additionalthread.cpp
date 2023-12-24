#include "additionalthread.h"

#include <QElapsedTimer>
#include <QDebug>
#include <QEventLoop>

AdditionalThread::AdditionalThread(QObject *parent)
    : QObject{parent}, et_(std::make_unique<QElapsedTimer>()),
      eventLoop_(std::make_unique<QEventLoop>())
{}

AdditionalThread::~AdditionalThread() = default;

void AdditionalThread::start()
{
    run_ = true;
    while(run_){
        /* useful work*/
        et_->start();
        while(et_->elapsed() < 1000){}
        eventLoop_->processEvents();
    }
}

void AdditionalThread::stop()
{
    run_ = false;
}
