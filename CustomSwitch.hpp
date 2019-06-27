#include <iostream>
//#include <boost/preprocessor/variadic/size.hpp>
//#include <boost/preprocessor/variadic/elem.hpp>
//#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/seq/pop_back.hpp>
//#include <boost/preprocessor/seq/pop_front.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
//#include <boost/preprocessor/seq/enum.hpp>
//#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
//#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/seq/reverse.hpp>

#define WithoutLast(...)                       \
    BOOST_PP_SEQ_POP_BACK(                     \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define Last(...)                                   \
    BOOST_PP_SEQ_HEAD(                              \
        BOOST_PP_SEQ_REVERSE(                       \
            BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

#define SimpleCase(x,y) case x: y; break;

#define ParticularCase(r, data, elem) case elem:data

#define FallthroughCase(...)                                          \
    BOOST_PP_SEQ_FOR_EACH(ParticularCase, , WithoutLast(__VA_ARGS__)) \
    Last(__VA_ARGS__); break;

#define Default(x) default: x; break;

#define Switch(condition,...) \
	switch(condition)         \
	{                         \
	    __VA_ARGS__           \
	}

#define Case(...) BOOST_PP_IIF(                               \
    BOOST_PP_GREATER(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 2), \
        FallthroughCase, SimpleCase)(__VA_ARGS__)

/* int main() */
/* { */
/* 	int a{89}; */
/* 	Switch(a, */
/* 		   Case(1,5, */
/* 				std::cout << "a") */
/* 		   Case(2, */
/* 				std::cout << "b") */
/* 		   Case(3,7, */
/*                 89, */
/*                 78, */
/* 				std::cout << "c") */
/* 		   Case(4, */
/* 				std::cout << "d") */
/* 		   Default(std::cout << "e")); */
 
/* 	return 0; */
/* } */
