#include <QImage>
#include <QDebug>
#include <QQueue>

#include "imagequeue.h"
#include "simpletracer.h"

ImageQueue::ImageQueue(QObject *parent, int capacity) :
    QObject(parent),
    m_capacity(capacity)
{
    // TODO
}

ImageQueue::~ImageQueue()
{
    // TODO
}

void ImageQueue::enqueue(QImage *item)
{
    // TODO
    // tracer la taille de la file lorsqu'elle change
    SimpleTracer::writeEvent(this, 0);
}

QImage *ImageQueue::dequeue()
{
    // TODO
    // tracer la taille de la file lorsqu'elle change
    SimpleTracer::writeEvent(this, 0);
    return NULL;
}
