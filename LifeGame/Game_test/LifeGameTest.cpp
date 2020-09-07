//#pragma once
//#include <gtest\gtest.h>
//#include "../LifeGame/Game.h"
//
//class LifeGameTest :public testing::Test
//{
//};
//
//TEST_F(LifeGameTest, Set)
//{
//	Field f;
//	Strategy s(f);
//	s.set(1, 9);
//	s.set(2, 3);
//	s.set(0, 0);
//	s.set(9, 9);
//	s.set(1, 8);
//	ASSERT_TRUE(f[1][9].alive());
//	ASSERT_TRUE(f[9][9].alive());
//	ASSERT_TRUE(f[2][3].alive());
//	ASSERT_TRUE(f[0][0].alive());
//	ASSERT_TRUE(f[1][8].alive());
//	ASSERT_FALSE(f[1][1].alive());
//}
//
//TEST_F(LifeGameTest, Reset)
//{
//	Field f;
//	Strategy s(f);
//	ASSERT_FALSE(f[1][1].alive());
//	ASSERT_FALSE(f[8][6].alive());
//	ASSERT_FALSE(f[2][9].alive());
//	s.set(1, 1);
//	s.set(8, 6);
//	s.set(2, 9);
//	ASSERT_TRUE(f[1][1].alive());
//	ASSERT_TRUE(f[8][6].alive());
//	ASSERT_TRUE(f[2][9].alive());
//	s.clear(1, 1);
//	s.clear(8, 6);
//	s.clear(2, 9);
//	ASSERT_FALSE(f[1][1].alive());
//	ASSERT_FALSE(f[8][6].alive());
//	ASSERT_FALSE(f[2][9].alive());
//}
//
//TEST_F(LifeGameTest, Clear)
//{
//	Field f;
//	for (int i = 0; i < FIELD_SIZE; i++)
//		for (int j = 0; j < FIELD_SIZE; j++)
//			ASSERT_FALSE(f[i][j].alive());
//	Strategy s(f);
//	s.set(1, 9);
//	s.set(2, 3);
//	s.set(0, 0);
//	s.set(9, 9);
//	s.set(1, 8);
//
//	s.reset();
//	for (int i = 0; i < FIELD_SIZE; i++)
//		for (int j = 0; j < FIELD_SIZE; j++)
//			ASSERT_FALSE(f[i][j].alive());
//
//}
//
//TEST_F(LifeGameTest, Step)
//{
//	Field f;
//	Strategy s(f);
//	s.set(2, 2);
//	s.set(2, 3);
//	s.set(3, 2);
//	s.set(9, 9);
//
//	s.step();
//	ASSERT_FALSE(f[9][9].alive());
//	ASSERT_TRUE(f[3][3].alive());
//	ASSERT_TRUE(f[2][3].alive());
//	ASSERT_TRUE(f[3][2].alive());
//	ASSERT_TRUE(f[2][2].alive());
//
//}
//
//TEST_F(LifeGameTest, Back)
//{
//	Field f;
//	Strategy s(f);
//	s.set(9, 9);
//	s.back();
//	ASSERT_FALSE(f[9][9].alive());
//	s.set(9, 9);
//	s.step();
//	ASSERT_FALSE(f[9][9].alive());
//	s.back();
//	ASSERT_TRUE(f[9][9].alive());
//}
//
//TEST_F(LifeGameTest, Save)
//{
//	Field f;
//	Executor e(f);
//	Strategy s(f);
//
//	s.set(1, 9);
//	s.set(2, 3);
//	s.set(0, 0);
//	s.set(9, 9);
//	s.set(1, 8);
//	std::ofstream file2("output.txt");
//	e.serealizer_executor(file2);
//	file2.close();
//	std::ifstream file1("output.txt");
//	e.deserealizer_executor(file1);
//	file1.close();
//
//	ASSERT_TRUE(f[1][9].alive());
//	ASSERT_TRUE(f[9][9].alive());
//	ASSERT_TRUE(f[2][3].alive());
//	ASSERT_TRUE(f[0][0].alive());
//	ASSERT_TRUE(f[1][8].alive());
//	ASSERT_FALSE(f[1][1].alive());
//}
//
//TEST_F(LifeGameTest, Load)
//{
//	Field f;
//	Executor e(f);
//	std::ifstream file("input.txt");
//	e.deserealizer_executor(file);
//
//	ASSERT_TRUE(f[1][9].alive());
//	ASSERT_TRUE(f[3][3].alive());
//	ASSERT_TRUE(f[1][3].alive());
//	ASSERT_TRUE(f[0][0].alive());
//	ASSERT_TRUE(f[0][8].alive());
//	ASSERT_FALSE(f[1][0].alive());
//}
//
