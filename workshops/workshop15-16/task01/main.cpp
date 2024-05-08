/*
-You work as an analyst in a company that sells electronics. You are provided 
-with monthly sales of products for a year in the form of a vector, where each 
-element of the vector represents the sales amount for a month. Your task is 
-to analyze the data and perform the following operations:
-
-Find the total sales volume for the year.
-Determine the month with the maximum sales volume. If there are multiple months 
-with the maximum sales, output the first one.
-Calculate the average monthly sales.
-Determine whether the sales in each month exceed the average monthly sales. 
-For each month, output true or false accordingly.
-Find the number of months with sales below the average.
-
-Input Data
-Vector std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000, 
-                                 18000, 21000, 20000, 17000, 22000, 19000};, 
-where each element represents the sales amount for a month.
-
-Tasks to Implement
-Implement a function to calculate the total sales volume for the year.
-Implement a function to find the month with the maximum sales volume.
-Calculate the average monthly sales.
-Determine whether the sales in each month exceed the average monthly sales, 
-and output the corresponding true or false values.
-Find the number of months with sales below the average.
-
-Total sales volume for the year: 204000
-Month with maximum sales volume: 11
-Average monthly sales: 17000
-Sales above average: false false false true true false true true true true true true
-Number of months with sales below average: 3
-
-*/

#include <iostream>
#include <vector>

int getTotalSales(const std::vector<int>& sales) {
  int total = 0;
  for (int sale : sales) {
    total += sale;
  }
  return total;
}

int getMaxSalesMonth(const std::vector<int>& sales) {
  int max_month = 0;
  int max_sales = 0;
  for (int i = 0; i < sales.size(); ++i) {
    if (sales[i] > max_sales) {
      max_sales = sales[i];
      max_month = i + 1;
    }
  }
  return max_month;
}

double getAverageMonthlySales(const std::vector<int>& sales) {
  int total = getTotalSales(sales);
  return static_cast<double>(total) / sales.size();
}

bool isMonthSalesAboveAverage(const std::vector<int>& sales, int month) {
  double average = getAverageMonthlySales(sales);
  return sales[month - 1] > average;
}

int getMonthsBelowAverage(const std::vector<int>& sales) {
  int count = 0;
  double average = getAverageMonthlySales(sales);
  for (int sale : sales) {
    if (sale < average) {
      ++count;
    }
  }
  return count;
}

int main() {
  std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000,
                            18000, 21000, 20000, 17000, 22000, 19000};

  int total = getTotalSales(sales);
  int max_month = getMaxSalesMonth(sales);
  double average = getAverageMonthlySales(sales);
  int months_below_average = getMonthsBelowAverage(sales);

  std::cout << "total sales for year: " << total << std::endl;
  std::cout << "month volume: " << max_month << std::endl;
  std::cout << "average monthly sales: " << average << std::endl;
  for (int i = 0; i < sales.size(); ++i) {
    std::cout << "sales above average: ";
    std::cout << isMonthSalesAboveAverage(sales, i + 1) << " ";
  }
  std::cout << std::endl;
  std::cout << "number of months having sales below average: "
            << months_below_average << std::endl;

  return 0;
}
