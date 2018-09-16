#ifndef PIPELINEMANAGER_H
#define PIPELINEMANAGER_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include <QDir>

#include "effects/effects.h"
#include "pipelinestage.h"

class PipelineManager : public QObject
{
    Q_OBJECT
public:
    explicit PipelineManager(QObject *parent = 0);
    void setup(QStringList fx, QDir &input, QDir &output);
    void launchParallel(int queueSize = 5);
    void joinThreads();
signals:
    void done();
public slots:
private:
    Effects m_effects;
    QList<PipelineStage*> m_stageList;
};

#endif // PIPELINEMANAGER_H
