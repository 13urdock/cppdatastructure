#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h>

#define _DEBUG_  //디버그 모드 선언(?)

#ifndef _DEBUG_  //디버그 모드라면
#define LOG(x)
#else            //아닐 때는
//#define LOG(x) printf(c)
//#define LOG(...) printf(__VA_ARGS__) // 파라미터가 여러개 들어와도 됨
#define LOG(...) do{printf("LINE:%d/FUNC:%s/FILE:%s", __LINE__, __func__, __FILE__); printf(__VA_ARGS__); printf("\n");} while(0)
#endif

#endif
