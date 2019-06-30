#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <boost/preprocessor.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>

static int is_init_rand = 0;
static int number_function = 1;

static uint32_t do_random(uint32_t start, uint32_t end)
{
	if (is_init_rand == 0)
	{
		srand((unsigned)time(0));
	}

	return (start + rand() % end);
}

//Сложение двух случайных чисел
static inline void function1(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	uint32_t  x = do_random(25, 50);
	uint32_t  y = do_random(25, 50);
	uint32_t summ = x + y;
}

//Сложение x с y*2 (Числа случайные)
static inline void function2(void) {

	printf("Function %d start \n", number_function);
	number_function++;

#define PRED(d, data) BOOST_PP_TUPLE_ELEM(2, 0, data)
#define OP(d, data) \
   ( \
      BOOST_PP_DEC( \
         BOOST_PP_TUPLE_ELEM(2, 0, data) \
      ), \
      BOOST_PP_ADD_D( \
         d, \
         BOOST_PP_TUPLE_ELEM(2, 1, data), \
         2 \
      ) \
   ) \
   /**/
	// increment 'x' by 2 'n' times
#define STRIDE(x, n) BOOST_PP_TUPLE_ELEM(2, 1, BOOST_PP_WHILE(PRED, OP, (n, x)))

	uint32_t  x = do_random(25, 50);
	uint32_t  y = do_random(25, 50);

	STRIDE(x, y)
}

//Декремент
static inline void function3(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_DEC(BOOST_PP_DEC(6)); // expands to 4
}

//Инкремент
static inline void function4(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_INC(BOOST_PP_INC(6)); // expands to 8
}

//Деление
static inline void function5(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_DIV(11, 5); // expands to 2
}

//Деление x на y и полученный результат делится ещё на два (Числа случайные)
static inline void function6(void) {

	printf("Function %d start \n", number_function);
	number_function++;

	uint32_t  x = do_random(50, 500);
	uint32_t  y = do_random(2, 5);

#define PRED(d, data) BOOST_PP_TUPLE_ELEM(2, 0, data)

#define OP(d, data) \
   ( \
      BOOST_PP_DEC( \
         BOOST_PP_TUPLE_ELEM(2, 0, data) \
      ), \
      BOOST_PP_DIV_D( \
         d, \
         BOOST_PP_TUPLE_ELEM(2, 1, data), \
         2 \
      ) \
   ) \
   /**/

	// halve 'x' 'n' times
#define HALVE(x, n) BOOST_PP_TUPLE_ELEM(2, 1, BOOST_PP_WHILE(PRED, OP, (n, x)))

	HALVE(x, y)

}

//Вычисляет остаток от деления
static inline void function7(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_MOD(11, 5);
}

static inline void function8(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_MUL(4, 4); // expands to 16
}

static inline void function9(void) {

	printf("Function %d start \n", number_function);
	number_function++;

	uint32_t  x = do_random(50, 500);
	uint32_t  y = do_random(2, 5);

#define PRED(d, data) BOOST_PP_TUPLE_ELEM(3, 0, data)

#define OP(d, data) \
   ( \
      BOOST_PP_DEC( \
         BOOST_PP_TUPLE_ELEM(3, 0, data) \
      ), \
      BOOST_PP_TUPLE_ELEM(3, 1, data), \
      BOOST_PP_MUL_D( \
         d, \
         BOOST_PP_TUPLE_ELEM(3, 2, data), \
         BOOST_PP_TUPLE_ELEM(3, 1, data) \
      ) \
   ) \
   /**/

	// raise 'x' to the 'n'-th power
	#define EXP(x, n) BOOST_PP_TUPLE_ELEM(3, 2, BOOST_PP_WHILE(PRED, OP, (n, x, 1)))

	EXP(x, y) // expands to 16
}

//Вычитание
static inline void function10(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_SUB(4, 3); // expands to 1
}

static inline void function11(void) {

	printf("Function %d start \n", number_function);
	number_function++;

#define PRED(d, data) BOOST_PP_TUPLE_ELEM(2, 0, data)

#define OP(d, data) \
   ( \
      BOOST_PP_DEC( \
         BOOST_PP_TUPLE_ELEM(2, 0, data) \
      ), \
      BOOST_PP_SUB_D( \
         d, \
         BOOST_PP_TUPLE_ELEM(2, 1, data), \
         2 \
      ) \
   ) \
   /**/

	// decrement 'x' by 2 'n' times
#define STRIDE(x, n) BOOST_PP_TUPLE_ELEM(2, 1, BOOST_PP_WHILE(PRED, OP, (n, x)))

	STRIDE(10, 2); // expands to 6
	STRIDE(14, 6); // expands to 2
}

static inline void function12(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_XOR(4, 3); // expands to 0
}

static inline void function13(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_XOR(5, 0); // expands to 1
}

static inline void function14(void) {
	printf("Function %d start \n", number_function);
	number_function++;
	BOOST_PP_OR(4, 3); // expands to 1
}