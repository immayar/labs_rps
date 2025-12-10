#pragma once
#ifndef TEST_SORT_H
#define TEST_SORT_H

#include <vector>
#include <string>

// Функции для тестирования
void testEmptyArray();
void testSingleElement();
void testSortedArray();
void testReverseSortedArray();
void testRandomArray();
void testDuplicateElements();
void testNegativeNumbers();
void testMixedNumbers();

// Вспомогательные функции
bool isSorted(const std::vector<double>& arr);
void printTestResult(const std::string& testName, bool passed);
void runAllTests();

#endif