#include <iostream>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/seq/pop_back.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/reverse.hpp>

#define WithoutLast(...)                       \
    BOOST_PP_SEQ_POP_BACK(                     \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define Last(...)                                   \
    BOOST_PP_SEQ_HEAD(                              \
        BOOST_PP_SEQ_REVERSE(                       \
            BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

#define ParticularCase(r, _, elem) case elem:

#define Case(...)                                                     \
    BOOST_PP_SEQ_FOR_EACH(ParticularCase, , WithoutLast(__VA_ARGS__)) \
    {                                                                 \
        Last(__VA_ARGS__);                                            \
        break;                                                        \
    }

#define Default(x) default: x; break;

#define Switch(condition,...) \
	switch(condition)         \
	{                         \
	    __VA_ARGS__           \
	}
