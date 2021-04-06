// Copyright 2021 GHA Test Team


#include <random>
#include "gtest/gtest.h"
#include "train.h"


TEST(TrainTest, test1) {
  Train* train = new Train;
  train->CreateCages(45);
  EXPECT_EQ(45, train->CountLength());
}


TEST(TrainTest, test2) {
  Train* train = new Train;
  train->CreateCages(7);
  EXPECT_EQ(7, train->CountLength());
}


TEST(TrainTest, test3) {
  Train* train = new Train;
  train->CreateCages(9);
  EXPECT_EQ(9, train->CountLength());
}


TEST(TrainTest, test4) {
  Train* train = new Train;
  train->CreateCages(12);
  EXPECT_EQ(12, train->CountLength());
}


TEST(TrainTest, test5) {
  Train* train = new Train;
  train->CreateCages(25);
  EXPECT_EQ(25, train->CountLength());
}

