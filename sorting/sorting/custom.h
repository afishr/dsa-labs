#pragma once
#ifndef CUSTOM_H
#define CUSTOM_H

#include <random>
#include <ctime>

int* getradomarray(int);

float mtime(void(*)(int*, int), int *, int );

float mtime(void(*)(int*, int, int), int *, int, int);

void swap(int &, int &);

void printarr(int *, int);

int binarysearch(int *, int, int, int);


#endif //CUSTOM_H
