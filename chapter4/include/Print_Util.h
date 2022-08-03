//
// Created by helisi on 2022/8/1.
//

#ifndef STUDY_C_PRINT_UTIL_H
#define STUDY_C_PRINT_UTIL_H

//#define DEBUG

#ifdef DEBUG
#define Printlnf(format,...) printf("("__FILE__":%d) %s: "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define Printlnf(format,...) printf(format"\n", ##__VA_ARGS__)
#endif

#define Print_Int(value) Printlnf(#value": %d", value)
#define Print_Long(value) Printlnf(#value": %ld", value)
#define Print_Float(value) Printlnf(#value": %f", value)
#define Print_Double(value) Printlnf(#value": lf", value)
#define Print_Char(value) Printlnf(#value": %c", value)
#define Print_Str(value) Printlnf(#value": %s", value)

#define Print_Array(format, array, length) \
{ \
for(int i = 0;i < length; ++i) \
{ \
    printf(format, array[i]); \
}; \
printf("\n"); }

#define Print_Array_Ln(format, array, length) \
{\
for(int i = 0;i < length; ++i) \
{ \
   Printlnf(#array"[%d]: %d", i, array[i]); \
} \
}

#define Print_Int_Array(array, length) Print_Array("%d, ", array, length)

#endif //STUDY_C_PRINT_UTIL_H
