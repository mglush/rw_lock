#include <stdio.h>
#include <pthread.h>
#include <iostream> 

#include "rwlock.h"

RWLock::RWLock() : ar(0), wr(0), aw(0), ww(0) {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&okToRead, NULL);
    pthread_cond_init(&okToWrite, NULL);
}
RWLock::~RWLock() {
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&okToRead);
    pthread_cond_destroy(&okToWrite);
}

void RWLock::startRead() {
    pthread_mutex_lock(&lock);
    // printf("START READ\n");
    pthread_mutex_unlock(&lock);
}

void RWLock::doneRead() {
    pthread_mutex_lock(&lock);
    // printf("DONE READ\n");
    pthread_mutex_unlock(&lock);
}

void RWLock::startWrite() {
    pthread_mutex_lock(&lock);
    // printf("START WRITE\n");
    pthread_mutex_unlock(&lock);
}

void RWLock::doneWrite() {
    pthread_mutex_lock(&lock);
    // printf("DONE WRITE\n");
    pthread_mutex_unlock(&lock);
}
