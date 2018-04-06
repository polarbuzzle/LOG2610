#include <QImage>
#include <QDebug>
#include <QQueue>
#include <windows.h>

#include "imagequeue.h"
#include "simpletracer.h"

ImageQueue::ImageQueue(QObject *parent, int capacity) :
    QObject(parent),
    m_capacity(capacity)
{
    // TODO
    semaphore_libre = CreateSemaphore(NULL,capacity, capacity, NULL);
    semaphore_occupee = CreateSemaphore(NULL, 0, capacity, NULL);
    mutex = CreateMutex(NULL, false, NULL);
}

ImageQueue::~ImageQueue()
{
    // TODO
    CloseHandle(semaphore_libre);
    CloseHandle(semaphore_occupee);
    CloseHandle(mutex);
}

void ImageQueue::enqueue(QImage *item)
{
    // TODO
    // tracer la taille de la file lorsqu'elle change
    WaitForSingleObject(semaphore_libre, INFINITE);
    WaitForSingleObject(mutex, INFINITE);
    queue.enqueue(item);
    SimpleTracer::writeEvent(this, queue.size());
    ReleaseMutex(mutex);
    ReleaseSemaphore(semaphore_occupee, 1, NULL);

}

QImage *ImageQueue::dequeue()
{
    // TODO
    // tracer la taille de la file lorsqu'elle change

    QImage* image;
    WaitForSingleObject(semaphore_occupee, INFINITE);
    WaitForSingleObject(mutex, INFINITE);
    image = queue.dequeue();
    SimpleTracer::writeEvent(this, queue.size());
    ReleaseMutex(mutex);
    ReleaseSemaphore(semaphore_libre, 1, NULL);

    return image;
}
