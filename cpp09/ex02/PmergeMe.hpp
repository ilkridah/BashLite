#pragma once

#include<iostream>
#include<cmath>
#include<deque>
#include<vector>
#include<sstream>
#include<ctime>

void insertionSort_deque(std::deque<int>& arr, int left, int right) ;
void insertionSort(std::vector<int>& arr, int left, int right);
void mergeSort(std::vector<int>& arr, int left, int right);
void mergeSort_deque(std::deque<int>& arr, int left, int right);