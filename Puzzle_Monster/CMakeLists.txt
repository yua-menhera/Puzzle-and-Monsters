cmake_minimum_required(VERSION 3.13)

project(Puzzle_Monster)

add_executable(Puzzle_Monster
                battle.c
                define.c
				dungeon.c
				gems.c
				initialize.c
				main.c
				party.c
				utility.c)

target_include_directories(Puzzle_Monster PRIVATE include)