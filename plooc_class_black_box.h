/****************************************************************************
*  Copyright 2017 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/



/*============================ INCLUDES ======================================*/
#include <stdint.h>
#include <stdbool.h>

/*============================ MACROS ========================================*/
#undef def_class
#undef __def_class
#undef end_def_class
#undef __end_def_class
#undef extern_class
#undef __extern_class
#undef end_extern_class
#undef __end_extern_class
#undef class
#undef __class
/*============================ MACROFIED FUNCTIONS ===========================*/
/*! \NOTE: Never define __OOC_DEBUG__ unless you know the consequence and how  
 *!        the issue could be solved. But in anyway, there is nothing you can 
 *!        do about this header file. 
 */
#ifndef __OOC_DEBUG__

#define __class(__NAME)             __##__NAME

#define declare_class(__NAME)                                                   \
     typedef union __NAME __NAME;                

#define __def_class(__NAME,...)                                                 \
    typedef struct __##__NAME __##__NAME;                                       \
    struct __##__NAME {                                                         \
        __VA_ARGS__

#define __end_def_class(__NAME, ...)                                            \
    };    


#define __extern_class(__NAME,...)                                              \
    union __NAME {                                                              \
        __VA_ARGS__                                                             \
        uint_fast8_t __NAME##__chMask[(sizeof(struct{                           \
        __VA_ARGS__


#define __end_extern_class(__NAME, ...)                                         \
        }) + sizeof(uint_fast8_t) - 1) / sizeof(uint_fast8_t)];                 \
    };
    
#else

#define __class(__NAME)             __NAME

#define declare_class(__NAME)                                                   \
     typedef struct __NAME __NAME;                

#define __def_class(__NAME,...)                                                 \
    struct __NAME {                                                             \
        __VA_ARGS__
          
#define __end_def_class(__NAME, ...)                                            \
    };                                                                          
    
#define __extern_class(__NAME,...)                                              \
    struct __NAME {                                                             \
        __VA_ARGS__                                                             

#define __end_extern_class(__NAME, ...)                                         \
    };
    
#endif

#define end_def_class(__NAME, ...)      __end_def_class(__NAME, __VA_ARGS__)
#define def_class(__NAME, ...)          __def_class(__NAME, __VA_ARGS__)
#define class(__NAME)                   __class(__NAME)

#define extern_class(__NAME, ...)       __extern_class(__NAME, __VA_ARGS__)
#define end_extern_class(__NAME, ...)   __end_extern_class(__NAME, __VA_ARGS__)

#ifndef __PLOOC_CLASS_BLACK_BOX_H__
#define __PLOOC_CLASS_BLACK_BOX_H__

/*! \brief macro for initializing class in compiler-time
 *! \param __TYPE class name
 *! \param __OBJ target object
 *! \param ... initialization list
 */
#define __INIT_CLASS_OBJ(__TYPE, __OBJ, ...)                                    \
            union {                                                             \
                class(__TYPE) __##__OBJ;                                        \
                __TYPE;                                                         \
            } __OBJ = {                                                         \
                .__##__OBJ = __VA_ARGS__                                        \
            }
#define init_class_obj(__TYPE, __OBJ, ...)                                      \
            __INIT_CLASS_OBJ(__TYPE, __OBJ, __VA_ARGS__)

#define __EXTERN_CLASS_OBJ( __TYPE, __OBJ )                                     \
            extern union {                                                      \
                class(__TYPE) __##__OBJ;                                        \
                __TYPE;                                                         \
            }__OBJ;
#define extern_class_obj(__TYPE, __OBJ)                                         \
            __EXTERN_CLASS_OBJ( __TYPE, __OBJ )
#endif

/*----------------------------------------------------------------------------*          
 * new standard (lower case)                                                  *
 *----------------------------------------------------------------------------*/

#   undef __class_internal
#   define __class_internal(__SRC, __DES, __TYPE, ...)                          \
            class(__TYPE) *(__DES) = (class(__TYPE) *)(__SRC);                  \
            __with_class(__TYPE, (__SRC), __VA_ARGS__)
            
#   undef class_internal
#   define class_internal(__SRC, __DES, __TYPE,...)                             \
            __class_internal(__SRC, __DES, __TYPE, __VA_ARGS__)
            
#   undef __with_class
#   define __with_class(__TYPE, __SRC, ...)                                     \
        {                                                                       \
            class(__TYPE)*_ =(class(__TYPE) *)(__SRC);                          \
            UNUSED_PARAM(_);                                                    \
            __VA_ARGS__;                                                        \
        }                                                                       \
        for (class(__TYPE)*_ =(class(__TYPE) *)(__SRC); NULL != _; _ = NULL)

#   undef with_class
#   define with_class(__TYPE, __SRC, ...)                                       \
            __with_class(__TYPE, __SRC, __VA_ARGS__)                  

        
/*============================ TYPES =========================================*/

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


/* EOF */
