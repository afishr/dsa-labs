#pragma once
#ifndef CUSTOM_H
#define CUSTOM_H

#include <random>
#include <ctime>


int* getradomarray(int x);


float mtime(void(*f)(int*, int), int *arr, int l);

void swap(int &a, int &b);

void printarr(int *arr, int l);


#endif //CUSTOM_H
